#pragma once

class Wing{
public:

	GLfloat size;

	Vector3<GLubyte> color1;
	Vector3<GLubyte> color2;
	Vector3<GLubyte> color3;

	GLfloat Mirrer_Matrix[16];
	int mirrerX;

	Wing(int c = 1){ mirrerX = c; init(); }

	void init(){

		size = 2.0f;
		GLfloat mm[16] = { (GLfloat)mirrerX, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
		for (int i = 0; i < 16; i++)Mirrer_Matrix[i] = mm[i];

		init_color();
	}

	void init_color(){
		color1 = Vector3<GLubyte>(200, 200, 200);
		color2 = Vector3<GLubyte>(176, 176, 176);
		color3 = Vector3<GLubyte>(192, 192, 192);
	}

	void draw(){
		glPushMatrix();
		{
			glColor3ubv(color1.toArray());
			glMultMatrixf(Mirrer_Matrix);

			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(20.0f, 0.0f, 1.0f, 0.0f);

			GLfloat a = 0.5f;

			glPushMatrix();   //layer 1
			{

				glScalef(1.0f, 0.3f, 1.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //1

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.2f, 30, 30);  //2

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //3

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.4f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //4

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //5

				glColor3ubv(color3.toArray());
				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //6

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //7

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //8

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.4f, 30, 30);  //9

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.65f, 30, 30);  //10

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.33f, size*1.45f, 30, 30);  //11

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.63f, 30, 30);  //12

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //13

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.28f, size*1.45f, 30, 30);  //14

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.67f, 30, 30);  //15

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //16

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.62f, 30, 30);  //17

			}
			glPopMatrix();

			glPushMatrix();   //layer 5
			{
				glTranslatef(0.0f, size*-0.4f, 0.0f);
				glScalef(1.0f, 0.3f, 1.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //1

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.2f, 30, 30);  //2

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //3

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.4f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //4

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //5

				glColor3ubv(color3.toArray());
				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //6

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //7

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //8

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.4f, 30, 30);  //9

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.65f, 30, 30);  //10

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.33f, size*1.45f, 30, 30);  //11

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.63f, 30, 30);  //12

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //13

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.28f, size*1.45f, 30, 30);  //14

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.67f, 30, 30);  //15

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //16

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.62f, 30, 30);  //17

			}
			glPopMatrix();

			glPushMatrix();   //layer 3
			{
				glTranslatef(0.0f, size*-0.2f, 0.0f);
				glScalef(1.0f, 0.3f, 1.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //1

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.2f, 30, 30);  //2

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //3

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.4f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //4

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.5f, 30, 30);  //5

				glColor3ubv(color3.toArray());
				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //6

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //7

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //8

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.4f, 30, 30);  //9

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.65f, 30, 30);  //10

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.33f, size*1.45f, 30, 30);  //11

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.63f, 30, 30);  //12

				glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.6f, 30, 30);  //13

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.28f, size*1.45f, 30, 30);  //14

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.67f, 30, 30);  //15

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //16

				glRotatef(12.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.62f, 30, 30);  //17

			}
			glPopMatrix();

			glPushMatrix();  //layer 4
			{
				glTranslatef(size * 0.1f, size*-0.3f, size*0.25f);
				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glColor3ubv(color2.toArray());

				glScalef(1.0f, 0.3f, 1.0f);
				glutSolidCone(size*0.3f, size*1.7f, 30, 30);  //1

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.25f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //2

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.45f, 30, 30);  //3

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.1f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //4

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*1.82f, 30, 30);  //5

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.35f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.6f, 30, 30);  //6

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.15f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.35f, size*1.8f, 30, 30);  //7

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.9f, 30, 30);  //8

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.4f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*2.1f, 30, 30);  //9

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*2.2f, 30, 30);  //10

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*2.12f, 30, 30);  //11

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.23f, 30, 30);  //12

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.12f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.41f, size*2.44f, 30, 30);  //13

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.44f, size*2.5f, 30, 30);  //14

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.45f, size*2.56f, 30, 30);  //15

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.7f, 30, 30);  //16

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.25f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.6f, 30, 30);  //17

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.46f, size*2.76f, 30, 30);  //18

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.27f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*2.8f, 30, 30);  //19

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.12f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.85f, 30, 30);  //20
			}
			glPopMatrix();

			glTranslatef(size * 0.1f, size*-0.1f, size*0.25f);
			glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
			glColor3ubv(color2.toArray());

			{	// layer 2
				glScalef(1.0f, 0.3f, 1.0f);
				glutSolidCone(size*0.3f, size*1.7f, 30, 30);  //1

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.25f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.5f, 30, 30);  //2

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.45f, 30, 30);  //3

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.1f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //4

				glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*1.82f, 30, 30);  //5

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.35f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.6f, 30, 30);  //6

				glRotatef(3.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.15f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.35f, size*1.8f, 30, 30);  //7

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*1.9f, 30, 30);  //8

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.4f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*2.1f, 30, 30);  //9

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*2.2f, 30, 30);  //10

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.3f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.38f, size*2.12f, 30, 30);  //11

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.23f, 30, 30);  //12

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.12f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.41f, size*2.44f, 30, 30);  //13

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.44f, size*2.5f, 30, 30);  //14

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.2f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.45f, size*2.56f, 30, 30);  //15

				glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.7f, 30, 30);  //16

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.25f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.6f, 30, 30);  //17

				glRotatef(8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.46f, size*2.76f, 30, 30);  //18

				glRotatef(7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.27f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.42f, size*2.8f, 30, 30);  //19

				glRotatef(6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(size*0.12f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.43f, size*2.85f, 30, 30);  //20
			}

			glTranslatef(size * -0.2f*a, size*-0.333f, size*0.25f);
			glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

			glColor3ubv(color1.toArray());
			glPushMatrix();   //layer3
			{
				glutSolidCone(size*0.5f, size*4.8f, 30, 30);  //1

				glRotatef(-5.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.25f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*4.7f, 30, 30);  //2

				glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.24f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*4.5f, 30, 30);  //3

				glRotatef(-7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.26f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*4.3f, 30, 30);  //4

				glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*4.1f, 30, 30);  //5

				glRotatef(-7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.24f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*3.9f, 30, 30);  //6

				glRotatef(-8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*3.7f, 30, 30);  //7

				glRotatef(-9.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.21f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*3.5f, 30, 30);  //8

				glRotatef(-8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*3.2f, 30, 30);  //9

				glRotatef(-7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.21f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*3.0f, 30, 30);  //10

				glRotatef(-7.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*2.8f, 30, 30);  //11

				glRotatef(-8.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.23f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*2.5f, 30, 30);  //12

				glRotatef(-9.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.22f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*2.3f, 30, 30);  //13

				glRotatef(-9.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.21f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*2.1f, 30, 30);  //14

				glRotatef(-9.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.21f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.5f, size*2.0f, 30, 30);  //15

				glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.24f*a, 0.0f, size*0.15f);
				glutSolidCone(size*0.4f, size*1.8f, 30, 30);  //16

				glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.24f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.4f, size*1.7f, 30, 30);  //17

				glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
				glTranslatef(-size*0.24f*a, 0.0f, 0.0f);
				glutSolidCone(size*0.3f, size*1.6f, 30, 30);  //18
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
};


