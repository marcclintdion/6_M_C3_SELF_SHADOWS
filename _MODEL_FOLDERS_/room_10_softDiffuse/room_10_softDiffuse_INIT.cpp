/*//========================================================================
#ifdef __APPLE__                                                                                      
 //--------------                                                                                     
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"room_10_softDiffuse.png"].CGImage;           
    width                   =  CGImageGetWidth(spriteImage);                                          
    height                  =  CGImageGetHeight(spriteImage);                                         
    spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                    
    spriteContext           =  CGBitmapContextCreate(spriteData,                                      
                                                     width,                                           
                                                     height,                                          
                                                     8,                                               
                                                     width * 4,                                       
                                                     CGImageGetColorSpace(spriteImage),               
                                                     kCGImageAlphaNoneSkipLast);                      
    CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                           
    CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                           
    CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                           
    CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                 
    CGContextRelease(spriteContext);                                                                  
    //---------                                                                                       
        glGenTextures(1, &room_10_softDiffuse_TEXTUREMAP);                                         
        glBindTexture(GL_TEXTURE_2D, room_10_softDiffuse_TEXTUREMAP);                              
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
            free(spriteData);                                                                         
        }                                                                                             
//----                                                                                                
#endif                                                                                                
//========================================================================                            
    //-----------------------------------------------------------------------------------                                              
    #ifdef WIN32                                                                                                                       
    loadTexture("_MODEL_FOLDERS_/room_10_softDiffuse/room_10_softDiffuse.png",          room_10_softDiffuse_TEXTUREMAP);    
    #endif                                                                                                                             
*/    //-----------------------------------------------------------------------------------                                              
    #include    "room_10_softDiffuse.cpp"                                                                                         
    glGenBuffers(1,              &room_10_softDiffuse_VBO);                                                                         
    glBindBuffer(GL_ARRAY_BUFFER, room_10_softDiffuse_VBO);                                                                         
    glBufferData(GL_ARRAY_BUFFER, sizeof(room_10_softDiffuse), room_10_softDiffuse, GL_STATIC_DRAW);                             
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
    //-----------------------------------------------------------------------------------                                              
    #include    "room_10_softDiffuse_INDICES.cpp"                                                                                 
    glGenBuffers(1,              &room_10_softDiffuse_INDICES_VBO);                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, room_10_softDiffuse_INDICES_VBO);                                                         
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(room_10_softDiffuse_INDICES), room_10_softDiffuse_INDICES, GL_STATIC_DRAW);     
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                          
    //-----------------------------------------------------------------------------------                                              
