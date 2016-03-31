
/********************************************************************
**                                                                 **
**     GLRobot                               -Trial ver-           **
**                                                                 **
**          Created by Ending2012 (103062372) on 2016/3/17         **
**                                                                 **
**        Copyright (c) 2015 Ending's APP. All rights reserved.    **
**                                                                 **
*********************************************************************/



#include <glew.h> // glew.h must be included before gl.h/glu.h/freeglut.h
#include <freeglut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<texture_loader.h>
#include"Vector.h"


#define MENU_ACTION_WALK 11
#define MENU_ACTION_RUN 12
#define MENU_ACTION_PATRONUM 13
#define MENU_ACTION_PATRONUM_DISAPPEAR 14
#define MENU_STOP_ACTION 19
#define MENU_TIMER_START 21
#define MENU_TIMER_STOP 22
#define MENU_EXIT 3


#define PI 3.14159265f


// Light values and coordinates
GLfloat	 lightPos[] = { -50.0f, 50.0f, 100.0f, 1.0f };
GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 01.0f, 1.0f };
GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  shiness[] = { 100.0f };

GLfloat	 SpotlightPos[4];
GLfloat	 SpotlightPos2[4];

bool timer_enabled = true;
unsigned int timer_speed = 16;

GLfloat nRange = 10.0f;
int windowRotateX = 0, windowRotateY = 0;
GLfloat angle = 0.0f;

Vector3 < GLfloat > v0, v1, World_Rotate_Axis;
GLfloat World_Rotate_Angle = 0.0f;
GLfloat World_Matrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };


#include "MyFunc.h"
#include "Torso.h"
#include "Head.h"
#include "Arm.h"
#include "Leg.h"

Torso body;
Head head;
Arm left_arm(1, 1, 1);
Arm right_arm(-1, 1, 1);
Leg left_leg(1,1,1);
Leg right_leg(-1,1,1);

Torso nbody;
Head nhead;
Arm nleft_arm(1, 1, 1);
Arm nright_arm(-1, 1, 1);
Leg nleft_leg(1, 1, 1);
Leg nright_leg(-1, 1, 1);
GLfloat nbody_pos_up = 0.0f;
GLfloat nbody_pos_down = 0.0f;
Vector3<GLfloat> nbody_tilt(0.0f,0.0f,0.0f);
GLfloat K = PI;

#include "decoration.h"

Wing left_wing(1);
Wing right_wing(-1);
MagicCircle magiccircle;

MagicCircle nmagiccircle;
FlyingSpoon flyingspoon;


#include "Animation.h"
Animation animation;




