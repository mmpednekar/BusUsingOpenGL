/*
COMMAND:
COMPILE:g++ wheel.cpp -lGL -lGLU -lglut -lm
*/
#include <GL/freeglut.h>
#include <cmath>
void draw2Wheels(GLfloat, GLfloat);

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen
bool light = true;
GLfloat angleBus=0.0f; //angle of rotation of Bus

GLint draw_type = GL_LINE_LOOP;

float rad = 5.0;
#define PI              3.1415926536
#define CIRC_INC        (2 * PI / 30)

int main(int argc,char** argv)
{
	//function prototypes
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
    void spin(void);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(800,600); //to declare initial window size
	glutInitWindowPosition(100,100); //to declare initial window position
	glutCreateWindow("ST Bus"); //open the window with "3D Rotation : Pyramid And Cube" in the title bar

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);


	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

void display(void)
{
	//to clear all pixels
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat i, j;

	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-6.0f);
	glScalef(0.75f,0.75f,0.75f);
	glRotatef(angleBus,0.0f,1.0f,0.0f);

        //FRONT AND REAR WHEELS
		draw2Wheels(-1.6, -1.0);
		draw2Wheels( 1.8, -1.0);

	    //TOP HOOD
		glBegin(draw_type);
		glColor3f(0.8f,0.0f,0.0f);
		glVertex3f(3.0f,1.0f,-0.9f);
		glVertex3f(-2.0f,1.0f,-0.9f);
		glVertex3f(-2.0f,1.0f,0.9f);
		glVertex3f(3.0f,1.0f,0.9f);
		glEnd();

		//FRONT UPPER FACE
		glBegin(draw_type);
		glColor3f(0.8f,0.0f,0.0f);
		glVertex3f(3.0f,1.0f,0.9f);
		glVertex3f(3.0f,0.9f,1.0f);
		glVertex3f(3.0f,-0.3f,1.0f);
		glVertex3f(-2.2f,-0.3f,1.0f);
		glVertex3f(-2.2f,0.0f,1.0f);
		glVertex3f(-2.0f,0.9f,1.0f);
		glVertex3f(-2.0f,1.0f,0.9f); 
		glEnd();

		//FRONT LOWER FACE
		glBegin(draw_type);
		glColor3f(0.6f,0.0f,0.0f);
		glVertex3f(3.0f,-0.35f,1.0f);
		glVertex3f(3.0f,-1.0f,1.0f);
		glVertex3f(-2.2f,-1.0f,1.0f);
		glVertex3f(-2.2f,-0.35f,1.0f);
		glEnd();


		//FRONT WINDOWS
		for (i = 0.0f; i < 4; i+=0.55f)
		{
			glBegin(draw_type);
			glColor3f(0.1f,0.1f,0.1f);
			glVertex3f(-1.9f+i+0.1,0.8f,1.0f);
			glVertex3f(-1.9f+i+0.1,0.7f,1.0f);
			glVertex3f(-1.35f+i,0.7f,1.0f);
			glVertex3f(-1.35f+i,0.8f,1.0f);
			glEnd();

			glBegin(draw_type);
			glColor3f(0.1f,0.1f,0.1f);
			glVertex3f(-1.9f+i+0.1,0.6f,1.0f);
			glVertex3f(-1.9f+i+0.1,0.1f,1.0f);
			glVertex3f(-1.35f+i,0.1f,1.0f);
			glVertex3f(-1.35f+i,0.6f,1.0f);
			glEnd();
		}

		//BACK UPPER FACE
		glBegin(draw_type);
		glColor3f(0.8f,0.0f,0.0f);
		glVertex3f(3.0f,1.0f,-0.9f);
		glVertex3f(3.0f,0.9f,-1.0f);
		glVertex3f(3.0f,-0.3f,-1.0f);
		glVertex3f(-2.2f,-0.3f,-1.0f);
		glVertex3f(-2.2f,0.0f,-1.0f);
		glVertex3f(-2.0f,0.9f,-1.0f);
		glVertex3f(-2.0f,1.0f,-0.9f);
		glEnd();

		//BACK LOWER FACE
		glBegin(draw_type);
		glColor3f(0.6f,0.0f,0.0f);
		glVertex3f(3.0f,-0.35f,-1.0f);
		glVertex3f(3.0f,-1.0f,-1.0f);
		glVertex3f(-2.2f,-1.0f,-1.0f);
		glVertex3f(-2.2f,-0.35f,-1.0f);
		glEnd();


		//BACK WINDOWS
		for (i = 0.0f; i < 4; i+=0.55f)
		{
			glBegin(draw_type);
			glColor3f(0.1f,0.1f,0.1f);
			glVertex3f(-1.9f+i+0.1,0.8f,-1.0f);
			glVertex3f(-1.9f+i+0.1,0.7f,-1.0f);
			glVertex3f(-1.35f+i,0.7f,-1.0f);
			glVertex3f(-1.35f+i,0.8f,-1.0f);
			glEnd();

			glBegin(draw_type);
			glColor3f(0.1f,0.1f,0.1f);
			glVertex3f(-1.9f+i+0.1,0.6f,-1.0f);
			glVertex3f(-1.9f+i+0.1,0.1f,-1.0f);
			glVertex3f(-1.35f+i,0.1f,-1.0f);
			glVertex3f(-1.35f+i,0.6f,-1.0f);
			glEnd();

		}

		//LEFT GLASS PORTION
		glBegin(draw_type);
		glColor3f(0.0f,0.0f,0.0f);

		glVertex3f(-2.0f,1.0f,0.9f);
		glVertex3f(-2.0f,0.9f,1.0f);
		glVertex3f(-2.2f,-0.0f,1.0f);
		glVertex3f(-2.2f,-0.0f,-1.0f);
		glVertex3f(-2.0f,0.9f,-1.0f);
		glVertex3f(-2.0f,1.0f,-0.9f);
		glEnd();

		//LEFT GLASS
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		glVertex3f(-2.05f,0.8f,0.95f);
		glVertex3f(-2.2f,0.1f,0.95f);
		glVertex3f(-2.2f,0.1f,-0.95f);
		glVertex3f(-2.05f,0.8f,-0.95f);
		glEnd();

		//LEFT ENGINE PORTION
		glBegin(draw_type);
		glColor3f(0.6f,0.0f,0.0f);
		glVertex3f(-2.2f,0.0f,1.0f);
		glVertex3f(-2.2f,0.0f,-1.0f);
		glVertex3f(-2.2f,-0.8f,-1.0f);
		glVertex3f(-2.2f,-0.8f,1.0f);
		glEnd();

		//ENGINE BLOCK
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		glVertex3f(-2.25f,-0.2f,0.9f);
		glVertex3f(-2.25f,-0.2f,-0.9f);
		glVertex3f(-2.25f,-0.7f,-0.9f);
		glVertex3f(-2.25f,-0.7f,0.9f);
		glEnd();

		//ENGINE STRIP
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(-2.3f,-0.2f,0.9f);
		glVertex3f(-2.3f,-0.2f,-0.9f);
		glVertex3f(-2.3f,-0.1f,-0.9f);
		glVertex3f(-2.3f,-0.1f,0.9f);
		glEnd();

		//HEAD LAMPS
		glBegin(draw_type);
		if(light)
			glColor3f(1.0f,1.0f,0.0f);
		else
			glColor3f(0.1f,0.1f,0.1f);
		
		glVertex3f(-2.3f,-0.5f,0.9f);
		glVertex3f(-2.3f,-0.5f,0.5f);
		glVertex3f(-2.3f,-0.7f,0.5f);
		glVertex3f(-2.3f,-0.7f,0.9f);
		glEnd();

		glBegin(draw_type);
		if(light)
			glColor3f(1.0f,1.0f,0.0f);
		else
			glColor3f(0.1f,0.1f,0.1f);

		glVertex3f(-2.3f,-0.5f,-0.5f);
		glVertex3f(-2.3f,-0.5f,-0.9f);
		glVertex3f(-2.3f,-0.7f,-0.9f);
		glVertex3f(-2.3f,-0.7f,-0.5f);
		glEnd();


		//RIGHT FACE
		glBegin(draw_type);
		glColor3f(0.6f,0.0f,0.0f);
		glVertex3f(3.0f,1.0f,-0.9f);
		glVertex3f(3.0f,0.9f,-1.0f);
		glVertex3f(3.0f,-1.0f,-1.0f);
		glVertex3f(3.0f,-1.0f,1.0f);
		glVertex3f(3.0f,0.9f,1.0f);
		glVertex3f(3.0f,1.0f,0.9f);

		glEnd();

		//RIGHT WINDOWS
		glBegin(draw_type);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(3.1f,0.8f,-0.8f);
		glVertex3f(3.1f,0.1f,-0.8f);
		glVertex3f(3.1f,0.1f,-0.1f);
		glVertex3f(3.1f,0.8f,-0.1f);
		glEnd();

		glBegin(draw_type);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(3.1f,0.8f,0.1f);
		glVertex3f(3.1f,0.1f,0.1f);
		glVertex3f(3.1f,0.1f,0.8f);
		glVertex3f(3.1f,0.8f,0.8f);
		glEnd();

		//BACK LAMPS
		glBegin(draw_type);
		if(light)
			glColor3f(1.0f,0.0f,0.0f);
		else
			glColor3f(0.1f,0.0f,0.0f);
		
		glVertex3f(3.1,-0.5f,0.9f);
		glVertex3f(3.1,-0.5f,0.5f);
		glVertex3f(3.1,-0.7f,0.5f);
		glVertex3f(3.1,-0.7f,0.9f);
		glEnd();

		glBegin(draw_type);
		if(light)
			glColor3f(1.0f,0.0f,0.0f);
		else
			glColor3f(0.1f,0.0f,0.0f);

		glVertex3f(3.1,-0.5f,-0.5f);
		glVertex3f(3.1,-0.5f,-0.9f);
		glVertex3f(3.1,-0.7f,-0.9f);
		glVertex3f(3.1,-0.7f,-0.5f);
		glEnd();

		//RIGHT BONET
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		glVertex3f(3.1f,-0.8f,-1.0f);
		glVertex3f(3.1f,-1.0f,-1.0f);
		glVertex3f(3.1f,-1.0f,1.0f);
		glVertex3f(3.1f,-0.8f,1.0f);
		glEnd();

		//LEFT BONET
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		glVertex3f(-2.3f,-0.8f,1.0f);
		glVertex3f(-2.3f,-0.8f,-1.0f);
		glVertex3f(-2.3f,-1.0f,-1.0f);
		glVertex3f(-2.3f,-1.0f,1.0f);
		glEnd();

	glutSwapBuffers();
}

