#include <stdio.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

int main(void)
{
EGLint majorVersion;
EGLint minorVersion;
EGLBoolean success = EGL_FALSE;
EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
if (display != EGL_NO_DISPLAY) {
success = eglInitialize(display, &majorVersion, &minorVersion);
}
if (success != EGL_TRUE)
{
EGLint errno = eglGetError();
if (errno != EGL_SUCCESS)
{
char errmsg[32];
sprintf(errmsg, "[EGL]Initializationfailed.Errorcode:0x%04x", errno);
// EGL_BAD_DISPLAYEGLDisplay参数错误
// EGL_NOT_INITIALIZEDEGL不能初始化
}
}
return 0;
}