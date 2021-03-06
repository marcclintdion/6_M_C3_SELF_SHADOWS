//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //=======================================================================================================================
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0 );
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    //----------------------------------------------------------------------------------
    
    //=======================================================================================================================
    #ifdef WIN32
        //-------------------------------------------------------------------------------------------------------               
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        LoadIdentity(projection);
        PerspectiveMatrix(projection, fieldOfView, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar_CAMERA[0],  adjustNearFar_CAMERA[1]);
        //-------------------------------------------------------------------------------------------------------          
    #endif
    //=======================================================================================================================
    
    //=======================================================================================================================
    #ifdef __APPLE__
                            //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
        //-------------------------------------------------------------------------------------------------------               
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        LoadIdentity(projection);
        PerspectiveMatrix(projection, fieldOfView+14, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar_CAMERA[0],  adjustNearFar_CAMERA[1]);
        //-------------------------------------------------------------------------------------------------------  
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        //-------------------------------------------------------------------------------------------------------          
    #endif                  //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
    //=======================================================================================================


for(float i = 0; i < 6.5*3; i+=6.5)
{    
    //=================================================================================
    shaderNumber = 12;
    //----------------
    room_10_softDiffuse_POSITION[0] = i;
    //-----------------------
    //#include "_MODEL_FOLDERS_/room_10/room_10_RENDER.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/room_10_softDiffuse/room_10_softDiffuse_RENDER.cpp"  
}
    //=================================================================================
    shaderNumber = 13;  
    //-------------------   
    switchMoveTemp = 0.0;    
    #include "_MODEL_FOLDERS_/marc/marc_RENDER.cpp"
    
    switchMoveTemp = 1.0;
    #include "_MODEL_FOLDERS_/marc/marc_RENDER.cpp"
    





