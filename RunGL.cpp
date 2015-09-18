#define var GLfloat
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))//to_use-> COUNT_OF( floorTile_2m_INDICES)
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//=======================================================================================================================
    
    
    
#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT
        #define   glGenFramebuffers      glGenFramebuffersEXT
        #define   glBindFramebuffer      glBindFramebufferEXT
        #define   glDeleteFramebuffers   glDeleteFramebuffersEXT        
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT
         
         
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
       // #include <iostream.h>
        #include <fstream.h>
        #include <vector>
        //using namespace std; //___used for string object

        //-----------------------------------------------------------------------------
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include "headerFiles/glext.h"
        #include "headerFiles/glext_Init_A.cpp"
        //=====================================
        void InitGL(void);
        void RenderGL(void);
        void KillALData(void);
        void ProcessKeyboard(void);
        void shutDownGL(void); 
        bool CreateDummyGLWindow();       
        //=========================
        int  screenWidth;
        int  screenHeight; 
        int  viewWidth;
        int  viewHeight;        
        //----------------------------------------------------------------------
        GLfloat  Pass_MIDDLE_Mouse[2];
        GLfloat  Pass_MIDDLE_CONTROL_Mouse;
        GLfloat  Pass_MIDDLE_SHIFT_Mouse[2];        
        //-------------------------------
        bool keys[256], keypressed[256];
        bool mkeyIsReset = true;
        
        //#include "cpp/winInit.cpp"
        #include "cpp/configureWindow.cpp"
        //-------------------------------

        #include "headerFiles/VSync.h"
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------


#endif


/*
//===========================
#include "cpp/Timer.cpp"
Timer timer, t1;
float readTime;
//===========================
*/


//#include <cstdlib>
#include <sys/timeb.h>

int getMilliCount(){
	struct timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

int start = 0;
int milliSecondsElapsed = 0;
//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

bool sound_API_selector = 0;//_0_is_openAL_/_1_is_fMod

//=========================================================
GLfloat frequency[512];
GLfloat audioRotation[] = {1.0, 0.0, 1.0, 0.0};
GLfloat directionSoundTravels = 1.0;
GLuint  selectFrequency = 4;
//----------------------------------------------
#ifdef __APPLE__
        //--------------
        int  viewWidth;
        int  viewHeight;
        //----------------------------------------------
        #include "AUDIO/openAL_iOS/openAL_iOS_GLOBALS.cpp"
        //-----------------------------------------------
//        #import "fmod.hpp"
//        #import "fmod_errors.h"
        GLfloat frequency_fMod_iOS[64];

//        #include "AUDIO/fMod_iOS/fMod_iOS_GLOBALS.cpp" //_____found_in_EAGLView

        

#endif
//=========================================================
#ifdef WIN32
        
       #include "AUDIO/openAL_WIN/openAL_WIN_GLOBALS.cpp"
        //-----------------------------------------------
       #include "AUDIO/fMod_WIN/fMod_WIN_GLOBALS.cpp"
        int        playing  = 0;
        int       *channel  = 0;
        bool       playOnce = true;
        
#endif
//=========================================================




//=======================================================================================================================

GLfloat adjust_w = 1.0;

#include <math.h>
  
//=======================================================================================================================

#include "MATRIX_MATH.cpp"

//=======================================================================================================================


//--------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
        extern GLuint msaaFramebuffer;
        extern GLuint viewRenderbuffer;

        bool iOS_MSAA_IS_ON = true;
        
        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef __APPLE__
               GLuint  viewFramebuffer;
        #endif
          
        //-------------------------------------------------------------------------------


        GLuint m_uiShadowMapTexture;
        GLuint m_uiFrameBufferObject;



//=======================================================================================================================
//=======================================================================================================================


void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //---------------
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        ////glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //---------------
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //----------------
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	  
        //----------------        
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //----------------
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif
}

//===============================================================================================================================
var     lightMatrix[16];



var     view[16];
var     view_rotate[16];
var     modelWorld[16];
var     modelView[16];
var     projection[16];

var     modelRotation[16];

var     moveSetMatrix[16];

var     light_modelWorld[16];
var     light_view[16];
var     light_modelView[16];
var     light_projection[16];
var     shadowLight_textureMatrix[16];
var     invertView[16];

