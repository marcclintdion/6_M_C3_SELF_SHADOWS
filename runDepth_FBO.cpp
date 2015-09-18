//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#ifdef WIN32
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (GLsizei)(viewWidth) * resize_SHADOW_FBO - 2, (GLsizei)(viewHeight) * resize_SHADOW_FBO - 2);
        //----------------------------------------------------------------

      LoadIdentity(light_projection);
      PerspectiveMatrix(light_projection, fieldOfView, (GLfloat)viewWidth /(GLfloat)viewHeight,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);

//float aspectRatio = viewWidth/viewHeight;
//LoadIdentity(light_projection);
//mtxOrtho(light_projection, -4*aspectRatio, 4*aspectRatio , -4, 4, 2, 50);




/*
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (2048)-2, (2048)-2);
        //----------------------------------------------------------------

        LoadIdentity(Light_Projection);
        PerspectiveMatrix(Light_Projection, fieldOfView, 2048 / 2048,  adjustNearFar[0],  adjustNearFar[1]);
*/
#endif
   
#ifdef   __APPLE__     
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, 2000 - 2, 1000 - 2);
        //----------------------------------------------------------------
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        LoadIdentity(light_projection);
        PerspectiveMatrix(light_projection, fieldOfView, 2000 / 1000,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);
#endif          
      

        //====================================================================================    

shaderNumber = 11;      
setupTransforms_Shadows();         

                                                            
for(float i = 0; i < 6.5 * 3.0; i += 6.5)
{    
        //=================================================================================
        room_10_softDiffuse_POSITION[0] = i;
        //#include "_MODEL_FOLDERS_/room_10/room_10_SHADOW_00.cpp"
        //#include "_MODEL_FOLDERS_/room_10_softDiffuse/room_10_softDiffuse_RENDER.cpp"
        //=================================================================================
      

}
    GLfloat switchMoveTemp = 0.0;
    GLfloat moveTemp[] = {0.1, 0.0, 1.5, 0.0};

    #include "_MODEL_FOLDERS_/marc/marc_SHADOW_00.cpp"

    switchMoveTemp = 1.0;
    #include "_MODEL_FOLDERS_/marc/marc_SHADOW_00.cpp"












