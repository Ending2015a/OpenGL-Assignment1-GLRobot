#pragma once

class Leg{
public:
	/*
	    |   |       Z <--|    x Y
	    |   |            v 
	    |   |            X
	    |   |
	    /    \
	   |      |
	  / | | | | 

	*/
	GLfloat size;  //total size
	GLfloat leg_joint_size;  //leg joint redix (size%)
	GLfloat leg_width, leg_length;  //(size%)

	GLfloat leg_side;  //distance between joint and leg (size%)
	Vector3<GLubyte> leg_joint_color;
	Vector3<GLubyte> leg_color;

	Vector3<GLfloat> leg_joint_angle[3];

	Vector3<GLfloat> footplate_size; //footplate radix(size%)
	GLfloat footplate_side;  //footplate size (size%)
	Vector3<GLubyte> footplate_color;

	GLfloat toe_joint_size;  //toe joint size (size%)
	GLfloat toe_side;  //distance between joint and toe (toe_joint_size%)
	GLfloat toe_dist[5];  //toe position (x from footplate center)
	GLfloat toe_tilt[5];  //(angle)
	GLfloat toe_width[19]; //(toe_joint_size%)
	GLfloat toe_length[19]; //(toe_joint_size%)

	Vector3<GLubyte> toe_joint_color;
	Vector3<GLubyte> toe_color;
	Vector3<GLfloat> toe_joint_angle[19];

	GLfloat Mirrer_Matrix[16];
	int mirrerX, mirrerY, mirrerZ;

	Leg(int cx=1, int cy=1, int cz=1){
		mirrerX = cx;
		mirrerY = cy;
		mirrerZ = cz;
		init();
	}

	void init(){

		size = 0.7f;
		leg_joint_size = 1.2f;

		leg_side = 0.3f;
		leg_width = 1.5f;
		leg_length = 4.5f;

		footplate_side = 0.6f;
		footplate_size = Vector3<GLfloat>(1.3f, 0.7f, 0.9f);

		toe_joint_size = 0.3f;
		toe_side = 0.1f;

		GLfloat fd[5] = {
			0.6f,0.9f,1.0f,0.9f,0.8f
		};
		for (int i = 0; i < 5; i++) toe_dist[i] = fd[i];

		GLfloat ft[5] = {
			-50.0f, -25.0f, 0.0f, 25.0f,40.0f
		};
		for (int i = 0; i < 5; i++)toe_tilt[i] = ft[i];

		GLfloat fw[19] = {
			0.8f,0.7f,0.6f,
			0.5f,0.5f,0.5f,0.4f,
			0.5f,0.5f,0.5f,0.4f,
			0.5f,0.5f,0.4f,0.4f,
			0.6f,0.5f,0.5f,0.4f
		};
		for (int i = 0; i < 19; i++)toe_width[i] = fw[i];

		GLfloat fl[19] = {
			6.0f,3.5f,2.5f,
			7.0f,3.3f,2.4f,1.0f,
			5.0f,5.0f,5.0f,5.0f,
			5.0f,5.0f,5.0f,5.0f,
			5.0f,5.0f,5.0f,5.0f
		};
		for (int i = 0; i < 19; i++)toe_length[i] = fl[i];

		GLfloat m[16] = { (GLfloat)mirrerX, 0, 0, 0, 0, (GLfloat)mirrerY, 0, 0, 0, 0, (GLfloat)mirrerZ, 0, 0, 0, 0, 1 };
		for (int i = 0; i < 16; i++)Mirrer_Matrix[i] = m[i];

		init_pos();
		init_color();
	}

	void init_pos(){
		Vector3<GLfloat>  l[3] = {
			Vector3<GLfloat>(0.0f,0.0f,0.0f),
			Vector3<GLfloat>(0.0f,0.0f,0.0f),
			Vector3<GLfloat>(0.0f,0.0f,90.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];

		Vector3<GLfloat> t[19] = { 
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f), Vector3<GLfloat>(0.0f, 0.0f, 0.0f)
		};
		for (int i = 0; i < 14; i++)toe_joint_angle[i] = t[i];
	}