// Print OpenGL context related information.
void dumpInfo(void)
{
    printf("Vendor: %s\n", glGetString (GL_VENDOR));
    printf("Renderer: %s\n", glGetString (GL_RENDERER));
    printf("Version: %s\n", glGetString (GL_VERSION));
    printf("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));
}

// GLUT callback. Called to draw the scene.
void My_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//GLfloat angleX = ((GLfloat)windowRotateX / ((GLfloat)window_width / 2)) * 180;
	//GLfloat angleY = ((GLfloat)windowRotateY / ((GLfloat)window_height / 2)) * 180;

	
	//Arm left_up_arm(1, -1, 1);
	//Arm right_up_arm(-1,-1,1);

	//initial matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	gluLookAt(0.0, 0.0, nRange, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);

	{
		glutSolidCube(0.08f*nRange/10.0f);
	}

	glMultMatrixf(World_Matrix);

	SpotlightPos[0] = 0.0f;
	SpotlightPos[1] = -13.5f;
	SpotlightPos[2] = 8.0f;
	SpotlightPos[3] = 1.0f;

	
	
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT1, GL_POSITION, SpotlightPos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Vector3<GLfloat>(0.0f, 13.5f, -0.8f).toArray());
	glLighti(GL_LIGHT1, GL_SPOT_CUTOFF, 30);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1000.0f);

	SpotlightPos[0] = 0.0f;
	SpotlightPos[1] = -9.5f;
	SpotlightPos[2] = 0.0f;
	SpotlightPos[3] = 1.0f;

	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT2, GL_POSITION, SpotlightPos);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Vector3<GLfloat>(0.0f, -1.0f, 0.0f).toArray());
	glLighti(GL_LIGHT2, GL_SPOT_CUTOFF, 60);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 1000.0f);
	


	glPushMatrix();
	{
		
		//glRotatef(angleX, 0.0, 1.0, 0.0);
		//glRotatef(angleY, 1.0, 0.0, 0.0);
		//glRotatef(angle,0.0f,1.0f,0.0f);

		glPushMatrix();
		{
			glPushMatrix();
			{
				glTranslatef(0.0f,-13.5f,0.0f);
				magiccircle.draw();
			}
			glPopMatrix();
			
			glTranslatef(0.0f, body.torso_pos, 0.0f);
			
			glPushMatrix();
			{
				glRotateXYZ(body.torso_tilt);
				body.draw();    //body


				glPushMatrix();   //left wing
				{
					glTranslatef(1.3f, 3.0f, -1.1f);
					glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
					glRotatef(-5.0f, 0.0f, 0.0f, 1.0f);
					left_wing.draw();
				}
				glPopMatrix();

				glPushMatrix();   //right wing
				{
					glTranslatef(-1.3f, 3.0f, -1.1f);
					glRotatef(-25.0f, 0.0f, 1.0f, 0.0f);
					glRotatef(5.0f, 0.0f, 0.0f, 1.0f);
					right_wing.draw();
				}
				glPopMatrix();

				glPushMatrix();   //head
				{
					glTranslatef(0.0f, 4.0f, 0.0f);
					head.draw();
				}
				glPopMatrix();

				glPushMatrix();    //left arm
				{
					glTranslatef(3.0f, 2.6f, 0.0f);
					left_arm.draw();
					
				}
				glPopMatrix();
				
				glPushMatrix();    //right arm
				{
					glTranslatef(-3.0f, 2.6f, 0.0f);
					right_arm.draw();
					
				}
				glPopMatrix();
				
				glPushMatrix();    //left leg
				{
					glTranslatef(1.7f, -4.0f, 0.0f);
					glRotateXYZ(-body.torso_tilt[0], 0.0f, 0.0f);
					left_leg.draw();

				}
				glPopMatrix();

				glPushMatrix();    //right leg
				{
					glTranslatef(-1.7f, -4.0f, 0.0f);
					glRotateXYZ(-body.torso_tilt[0], 0.0f, 0.0f);
					right_leg.draw();
				}
				glPopMatrix();
			}
			glPopMatrix();
			
			
		}
		glPopMatrix();

		
		/*
		glPushMatrix();
		{
			glTranslatef(2.2f, 0.7f, 0.0f);
			left_up_arm.draw();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-2.2f, 0.7f, 0.0f);
			right_up_arm.draw();
		}
		glPopMatrix();*/

	}
	glPopMatrix();

	glutSwapBuffers();
}

void My_Reshape(int width, int height)
{
	// Prevent a divide by zero
	if (height == 0)
		height = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, width, height);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	/*if (width <= height)
		glOrtho(-nRange, nRange, -nRange*height / width, nRange*height / width, -nRange, nRange);
	else
		glOrtho(-nRange*width / height, nRange*width / height, -nRange, nRange, -nRange, nRange);*/

	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0, 400.0);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	gluLookAt(0.0, 0.0, nRange, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);
}

void My_Timer(int val)
{
	
	angle += 1.0f;
	if (angle >= 360.0f)angle = 0.0f;
	magiccircle.rotate_angle += 2.0f;
	if (magiccircle.rotate_angle >= 360.0f)magiccircle.rotate_angle = 0.0f;
	body.change_core_color(angle);
	if (magiccircle.light_enable){
		magiccircle.light_offset += 0.2f;
		if (magiccircle.light_offset >= magiccircle.light_blank)magiccircle.light_offset = 0.0f;
	}

	// animation control
	if (animation.enable){
		switch (animation.kind){
		case ACTION_WALK_UP:
			if (!animation.action()){
				animation.walk_down();
				animation.start(40,0);
			}break;
		case ACTION_WALK_DOWN:
			if (!animation.action()){
				animation.walk_up();
				animation.start(40, 0);
			}break;
		case ACTION_RUN_UP_BACK:
			if (!animation.action()){
				animation.run_up_front();
				animation.start(8, 0);
			}break;
		case ACTION_RUN_UP_FRONT:
			if (!animation.action()){
				animation.run_down_back();
				animation.start(8, 0);
			}break;
		case ACTION_RUN_DOWN_BACK:
			if (!animation.action()){
				animation.run_down_front();
				animation.start(8, 0);
			}break;
		case ACTION_RUN_DOWN_FRONT:
			if (!animation.action()){
				animation.run_up_back();
				animation.start(8, 0);
			}break;
		case ACTION_PATRONUM_STAY:
			if (!animation.action()){
				animation.patronum_begin();
				animation.start(80, 0);
			}break;
		case ACTION_PATRONUM_BEGIN:
			if (!animation.action()){
				animation.patronum_appear();
				animation.start(100, 0);
			}break;
		case ACTION_PATRONUM_APPEAR:
			if (!animation.action()){
				animation.magiccircle_disappear();
				animation.start(80, 0);
			}break;
		case ACTION_MAGICCIRCLE_DISAPPEAR:
			if (!animation.action()){
				magiccircle.enable = 0;
				animation.animation_disable = 0;
				animation.init_pos();
				animation.start(20, 0);
			}
			break;
		case STOP_ACTION:
			if (!animation.action()){
				animation.enable = false;
			}
			break;
		default:
			break;
		}
	}
	//....
	glutPostRedisplay();
	if(timer_enabled)
	{
		glutTimerFunc(timer_speed, My_Timer, val);
	}
}