var     biasMatrix[] = {0.5, 0.0, 0.0, 0.0, 
                        0.0, 0.5, 0.0, 0.0, 
                        0.0, 0.0, 0.5, 0.0, 
                        0.5, 0.5, 0.5, 1.0};






//============================================================================================================================

var     moveShadowPivot_Z = 0.0;

//============================================================================================================================

//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================



//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================

 
#include "GLOBALS.cpp"
  
//============================================================================================================================

//============================================================================================================================

void setupTransforms_MainColor(void)
{
        
        LoadIdentity(view);
        Translate(view,             eyeposition[0], 
                                    eyeposition[1], 
                                    eyeposition[2]);


        //===========================================
        LoadIdentity(invertView);
        InvertMatrix(invertView, view);
        //=============================
        
        LoadIdentity(view_rotate);
        //--------------------   
        Rotate(view_rotate, 1.0, 0.0, 0.0, rotateModelWithMiddleMouse[0]);
        Rotate(view_rotate, 0.0, 1.0, 0.0, rotateModelWithMiddleMouse[1]);        
}

//============================================================================================================================


void setupTransforms_Shadows(void)
{

        LoadIdentity(light_view);
        //-------------------------------------------------
        Translate(light_view,       eyeposition_SHADOW[0],
                                    eyeposition_SHADOW[1],
                                    eyeposition_SHADOW[2]);
        
//LookAt(light_View, eyeposition_SHADOW[0] + eyeposition[0] * scaleViewMovement[0], eyeposition_SHADOW[1], eyeposition_SHADOW[2] ,  0 + eyeposition[0] * scaleViewMovement[0], 0, 0, 0.0f, 1.0f, 0.0f);

}

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{
        
    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   1)
    {
        #include "_SHADERS/copyFBO/copyFBO_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   2)//gaussianBlur_9x_Horizontal
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Horizontal_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   3)//gaussianBlur_9x_Vertical
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Vertical_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   4)
    {
        
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   5)
    {
        //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   6)
    {
        #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    
    
    
    //==================================================================================================          
    if(shaderNumber ==   10)
    {
        #include "_SHADERS/finalComposite/finalComposite_SHADER_RENDER.cpp"
    }         
    //--------------------------------------------------------------------------------------  


    if(shaderNumber ==  11)
    {
        #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_RENDER.cpp"
    }  
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  12)
    {
        #include "_SHADERS/baseRoom/baseRoom_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  13)
    {
        #include "_SHADERS/basic/basic_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------


}

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
        //==========================================================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp"
            alutInit(NULL, 0);
            //-------------------------------------
            SetVSyncState(true);
            //-----------------------------------------------------------------------------
                        rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                        rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                        //-----------------------------------------------------------------
                        zoomModelWithMiddleMouse      = Pass_MIDDLE_CONTROL_Mouse;
                        //-----------------------------------------------------------------     
                        moveModelWithMiddleMouse[0]   = Pass_MIDDLE_SHIFT_Mouse[0];
                        moveModelWithMiddleMouse[1]   = Pass_MIDDLE_SHIFT_Mouse[1];
                        //-----------------------------------------------------------------       
       
        //=================
        #endif
                   
                   
time(&gameTimerInit);                
                   
start = getMilliCount();
                
//################################################################################################################################
/*
        #ifdef __APPLE__
        
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_iOS/openAL_iOS_Init.cpp"
                }        
                if(sound_API_selector == 1)
                {        
                        //#include "AUDIO/fMod_iOS/fMod_iOS_Init.cpp" //_____found_in_EAGLView
                }
        
        #endif
        //=========================================================
        #ifdef WIN32
                
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_WIN/openAL_WIN_Init.cpp"
                }
                
                if(sound_API_selector == 1)
                {    
                        #include "AUDIO/fMod_WIN/fMod_WIN_Init.cpp"
                }
        
        #endif
*/



//========================================================================
#ifdef WIN32
                screenRatio                = (GLfloat)viewWidth / (GLfloat)viewHeight;
#endif
//--------------
#ifdef __APPLE__
                screenRatio                = (GLfloat)viewHeight/(GLfloat)viewWidth;
#endif
//========================================================================    
 
    
//NSLog(@"screenRatio: %f", (GLfloat)screenRatio);
   
//=====================================================================================================
//-----------------------------------------------------------------------------------------------------
//_____________________________________________________________________________________________________
GLfloat adjustToResolution = (GLfloat)viewWidth/(GLfloat)viewHeight;
//===================================================================
#ifdef WIN32
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //------------------------------------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   = (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = 1.0 / (GLfloat)viewWidth * (GLfloat)viewHeight; 
        display_00_MOVE[0]           += inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[1]           -=  display_00_SCALE[1] * 0.5;
        //------------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] / scaleScreenAlignedQuadRatio;
        display_00_MOVE[0] += skipTouchIncrement;
#endif       
//========================= 
#ifdef __APPLE__
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10*4.0;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //-----------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   =  (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = (1.0 / (GLfloat)viewHeight) * viewWidth; 
        display_00_MOVE[1]           -=  inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[0]           -=  display_00_SCALE[1] * 0.5 ;        
        //------------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] * scaleScreenAlignedQuadRatio;
        display_00_MOVE[1] -= skipTouchIncrement;
#endif        
//_____________________________________________________________________________________________________   
//-----------------------------------------------------------------------------------------------------   
//=====================================================================================================   


//======================================================================================================================
//======================================================================================================================
#ifdef WIN32        
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth  * resize_SHADOW_FBO, 
                                                           (GLsizei)viewHeight * resize_SHADOW_FBO, 
                                                            0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);        
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
        glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
	    //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
#endif
//===================== NSLog(@"viewWidth: %f", (GLfloat)viewWidth);   
#ifdef __APPLE__
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000, 
                                                           1000, 
                                                           0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
 #endif
//======================================================================================================================
//======================================================================================================================










//=======================
#include "INITIALIZE.cpp" //NOW USING FBO TO DISPLAY SCENE
//=======================




       
       
       
//==============================================================================
    #ifdef WIN32   
        atexit(KillALData);//_tell_openAL_to_run_KillALData_function_at_shutdown 
#endif    
        
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
        
//====================================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void RenderGL(void)
{
//t1.start();
//============
//countFrames ++;
//============

//=======================================================================================================================

      
                        //=================================================================
                        #ifdef __APPLE__   
                        //--------------         
                                //eyeposition[0] -= PassTouchMovement[0];
                                //eyeposition[1] -= PassTouchMovement[1];
                                //eyeposition[2] -= PassTouchMovement[2];                   
                        
                                //PassTouchMovement[0] = 0.0;
                                //PassTouchMovement[1] = 0.0;
                                //PassTouchMovement[2] = 0.0;
                        
                        //--------------                        
                        #endif 
                        //=================================================================
                                      
                        //=================================================================        
                        #ifdef WIN32  
                        //------------
                                rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                                rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                                //-------------------------------------------------------
                                zoomModelWithMiddleMouse = Pass_MIDDLE_CONTROL_Mouse;
                                //-------------------------------------------------------
                                moveModelWithMiddleMouse[0] = Pass_MIDDLE_SHIFT_Mouse[0];
                                moveModelWithMiddleMouse[1] = Pass_MIDDLE_SHIFT_Mouse[1];
                        //------------ 
                        #endif            
                        //=================================================================  
       
//============================================================================================================================       
//turnTable += 0.1;

        
      
LoadIdentity(moveSetMatrix);
Translate(moveSetMatrix, moveSet[0], moveSet[1],moveSet[2]);




//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
        glEnable(GL_DEPTH_TEST);
        glDepthMask(1);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        glDepthFunc(GL_LESS);
        glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);   

            #include "runDepth_FBO.cpp"
        
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
	    //glDepthMask(0);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 
        //glDepthFunc(GL_EQUAL);    
//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
  
//=============================================================================================================== 
//=============================================================================================================== 
/*
    glBindFramebuffer(GL_FRAMEBUFFER, softDiffuse_FBO);//softDiffuse_FBO_TEXTURE
    //==========================================
            shaderNumber = 5;  
    #include "softDiffuse.cpp" 
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  
*/  

//=============================================================================================================== 
//=============================================================================================================== 

    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_PRIMARY_FBO);//drawMainColor_PRIMARY_FBO_COLOR_TEXTURE, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE
    //==========================================
    #include "drawMainColor_FBO.cpp" 
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  