void draw2Wheels(GLfloat wheel_x, GLfloat wheel_y)
{
	float theta, i;
    //WHEELS
	for (i = 0.0f;i < 0.2f; i+=0.025f)
	{
        //RIM
		rad = 0.3;
		glBegin(draw_type);
		glColor3f(1.1f,1.1f,1.1f);
		for(theta=0.0; theta < 2 * PI; theta += CIRC_INC)
		glVertex3f(wheel_x+rad*cos(theta), wheel_y+rad*sin(theta),1.2-i);
		glEnd();

        //TIRE
		rad = 0.4;
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		for(theta=0.0; theta < 2 * PI; theta += CIRC_INC)
		glVertex3f(wheel_x+rad*cos(theta), wheel_y+rad*sin(theta),1.15-i);
		glEnd();
	}

	for (i = 0.0f;i < 0.2f; i+=0.025f)
	{
		rad = 0.3;
		glBegin(draw_type);
		glColor3f(1.1f,1.1f,1.1f);
		for(theta=0.0; theta < 2 * PI; theta += CIRC_INC)
		glVertex3f(wheel_x+rad*cos(theta), wheel_y+rad*sin(theta),-1.2+i);
		glEnd();

		rad = 0.4;
		glBegin(draw_type);
		glColor3f(0.1f,0.1f,0.1f);
		for(theta=0.0; theta < 2 * PI; theta += CIRC_INC)
		glVertex3f(wheel_x+rad*cos(theta), wheel_y+rad*sin(theta),-1.15+i);
		glEnd();
	}
}

void initialize(void)
{
	glShadeModel(GL_SMOOTH);
	// set background clearing color to black
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	// set-up depth buffer
	glClearDepth(1.0f);
	// enable depth testing
	glEnable(GL_DEPTH_TEST);
	// depth test to do
	glDepthFunc(GL_LEQUAL);
	// set really nice percpective calculations ?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 27: // Escape
		glutLeaveMainLoop();
		break;
	case 'C':
	case 'c':
				if(draw_type == GL_POLYGON)
				{
					draw_type = GL_LINE_LOOP;
				}
				else
				{
					draw_type = GL_POLYGON;
				}
				break;
	case 'L':
	case 'l':
			angleBus=angleBus+1.0f;
			if(angleBus>=360.0f)
				angleBus=angleBus-360.0f;
			break;
	case 'O':
	case 'o':
		if(light==false)
		{
			light=true;
		}
		else
		{
			light=false;
		}
		break;
	case 'F':
	case 'f':
		if(bFullscreen==false)
		{
			glutFullScreen();
			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void resize(int width,int height)
{
	if(height==0)
		height=1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void uninitialize(void)
{
}
