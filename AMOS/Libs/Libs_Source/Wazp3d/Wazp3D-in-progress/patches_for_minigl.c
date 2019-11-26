#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define MLOOP(nbre) for(m=0;m<nbre;m++)
#define NLOOP(nbre) for(n=0;n<nbre;n++)

PatchGLReadPixels(struct GLContextIFace *Self,GLint x, GLint y, GLsizei width,GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
GLcontext context = GET_INSTANCE(Self);
double dzspan[2048];
float  *fz=pixels;
double *dz=pixels;

	if(format!=GL_DEPTH_COMPONENT)
		glReadPixels(x,y,width,height,format,type,pixels);

	if(format==GL_DEPTH_COMPONENT)
	if(type==GL_FLOAT)
	MLOOP(height)
	{
	PatchW3D_ReadZSpan(context->w3dContext,x,y+m,width,dzspan);
	NLOOP(width)
		fz[n]=dzspan[n];
	fz+=width;
	}

	if(format==GL_DEPTH_COMPONENT)
	if(type==GL_DOUBLE)
	MLOOP(height)
	{
	PatchW3D_ReadZSpan(context->w3dContext,x,y+m,width,dz);
	dz+=width;
	}
}