/*
//=============================================================================================================== 
//=============================================================================================================== 
    glBindFramebuffer(GL_FRAMEBUFFER, hardEdgeShadow_TEXTURE); //hardEdgeShadow_TEXTURE
    //----------------------------------------------------------------
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);
        shaderNumber = 1;        
        //---------------  
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//=============================================================================================================== 
*/



       #include "_SHADERS/PowerVR_blur/PowerVR_blur_RENDER.cpp"




//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================
#ifdef __APPLE__ //=======================================================
                  if(iOS_MSAA_IS_ON)
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);     
                  }else 
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, viewRenderbuffer);  
                  }
#endif //=================================================================

    //==================================__FINAL_COMPOSITE__===============================
    glActiveTexture (GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    //----------------------------
    glActiveTexture (GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    //----------------------------    
    glActiveTexture (GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, generic_01_TEXTURE);//
    //---------------------------------------------------------------------
    shaderNumber = 10;
    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    //==================================__FINAL_COMPOSITE__===============================


/*
    
    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_FBO);
    const GLenum discards[]  = {GL_COLOR_ATTACHMENT0,GL_DEPTH_ATTACHMENT};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,2,discards);
   
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_HorizontalPass_fboId);
    const GLenum discards2[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards2);
    
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_VerticalPass_fboId);
    const GLenum discards3[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards3);
*/
//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================

    
    
    
    
marc_ROTATE[3] += 1.2;
//marc_POSITION[2] -= 0.0005;
//moveSet[0] -= 0.01;

         //t1.stop();
        //readTime = t1.getElapsedTimeInMilliSec();
        
        
time(&gameTimerEnd);

milliSecondsElapsed = getMilliSpan(start);

#ifdef __APPLE__
NSLog(@"milliSecondsElapsed: %i", (int)milliSecondsElapsed);
#endif
   
}//_END_RenderGL()//#####################################################################################################


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void ProcessKeyboard(void)
{
/*    if (keys['L'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyeposition_SHADOW[0]         +=  1.011;
    }
    if (keys['J'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyeposition_SHADOW[0]         -=  1.011;
    }    
    if (keys['I'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyeposition_SHADOW[1]         += 1.011;
    } 
    if (keys['K'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyeposition_SHADOW[1]         -=  1.011;
    }
    if (keys['O'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyeposition_SHADOW[2]         +=  1.011;
    }
    if (keys['U'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             eyeposition_SHADOW[2]         -=  1.011;
    }
*/   //--------------------------------------------------------------------------
  
  
    #include "_SHADERS/baseRoom/baseRoom_SHADER_KEYBOARD.cpp"
    //=================================================================================================================      
    
    #include "KEYBOARD/mainRoomControls.cpp"
 
 
 	

  
 
    //=======================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__LIGHTING__======================
    if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            ambient_LIGHT_01_baseRoom              +=   0.01015;
   
    }
    if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            ambient_LIGHT_01_baseRoom              -=   0.01015;

    }
    //-----------------------------------------------------------
    if (keys['X'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[0]             +=   0.000001;
    }
    if (keys['Z'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[0]             -=   0.000001;
    }    
    //-----------------------------------------------------------
    if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[1]             +=   0.000001;
    }
    if (keys['C'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustShadowPos[1]             -=   0.000001;
    }     
    //-----------------------------------------------------------    
    if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustBlurOffset               +=  0.01;
    }
    if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            adjustBlurOffset               -=  0.01;
    }     
  
      //======================================__LIGHTING__======================    
    //--------------------------------------------------------------------------       
    //=================================================================================================================    

  
    if(keys[VK_F8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         ofstream outSettings("settings.cpp");
             
         
         //------------------------------------------------------------------------------------------------------------------------------        
         outSettings << "var          adjustShadowPos[]      =  {"    
                                  <<  adjustShadowPos[0]      << ", "   
                                  <<  adjustShadowPos[1]      << "};\n\n";   
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyeposition_SHADOW[]    =  {"   
                                  << eyeposition_SHADOW[0] << ", "
                                  << eyeposition_SHADOW[1] << ", "
                                  << eyeposition_SHADOW[2] << ", "
                                  << eyeposition_SHADOW[3] << "};\n\n";
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var          gameTimerInit        =  "    
                                  <<  gameTimerInit        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          gameTimerEnd        =  "    
                                  <<  gameTimerEnd        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          secondsElapsed        =  "    
                                  <<  (GLfloat)milliSecondsElapsed * 0.001        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var          countFrames                    =  "    
                                  <<  countFrames                    << ";\n\n";   
        
        
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "GLuint       getOpenGL_ExtentionValues                    =  "    
                                  <<  getOpenGL_ExtentionValues                    << ";\n\n";   
        
          
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyeposition_SHADOW[]    =  {"   
                                  << eyeposition_SHADOW[0] << ", "
                                  << eyeposition_SHADOW[1] << ", "
                                  << eyeposition_SHADOW[2] << ", "
                                  << eyeposition_SHADOW[3] << "};\n\n";
         //------------------------------------------------------------------------------------------------------------------------------

         outSettings << "var           eyeposition[]      =  {"   
                                    << eyeposition[0]     << ", "
                                    << eyeposition[1]     << ", "
                                    << eyeposition[2]     << ", 0.0};\n";                

         //------------------------------------------------------------------------------------------------------------------------------

         //------------------------------------------------------------------------------------------------------------------------------
        
        outSettings << "var           rotateModelWithMiddleMouse[]       =  {"   
                                    << rotateModelWithMiddleMouse[0]      << ", "
                                    << rotateModelWithMiddleMouse[1]      << "};\n\n"; 
        
         //------------------------------------------------------------------------------------------------------------------------------
       
         outSettings << "var           moveSet[]       =  {"   
                                    << moveSet[0]      << ", "
                                    << moveSet[1]      << ", "
                                    << moveSet[2]      << ", 1.0};\n";                
        
         //------------------------------------------------------------------------------------------------------------------------------
    
    
   //----------------------------------------------------------------------------------------------------------------
        
    }//_END_F8

//=======================================================================================
//---------------------------------------------------------------------------------------
//_______________________________________________________________________________________
if(keys[VK_F9])
{
    GLsizei screenCaptureWidth  = (GLsizei)viewWidth; 
    GLsizei screenCaptureHeight = (GLsizei)viewHeight;        
                
    GLubyte *pixmap =(GLubyte *)malloc(screenCaptureWidth*screenCaptureHeight*4);
    
    glReadPixels(0,0,screenCaptureWidth,screenCaptureHeight,GL_BGRA,GL_UNSIGNED_BYTE,pixmap);
    
    FIBITMAP *texture = FreeImage_ConvertFromRawBits( pixmap, screenCaptureWidth, screenCaptureHeight, screenCaptureWidth*4, 32, 0xFF0000, 0x00FF00, 0x0000FF, true);    
    FreeImage_Save(FIF_BMP, texture, "AAAAA.bmp", 0);         
        
    free(pixmap);                 
}          
//_______________________________________________________________________________________
//---------------------------------------------------------------------------------------
//=======================================================================================



#include "KEYBOARD/keyboard_RESET.c"

    

    //=================================================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__SELECT_MODEL======================
    if (keys[VK_OEM_PERIOD] && VK_OEM_PERIOD_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel += 1;
             VK_OEM_PERIOD_KeyIsReset = false;   
    }
    //=============================================================    
    if (keys[VK_OEM_COMMA] && VK_OEM_COMMA_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel -= 1;
             VK_OEM_COMMA_KeyIsReset = false;   
    }
    //======================================__SELECT_MODEL__====================     
    //--------------------------------------------------------------------------
    //=================================================================================================================
    //=================================================================================================================
    //--------------------------------------------------------------------------     
    //======================================__BOX_COUNT__====================        
    if (keys[VK_PRIOR] && VK_PRIOR_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount +=  1;
         VK_PRIOR_KeyIsReset  = false;
    }         
    if (keys[VK_NEXT]  && VK_NEXT_KeyIsReset  && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount -=  1;
         VK_NEXT_KeyIsReset   = false;    
    }       
    //======================================__BOX_COUNT__====================         
    //--------------------------------------------------------------------------       
    //=================================================================================================================   
    
    
     
   
}//_END_ProcessKeyboard()
#endif


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


void shutDownGL( void )
{

//=======================================================================================================================
//=======================================================================================================================
        
        #include "SHUTDOWN.cpp"
        
                                                               
 
 
 
 
}


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void KillALData()
{
	alDeleteBuffers(1, &Buffer_dungeonWAV);
	alDeleteSources(1, &Source_dungeonWAV);
    alutExit();
}
#endif




