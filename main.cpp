#include<stdio.h>
#include<GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#define PI 3.1416
void bus();
void road();
void signal();
void car();
void bus2();
void Hill(float x, float y, float width, float height);
void circle(float x, float y, float radius);
void person(float x ,float y);
void house1(int x, int y);
void house2(int x, int y);
void house3(int x, int y);
void tree(float x, float y, float height);
void car2(float y);
void car3(int x,float c1,float c2);
void tree1(float x1, float y1);
void tree2(float x1, float y1);
void persons();
void houses();
void trees();
void hills();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void control();
void helpscreen();
GLint a=300,b=-300,c=50,d=50,flag=0,traffic_regulator=1,control_keyl,control_keyr;
GLfloat spin = 30.0;
GLfloat red=0,blue=1,green=.3;
GLfloat angle = 0.0f;
GLfloat scale = 0.0f;
GLfloat p=0,q=0,r=0;


void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0.15,0.1,0.01,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
drawstring(600.0,700.0,0.0," NMAMIT");
glColor3f(0.7,0,1);
drawstring(330,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f(1,0.5,0);
drawstring(530,600,0.0,"A MINI PROJECT ON");
glColor3f(1,0,0);
drawstring(360,500,0.0,"GRAPHICAL REPRESENTATION OF TRAFFIC SIGNALS");
glColor3f(1,0.5,0);
drawstring(200,400,0.0,"BY:");
glColor3f(1,1,1);
drawstring(100,300,0.0,"PRASHASTI PANDEY");
glColor3f(1,1,1);
drawstring(100,240,0.0,"NAIJA SHETTY");
glColor3f(1,0.5,0);
drawstring(980,400,0.0,"USN:");
glColor3f(1,1,1);
drawstring(930,300,0.0,"4NM20CS135");
glColor3f(1,1,1);
drawstring(930,240,0.0,"4NM20CS122");
glColor3f(1,0.1,1);
drawstring(543,100,0.0,"PRESS ENTER TO START");
glFlush();
}
void helpscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(550.0,700.0,0.0,"FOLLOW ");
glColor3f(1,0,0);
drawstring(650.0,700.0,0.0,"THESE");
glColor3f(0,0,1);
drawstring(750.0,700.0,0.0,"INSTRUCTIONS");
glColor3f(0.5,0.1,0.2);
drawstring(350.0,640.0,0.0,"Stop the traffic (Red Light)                                  MOUSE LEFT CLICK");
glColor3f(0.5,0.1,0.3);
drawstring(350.0,540.0,0.0,"Yellow Signal                                                        MOUSE RIGHT BUTTON (HOLD ON)");
glColor3f(0.5,0.1,0.4);
drawstring(350.0,440.0,0.0,"Green Signal                                                         MOUSE RIGHT BUTTON (RELEASE)");
glColor3f(0.4,0.1,0.5);
drawstring(350.0,340.0,0.0,"Allow vehicles to MOVE left to right                  PRESS 'L'");
glColor3f(0.5,0.1,0.6);
drawstring(350.0,240.0,0.0,"Allow vehicles to MOVE right to left                  PRESS 'R'");
glColor3f(0.5,0.1,0.7);
drawstring(350.0,140.0,0.0,"Speed up the vehicles                                           PRESS 'S'");
glColor3f(0.5,0.1,0.8);
drawstring(350.0,90.0,0.0,"Help                                                                      PRESS 'H'");
glColor3f(0.5,0.1,0.9);
drawstring(350.0,40.0,0.0,"Escape                                                                  PRESS 'ENTER'");
glFlush();
}

void control()
{
	if(control_keyl!='l'||control_keyr!='r')
	{
	if(control_keyl=='l')
      a=a+8;
	if(control_keyr=='r')
	 b=b-8;
	}

}

void myKeyboard( unsigned char key, int x, int y )

{
switch(key)
{
	case 13:
		if(flag==1)
		{
			flag=2;
			mydisplay();
		}
		if(flag==0)
		{
	flag=1;mydisplay();
		}

	break;
	case 'l':control_keyl=key;
		p=0;q=0;r=1;
	break;
	case 'r':control_keyr=key;
		p=0;q=0;r=1;
	break;
	case 's':mydisplay();
	break;
	case 'h':flag=1;mydisplay();
		break;
	default:break;
}

}

void myMouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=1;
	q=0;
	r=0;
	}

	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	traffic_regulator=0;
	p=0;
	q=1;
	r=0;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{
	traffic_regulator=1;
	p=0;
	q=0;
	r=1;
	}
	glutPostRedisplay();
}

void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
    frontscreen ();
if(flag==1)
	helpscreen();
if(flag==2)
    display();

glutSwapBuffers();
}

void update(int value)
{
a=a-8;
b=b+8;
c=c+2.5;
control();

if(blue!=0&&green!=0)
{blue-=.004;green-=.004;
}

glutPostRedisplay();
}

void display(void)
{if (traffic_regulator) {
    glutTimerFunc(50, update, 0);
}

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(red, green, blue, 0);
hills();
road();
trees();
houses();

persons();
bus();
car2(330.0f);
signal();
car();
car3(600,0.2,0.1);
car3(2400,0.3,0.8);
car3(2900,1,0.7);

glFlush();

}

void hills()
{

Hill(0,13,5,5);
Hill(5,13,5,5);
Hill(11,13,5,5);
Hill(16,13,5,5);
Hill(21,13,5,5);
Hill(26,13,5,5);
Hill(31,13,5,5);

}
void houses()
{
 house1(118,89);
 house3(128,90);
 house2(138,89);
 house3(148,90);
 house1(158,89);
 house2(168,90);
 house3(178,89);
 house2(188,90);
 house1(198,89);
 house3(208,90);
 house1(218,89);
 house2(228,90);
 house1(238,89);
 house3(248,90);
 house2(258,89);
 house3(268,90);
 house2(67,90);
 house1(57,90);
 house3(47,89);
 house1(37,89);
 house3(27,89);
 house2(17,89);
 house1(7,89);

 house2(107,26);
  house1(118,19);
 house3(128,7);
 house2(138,24);
 house3(148,8);
 house1(158,23);
 house2(168,13);
 house3(178,22);
 house2(188,9);
 house1(198,16);
 house3(208,23);
 house1(218,7);
 house2(228,15);
 house1(238,11);
 house3(248,26);
 house2(258,18);
 house3(268,24);

  house3(97,13);
 house1(87,7);

 house3(77,23);
 house2(67,18);
 house1(57,7);
 house2(47,13);
 house1(37,26);
 house3(27,17);
 house2(17,7);
 house3(7,15);
}
void persons()
{
     glPushMatrix();
    glTranslated(c,-20,0);
person(150,180);
person(90,130);
person(100,600);
person(20,490);
person(70,115);
glPopMatrix();
 glPushMatrix();
glTranslated(-c,-10,0);
person(800,180);
person(880,90);
person(898,150);
person(740,580);
glPopMatrix();
}

