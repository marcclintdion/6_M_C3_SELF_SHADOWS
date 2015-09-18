//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

var         baseRoom_LIGHT_01_POSITION[]    =  {8.3626, 14.1865, 18.1465, 1};
var         baseRoom_LIGHT_02_POSITION[]    =  {-2.36245, -1.16566, 0.7939, 1};
var         baseRoom_LIGHT_03_POSITION[]    =  {-0.2, -3, -4.09981, 1};

var          ambient_LIGHT_01_baseRoom      =  0.0919002;
var          ambient_LIGHT_02_baseRoom      =  0.56895;
var          ambient_LIGHT_03_baseRoom      =  1.02997;

var          shininess_LIGHT_01_baseRoom    =  100.0;
var          shininess_LIGHT_02_baseRoom    =  100.0;
var          shininess_LIGHT_03_baseRoom    =  100.0;


//=======================================================
GLuint      baseRoom_SHADER_VERTEX;                                                                                 
GLuint      baseRoom_SHADER_FRAGMENT;                                                                               
GLuint      baseRoom_SHADER;     
//-------------------------------------------------------
GLuint      UNIFORM_LIGHT_01_POSITION_baseRoom;                                                                     
GLuint      UNIFORM_LIGHT_02_POSITION_baseRoom; 
GLuint      UNIFORM_LIGHT_03_POSITION_baseRoom; 

GLuint      UNIFORM_ambient_LIGHT_01_baseRoom;
GLuint      UNIFORM_ambient_LIGHT_02_baseRoom;
GLuint      UNIFORM_ambient_LIGHT_03_baseRoom;

GLuint      UNIFORM_shininess_LIGHT_01_baseRoom;
GLuint      UNIFORM_shininess_LIGHT_02_baseRoom;
GLuint      UNIFORM_shininess_LIGHT_03_baseRoom;
//-------------------------------------------------------
GLuint      UNIFORM_LIGHT_MATRIX_baseRoom;                 

GLuint      UNIFORM_PROJECTION_baseRoom;  
GLuint      UNIFORM_MODELVIEW_baseRoom; 
GLuint      UNIFORM_VIEW_baseRoom; 
GLuint      UNIFORM_MODELWORLD_baseRoom; 
GLuint      UNIFORM_VIEW_ROTATE_baseRoom;

GLuint      UNIFORM_MOVESET_MATRIX_baseRoom;

GLuint      UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_baseRoom;

//--------------------------------------------------------
GLuint      UNIFORM_ShadowTexture_baseRoom;       
GLuint      UNIFORM_TEXTURE_cornerSoftDiffuse;       
GLuint      UNIFORM_TEXTURE_DOT3_baseRoom;  
GLuint      UNIFORM_TEXTURE_baseRoom; 

//===============================================
GLuint      selectBaseRoomLight = 0;


