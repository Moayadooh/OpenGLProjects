#include <cstdlib>
#include <GL/gl.h>
#include <GL/glut.h>

// Display callback ------------------------------------------------------------

void display()
{
    // clear the draw buffer .
    glClear(GL_COLOR_BUFFER_BIT);   // Erase everything

    // set the color to use in draw
    glColor3f(0.5, 0.5, 0.0);
    // create a polygon ( define the vertexs)
    glBegin(GL_POLYGON); {
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
   if (key=='f' || key=='F')
	   glutFullScreen();

    if (key == 'q' || key == 'Q')
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