void tree1(float x1, float y1)
{


 glPushMatrix();
glScaled(4,3,1);
    float x2 = x1+4,y2=y1, x3=x1+2,y3=y1+5;
    glColor3ub(11, 70, 11);
    glBegin(GL_TRIANGLES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(x1+1.5, y1);
        glVertex2d(x1, y1-4);
        glVertex2d(x2, y1-4);
        glVertex2d(x2-1.5, y1);

        glVertex2d(x1+1.5, y1-4);
        glVertex2d(x1, y1-8);
        glVertex2d(x2, y1-8);
        glVertex2d(x2-1.5, y1-4);
        glColor3ub(68, 43, 2);
        glVertex2d(x1+1.5, y1-8);
        glVertex2d(x1+1, y1-14);
        glVertex2d(x2-1, y1-14);
        glVertex2d(x2-1.5, y1-8);
    glEnd();
      glPopMatrix();
}

void trees()
{

tree1(5,165);
tree1(15,165);
tree1(25,165);
tree1(35,165);
tree1(45,165);
tree1(55,165);
tree1(85,165);
tree1(65,165);
tree1(75,165);
tree1(145,165);
tree1(155,165);
tree1(165,165);
tree1(175,165);
tree1(185,165);
tree1(195,165);
tree1(205,165);
tree1(215,165);
tree1(225,165);
tree1(235,165);
tree1(245,165);
tree1(255,165);
tree1(265,165);
tree1(275,165);
tree1(285,165);
tree1(295,165);
tree1(305,165);
tree1(315,165);
tree1(325,165);

tree1(5,35);
tree1(15,50);
tree1(25,35);
tree1(35,50);
tree1(45,35);
tree1(55,50);
tree1(65,35);
tree1(75,50);
tree1(85,35);


tree1(95,50);
tree1(105,35);
tree1(115,50);
tree1(125,35);
tree1(135,50);
tree1(145,35);
tree1(155,50);
tree1(165,35);
tree1(175,50);
tree1(185,35);
tree1(195,50);
tree1(205,35);
tree1(215,50);
tree1(225,35);
tree1(235,50);
tree1(245,35);
tree1(255,50);
tree1(265,35);
tree1(275,50);
tree1(285,35);
tree1(295,50);
tree1(305,35);
tree1(315,50);
tree1(325,35);

}
void circle(float x, float y, float radius) {
    glColor3f(1.0f, 0.5f, 0.31f);
	int i;
	int triangleAmount = 500;
	float twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + 0.35*(radius * cos(i *  twicePi / triangleAmount)),
			    y +0.35*(radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glFlush();
}
void person(float x,float y){
    glColor3f(1,1,1);
   //head
    circle(x,y+5,25);
        glLineWidth(2);
   //body
   glBegin(GL_LINES);
   glVertex2f(x,y);
   glVertex2f(x,y-40);
   //legs
   glVertex2f(x,y-40);
   glVertex2f(x-10,y-60);
   glVertex2f(x,y-40);
   glVertex2f(x+10,y-60);
   //hands
   glVertex2f(x,y-20);
   glVertex2f(x-10,y-40);
   glVertex2f(x,y-20);
   glVertex2f(x+10,y-40);
   glEnd();
   glFlush();
}

void Hill(float x, float y, float width, float height) {

     glPushMatrix();
     glScaled(40.0,40.0,0.0);
    glColor3f(0.0f, 0.4f, 0.2f);

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width / 2.0f, y + height);
    glVertex2f(x + width, y);
    glEnd();
     glPopMatrix();
}
void road()
{
glPushMatrix();
glScaled(40.0,40.0,0.0);
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);

glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,10);
glVertex2f(0,10);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.1,0.2,0.1);
glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,4);
glVertex2f(0,4);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(10,10);
glVertex2f(15,10);
glVertex2f(0,40);
glVertex2f(4,40);

glEnd();
glPopMatrix();
}

void signal()
{
glPushMatrix();
glScaled(40.0,40.0,0.0);
//stand
glColor3f(0.1,0.2,0.1);
glBegin(GL_POLYGON);
glVertex2f(15,7);
glVertex2f(15,8);
glVertex2f(18,8);
glVertex2f(18,7);
glEnd();
//pole
glBegin(GL_POLYGON);
glVertex2f(16,7);
glVertex2f(17,8);
glVertex2f(17,15);
glVertex2f(16,15);
glEnd();
//board
glBegin(GL_POLYGON);
glVertex2f(15.5,15);
glVertex2f(17.5,15);
glVertex2f(17.5,10);
glVertex2f(15.5,10);
glEnd();
//red
glColor3f(p,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,14.5);
glVertex2f(17,14.5);
glVertex2f(17,14);
glVertex2f(16,14);
glEnd();
//yellow
glColor3f(q,q,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,13.5);
glVertex2f(17,13.5);
glVertex2f(17,13);
glVertex2f(16,13);
glEnd();
//green
glColor3f(0.0,r,0.0);
glBegin(GL_POLYGON);
glVertex2f(16,12.5);
glVertex2f(17,12.5);
glVertex2f(17,12);
glVertex2f(16,12);
glEnd();
glPopMatrix();
}

