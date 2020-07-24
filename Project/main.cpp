/*************Instruction************

    press d/D to enable day mode
    press n/N to enable night mode
    press m/M to enable the animation "moving train, house rotation, street translation and mountains translation"
    press p/P to pause the animation
    press s/S to scale the sun "sunrise and sunset"
    press t/T to translate the mountains
    press f/F to display full screen
    press q/Q to quit
*/

#include <windows.h>
#include <GL/glut.h>

GLfloat trainX = -1.3f;//Train translate position of X
GLfloat streetX = -0.01f;//Street translate position of X

GLfloat sunOrMoonScale = 1.2f;//Sun scaling of X,Y and Z
GLfloat sunY = 0.3f;//Sun position of Y
bool decreaseScale = true;//Control sun scaling

GLfloat mountainsX = 0.0f;//Mountain translate position of X
bool goRight = true;//Control the mountains movement

GLfloat rotate_ = -30.0f;//Rotation angle of houses
bool increaseAngle = true;//Control houses rotation

bool isNight = false;//Control the night and day
bool isMoving = false;//Control the animation

//Colors
GLfloat r=0.4f, g=0.7f, b=1.0f;//Sky                       "Blue"
GLfloat r1=0.0f, g1=0.6f, b1=0.0f;//Ground                 "Green"
GLfloat r2=0.35f, g2=0.1f, b2=0.0f;//Mountains             "Brown"
GLfloat r3=1.0f, g3=1.0f, b3=0.0f;//Front and rear walls   "Yellow"
GLfloat r4=0.5f, g4=0.1f, b4=0.0f;//Door and windows       "Brown"
GLfloat r5=0.7f, g5=0.1f, b5=0.0f;//Roof                   "Light brown"
GLfloat r6=1.0f, g6=0.7f, b6=0.0f;//Left and right walls   "Light yellow"
GLfloat r7=1.0f, g7=1.0f, b7=0.0f;//Sun                    "Yellow"