	void init_color(){
		leg_joint_color = Vector3<GLubyte>(102,221,0);
		leg_color = Vector3<GLubyte>(34,0,136);
		footplate_color = Vector3<GLubyte>(34,0,136);
		toe_joint_color = Vector3<GLubyte>(225,136,0);
		toe_color = Vector3<GLubyte>(68,68,68);
	}

	void interpolation(Leg &nleg, int f, int n){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				leg_joint_angle[i][j] += (GLfloat)(nleg.leg_joint_angle[i][j] - leg_joint_angle[i][j]) / (GLfloat)(f-n);
			}
		}
	}

	void walk_up(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, 20.0f),
			Vector3<GLfloat>(0.0f, 0.0f, -10.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 90.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void walk_step_up(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, 15.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 75.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void walk_step_down(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, -10.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 100.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void walk_down(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, -10.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 100.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void run_up_back(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, -45.0f),
			Vector3<GLfloat>(0.0f, 0.0f, -20.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 80.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void run_up_front(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, 45.0f),
			Vector3<GLfloat>(0.0f, 0.0f, -140.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 90.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void run_down_back(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, 60.0f),
			Vector3<GLfloat>(0.0f, 0.0f, -50.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 95.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void run_down_front(){
		Vector3<GLfloat> l[3] = {
			Vector3<GLfloat>(0.0f, 0.0f, 20.0f),
			Vector3<GLfloat>(0.0f, 0.0f, -40.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 110.0f)
		};
		for (int i = 0; i < 3; i++)leg_joint_angle[i] = l[i];
	}

	void draw(){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			GLfloat ss = size * leg_joint_size;

			glMultMatrixf(Mirrer_Matrix);
			glRotateXYZ(0.0f,-90.0f,-90.0f);

			//1st leg joint...
			glColor3ubv(leg_joint_color.toArray());  
			glutSolidSphere(ss,30,30);   
			glRotateXYZ(leg_joint_angle[0]);
			//.....

			glTranslatef(ss*leg_side, 0.0f, 0.0f);
			glTranslatef(ss*leg_length / 2, 0.0f, 0.0f);
			
			//lst leg...
			glColor3ubv(leg_color.toArray());
			glutSolidCube(Vector3<GLfloat>(leg_length, leg_width, leg_width), ss);
			//.....

			glTranslatef(ss*leg_side, 0.0f, 0.0f);
			glTranslatef(ss*leg_length / 2, 0.0f, 0.0f);

			//2st leg joint...
			glColor3ubv(leg_joint_color.toArray());
			glutSolidSphere(ss, 30, 30);
			glRotateXYZ(leg_joint_angle[1]);
			//.....

			glTranslatef(ss*leg_side, 0.0f, 0.0f);
			glTranslatef(ss*leg_length / 2, 0.0f, 0.0f);

			//2st leg...
			glColor3ubv(leg_color.toArray());
			glutSolidCube(Vector3<GLfloat>(leg_length, leg_width, leg_width), ss);
			//.....

			glTranslatef(ss*leg_side, 0.0f, 0.0f);
			glTranslatef(ss*leg_length / 2, 0.0f, 0.0f);

			//3st leg joint...
			glColor3ubv(leg_joint_color.toArray());
			glutSolidSphere(ss, 30, 30);
			glTranslatef(ss*footplate_side, -ss*footplate_side, 0.0f);
			glRotateXYZ(leg_joint_angle[2]);
			
			//.....

			
			glTranslatef(ss*footplate_size[0], 0.0f, 0.0f);

			glPushMatrix();  //footplate
			{
				glColor3ubv(footplate_color.toArray());
				glScalef(footplate_size[0], footplate_size[1], footplate_size[2]);
				glutMySolidCylinder(ss, ss, 30, 30, 1);
			}
			glPopMatrix();
			
			GLfloat coe = size * toe_joint_size;
			
			/*
			glPushMatrix();  //1st toe
			{
				glRotateXYZ(0.0f, toe_tilt[0], 0.0f);
				glTranslatef(ss*footplate_size[0] * toe_dist[0], 0.0f, 0.0f);
				glRotateXYZ(0.0f, -toe_tilt[0], 0.0f);
				
				//os toe...
				glColor3ubv(footplate_color.toArray());
				glTranslatef(coe*toe_length[0] / 2,0.0f , 0.0f);
				glutMySolidCylinder(coe*toe_width[0], coe*toe_length[0], 30, 30,0);
				//.....
				glTranslatef(coe*toe_length[0] / 2, 0.0f, 0.0f);
				glTranslatef(coe*toe_side, 0.0f, 0.0f);


				
				//1st joint...
				glColor3ubv(toe_joint_color.toArray());
				glutSolidSphere(coe,30,30);
				//....
				glTranslatef(coe*toe_side, 0.0f, 0.0f);
				glTranslatef(coe*toe_length[1] / 2, 0.0f, 0.0f);

				//1st toe....
				glColor3ubv(toe_color.toArray());
				glutMySolidCylinder(coe*toe_width[1], coe*toe_length[1], 30, 30, 0);
				//....
				glTranslatef(coe*toe_length[1] / 2, 0.0f, 0.0f);
				glTranslatef(coe*toe_side, 0.0f, 0.0f);

				//2st joint....
				glColor3ubv(toe_joint_color.toArray());
				glutSolidSphere(coe, 30, 30);
				//....

				glTranslatef(coe*toe_side, 0.0f, 0.0f);
				glTranslatef(coe*toe_length[2] / 2, 0.0f, 0.0f);

				//2st toe...
				glColor3ubv(toe_color.toArray());
				glutMySolidCone(coe*toe_width[2], coe*toe_length[2], 30, 30, 0);
				//....
				
			}
			glPopMatrix();*/
			/*
			draw_toe(1,3);
			draw_toe(2,7);
			draw_toe(3,11);
			draw_toe(4,15);*/

		}
		glPopMatrix();
	}

	void draw_toe(int f,int c){
		GLfloat ss = size * leg_joint_size;
		GLfloat coe = size * toe_joint_size;
		glPushMatrix();
		{
			glRotateXYZ(0.0f, toe_tilt[f], 0.0f);
			glTranslatef(ss*footplate_size[0] * toe_dist[f], 0.0f, 0.0f);
			glRotateXYZ(0.0f, -toe_tilt[f], 0.0f);

			//os toe...
			glColor3ubv(footplate_color.toArray());
			glTranslatef(coe*toe_length[c] / 2, 0.0f, 0.0f);
			glutMySolidCylinder(coe*toe_width[c], coe*toe_length[c], 30, 30, 0);
			//.....
			glTranslatef(coe*toe_length[c] / 2, 0.0f, 0.0f);
			glTranslatef(coe*toe_side, 0.0f, 0.0f);


			/*
			//1st joint...
			glColor3ubv(toe_joint_color.toArray());
			glutSolidSphere(coe, 30, 30);
			//....
			glTranslatef(coe*toe_side, 0.0f, 0.0f);
			glTranslatef(coe*toe_length[c+1] / 2, 0.0f, 0.0f);

			//1st toe....
			glColor3ubv(toe_color.toArray());
			glutMySolidCylinder(coe*toe_width[c+1], coe*toe_length[c+1], 30, 30, 0);
			//....
			glTranslatef(coe*toe_length[c+1] / 2, 0.0f, 0.0f);
			glTranslatef(coe*toe_side, 0.0f, 0.0f);

			//2st joint....
			glColor3ubv(toe_joint_color.toArray());
			glutSolidSphere(coe, 30, 30);
			//....

			glTranslatef(coe*toe_side, 0.0f, 0.0f);
			glTranslatef(coe*toe_length[c+2] / 2, 0.0f, 0.0f);

			//2st toe...
			glColor3ubv(toe_color.toArray());
			glutMySolidCylinder(coe*toe_width[c+2], coe*toe_length[c+2], 30, 30, 0);
			//....
			glTranslatef(coe*toe_length[c + 2] / 2, 0.0f, 0.0f);
			glTranslatef(coe*toe_side, 0.0f, 0.0f);

			//2st joint....
			glColor3ubv(toe_joint_color.toArray());
			glutSolidSphere(coe, 30, 30);
			//....

			glTranslatef(coe*toe_side, 0.0f, 0.0f);
			glTranslatef(coe*toe_length[c + 3] / 2, 0.0f, 0.0f);

			//3st toe...
			glColor3ubv(toe_color.toArray());
			glutMySolidCone(coe*toe_width[c + 3], coe*toe_length[c + 3], 30, 30, 0);
			//....

			*/
		}
		glPopMatrix();
	}
};