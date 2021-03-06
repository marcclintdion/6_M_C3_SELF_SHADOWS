    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-       
    setupTransforms_Shadows();                                                                   
    //========================                                                                   

    LoadIdentity(modelWorld);                                                                    
    //------------------------                                                                   
    glBindBuffer(GL_ARRAY_BUFFER, room_10_softDiffuse_VBO);                                   
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, room_10_softDiffuse_INDICES_VBO);                   
    //------------------------------------------------------------------------                   
    Translate(modelWorld, room_10_softDiffuse_POSITION[0],                                    
                          room_10_softDiffuse_POSITION[1],                                    
                          room_10_softDiffuse_POSITION[2]);                                   
    //------------------------------------------------------------------------                   
    Rotate(modelWorld,    room_10_softDiffuse_ROTATE[0],                                      
                          room_10_softDiffuse_ROTATE[1],                                      
                          room_10_softDiffuse_ROTATE[2],                                      
                          room_10_softDiffuse_ROTATE[3]);                                     
//=============================================                                                  
SelectShader(shaderNumber);                                                                      
//=============================================                                                  
    glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);      