//Sphere properties "Cloud"
GLdouble radius=0.035d;
GLint slices=100, stacks=11;

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void Mountain(float translateX){

    glTranslatef(translateX,0.0f,0.0f);
    glColor3f(r2, g2, b2);

    glBegin(GL_TRIANGLES);
    //Front side
    glVertex3f( 4.0f, 8.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(9.0f, 0.0f, 0.0f);

    //Rear side
    glVertex3f( 4.0f, 8.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glVertex3f(9.0f, 0.0f, 10.0f);

    glColor3f(0.5,0.15,0.0);//Light brown color
    //Right side
    glVertex3f( 4.0f, 8.0f, 0.0f);
    glVertex3f(9.0f, 0.0f, 0.0f);
    glVertex3f(9.0f, 0.0f, 10.0f);

    //Left side
    glVertex3f( 4.0f, 8.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
}

void Background(){
    glLoadIdentity();//Reset the model-view matrix
    glTranslatef(-10.0f, 0.0f, -31.0f);
    glColor3f(r, g, b);

    //Sky
	glBegin(GL_POLYGON);
	glVertex2f(-15.0f, 0.0f);
	glVertex2f(-15.0f, 16.0f);
	glVertex2f( 36.0f, 16.0f);
	glVertex2f( 36.0f, 0.0f);
	glEnd();

	//Ground
	glColor3f(r1, g1, b1);
	glBegin(GL_POLYGON);
	glVertex2f(-15.0f, 0.0f);
	glVertex2f(-15.0f,-16.0f);
	glVertex2f( 36.0f,-16.0f);
	glVertex2f( 36.0f, 0.0f);
	glEnd();

	glTranslatef(mountainsX,0.0f,0.0f);
	for(float i=0.0f;i<6.0f;i+=1.0f)
    {
        Mountain(-4.0f);
    }
    Mountain(0.0f);
    for(float i=0.0f;i<14.0f;i+=1.0f)
    {
        Mountain(4.0f);
    }
}

void Sun(){
    glLoadIdentity();
    glTranslatef(0.3f,sunY,-0.9f);
    glScalef(sunOrMoonScale,sunOrMoonScale,sunOrMoonScale);
    glColor3f(r7, g7, b7);
    glutSolidSphere(0.035d,100,11);
    glFlush();
}

void Cloud(float x,float y){
    glLoadIdentity();
	glColor3f(0.9f,0.9f,0.9f);//Snowy color

	glTranslatef(x,y,-1.0f);
    glutSolidSphere(radius, slices, stacks);
    glFlush();

    glTranslatef(-0.04f,0.0f,0.0f);
    glutSolidSphere(radius, slices, stacks);
    glFlush();

    glTranslatef(-0.04f,0.0f,0.0f);
    glutSolidSphere(radius, slices, stacks);
    glFlush();

    glTranslatef(-0.04f,0.0f,0.0f);
    glutSolidSphere(radius, slices, stacks);
    glFlush();
}

void House(float translateX, float translateZ)
{
    glLoadIdentity();
    glTranslatef(translateX, 0.0f, translateZ);
    glScalef(9.0f,9.0f,9.0f);
    glRotatef(rotate_,0.0f,1.0f,0.0f);
    glColor3f(r3, g3, b3);

    glBegin(GL_QUADS);
    //Front wall
    glVertex3f( 0.02f, -0.02f, -1.0f);
    glVertex3f(-0.02f, -0.02f, -1.0f);
    glVertex3f(-0.02f,  0.02f, -1.0f);
    glVertex3f( 0.02f,  0.02f, -1.0f);

    //Rear wall
    glVertex3f( 0.02f, -0.02f, -1.1f);
    glVertex3f(-0.02f, -0.02f, -1.1f);
    glVertex3f(-0.02f,  0.02f, -1.1f);
    glVertex3f( 0.02f,  0.02f, -1.1f);

    glColor3f(r6, g6, b6);
    //Left wall
    glVertex3f(-0.02f,  0.02f, -1.0f);
    glVertex3f(-0.02f,  0.02f, -1.1f);
    glVertex3f(-0.02f, -0.02f, -1.1f);
    glVertex3f(-0.02f, -0.02f, -1.0f);

    //Right wall
    glVertex3f(0.02f,  0.02f, -1.1f);
    glVertex3f(0.02f,  0.02f, -1.0f);
    glVertex3f(0.02f, -0.02f, -1.0f);
    glVertex3f(0.02f, -0.02f, -1.1f);

    glColor3f(r4, g4, b4);
    //Door
    glVertex3f( 0.005f,  -0.02f, -0.999f);
    glVertex3f(-0.005f,  -0.02f, -0.999f);
    glVertex3f(-0.005f, -0.005f, -0.999f);
    glVertex3f( 0.005f, -0.005f, -0.999f);

    //Window 1
    glVertex3f(-0.005f, 0.01f, -0.999f);
    glVertex3f(-0.015f, 0.01f, -0.999f);
    glVertex3f(-0.015f, 0.0f,  -0.999f);
    glVertex3f(-0.005f, 0.0f,  -0.999f);

    //Window 2
    glVertex3f(0.015f, 0.01f,-0.999f);
    glVertex3f(0.005f, 0.01f,-0.999f);
    glVertex3f(0.005f, 0.0f, -0.999f);
    glVertex3f(0.015f, 0.0f, -0.999f);

    //Roof
    //Right side
    glVertex3f(0.0f, 0.05f, -1.0f);
    glVertex3f(0.02f,0.02f, -1.0f);
    glVertex3f(0.02f,0.02f, -1.1f);
    glVertex3f(0.0f, 0.05f, -1.1f);
    //Left side
    glVertex3f( 0.0f, 0.05f, -1.0f);
    glVertex3f(-0.02f,0.02f, -1.0f);
    glVertex3f(-0.02f,0.02f, -1.1f);
    glVertex3f( 0.0f, 0.05f, -1.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(r5, g5, b5);
    //Front side
    glVertex3f( 0.0f, 0.05f, -1.0f);
    glVertex3f(-0.02f,0.02f, -1.0f);
    glVertex3f( 0.02f,0.02f, -1.0f);
    //Rear side
    glVertex3f( 0.0f, 0.05f, -1.1f);
    glVertex3f(-0.02f,0.02f, -1.1f);
    glVertex3f( 0.02f,0.02f, -1.1f);
    glEnd();
}

void Train()
{
    glLoadIdentity();
    glTranslatef(trainX, 0.0f, -1.0f);
    glScalef(0.5f,0.5f,0.5f);
    glColor3f(1.0f,0.0f,0.0f);//Red Color

    //Train compartment 1
    glBegin(GL_QUADS);
    //Right side
    glVertex3f(0.05,-0.2,0.0);
    glVertex3f(-0.9,-0.2,0.0);
    glVertex3f(-0.9,-0.5,0.0);
    glVertex3f(0.05,-0.5,0.0);

    //Left side
    glVertex3f(0.05,-0.2,-0.3);
    glVertex3f(-0.9,-0.2,-0.3);
    glVertex3f(-0.9,-0.5,-0.3);
    glVertex3f(0.05,-0.5,-0.3);

    glColor3f(0.8,0.0,0.0);//Dark red color
    //Rear side
    glVertex3f(-0.9,-0.2,0.0);
    glVertex3f(-0.9,-0.5,0.0);
    glVertex3f(-0.9,-0.5,-0.3);
    glVertex3f(-0.9,-0.2,-0.3);

    //Top side
    glVertex3f(0.05,-0.2,-0.3);
    glVertex3f(-0.9,-0.2,-0.3);
    glVertex3f(-0.9,-0.2,0.0);
    glVertex3f(0.05,-0.2,0.0);

    //Front side
    glVertex3f(0.05,-0.2,-0.3);
    glVertex3f(0.05,-0.5,-0.3);
    glVertex3f(0.05,-0.5,0.0);
    glVertex3f(0.05,-0.2,0.0);

    //Down side
    glVertex3f(-0.9,-0.5,-0.3);
    glVertex3f(0.05,-0.5,-0.3);
    glVertex3f(0.05,-0.5,0.0);
    glVertex3f(-0.9,-0.5,0.0);

    glColor3f(0.8,0.9,0.8);//Light snowy color
    //Stick
    //Right side
    glVertex3f(0.05,-0.32,-0.1);
    glVertex3f(0.15,-0.32,-0.1);
    glVertex3f(0.15,-0.38,-0.1);
    glVertex3f(0.05,-0.38,-0.1);

    //Left side
    glVertex3f(0.05,-0.32,-0.2);
    glVertex3f(0.15,-0.32,-0.2);
    glVertex3f(0.15,-0.38,-0.2);
    glVertex3f(0.05,-0.38,-0.2);

    glColor3f(0.7,0.7,0.7);//Snowy color
    //Top side
    glVertex3f(0.05,-0.32,-0.1);
    glVertex3f(0.15,-0.32,-0.1);
    glVertex3f(0.15,-0.32,-0.2);
    glVertex3f(0.05,-0.32,-0.2);

    //Down side
    glVertex3f(0.15,-0.38,-0.1);
    glVertex3f(0.05,-0.38,-0.1);
    glVertex3f(0.05,-0.38,-0.2);
    glVertex3f(0.15,-0.38,-0.2);

    glColor3f(1.0,0.0,0.0);//Red Color
    //Train compartment 2
    //Right side
    glVertex3f(0.15,-0.2,0.0);
    glVertex3f(0.15,-0.5,0.0);
    glVertex3f(0.8,-0.5,0.0);
    glVertex3f(0.8,-0.2,0.0);

    //Left side
    glVertex3f(0.15,-0.2,-0.3);
    glVertex3f(0.15,-0.5,-0.3);
    glVertex3f(0.8,-0.5,-0.3);
    glVertex3f(0.8,-0.2,-0.3);

    glColor3f(0.8,0.0,0.0);//Dark red color
    //Rear side
    glVertex3f(0.15,-0.2,-0.3);
    glVertex3f(0.15,-0.5,-0.3);
    glVertex3f(0.15,-0.5,0.0);
    glVertex3f(0.15,-0.2,0.0);

    //Front side
    glVertex3f(0.8,-0.5,-0.3);
    glVertex3f(0.8,-0.2,-0.3);
    glVertex3f(0.8,-0.2,0.0);
    glVertex3f(0.8,-0.5,0.0);

    //Down side
    glVertex3f(0.15,-0.5,-0.3);
    glVertex3f(0.8,-0.5,-0.3);
    glVertex3f(0.8,-0.5,0.0);
    glVertex3f(0.15,-0.5,0.0);

    //Top side
    glVertex3f(0.15,-0.2,-0.3);
    glVertex3f(0.8,-0.2,-0.3);
    glVertex3f(0.8,-0.2,0.0);
    glVertex3f(0.15,-0.2,0.0);

    glColor3f(0.8,0.9,0.8);//Snowy color
    //Window 1
    glVertex3f(-0.85,-0.275,0.0);
    glVertex3f(-0.85,-0.375,0.0);
    glVertex3f(-0.75,-0.375,0.0);
    glVertex3f(-0.75,-0.275,0.0);

    //Window 2
    glVertex3f(-0.7,-0.275,0.0);
    glVertex3f(-0.7,-0.375,0.0);
    glVertex3f(-0.6,-0.375,0.0);
    glVertex3f(-0.6,-0.275,0.0);

    //Window 3
    glVertex3f(-0.55,-0.275,0.0);
    glVertex3f(-0.55,-0.375,0.0);
    glVertex3f(-0.45,-0.375,0.0);
    glVertex3f(-0.45,-0.275,0.0);

    //Window 4
    glVertex3f(-0.4,-0.275,0.0);
    glVertex3f(-0.4,-0.375,0.0);
    glVertex3f(-0.3,-0.375,0.0);
    glVertex3f(-0.3,-0.275,0.0);

    //Window 5
    glVertex3f(-0.25,-0.275,0.0);
    glVertex3f(-0.25,-0.375,0.0);
    glVertex3f(-0.15,-0.375,0.0);
    glVertex3f(-0.15,-0.275,0.0);

    //Window 6
    glVertex3f(-0.1,-0.275,0.0);
    glVertex3f(-0.1,-0.375,0.0);
    glVertex3f(0.0,-0.375,0.0);
    glVertex3f(0.0,-0.275,0.0);

    //Window 7
    glVertex3f(0.2,-0.275,0.0);
    glVertex3f(0.2,-0.375,0.0);
    glVertex3f(0.3,-0.375,0.0);
    glVertex3f(0.3,-0.275,0.0);

    //Window 8
    glVertex3f(0.35,-0.275,0.0);
    glVertex3f(0.35,-0.375,0.0);
    glVertex3f(0.45,-0.375,0.0);
    glVertex3f(0.45,-0.275,0.0);

    //Window 9
    glVertex3f(0.5,-0.275,0.0);
    glVertex3f(0.5,-0.375,0.0);
    glVertex3f(0.6,-0.375,0.0);
    glVertex3f(0.6,-0.275,0.0);

    //Window 10
    glVertex3f(0.65,-0.275,0.0);
    glVertex3f(0.65,-0.375,0.0);
    glVertex3f(0.75,-0.375,0.0);
    glVertex3f(0.75,-0.275,0.0);

    //Train chimney pillar
    //Right side
    glVertex3f(0.6,-0.05,-0.1);
    glVertex3f(0.6,-0.2,-0.1);
    glVertex3f(0.7,-0.2,-0.1);
    glVertex3f(0.7,-0.05,-0.1);

    //Left side
    glVertex3f(0.6,-0.05,-0.2);
    glVertex3f(0.6,-0.2,-0.2);
    glVertex3f(0.7,-0.2,-0.2);
    glVertex3f(0.7,-0.05,-0.2);

    //Front side
    glVertex3f(0.7,-0.2,-0.1);
    glVertex3f(0.7,-0.05,-0.1);
    glVertex3f(0.7,-0.05,-0.2);
    glVertex3f(0.7,-0.2,-0.2);

    //Rear side
    glVertex3f(0.6,-0.05,-0.1);
    glVertex3f(0.6,-0.2,-0.1);
    glVertex3f(0.6,-0.2,-0.2);
    glVertex3f(0.6,-0.05,-0.2);
    glEnd();

    //Wheel 1 right side
    glTranslatef(-0.65,-0.51,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 2 right side
    glTranslatef(0.45,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 3 right side
    glTranslatef(0.5,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 4 right side
    glTranslatef(0.35,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    glColor3f(0.7,0.7,0.7);//Dark snowy color
    //Train chimney slot
    glTranslatef(0.0,0.47,-0.15);
    glutSolidSphere(0.05,100,11);
    glFlush();

    glColor3f(0.8,0.9,0.8);//Snowy color
    //Wheel 1 left side
    glTranslatef(0.0,-0.48,-0.15);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 2 left side
    glTranslatef(-0.35,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 3 left side
    glTranslatef(-0.5,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();

    //Wheel 4 left side
    glTranslatef(-0.45,0.0,0.0);
    glutSolidSphere(0.08,100,11);
    glFlush();
}

void Street(float x){
    glLoadIdentity();
    glColor3f(0.3,0.1,0.0);//Brown Color

    //Right line
    glBegin(GL_QUADS);
    glVertex3f( 5.0f, -0.3f, -1.0f);
    glVertex3f(-5.0f, -0.3f, -1.0f);
    glVertex3f(-5.0f,  -0.29f, -1.0f);
    glVertex3f( 5.0f,  -0.29f, -1.0f);

    //Left line
    glVertex3f( 5.0f, -0.3f, -1.13f);
    glVertex3f(-5.0f, -0.3f, -1.13f);
    glVertex3f(-5.0f,  -0.29f, -1.13f);
    glVertex3f( 5.0f,  -0.29f, -1.13f);
    glEnd();

    //Middle lines
    glLoadIdentity();
    glColor3f(0.3,0.1,0.0);//Brown Color
    glTranslatef(streetX, 0.0f, 0.0f);
    glTranslatef(x, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.49f, -0.315f, -1.0f);
    glVertex3f(-0.5f,  -0.315f, -1.0f);
    glVertex3f(-0.5f,  -0.495f, -2.0f);
    glVertex3f(-0.49f, -0.495f, -2.0f);
    glEnd();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix

    Background(); //Sky, ground and mountains

    for(float i=7.0f;i>-7.0f;i-=1.0f)
    {
        House(i,-0.7f);
    }

    for(float i=3.5f;i>-3.5f;i-=0.5f)
    {
        if(i==0.0f)
            House(i,5.3f);
        else
            House(i,2.3f);
    }

    for(float i=3.5f;i>-3.5f;i-=1.0f)
    {
        House(i,4.3f);;
    }

    for(float i=-0.95f;i<8.0f;i+=0.05f)
    {
        Street(i);
    }

    Train();

    Sun();

    Cloud(0.0,0.35);
    Cloud(-0.35,0.33);

   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void animation(void)
{
    if(isMoving)
    {
        trainX += 0.0015;//Train movement
        if(trainX>1.3)
        {
            trainX = -1.3f;//Reset train position of X
            mountainsX = 0.0f;//Reset mountains position of X
            rotate_ = -30.0f;//Reset houses angle position
            streetX = 0.0f;//Reset street position position X
            isMoving = false;
        }

        if(increaseAngle)
        {
            rotate_ += 0.0565f;//Houses rotation
            if(rotate_>70.0f)
                increaseAngle = false;
        }
        else
        {
            rotate_ = -0.30f;//Houses rotation
            increaseAngle = true;
        }

        mountainsX -= 0.002f;//Mountains movement
        streetX -= 0.001f;//Street movement
    }
    Display();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GL size for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the view port to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the view port
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key=='m' || key=='M')
        isMoving = true;

    if (key=='p' || key=='P')
        isMoving = false;

    if (key=='s' || key=='S')
    {
        if(!isNight)
        {
            if(decreaseScale)
            {
                sunOrMoonScale -= 0.3f;//Decrease sun scaling
                sunY -= 0.02f;//Sun translation to down
                if(sunOrMoonScale==0.3f)
                    decreaseScale = false;
            }
            else
            {
                sunOrMoonScale += 0.3f;//Increase sun scaling
                sunY = 0.3f;//Reset sun position of Y
                if(sunOrMoonScale==1.2f)
                    decreaseScale = true;
            }
        }
    }

    if (key=='t' || key=='T')
    {
        if(goRight)
        {
            mountainsX += 5.0f;//Mountains translation
            if(mountainsX>60.0f)
                goRight = false;
        }
        else
        {
            mountainsX -= 5.0f;//Mountains translation
            if(mountainsX<-55.0f)
                goRight = true;
        }
    }

    if (key=='n' || key=='N')
    {
        isNight = true;
        sunY = 0.3f;//Reset moon position of Y to 0.3

        //Sky "Black"
        r=0.0f;
        g=0.0f;
        b=0.0f;

        //Ground "Dark green"
        r1=0.0f;
        g1=0.4f;
        b1=0.0f;

        //Mountains "Dark brown"
        r2=0.2f;
        g2=0.1f;
        b2=0.0f;

        //Front and rear walls
        r3=0.7f;
        g3=0.6f;
        b3=0.6f;

        //Door and windows "Light purple"
        r4=0.3f;
        g4=0.1f;
        b4=0.3f;

        //Roof "Purple"
        r5=0.3f;
        g5=0.0f;
        b5=0.3f;

        //Left and right walls "Snowy"
        r6=0.7f;
        g6=0.6f;
        b6=0.6f;

        r7=1.0f;
        g7=1.0f;
        b7=1.0f;

        //Sphere properties "Cloud"
        radius=0;
        slices=0;
        stacks=0;

        sunOrMoonScale = 0.9f; //Reset moon scaling of X, Y and Z to 0.9
    }

    if (key=='d' || key=='D')
    {
        isNight = false;
        decreaseScale = true;

        //Sky "Blue"
        r=0.4f;
        g=0.7f;
        b=1.0f;

        //Ground "Green"
        r1=0.0f;
        g1=0.6f;
        b1=0.0f;

        //Mountains "Brown"
        r2=0.35f;
        g2=0.1f;
        b2=0.0f;

        //Front and rear walls "Yellow"
        r3=1.0f;
        g3=1.0f;
        b3=0.0f;

        //Door and windows "Brown"
        r4=0.5f;
        g4=0.1f;
        b4=0.0f;

        //Roof "Light brown"
        r5=0.7f;
        g5=0.1f;
        b5=0.0f;

        //Left and right walls "Light yellow"
        r6=1.0f;
        g6=0.7f;
        b6=0.0f;

        //Sun "Yellow"
        r7=1.0f;
        g7=1.0f;
        b7=0.0f;

        //Sphere properties "Cloud"
        radius=0.035f;
        slices=100;
        stacks=11;

        sunOrMoonScale = 1.2f;//Reset sun scaling of X, Y and Z to 1.2
        sunY = 0.3f;//Reset sun position of Y to 0.3
    }

   if (key=='f' || key=='F')
	   glutFullScreen();

    if (key=='q' || key=='Q')
        exit(EXIT_SUCCESS);

}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1000,1000);
   glutInitWindowPosition(0,0);
   glutCreateWindow("3D Train and Houses");          // Create window with the given title
   glutDisplayFunc(Display);       // Register callback handler for window re-paint event
   glutIdleFunc(animation);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
