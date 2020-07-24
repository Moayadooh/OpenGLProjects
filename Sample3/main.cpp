#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
// Display callback ------------------------------------------------------------
float r = 0.0f;
float g = 0.0f;
float b = 1.0f;

void display()
{
    // clear the draw buffer .
    glClear(GL_COLOR_BUFFER_BIT);   // Erase everything

    // set the color to use in draw

    // create a polygon ( define the vertexs)
    glBegin(GL_POLYGON); {
        glColor3f(r, g, b);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5,  0.5);
        glVertex2f( 0.5,  0.5);
        glVertex2f( 0.5, -0.5);
    } glEnd();

    // flush the drawing to screen .
    glFlush();
}

// Keyboard callback function ( called on keyboard event handling )
void keyboard(unsigned char key, int x, int y)
{
  if (key=='r' || key=='R')
  {
       r = 1.0f;
       g = 0.0f;
       b = 0.0f;
       glutPostRedisplay();
  }

  if (key=='g' || key=='G')
  {
       r = 0.0f;
       g = 1.0f;
       b = 0.0f;
       glutPostRedisplay();
  }

  if (key=='b' || key=='B')
  {
       r = 0.0f;
       g = 0.0f;
       b = 1.0f;
       glutPostRedisplay();
  }

  if (key=='y' || key=='Y')
  {
       r = 1.0f;
       g = 1.0f;
       b = 0.0f;
       glutPostRedisplay();
  }

  if (key=='p' || key=='P')
  {
       r = 1.0f;
       g = 0.0f;
       b = 1.0f;
       glutPostRedisplay();
  }

  if (key=='o' || key=='O')
  {
       r = 1.0f;
       g = 0.5f;
       b = 0.0f;
       glutPostRedisplay();
  }

  if (key=='c')
  {
      x = 400;
      y = 300;
      glutPositionWindow(x,y);
  }


   if (key=='f' || key=='F')
	   glutFullScreen();

    if (key=='q' || key=='Q')
        exit(EXIT_SUCCESS);

}

// Main execution  function
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);      // Initialize GLUT
    glutCreateWindow("OpenGL example");  // Create a window
    glutDisplayFunc(display);   // Register display callback
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutMainLoop();             // Enter main event loop
    return (EXIT_SUCCESS);
}
