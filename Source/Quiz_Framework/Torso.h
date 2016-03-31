#pragma once
#include "decoration.h"

GLfloat core_rotate_matrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

class Torso{
private:
	int R=-2, G=2, B=2;
public:
	GLfloat size;
	Vector3<GLubyte> torso_color;
	Vector3<GLfloat> torso_size;

	Vector3<GLfloat> torus_size;
	GLfloat torus_outer_radix;
	GLfloat torus_inner_radix;
	Vector3<GLubyte> torus_color;

	Vector3<GLfloat> core_size;
	GLfloat core_dis;
	Vector3<GLubyte> core_color;
	Vector3<GLfloat> core_rotate_axis;
	GLfloat core_rotate_angle;
	
	Vector3<GLfloat> teaspoon_pos;
	Vector3<GLfloat> teaspoon_tilt;
	GLfloat teaspoon_size;
	GLfloat teaspoon_radix;
	Vector3<GLubyte> teaspoon_color[9];
	GLfloat teaspoon_rotate_speed;

	Vector3<GLfloat> teaspoon2_pos;
	Vector3<GLfloat> teaspoon2_tilt;
	GLfloat teaspoon2_size;
	GLfloat teaspoon2_radix;
	Vector3<GLubyte> teaspoon2_color[9];
	GLfloat teaspoon2_rotate_speed;

	Vector3<GLfloat> shoulder_pos;
	GLfloat shoulder_radix;
	GLfloat shoulder_height;
	GLfloat shoulder_up_angle;
	Vector3<GLubyte> shoulder_color;

	GLfloat torso_pos;
	Vector3<GLfloat> torso_tilt;

	GLfloat walk_down;
	GLfloat walk_up;
	Vector3<GLfloat> walk_tilt;
	GLfloat walk_K = (GLfloat)PI;

	GLfloat run_up;
	GLfloat run_down;
	Vector3<GLfloat> run_up_tilt;
	Vector3<GLfloat> run_down_tilt;
	GLfloat run_K = (GLfloat)PI / 2.0f;

	GLfloat Mirrer_Matrix[16];

	int enable_flying_teaspoon = 0;

	Torso(){ init(); }

