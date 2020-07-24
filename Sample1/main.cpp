# include <windows.h>
#include <GL/glut.h>

void mydisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);
//glColor3f(1.0,0.0,0.0);   red
//glColor3f(0.0,1.0,0.0);   green
//glColor3f(0.0,0.0,1.0);   blue
glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.5);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.3, -0.5);
    glVertex2f(-0.3, 0.5);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.3, -0.5);
    glVertex2f(0.3, -0.5);
glEnd();
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutCreateWindow("simple");
glutDisplayFunc(mydisplay);
glutMainLoop();
}