int downX, downY;
int mouse_button;

void My_Mouse(int button, int state, int x, int y)
{

	if(state == GLUT_DOWN)
	{
		printf("Mouse %d is pressed at (%d, %d)\n", button, x, y);

		{
			downX = x;
			downY = y;
			mouse_button = button;
			glutPostOverlayRedisplay();
		}
		
	}
	else if(state == GLUT_UP)
	{
		printf("Mouse %d is released at (%d, %d)\n", button, x, y);

		{ //mouse scroll
			if (button == 3){
				if (nRange > 1.0f) nRange -= 1.0f;
			}
			else if (button == 4){
				if (nRange <= 100.0f)nRange += 1.0f;
			}
			glutPostOverlayRedisplay();
		}
		
	}
}

void My_MouseMove(int x,int y){

	int w = glutGet(GLUT_WINDOW_WIDTH), h = glutGet(GLUT_WINDOW_HEIGHT);

	if (mouse_button == 0){
		v0 = normalize(2 * (GLfloat)downX / w - 1, -2 * (GLfloat)downY / h + 1, (GLfloat)1);
		v1 = normalize(2 * (GLfloat)x / w - 1, -2 * (GLfloat)y / h + 1, (GLfloat)1);
		World_Rotate_Axis = v0 / v1;
		World_Rotate_Angle = (GLfloat)acos((float)(v0*v1));
		downY = y;
		downX = x;

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			glLoadIdentity();
			glRotatef((GLfloat)World_Rotate_Angle * 180.0f * 2 / (GLfloat)PI, (GLfloat)World_Rotate_Axis[0], (GLfloat)World_Rotate_Axis[1], (GLfloat)World_Rotate_Axis[2]);
			glMultMatrixf(World_Matrix);
			glGetFloatv(GL_MODELVIEW_MATRIX, World_Matrix);
		}
		glPopMatrix();
		glutPostRedisplay();
	} else if (mouse_button == 1){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			glLoadIdentity();
			glTranslatef((GLfloat)(x-downX)/w *nRange , (GLfloat)(downY-y)/h *nRange,0.0f);
			glMultMatrixf(World_Matrix);
			glGetFloatv(GL_MODELVIEW_MATRIX, World_Matrix);
		}
		glPopMatrix();
		downX = x;
		downY = y;
		glutPostRedisplay();
	}
}

void My_Keyboard(unsigned char key, int x, int y)
{
	printf("Key %c is pressed at (%d, %d)\n", key, x, y);

	{ //re
		switch (key){
		case '1':  //back
		case '2':  //down
		case '4':  //left
		case '5':  //front
		case '6':  //right
		case '8':  //up
			nRange = 10.0f;
			glPushMatrix();
			{
				glLoadIdentity();
				if (key == '1')glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
				else if (key == '2')glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
				else if (key == '4')glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
				else if (key == '6')glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
				else if (key == '8')glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				glGetFloatv(GL_MODELVIEW_MATRIX, World_Matrix);
			}
			glPopMatrix();
			glutPostRedisplay();
		}
	}
	
}