void house3(int x, int y)
{
     glPushMatrix();
    glScalef(5,5,1);
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
        glVertex2d(x, y);//2.60
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+4,y-2);//6,58
    glEnd();
    glColor3f(0.2,0.8,0.2);
    glBegin(GL_QUADS);
        //wall right
        glColor3f(0,0.4,0.1);
        glVertex2f(x+3.5, y-7);//55,53
        glVertex2f(x+7.3, y-4.5);//9.3,55.5
        glVertex2f(x+7.3, y-1);//9.3,59
        glVertex2f(x+3.5, y-1.5);//5.5,58.5
        //door
        glColor3f(0.4,0,0.40);
        glVertex2f(x+5.5,y-5.5);//7.5,54.5
        glVertex2f(x+6.25,y-5);//8.25,55
        glVertex2f(x+6.25,y-2.5);//8.25,57.5
        glVertex2f(x+5.5,y-2.5);//7.5,57.5
        //right roof
        glColor3f(1,0,0.3);
        glVertex2d(x+2,y+4);
        glVertex2d(x+6,y+5);
        glVertex2d(x+8,y-1);
        glVertex2d(x+4,y-2);
        //wall left
        glColor3f(0.5,0,.31);
        glVertex2f(x +0.3, y-5);
        glVertex2f(x + 3.5, y-7);
        glVertex2f(x + 3.5, y-1.5);
        glVertex2f(x+0.5, y);
        //window left
        glColor3f(0.1,1.0,0.6);
        glVertex2f(x+1.5,y-3.5);
        glVertex2f(x+2.2,y-4);
        glVertex2f(x+2.2,y-1.7);
        glVertex2f(x+1.5,y-1.3);
    glEnd();
    glPopMatrix();
}