class MagicCircle{
public:
	int enable;
	GLfloat size;
	GLfloat radix;
	int rotate_enable;
	GLfloat rotate_angle;
	GLfloat width;
	GLfloat height;

	int light_enable;
	GLfloat light_angle;
	GLfloat light_size;
	GLfloat light_height;
	GLfloat light_blank;
	GLfloat light_offset;

	static const GLfloat root3;

	Vector3<GLubyte> color;
	Vector3<GLubyte> light_color;

	MagicCircle(){ init(); }

	void init(){
		enable = 0;
		rotate_enable = 1;
		size = 0.7f;
		radix = 0.0f;
		rotate_angle = 0.0f;
		width = 0.3f;
		height = 0.3f;

		light_enable = 1;
		light_angle = 20.0f;
		light_size = 0.5f;

		light_height = 0.0f;
		light_blank = 2.0f;
		light_offset = 0.0f;

		init_color();
	}

	void init_color(){
		color = Vector3<GLubyte>(255, 255, 119);
		light_color = Vector3<GLubyte>(193, 0, 102);
	}

	void interpolation(MagicCircle &m, int f, int n){
		light_height += (GLfloat)(m.light_height - light_height) / (GLfloat)(f - n);
		radix += (GLfloat)(m.radix - radix) / (GLfloat)(f - n);
	}

