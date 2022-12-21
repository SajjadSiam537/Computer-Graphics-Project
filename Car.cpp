#include <windows.h>
#include <GL/glut.h>
#define PI 3.141516
#include<math.h>


int wheel_angle=0;
float car_position=0;
float car_speed=0.00;
float police_car_position=0;
float police_car_speed=0.00;


void update(int value)
{
    ///wheel angle rotatoin
    if(wheel_angle>=0)
    {
        wheel_angle=0;
    }
    wheel_angle+=10;

    if (car_position>=2)
    {
        car_position=-1;
    }
    car_position+=car_speed;

    if (police_car_position>=1.2)
    {
        police_car_position=-1;
    }
    police_car_position+=police_car_speed;

glutPostRedisplay();


glutTimerFunc(100, update, 0);
}

void initGL()
{

    glClearColor(0.0f, 0.6f, 0.9f, 0.0f);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'n':

//void initGL()

    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	glutPostRedisplay();
break;

case 'd':

//void initGL()

    glClearColor(0.0f, 0.6f, 0.9f, 0.0f);
	glutPostRedisplay();
break;


	}
}

void circle(float p1, float q1, float r1)
{
    int i;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);

    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();
}

void wheel()
{
    ///outer outer circle
        glColor3ub(150,150,150);
        circle(0,0,0.05);
        ///outer inner circle
        glColor3ub(0,0,0);
        circle(0,0,0.04);
        ///inner lines 1
        glColor3ub(250,250,250);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2f(-0.035,0);
        glVertex2f( 0.035,0);
        glEnd();
        ///inner lines 2
        glPushMatrix();
        glRotatef(45,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner lines 3
        glPushMatrix();
        glRotatef(90,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner lines 4
        glPushMatrix();
        glRotatef(135,0,0,1);
            glColor3ub(250,250,250);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2f(-0.035,0);
            glVertex2f( 0.035,0);
            glEnd();
        glPopMatrix();
        ///inner outer circle
        glColor3ub(150,150,150);
        circle(0,0,0.015);
        ///inner inner circle
        glColor3ub(0,0,0);
        circle(0,0,0.01);
}


void car()
{
    /// car
    glBegin(GL_QUADS);/// car down body
	glColor3f(1.0f, 0.0f, 1.0f);

    glVertex2f(-0.7f, -0.35f);
	glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.35f, -0.45f);
	glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
	glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.39f, -0.35f);
	glVertex2f(-0.39f, -0.37f);
    glVertex2f(-0.357f, -0.37f);
	glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// car start
	glColor3f(1.0f, 0.0f, 1.0f);

    glVertex2f(-0.71f, -0.43f);
	glVertex2f(-0.71f, -0.45f);
    glVertex2f(-0.69f, -0.45f);
	glVertex2f(-0.69f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);/// car end
	glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.36f, -0.43f);
	glVertex2f(-0.36f, -0.45f);
    glVertex2f(-0.34f, -0.45f);
	glVertex2f(-0.34f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);/// car middle line
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.343f);
	glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.36f, -0.35f);
	glVertex2f(-0.363f, -0.343f);
    glEnd();

    glBegin(GL_QUADS);/// car middle body
	glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.7f, -0.31f);
	glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.363f, -0.343f);
	glVertex2f(-0.39f, -0.31f);
    glEnd();

        	     glBegin(GL_QUADS);/// car middle body end
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.31f);
	glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.69f, -0.343f);
	glVertex2f(-0.69f, -0.31f);
    glEnd();



    	     glBegin(GL_QUADS);/// car up body
	glColor3f(1.0f, 0.0f, 1.0f);

    glVertex2f(-0.65f, -0.17f);
	glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.39f, -0.31f);
	glVertex2f(-0.43f, -0.17f);
    glEnd();

    	     glBegin(GL_QUADS);/// car up body blue right quads
	glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.49f, -0.19f);
	glVertex2f(-0.49f, -0.31f);
    glVertex2f(-0.41f, -0.31f);
	glVertex2f(-0.45f, -0.19f);
    glEnd();

        	     glBegin(GL_QUADS);/// car up body blue left quads
	glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.57f, -0.19f);
	glVertex2f(-0.57f, -0.31f);
    glVertex2f(-0.5f, -0.31f);
	glVertex2f(-0.5f, -0.19f);
    glEnd();



    ///Left wheel
    glPushMatrix();
    glTranslatef(-0.6,-0.45,0);
    glRotatef(-wheel_angle,0,0,1);
        wheel();
    glPopMatrix();
    ///Right wheel
    glPushMatrix();
    glTranslatef(-0.45,-0.45,0);
        glRotatef(-wheel_angle,0,0,1);
        wheel();
    glPopMatrix();

}