void house1(int x, int y)
{
     glPushMatrix();
    glScalef(5,5,1);
    glColor3f(0.8,0.3,0.4);
    glBegin(GL_TRIANGLES);
        glVertex2d(x, y);//2.60
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+4,y-2);//6,58
    glEnd();


    glColor3f(0.1,0.1,0.2);
    glBegin(GL_QUADS);
        //wall right
        glColor3f(.3,0.1,.30);
        glVertex2f(x+3.5, y-7);//55,53
        glVertex2f(x+7.3, y-4.5);//9.3,55.5
        glVertex2f(x+7.3, y-1);//9.3,59
        glVertex2f(x+3.5, y-1.5);//5.5,58.5
        //door
        glColor3f(0.2,0.3,0.90);
        glVertex2f(x+5.5,y-5.5);//7.5,54.5
        glVertex2f(x+6.25,y-5);//8.25,55
        glVertex2f(x+6.25,y-2.5);//8.25,57.5
        glVertex2f(x+5.5,y-2.5);//7.5,57.5
        //right roof
        glColor3f(0.7,0.7,0.5);
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+6,y+5);//8,65
        glVertex2d(x+8,y-1);//10,59
        glVertex2d(x+4,y-2);//6,58
        //wall left
        glColor3f(.21,0.3,.31);
        glVertex2f(x +0.3, y-5);//2.3,55
        glVertex2f(x + 3.5, y-7);//5.5,53
        glVertex2f(x + 3.5, y-1.5);//5.5,58.5
        glVertex2f(x+0.5, y);//2.5,60

        //window left
        glColor3f(0.2,.0,.4);
        glVertex2f(x+1.5,y-3.5); //3.5,56.5
        glVertex2f(x+2.2,y-4);//4.2,56
        glVertex2f(x+2.2,y-1.7);//4.2,58.3
        glVertex2f(x+1.5,y-1.3);//3.5,58.7
    glEnd();
    glPopMatrix();
}
void house2(int x, int y)
{
     glPushMatrix();
    glScalef(5,5,1);
    glColor3f(0.9,0.5,0.7);
    glBegin(GL_TRIANGLES);
        glVertex2d(x, y);//2.60
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+4,y-2);//6,58
    glEnd();
    glColor3f(0.3,0.4,.11);
    glBegin(GL_QUADS);
        //wall right
        glColor3f(.24,0.4,.57);
        glVertex2f(x+3.5, y-7);//55,53
        glVertex2f(x+7.3, y-4.5);//9.3,55.5
        glVertex2f(x+7.3, y-1);//9.3,59
        glVertex2f(x+3.5, y-1.5);//5.5,58.5
        //door
        glColor3f(1,0.44,0.40);
        glVertex2f(x+5.5,y-5.5);//7.5,54.5
        glVertex2f(x+6.25,y-5);//8.25,55
        glVertex2f(x+6.25,y-2.5);//8.25,57.5
        glVertex2f(x+5.5,y-2.5);//7.5,57.5
        //right roof
        glColor3f(1,0.4,.31);
        glVertex2d(x+2,y+4);//4,64
        glVertex2d(x+6,y+5);//8,65
        glVertex2d(x+8,y-1);//10,59
        glVertex2d(x+4,y-2);//6,58
        //wall left
        glColor3f(.41,0.5,.31);
        glVertex2f(x +0.3, y-5);//2.3,55
        glVertex2f(x + 3.5, y-7);//5.5,53
        glVertex2f(x + 3.5, y-1.5);//5.5,58.5
        glVertex2f(x+0.5, y);//2.5,60

        //window left
        glColor3f(1,.0,.1);
        glVertex2f(x+1.5,y-3.5); //3.5,56.5
        glVertex2f(x+2.2,y-4);//4.2,56
        glVertex2f(x+2.2,y-1.7);//4.2,58.3
        glVertex2f(x+1.5,y-1.3);//3.5,58.7
    glEnd();
    glPopMatrix();
}
void bus()
{
glPushMatrix();
glTranslated(a,50.0,0.0);
glScaled(40.0,40.0,0.0);
glColor3f(0.5,0.0,0.0);
//bus out line
glBegin(GL_POLYGON);
glVertex2f(25,8);
glVertex2f(25,9.5);
glVertex2f(26,11);
glVertex2f(32,11);
glVertex2f(32,8);
glEnd();
//window frame
glColor3f(0,0.1,1);
glBegin(GL_POLYGON);
glVertex2f(26.1,9.5);
glVertex2f(26.1,10.5);
glVertex2f(31.8,10.5);
glVertex2f(31.8,9.5);
glEnd();
//Doors
glColor3f(0,0.8,1);
glBegin(GL_POLYGON);
glVertex2f(26.2,9);
glVertex2f(26.2,10.4);
glVertex2f(27.7,10.4);
glVertex2f(27.7,9);
glEnd();


glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(27,8.4);
glVertex2f(27,10.4);
glVertex2f(27.7,10.4);
glVertex2f(27.7,8.4);
glEnd();
//small windows
glColor3f(0,1,1);
glBegin(GL_POLYGON);
glVertex2f(27.8,9.6);
glVertex2f(27.8,10.4);
glVertex2f(29,10.4);
glVertex2f(29,9.6);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(29.1,9.6);
glVertex2f(29.1,10.4);
glVertex2f(30.2,10.4);
glVertex2f(30.2,9.6);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(30.3,9.6);
glVertex2f(30.3,10.4);
glVertex2f(31.7,10.4);
glVertex2f(31.7,9.6);
glEnd();


//driver window
glColor3f(0,0.8,1);
glBegin(GL_POLYGON);
glVertex2f(25,9.5);
glVertex2f(26,11);
glVertex2f(26,9.5);
glEnd();
glPopMatrix();
//tyre
glPushMatrix();//front tyre
glTranslated(a+970,320,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();
glPopMatrix();

glPushMatrix();//back tyre
glTranslated(a+1140,320,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();
glPopMatrix();
}

void car()
{
glPushMatrix(); //making color for outer line
glTranslated(b,190.0,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(1.0,1.0,1.0); //color for outer window
glBegin(GL_POLYGON);
glVertex2f(5.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glEnd();

glColor3f(0.0,0.0,0.0); //making outer line for car
glBegin(GL_LINE_LOOP);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP); //outer line for design a car
glVertex2f(8.0,3.0);
glVertex2f(16.0,3.0);
glVertex2f(16.5,3.5);
glVertex2f(17.0,4.0);
glVertex2f(16.5,4.25);
glVertex2f(16.0,4.5);
glVertex2f(15.0,4.5);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glVertex2f(5.0,5.0);
glVertex2f(7.0,5.0);
glVertex2f(6.5,4.5);
glEnd();


glBegin(GL_LINES); //connecting outer line
glVertex2d(7.0,5.0);
glVertex2d(15.0,5.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,4.0);
glVertex2d(17.0,4.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,3.5);
glVertex2d(16.5,3.5);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,5.0);
glVertex2d(14.0,3.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(12.0,5.0);
glVertex2d(12.0,6.2);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(7.0,5.0);
glVertex2d(7.0,6.7);
glEnd();

glBegin(GL_POLYGON); //drawing a back tyre
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();


glBegin(GL_POLYGON); //drawing front tyre
glVertex2f(17.0,2.5);
glVertex2f(17.0,2.6);
glVertex2f(17.15,3.1);
glVertex2f(17.2,3.2);
glVertex2f(17.3,3.35);
glVertex2f(17.4,3.4);
glVertex2f(17.5,3.45);
glVertex2f(17.6,3.55);
glVertex2f(17.7,3.6);
glVertex2f(17.8,3.63);
glVertex2f(18.0,3.65);
glVertex2f(18.2,3.7);
glVertex2f(18.4,3.7);
glVertex2f(18.6,3.65);
glVertex2f(18.8,3.55);
glVertex2f(19.0,3.45);
glVertex2f(19.1,3.4);
glVertex2f(19.2,3.25);
glVertex2f(19.3,3.2);
glVertex2f(19.4,3.0);

glVertex2f(19.5,2.5);
glVertex2f(19.45,2.15);
glVertex2f(19.4,1.9);
glVertex2f(19.35,1.8);
glVertex2f(19.2,1.6);
glVertex2f(19.0,1.5);
glVertex2f(18.9,1.4);
glVertex2f(18.7,1.3);
glVertex2f(18.6,1.27);
glVertex2f(18.4,1.25);
glVertex2f(18.0,1.25);
glVertex2f(17.9,1.3);
glVertex2f(17.75,1.35);
glVertex2f(17.6,1.4);
glVertex2f(17.45,1.55);
glVertex2f(17.3,1.7);
glVertex2f(17.2,1.8);
glVertex2f(17.1,2.2);
glEnd();
glPopMatrix();
}

void car2(float y)
{
glPushMatrix(); //making color for outer line
glTranslated(b-1800,y,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(1.0,1.0,0.4);
glBegin(GL_POLYGON);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(1.0,1.0,1.0); //color for outer window
glBegin(GL_POLYGON);
glVertex2f(5.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glEnd();

glColor3f(0.0,0.0,0.0); //making outer line for car
glBegin(GL_LINE_LOOP);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP); //outer line for design a car
glVertex2f(8.0,3.0);
glVertex2f(16.0,3.0);
glVertex2f(16.5,3.5);
glVertex2f(17.0,4.0);
glVertex2f(16.5,4.25);
glVertex2f(16.0,4.5);
glVertex2f(15.0,4.5);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glVertex2f(5.0,5.0);
glVertex2f(7.0,5.0);
glVertex2f(6.5,4.5);
glEnd();


glBegin(GL_LINES); //connecting outer line
glVertex2d(7.0,5.0);
glVertex2d(15.0,5.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,4.0);
glVertex2d(17.0,4.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,3.5);
glVertex2d(16.5,3.5);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,5.0);
glVertex2d(14.0,3.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(12.0,5.0);
glVertex2d(12.0,6.2);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(7.0,5.0);
glVertex2d(7.0,6.7);
glEnd();

glBegin(GL_POLYGON); //drawing a back tyre
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();


glBegin(GL_POLYGON); //drawing front tyre
glVertex2f(17.0,2.5);
glVertex2f(17.0,2.6);
glVertex2f(17.15,3.1);
glVertex2f(17.2,3.2);
glVertex2f(17.3,3.35);
glVertex2f(17.4,3.4);
glVertex2f(17.5,3.45);
glVertex2f(17.6,3.55);
glVertex2f(17.7,3.6);
glVertex2f(17.8,3.63);
glVertex2f(18.0,3.65);
glVertex2f(18.2,3.7);
glVertex2f(18.4,3.7);
glVertex2f(18.6,3.65);
glVertex2f(18.8,3.55);
glVertex2f(19.0,3.45);
glVertex2f(19.1,3.4);
glVertex2f(19.2,3.25);
glVertex2f(19.3,3.2);
glVertex2f(19.4,3.0);

glVertex2f(19.5,2.5);
glVertex2f(19.45,2.15);
glVertex2f(19.4,1.9);
glVertex2f(19.35,1.8);
glVertex2f(19.2,1.6);
glVertex2f(19.0,1.5);
glVertex2f(18.9,1.4);
glVertex2f(18.7,1.3);
glVertex2f(18.6,1.27);
glVertex2f(18.4,1.25);
glVertex2f(18.0,1.25);
glVertex2f(17.9,1.3);
glVertex2f(17.75,1.35);
glVertex2f(17.6,1.4);
glVertex2f(17.45,1.55);
glVertex2f(17.3,1.7);
glVertex2f(17.2,1.8);
glVertex2f(17.1,2.2);
glEnd();
glPopMatrix();
}

void car3(int x,float c1,float c2)
{
glPushMatrix(); //making color for outer line
glTranslated(b-x,190,0.0);
glScaled(20.0,20.0,0.0);
glColor3f(c1,c2,0.4);
glBegin(GL_POLYGON);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(1.0,1.0,1.0); //color for outer window
glBegin(GL_POLYGON);
glVertex2f(5.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glEnd();

glColor3f(0.0,0.0,0.0); //making outer line for car
glBegin(GL_LINE_LOOP);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP); //outer line for design a car
glVertex2f(8.0,3.0);
glVertex2f(16.0,3.0);
glVertex2f(16.5,3.5);
glVertex2f(17.0,4.0);
glVertex2f(16.5,4.25);
glVertex2f(16.0,4.5);
glVertex2f(15.0,4.5);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glVertex2f(5.0,5.0);
glVertex2f(7.0,5.0);
glVertex2f(6.5,4.5);
glEnd();


glBegin(GL_LINES); //connecting outer line
glVertex2d(7.0,5.0);
glVertex2d(15.0,5.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,4.0);
glVertex2d(17.0,4.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,3.5);
glVertex2d(16.5,3.5);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,5.0);
glVertex2d(14.0,3.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(12.0,5.0);
glVertex2d(12.0,6.2);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(7.0,5.0);
glVertex2d(7.0,6.7);
glEnd();

glBegin(GL_POLYGON); //drawing a back tyre
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();


glBegin(GL_POLYGON); //drawing front tyre
glVertex2f(17.0,2.5);
glVertex2f(17.0,2.6);
glVertex2f(17.15,3.1);
glVertex2f(17.2,3.2);
glVertex2f(17.3,3.35);
glVertex2f(17.4,3.4);
glVertex2f(17.5,3.45);
glVertex2f(17.6,3.55);
glVertex2f(17.7,3.6);
glVertex2f(17.8,3.63);
glVertex2f(18.0,3.65);
glVertex2f(18.2,3.7);
glVertex2f(18.4,3.7);
glVertex2f(18.6,3.65);
glVertex2f(18.8,3.55);
glVertex2f(19.0,3.45);
glVertex2f(19.1,3.4);
glVertex2f(19.2,3.25);
glVertex2f(19.3,3.2);
glVertex2f(19.4,3.0);

glVertex2f(19.5,2.5);
glVertex2f(19.45,2.15);
glVertex2f(19.4,1.9);
glVertex2f(19.35,1.8);
glVertex2f(19.2,1.6);
glVertex2f(19.0,1.5);
glVertex2f(18.9,1.4);
glVertex2f(18.7,1.3);
glVertex2f(18.6,1.27);
glVertex2f(18.4,1.25);
glVertex2f(18.0,1.25);
glVertex2f(17.9,1.3);
glVertex2f(17.75,1.35);
glVertex2f(17.6,1.4);
glVertex2f(17.45,1.55);
glVertex2f(17.3,1.7);
glVertex2f(17.2,1.8);
glVertex2f(17.1,2.2);
glEnd();
glPopMatrix();
}
void myinit()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("Traffic signal");


glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
glutMouseFunc(myMouse);


myinit();
sndPlaySound(TEXT("demo2.wav"),SND_ASYNC);
glutMainLoop();
return 0;
}
