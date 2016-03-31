#pragma once

class Head{
public:

	GLfloat size;
	Vector3<GLfloat> neak_size;
	Vector3<GLfloat> head_size;
	GLfloat head_side;

	Vector3<GLfloat> neak_angle;

	Vector3<GLubyte> head_color;
	Vector3<GLubyte> neak_color;

	Head(){
		init();
	}

	void init(){
		size = 0.7f;
		neak_size = Vector3<GLfloat>(0.8f,1.0f,0.8f);
		head_size = Vector3<GLfloat>(5.0f, 5.0f, 3.0f);
		head_side = 0.5f;

		init_pos();
		init_color();
	}

	void init_pos(){
		neak_angle = Vector3<GLfloat>(0.0f, 0.0f, 0.0f);
	}

	void init_color(){
		head_color = Vector3<GLubyte>(34,0,136);
		neak_color = Vector3<GLubyte>(102,221,0);
	}

	void draw(){
		glPushMatrix();
		{
			glColor3ubv(neak_color.toArray());
			glutMySolidSphere(size*neak_size[0], size*neak_size[1], size*neak_size[2], 30,30);  //neak
			glRotateXYZ(neak_angle);

			glTranslatef(0.0f, size * neak_size[1] *head_side, 0.0f);
			glTranslatef(0.0f,size*head_size[1]/2,0.0f);
			glColor3ubv(head_color.toArray());

			glutSolidCube(head_size, size);   //head

			glTranslatef(0.0f, 0.0f, size*head_size[2]/2);

			glEnable(GL_TEXTURE_2D);
			glColor3ub(255,255,255);
			glBegin(GL_QUADS);
			{
				glNormal3f(0, 0, 1);
				glTexCoord2f(0, 1); glVertex3f(-1.5f, 1.5f, 0.01f);
				glTexCoord2f(0, 0); glVertex3f(-1.5f, -1.5f, 0.01f);
				glTexCoord2f(1, 0); glVertex3f(1.5f, -1.5f, 0.01f);
				glTexCoord2f(1, 1); glVertex3f(1.5f, 1.5f, 0.01f);
			}
			glEnd();
			glDisable(GL_TEXTURE_2D);

		}
		glPopMatrix();
	}
};