	void appear(){
		light_height = 50.0f;
		radix = 10.0f;
	}

	void disappear2(){
		light_height = 0.0f;
	}

	void disappear(){
		light_height = 0.0f;
		radix = 0.0f;
	}

	void draw(){
		if (!enable)return;
		glPushMatrix();
		{
			glPushMatrix();
			{
				glScalef(1.0f, height, 1.0f);
				glPushMatrix();
				{
					glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
					glColor3ubv(color.toArray());
					if (rotate_enable)glRotatef(rotate_angle, 0.0f, 0.0f, (GLfloat)-rotate_enable);
					glutSolidTorus(size*width, size*radix, 30, 30);

				}
				glPopMatrix();

				if (rotate_enable)glRotatef(rotate_angle, 0.0f, (GLfloat)rotate_enable,0.0f);

				for (int i = -1; i < 2; i += 2){
					GLfloat Mir[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, (GLfloat)i, 0, 0, 0, 0, 1 };
					glPushMatrix();
					{
						glMultMatrixf(Mir);
						glTranslatef(0.0f, 0.0f, -size*radix);
						glRotatef(-60.0f, 0.0f, 1.0f, 0.0f);

						glTranslatef(size* radix*root3 / 2.0f, 0.0f, 0.0f);
						glPushMatrix();
						{
							glScalef(size*radix *root3, height, size*width);
							glutSolidCube(1.0f);
						}
						glPopMatrix();
						glTranslatef(size* radix*root3 / 2.0f, 0.0f, 0.0f);

						glRotatef(-120.0f, 0.0f, 1.0f, 0.0f);
						glTranslatef(size* radix*root3 / 2.0f, 0.0f, 0.0f);
						glPushMatrix();
						{
							glScalef(size*radix *root3, height, size*width);
							glutSolidCube(1.0f);
						}
						glPopMatrix();
						glTranslatef(size* radix*root3 / 2.0f, 0.0f, 0.0f);

						glRotatef(-120.0f, 0.0f, 1.0f, 0.0f);
						glTranslatef(size* radix*root3 / 2.0f, 0.0f, 0.0f);
						glPushMatrix();
						{
							glScalef(size*radix *root3, height, size*width);
							glutSolidCube(1.0f);
						}
						glPopMatrix();

					}
					glPopMatrix();
				}  //end for
			}
			glPopMatrix();

			if (light_enable == 1){
				glColor3ubv(light_color.toArray());
				for (GLfloat an = 0.0f; an < 360.0f; an += 10.0f){
					glPushMatrix();
					{
						glRotatef(-an, 0.0f, 1.0f, 0.0f);
						glTranslatef(size* radix, 0.0f, 0.0f);
						glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
						glRotatef(-light_angle, 0.0f, 1.0f, 0.0f);
						glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);
						glTranslatef(0.0f, 0.0f, -light_offset*size);
						for (GLfloat bk = 0.0f; bk < light_height*size; bk += light_blank*size){
							glPushMatrix();
							{
								glTranslatef(0.0f, 0.0f, -bk);
								glutSolidTeaspoon(size*light_size);
							}
							glPopMatrix();
						}
					}
					glPopMatrix();
				}
			}
		}
		glPopMatrix();

	}
};

const GLfloat MagicCircle::root3 = 1.73205080757f;


class FlyingSpoon{
public:

	Vector3<GLfloat> teaspoon_pos;
	Vector3<GLfloat> teaspoon2_pos;
	GLfloat teaspoon_size;
	GLfloat teaspoon_radix;
	GLfloat teaspoon2_size;
	GLfloat teaspoon2_radix;
	int enable_flying_teaspoon = 1;
	
	FlyingSpoon(){
		init();
	}

	void init(){
		enable_flying_teaspoon = 1;
		teaspoon_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon2_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon_size = 0.4f;
		teaspoon_radix = 4.0f;
		teaspoon2_size = 1.0f;
		teaspoon2_radix = 4.0f;
	}

	void disappear(){
		enable_flying_teaspoon = 0;
		teaspoon_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon2_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon_size = 0.4f;
		teaspoon_radix = 50.0f;
		teaspoon2_size = 1.0f;
		teaspoon2_radix = 50.0f;
	}
};