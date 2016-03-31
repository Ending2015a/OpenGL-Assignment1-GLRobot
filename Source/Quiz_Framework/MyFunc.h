#pragma once

void glRotateXYZ(GLfloat x, GLfloat y, GLfloat z){
	glRotatef(x, 1.0f, 0.0f, 0.0f);
	glRotatef(y, 0.0f, 1.0f, 0.0f);
	glRotatef(z, 0.0f, 0.0f, 1.0f);
}

void glRotateXYZ(GLfloat v[3]){
	glRotatef(v[0], 1.0f, 0.0f, 0.0f);
	glRotatef(v[1], 0.0f, 1.0f, 0.0f);
	glRotatef(v[2], 0.0f, 0.0f, 1.0f);
}

void glRotateXYZ(Vector3<GLfloat> v){
	glRotatef(v[0], 1.0f, 0.0f, 0.0f);
	glRotatef(v[1], 0.0f, 1.0f, 0.0f);
	glRotatef(v[2], 0.0f, 0.0f, 1.0f); 
}

void glColor4ub(Vector3<GLubyte> v, GLubyte a){
	glColor4ub(v[0],v[1],v[2],a);
}

void glutMySolidCylinder(GLfloat r, GLfloat h, GLint sl, GLint st, int d){
	glPushMatrix();
	{
		if (d == 0){
			glTranslatef(-h / 2, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		}
		else if (d == 1){
			glTranslatef(0.0f, -h / 2, 0.0f);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

		}
		else if (d == 2){
			glTranslatef(0.0f, 0.0f, -h / 2);
		}
		glutSolidCylinder(r, h, sl, st);
	}
	glPopMatrix();
}

void glutMySolidCone(GLfloat r, GLfloat h, GLint sl, GLint st, int d){
	glPushMatrix();
	{
		if (d == 0){  //-> x
			glTranslatef(-h / 2, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		}
		else if (d == 1){  //->y
			glTranslatef(0.0f, -h / 2, 0.0f);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

		}
		else if (d == 2){  // ->z
			glTranslatef(0.0f, 0.0f, -h / 2);
		}
		glutSolidCone(r, h, sl, st);
	}
	glPopMatrix();
}

void glutMySolidSphere(GLfloat x, GLfloat y, GLfloat z, GLint sl, GLint st){
	glPushMatrix();
	{
		glScalef(x/x,y/x,z/x);
		glutSolidSphere(x,sl,st);
	}
	glPopMatrix();
}

void glutMySolidCube(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	{
		glScalef(x / x, y / x, z / x);
		glutSolidCube(x);
	}
	glPopMatrix();
}

void glutMySolidTorus(Vector3<GLfloat> v, GLfloat i, GLfloat o,GLint si, GLint ri){
	glPushMatrix();
	{
		glScalef(v[0] / v[0], v[1] / v[0], v[2] / v[0]);
		glutSolidTorus(i,o,si,ri);
	}
	glPopMatrix();
}

void glutSolidCube(Vector3<GLfloat> v, GLfloat size){
	glPushMatrix();
	{
		glScalef(v[0]*size,v[1]*size,v[2]*size);
		glutSolidCube(1.0f);
	}
	glPopMatrix();
}