#include<windows.h>
#include<GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.25,0.25,0.0);
        glVertex3f(0.75,0.25,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.75,0.75,0.0);
        glVertex3f(0.25,0.75,0.0);
    glEnd();
    glTranslatef(-0.1,0.2,0.0); //Translation
    glutSolidSphere(0.15,12,2);
    glFlush();
}
void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); //size of output screen
    glutInitWindowPosition(400 ,300); // position of output screen
    glutCreateWindow("Sample2");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
