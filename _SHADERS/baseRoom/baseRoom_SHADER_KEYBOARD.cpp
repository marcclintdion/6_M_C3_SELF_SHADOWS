if(configureShader == 12)
{
    //=================================================================
    if(selectBaseRoomLight == 0)
    {
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[0]   +=  0.0404;;
        }	
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[0]   -=  0.0404;;
        }
        //---------------------------------------------------- 
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[1]   +=  0.0404;;
        }
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[1]   -=  0.0404;;       
        } 
        //----------------------------------------------------  
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[2]   +=  0.0404;;      
        }
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_01_POSITION[2]   -=  0.0404;;
        }
    }
    //=================================================================
    if(selectBaseRoomLight)
    {
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[0]   +=  0.0404;;
        }	
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[0]   -=  0.0404;;
        }
        //---------------------------------------------------- 
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[1]   +=  0.0404;;
        }
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[1]   -=  0.0404;;       
        } 
        //----------------------------------------------------  
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[2]   +=  0.0404;;      
        }
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_02_POSITION[2]   -=  0.0404;;
        }
    }
    //=================================================================
    if(selectBaseRoomLight)
    {
        if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[0]   +=  0.0404;;
        }	
        if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[0]   -=  0.0404;;
        }
        //---------------------------------------------------- 
        if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[1]   +=  0.0404;;
        }
        if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[1]   -=  0.0404;;       
        } 
        //----------------------------------------------------  
        if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[2]   +=  0.0404;;      
        }
        if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    	{
              baseRoom_LIGHT_03_POSITION[2]   -=  0.0404;;
        }
    }
    
    
    //===============================================================================================
    if(keys[VK_F7])
    {
         ofstream outSettings("_SHADERS/baseRoom/settings.cpp");
         
         //=================================================================
         outSettings << "var          baseRoom_LIGHT_01_POSITION[]    =  {"   
                                  <<  baseRoom_LIGHT_01_POSITION[0] << ", "
                                  <<  baseRoom_LIGHT_01_POSITION[1] << ", "
                                  <<  baseRoom_LIGHT_01_POSITION[2] << ", "
                                  <<  baseRoom_LIGHT_01_POSITION[3] << "};\n";            
         //---------------------------------------------------------------------
         outSettings << "var          baseRoom_LIGHT_02_POSITION[]    =  {"   
                                  <<  baseRoom_LIGHT_02_POSITION[0] << ", "
                                  <<  baseRoom_LIGHT_02_POSITION[1] << ", "
                                  <<  baseRoom_LIGHT_02_POSITION[2] << ", "
                                  <<  baseRoom_LIGHT_02_POSITION[3] << "};\n";            
         //---------------------------------------------------------------------      
         outSettings << "var          baseRoom_LIGHT_03_POSITION[]    =  {"   
                                  <<  baseRoom_LIGHT_03_POSITION[0] << ", "
                                  <<  baseRoom_LIGHT_03_POSITION[1] << ", "
                                  <<  baseRoom_LIGHT_03_POSITION[2] << ", "
                                  <<  baseRoom_LIGHT_03_POSITION[3] << "};\n\n";            
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       ambient_LIGHT_01_baseRoom           =  "    
                                  <<  ambient_LIGHT_01_baseRoom        << ";\n";   
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       ambient_LIGHT_02_baseRoom           =  "    
                                  <<  ambient_LIGHT_02_baseRoom        << ";\n";         
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       ambient_LIGHT_03_baseRoom           =  "    
                                  <<  ambient_LIGHT_03_baseRoom        << ";\n\n";            
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       shininess_LIGHT_01_baseRoom         =  "    
                                  <<  shininess_LIGHT_01_baseRoom      << ";\n";   
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       shininess_LIGHT_02_baseRoom         =  "    
                                  <<  shininess_LIGHT_02_baseRoom      << ";\n";         
         //--------------------------------------------------------------------- 
         outSettings << "GLuint       shininess_LIGHT_03_baseRoom         =  "    
                                  <<  shininess_LIGHT_03_baseRoom      << ";\n\n";            
          
    
    }//if(keys[VK_F7])
    //===============================================================================================

}//if(configureShader == 12;