void My_SpecialKeys(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_F1:
		printf("F1 is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_PAGE_UP:
		printf("Page up is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_LEFT:
		printf("Left arrow is pressed at (%d, %d)\n", x, y);
		break;
	default:
		printf("Other special key is pressed at (%d, %d)\n", x, y);
		break;
	}
}

void My_Menu(int id)
{
	switch(id)
	{
	case MENU_ACTION_WALK:
		if (animation.kind == ACTION_WALK_UP || animation.kind == ACTION_WALK_DOWN)break;
		animation.walk_up();
		animation.start(40,0);
		break;
	case MENU_ACTION_RUN:
		if (animation.kind == ACTION_RUN_UP_BACK || animation.kind == ACTION_RUN_UP_FRONT || animation.kind == ACTION_RUN_DOWN_BACK || animation.kind == ACTION_RUN_DOWN_FRONT)break;
		animation.run_up_back();
		animation.start(15, 0);
		break;
	case MENU_ACTION_PATRONUM:
		if (body.enable_flying_teaspoon != 0 || animation.kind == ACTION_PATRONUM_STAY || animation.kind == ACTION_PATRONUM_BEGIN || animation.kind == ACTION_PATRONUM_APPEAR)break;
		animation.patronum_stay();
		animation.animation_disable = 1;
		animation.start(20, 0);
		break;
	case MENU_ACTION_PATRONUM_DISAPPEAR:
		if (body.enable_flying_teaspoon == 0 || animation.animation_disable)break;
		flyingspoon.disappear();
		if (animation.enable == false)animation.start(20, 0);
		break;
	case MENU_STOP_ACTION:
		animation.init_pos();
		animation.start(20, 0);
		break;
	case MENU_TIMER_START:
		if(!timer_enabled)
		{
			timer_enabled = true;
			glutTimerFunc(timer_speed, My_Timer, 0);
		}
		break;
	case MENU_TIMER_STOP:
		timer_enabled = false;
		break;
	case MENU_EXIT:
		exit(0);
		break;
	default:
		break;
	}
}

void inittexture(){
	texture_data pic = load_jpg("r.jpg");

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pic.width, pic.height, GL_RGB, GL_UNSIGNED_BYTE, pic.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pic.width, pic.height, 0, GL_RGB, GL_UNSIGNED_BYTE, pic.data);

	free_texture_data(pic);
}

void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Enable Depth Testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Enable lighting
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
		

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glEnable(GL_NORMALIZE);
	glEnable(GL_RESCALE_NORMAL);
}

void BuildMenu(){
	// Create a menu and bind it to mouse right button.
	////////////////////////////
	int menu_main = glutCreateMenu(My_Menu);
	int menu_timer = glutCreateMenu(My_Menu);
	int menu_action = glutCreateMenu(My_Menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Action", menu_action);
	glutAddSubMenu("Timer", menu_timer);
	glutAddMenuEntry("Exit", MENU_EXIT);

	glutSetMenu(menu_action);
	glutAddMenuEntry("Walk",MENU_ACTION_WALK);
	glutAddMenuEntry("Run", MENU_ACTION_RUN);
	glutAddMenuEntry("Expecto Patronum", MENU_ACTION_PATRONUM);
	glutAddMenuEntry("Expecto Patronum Disappear", MENU_ACTION_PATRONUM_DISAPPEAR);
	glutAddMenuEntry("STOP ACTION", MENU_STOP_ACTION);

	glutSetMenu(menu_timer);
	glutAddMenuEntry("Start", MENU_TIMER_START);
	glutAddMenuEntry("Stop", MENU_TIMER_STOP);

	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	////////////////////////////
}

int main(int argc, char *argv[])
{
	// Initialize GLUT and GLEW, then create a window.
	////////////////////
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("HW1 - 103062372"); // You cannot use OpenGL functions before this line; The OpenGL context must be created first by glutCreateWindow()!
	glewInit();
    dumpInfo();
	////////////////////
	
	inittexture();
	
	// Initialize OpenGL states.
	////////////////////////
	SetupRC();  //initial
	////////////////////////

	BuildMenu();  //build menu

	// Register GLUT callback functions.
	///////////////////////////////
	glutDisplayFunc(My_Display);
	glutReshapeFunc(My_Reshape);
	glutMouseFunc(My_Mouse);
	glutMotionFunc(My_MouseMove);
	glutKeyboardFunc(My_Keyboard);
	glutSpecialFunc(My_SpecialKeys);
	glutTimerFunc(timer_speed, My_Timer, 0); 
	///////////////////////////////


	
	// Enter main event loop.
	//////////////
	glutMainLoop();
	//////////////
	return 0;
}