void policeCar()
{
    ///police car

    glBegin(GL_QUADS);/// white police car down body
	glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.37f, -0.77f);
	glVertex2f(0.35f, -0.89f);
    glVertex2f(0.7f, -0.89f);
	glVertex2f(0.69f, -0.77f);
    glEnd();

    glBegin(GL_QUADS);/// black police car down start line
	glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.34f, -0.87f);
	glVertex2f(0.34f, -0.89f);
    glVertex2f(0.37f, -0.89f);
	glVertex2f(0.37f, -0.87f);
    glEnd();

    glBegin(GL_QUADS);/// black police car down end line
	glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.68f, -0.87f);
	glVertex2f(0.68f, -0.89f);
    glVertex2f(0.72f, -0.89f);
	glVertex2f(0.72f, -0.87f);
    glEnd();



    glBegin(GL_QUADS);/// red police car middle line
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.366f, -0.79f);
	glVertex2f(0.363f, -0.81f);
    glVertex2f(0.39f, -0.81f);
	glVertex2f(0.39f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// blue police car middle line
	glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.4f, -0.79f);
	glVertex2f(0.4f, -0.81f);
    glVertex2f(0.66f, -0.81f);
	glVertex2f(0.66f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// red police car middle line
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.67f, -0.79f);
	glVertex2f(0.67f, -0.81f);
    glVertex2f(0.695f, -0.81f);
	glVertex2f(0.693f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// white police car up body
	glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.46f, -0.7f);
	glVertex2f(0.41f, -0.77f);
    glVertex2f(0.65f, -0.77f);
	glVertex2f(0.62f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);/// sky blue police car up body
	glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.465f, -0.715f);
	glVertex2f(0.42f, -0.77f);
    glVertex2f(0.52f, -0.77f);
	glVertex2f(0.52f, -0.715f);
    glEnd();

    glBegin(GL_QUADS);/// sky blue car up body
	glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.53f, -0.715f);
	glVertex2f(0.53f, -0.77f);
    glVertex2f(0.64f, -0.77f);
	glVertex2f(0.615f, -0.715f);
    glEnd();



    glBegin(GL_QUADS);/// red car upper light
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.475f, -0.68f);
	glVertex2f(0.475f, -0.7f);
    glVertex2f(0.49f, -0.7f);
	glVertex2f(0.49f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);/// blue car upper light
	glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.49f, -0.68f);
	glVertex2f(0.49f, -0.7f);
    glVertex2f(0.505f, -0.7f);
	glVertex2f(0.505f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);/// red car upper light
	glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.505f, -0.68f);
	glVertex2f(0.505f, -0.7f);
    glVertex2f(0.52f, -0.7f);
	glVertex2f(0.52f, -0.68f);
    glEnd();

    ///left wheel
    glPushMatrix();
    glTranslatef(0.45,-0.9,0);
    glRotatef(wheel_angle,0,0,1);
        wheel();
    glPopMatrix();

    ///right wheel
    glPushMatrix();
    glTranslatef(0.6,-0.9,0);
    glRotatef(wheel_angle,0,0,1);
        wheel();
    glPopMatrix();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
        glTranslatef(car_position,0,0);
        car();
	glPopMatrix();


	glPushMatrix();
        glTranslatef(-police_car_position,0,0);
        policeCar();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(0.6+car_position,-0.15,0);
        car();
	glPopMatrix();


	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("A Busy Street view");
	glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);

	initGL();
    glutKeyboardFunc(handleKeypress);

	glutMainLoop();
	return 0;
}