	void init(){
		size = 3.0f;
		torso_size = Vector3<GLfloat>(1.8f, 2.5f, 1.0f);
		torus_size = Vector3<GLfloat>(1.0f, 1.0f, 2.0f);
		torus_inner_radix = 0.1f;
		torus_outer_radix = 0.4f;

		core_size = Vector3<GLfloat>(0.15f, 0.15f, 0.15f);
		core_dis = 0.1f;

		teaspoon_tilt = Vector3<GLfloat>(0.0f, 0.0f, -35.0f);
		teaspoon_size = 0.0f;
		teaspoon_radix = 0.0f;

		teaspoon2_tilt = Vector3<GLfloat>(0.0f, 0.0f, 5.0f);
		teaspoon2_size = 0.0f;
		teaspoon2_radix = 0.0f;

		shoulder_radix = 0.12f;
		shoulder_height = 0.7f;
		shoulder_up_angle = 30.0f;

		GLfloat m[16] = {
			-1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
		for (int i = 0; i < 16; i++)Mirrer_Matrix[i] = m[i];

		init_pos();
		init_color();
	}

	void init_pos(){
		core_rotate_angle = 10.0f;
		core_rotate_axis = Vector3<GLfloat>(1.0f, 0.0f, 0.0f);
		teaspoon_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon2_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		shoulder_pos = Vector3<GLfloat>(0.9f, 1.25f, 0.0f);
		teaspoon_rotate_speed = 5.0f;
		teaspoon2_rotate_speed = 6.0f;

		torso_pos = 0.0f;

		walk_down = 0.1f;
		walk_up = -0.1f;
		walk_tilt = Vector3<GLfloat>(0.0f,0.0f,0.0f);

		run_up = 1.2f;
		run_down = 0.4f;
		run_up_tilt = Vector3<GLfloat>(15.0f, -5.0f, 0.0f);
		run_down_tilt = Vector3<GLfloat>(15.0f, 5.0f, 0.0f);
	}

	void init_color(){
		torso_color = Vector3<GLubyte>(34, 0, 136);
		torus_color = Vector3<GLubyte>(102, 221, 0);
		core_color = Vector3<GLubyte>(255, 0, 136);

		shoulder_color = Vector3<GLubyte>(68, 68, 68);

		teaspoon_color[0] = Vector3<GLubyte>(255, 0, 0);
		teaspoon_color[1] = Vector3<GLubyte>(255, 136, 0);
		teaspoon_color[2] = Vector3<GLubyte>(255, 255, 0);
		teaspoon_color[3] = Vector3<GLubyte>(119, 255, 0);
		teaspoon_color[4] = Vector3<GLubyte>(0, 255, 204);
		teaspoon_color[5] = Vector3<GLubyte>(0, 0, 255);
		teaspoon_color[6] = Vector3<GLubyte>(119, 0, 255);
		teaspoon_color[7] = Vector3<GLubyte>(255, 0, 255);
	}

	void change_core_color(GLfloat angle){
		core_rotate_axis = Vector3<GLfloat>(cos(angle), sin(angle), 0.0f);

		if (core_color[0] >= 254)R = -2;
		else if (core_color[0]<=2)R = 2;
		if (core_color[1] >= 254)G = -2;
		else if (core_color[1] <= 2)G = 2;
		if (core_color[2] >= 254)B = -2;
		else if (core_color[2] <= 2)B = 2;
		core_color[0] += R;
		core_color[1] += G;
		core_color[2] += B;
	}

	void interpolation(GLfloat npos_up,GLfloat npos_down, Vector3<GLfloat> npos_tilt, int f, int n, GLfloat K){
		torso_pos = -(npos_down + (npos_up - npos_down) * (GLfloat)sin((double)n / f  * K));
		for (int i = 0; i < 3; i++)torso_tilt[i] += (GLfloat)(npos_tilt[i] - torso_tilt[i]) / (GLfloat)(f-n);
	}

	void spoon_interpolation(FlyingSpoon &m, int f, int n){
		teaspoon_pos[2] += (GLfloat)(m.teaspoon_pos[2] - teaspoon_pos[2]) / (GLfloat)(f-n);
		teaspoon2_pos[2] += (GLfloat)(m.teaspoon2_pos[2] - teaspoon2_pos[2]) / (GLfloat)(f - n);
		teaspoon_size += (GLfloat)(m.teaspoon_size - teaspoon_size) / (GLfloat)(f - n);
		teaspoon_radix += (GLfloat)(m.teaspoon_radix - teaspoon_radix)/ (GLfloat)(f - n);
		teaspoon2_size += (GLfloat)(m.teaspoon2_size - teaspoon2_size) / (GLfloat)(f - n);
		teaspoon2_radix += (GLfloat)(m.teaspoon2_radix - teaspoon2_radix)/ (GLfloat)(f - n);
		if (f - 1 == n && m.enable_flying_teaspoon == 0)enable_flying_teaspoon = 0;
	}

	void appear(){
		enable_flying_teaspoon = 1;
		teaspoon_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon2_pos = Vector3<GLfloat>(0.0f, -0.2f, 0.0f);
		teaspoon_size = 0.1f;
		teaspoon_radix = 0.1f;
		teaspoon2_size = 0.1f;
		teaspoon2_radix = 0.1f;
	}

	void draw(void){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			glColor3ubv(torso_color.toArray());
			glutMySolidCube(size*torso_size[0], size*torso_size[1], size*torso_size[2]);  //body

			glPushMatrix();
			{
				glColor3ubv(torus_color.toArray());
				glTranslatef(0.0f, size*torso_size[1] / 4, size*torso_size[2] / 2);
				glutMySolidTorus(torus_size, size*torus_inner_radix, size*torus_outer_radix, 10, 10);

				glTranslatef(0.0f, 0.0f, size *core_dis);
				glRotatef(core_rotate_angle, core_rotate_axis[0], core_rotate_axis[1], core_rotate_axis[2]);
				glScalef(size*core_size[0], size*core_size[1], size*core_size[2]);
				glColor3ubv(core_color.toArray());
				glutSolidDodecahedron();
			}
			glPopMatrix();

			if (enable_flying_teaspoon){
				glPushMatrix();   //flying teaspoon
				{
					glTranslatef(size*teaspoon_pos[0], size*teaspoon_pos[1], size*teaspoon_pos[2]);
					glRotateXYZ(teaspoon_tilt);
					int j = 0;
					for (GLfloat i = angle*teaspoon_rotate_speed; j<8; i += 45.0f, j++){
						glPushMatrix();
						{
							glColor3ubv(teaspoon_color[j].toArray());
							glRotatef(i, 0.0f, -1.0f, 0.0f);
							glTranslatef(0.0f, 0.0f, size*teaspoon_radix);
							glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
							glutWireTeacup(size*teaspoon_size);
						}
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();   //flying teaspoon2
				{
					glTranslatef(size*teaspoon2_pos[0], size*teaspoon2_pos[1], size*teaspoon2_pos[2]);
					glRotateXYZ(teaspoon2_tilt);
					int j = 0;
					for (GLfloat i = (angle + 180.0f)*teaspoon2_rotate_speed; j<8; i += 45.0f, j++){
						glPushMatrix();
						{
							glColor3ubv(teaspoon_color[j].toArray());
							glRotatef(i, 0.0f, -1.0f, 0.0f);
							glTranslatef(0.0f, 0.0f, size*teaspoon2_radix);
							glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
							glutWireTeaspoon(size*teaspoon2_size);
						}
						glPopMatrix();
					}
				}
				glPopMatrix();
			}
			

			for (int i = 0; i < 2; i++)draw_shoulder(i);  //shoulder

		}
		glPopMatrix();
	}

	void draw_shoulder(int c){
		glPushMatrix();  //shoulder
		{
			if(c==1)glMultMatrixf(Mirrer_Matrix);  //Mirrer Matrix

			glColor3ubv(shoulder_color.toArray());
			glTranslatef(size*shoulder_pos[0] + size*shoulder_height / 2, size*shoulder_pos[1] - size*shoulder_radix / 2, size*shoulder_pos[2]);

			glPushMatrix();  //middle
			{
				glRotateXYZ(0.0f, 0.0f, shoulder_up_angle);
				glutMySolidCone(size*shoulder_radix, size*shoulder_height, 30, 30, 0);
			}
			glPopMatrix();

			glPushMatrix();  //front
			{
				glTranslatef(0.0f, 0.0f, size*shoulder_radix*1.9f);
				glPushMatrix();  //front1
				{
					glRotateXYZ(0.0f, -22.5f, shoulder_up_angle);
					glutMySolidCone(size*shoulder_radix, size*shoulder_height, 30, 30, 0);
				}
				glPopMatrix();

				glTranslatef(0.0f, 0.0f, size*shoulder_radix*1.9f);
				glPushMatrix();  //front2
				{
					glRotateXYZ(0.0f, -45.0f, shoulder_up_angle);
					glutMySolidCone(size*shoulder_radix, size*shoulder_height, 30, 30, 0);
				}
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();  //back
			{
				glTranslatef(0.0f, 0.0f, -size*shoulder_radix*1.9f);
				glPushMatrix();  //back1
				{
					glRotateXYZ(0.0f, 22.5f, shoulder_up_angle);
					glutMySolidCone(size*shoulder_radix, size*shoulder_height, 30, 30, 0);
				}
				glPopMatrix();

				glTranslatef(0.0f, 0.0f, -size*shoulder_radix*1.9f);
				glPushMatrix();  //back2
				{
					glRotateXYZ(0.0f, 45.0f, shoulder_up_angle);
					glutMySolidCone(size*shoulder_radix, size*shoulder_height, 30, 30, 0);
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
};