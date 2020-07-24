#include<windows.h>
#include<GL/glut.h>

void display(void)
{
    glPushMatrix();

    glColor3f(1.0,0.0,0.0); //Red Color
    //Train compartment 1
    glBegin(GL_QUADS);
        glVertex3f(0.05,-0.2,0.0);
        glVertex3f(-0.9,-0.2,0.0);
        glVertex3f(-0.9,-0.5,0.0);
        glVertex3f(0.05,-0.5,0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0); //White Color
    //Stick
    glBegin(GL_QUADS);
        glVertex3f(0.05,-0.32,0.0);
        glVertex3f(0.15,-0.32,0.0);
        glVertex3f(0.15,-0.38,0.0);
        glVertex3f(0.05,-0.38,0.0);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Red Color
    //Train compartment 2
    glBegin(GL_QUADS);
        glVertex3f(0.15,-0.2,0.0);
        glVertex3f(0.15,-0.5,0.0);
        glVertex3f(0.8,-0.5,0.0);
        glVertex3f(0.8,-0.2,0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0); //White Color
    //Window 1
    glBegin(GL_QUADS);
        glVertex3f(-0.85,-0.275,0.0);
        glVertex3f(-0.85,-0.375,0.0);
        glVertex3f(-0.75,-0.375,0.0);
        glVertex3f(-0.75,-0.275,0.0);
    glEnd();

    //Window 2
    glBegin(GL_QUADS);
        glVertex3f(-0.7,-0.275,0.0);
        glVertex3f(-0.7,-0.375,0.0);
        glVertex3f(-0.6,-0.375,0.0);
        glVertex3f(-0.6,-0.275,0.0);
    glEnd();

    //Window 3
    glBegin(GL_QUADS);
        glVertex3f(-0.55,-0.275,0.0);
        glVertex3f(-0.55,-0.375,0.0);
        glVertex3f(-0.45,-0.375,0.0);
        glVertex3f(-0.45,-0.275,0.0);
    glEnd();

    //Window 4
    glBegin(GL_QUADS);
        glVertex3f(-0.4,-0.275,0.0);
        glVertex3f(-0.4,-0.375,0.0);
        glVertex3f(-0.3,-0.375,0.0);
        glVertex3f(-0.3,-0.275,0.0);
    glEnd();

    //Window 5
    glBegin(GL_QUADS);
        glVertex3f(-0.25,-0.275,0.0);
        glVertex3f(-0.25,-0.375,0.0);
        glVertex3f(-0.15,-0.375,0.0);
        glVertex3f(-0.15,-0.275,0.0);
    glEnd();

    //Window 6
    glBegin(GL_QUADS);
        glVertex3f(-0.1,-0.275,0.0);
        glVertex3f(-0.1,-0.375,0.0);
        glVertex3f(0.0,-0.375,0.0);
        glVertex3f(0.0,-0.275,0.0);
    glEnd();

    //Window 7
    glBegin(GL_QUADS);
        glVertex3f(0.2,-0.275,0.0);
        glVertex3f(0.2,-0.375,0.0);
        glVertex3f(0.3,-0.375,0.0);
        glVertex3f(0.3,-0.275,0.0);
    glEnd();

    //Window 8
    glBegin(GL_QUADS);
        glVertex3f(0.35,-0.275,0.0);
        glVertex3f(0.35,-0.375,0.0);
        glVertex3f(0.45,-0.375,0.0);
        glVertex3f(0.45,-0.275,0.0);
    glEnd();

    //Window 9
    glBegin(GL_QUADS);
        glVertex3f(0.5,-0.275,0.0);
        glVertex3f(0.5,-0.375,0.0);
        glVertex3f(0.6,-0.375,0.0);
        glVertex3f(0.6,-0.275,0.0);
    glEnd();

    //Window 10
    glBegin(GL_QUADS);
        glVertex3f(0.65,-0.275,0.0);
        glVertex3f(0.65,-0.375,0.0);
        glVertex3f(0.75,-0.375,0.0);
        glVertex3f(0.75,-0.275,0.0);
    glEnd();

    //Train chimney pillar
    glBegin(GL_QUADS);
        glVertex3f(0.6,-0.05,0.0);
        glVertex3f(0.6,-0.2,0.0);
        glVertex3f(0.7,-0.2,0.0);
        glVertex3f(0.7,-0.05,0.0);
    glEnd();

    //Wheel 1
    glTranslatef(-0.65,-0.5,0.0); //Translation
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 2
    glTranslatef(0.45,0.0,0.0); //Translation
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 3
    glTranslatef(0.5,0.0,0.0); //Translation
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 4
    glTranslatef(0.35,0.0,0.0); //Translation
    glutSolidSphere(0.08,100,11);
    glFlush();

    glColor3f(1.0,0.0,0.0); //Red Color
    //Train chimney slot
    glTranslatef(0.0,0.45,0.0); //Translation
    glutSolidSphere(0.055,100,11);
    glFlush();

    glPopMatrix();
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
    glutInitWindowSize(600, 600); //size of output screen
    glutInitWindowPosition(400 ,200); // position of output screen
    glutCreateWindow("Assignment 1 - Draw 2D train");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
