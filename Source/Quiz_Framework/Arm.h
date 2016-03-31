#pragma once

class Arm{
public:
	GLfloat size; //total size
	GLfloat arm_joint_size; //arm joint radix (size%)
	GLfloat arm_width, arm_Length; //(size%)
	
	GLfloat arm_side;  //distance between joint and arm (size%)
	Vector3<GLubyte> arm_joint_color;
	Vector3<GLubyte> arm_color;

	Vector3<GLfloat> arm_joint_angle[3];  //three joints' angle (f)

	GLfloat hand_size; //hand radix (size%)
	GLfloat hand_height; //hand height (size%)
	GLfloat hand_side;
	Vector3<GLubyte> hand_color;

	GLfloat hand_back_size;
	GLfloat hand_back_side;

	GLfloat finger_joint_size; //finger joint radix (size%)
	GLfloat finger_width; //(finger_joint_size%)
	GLfloat finger_Length[14];

	GLfloat finger_side; //distance between joint and finger (finger_joint_size%)
	GLfloat finger_dist[5]; //finger position (angle)
	Vector3<GLubyte> finger_joint_color;
	Vector3<GLubyte> finger_color;

	Vector3<GLfloat> finger_joint_angle[14];

	//light

	GLfloat hand_back_specular[4];
	GLfloat hand_back_shiness;

	GLfloat Mirrer_Matrix[16];   //use Merrir Matrix to draw another hand
	int mirrerX, mirrerY, mirrerZ;

	Arm(int cx = 1,int cy = 1, int cz = 1){
		mirrerX = cx;
		mirrerY = cy;
		mirrerZ = cz;
		init();
	}

	void init(){
		size = 0.7f;
		arm_joint_size = 1.0f;
		arm_width = 0.8f;  arm_Length = 4.0f;
		arm_side = (GLfloat)1 / 10;

		hand_size = 1.1f;
		hand_height = 0.9f;
		hand_side = (GLfloat)9 / 10;

		hand_back_size = 0.6f;

		finger_joint_size = 0.2f;
		finger_width = 0.8f;
		finger_side = (GLfloat)1 / 10;

		finger_dist[0] = -90.0f;
		finger_dist[1] = -30.0f;
		finger_dist[2] = 0.0f;
		finger_dist[3] = 30.0f;
		finger_dist[4] = 55.0f;

		GLfloat gm[16] = { (GLfloat)mirrerX, 0, 0, 0, 0, (GLfloat)mirrerY, 0, 0, 0, 0, (GLfloat)mirrerZ, 0, 0, 0, 0, 1 };
		for (int i = 0; i < 16; i++)Mirrer_Matrix[i] = gm[i];  //init Mirrer Matrix

		init_color();
		init_pos();
	}

	void init_pos(){
		GLfloat fgl[14] = {
			4.5f, 5.0f,   //1st
			5.6f, 5.3f, 4.0f,  //2nd
			5.8f, 5.6f, 4.2f,  //3rd
			5.6f, 5.4f, 4.1f,  //4th
			4.2f, 4.0f, 3.8f  //5th
		};   for (int i = 0; i < 14; i++)finger_Length[i] = fgl[i];

		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(-30, 0, -50),
			Vector3<GLfloat>(-30, 0, -30),
			Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(0, -45, -40), Vector3<GLfloat>(0, 50, -10),
			Vector3<GLfloat>(0, -10, -5), Vector3<GLfloat>(0, 0, -30), Vector3<GLfloat>(0, 0, -30),
			Vector3<GLfloat>(0, 0, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 10, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 30, -10), Vector3<GLfloat>(0, 0, -40), Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void init_color(){
		arm_joint_color = Vector3<GLubyte>(102, 221, 0);
		arm_color = Vector3<GLubyte>(34, 0, 136);
		hand_color = Vector3<GLubyte>(34, 0, 136);
		finger_joint_color = Vector3<GLubyte>(255, 136, 0);
		finger_color = Vector3<GLubyte>(68, 68, 68);
	}

	void walk_up(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(-10.0f, 0.0f, -75.0f),
			Vector3<GLfloat>(0.0f, -50.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(0, -45, -40), Vector3<GLfloat>(0, 50, -10),
			Vector3<GLfloat>(0, -10, -5), Vector3<GLfloat>(0, 0, -30), Vector3<GLfloat>(0, 0, -30),
			Vector3<GLfloat>(0, 0, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 10, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 30, -10), Vector3<GLfloat>(0, 0, -40), Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void walk_down(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(15.0f, 0.0f, -80.0f),
			Vector3<GLfloat>(0.0f, -10.0f, 0.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(0, -45, -40), Vector3<GLfloat>(0, 50, -10),
			Vector3<GLfloat>(0, -10, -5), Vector3<GLfloat>(0, 0, -30), Vector3<GLfloat>(0, 0, -30),
			Vector3<GLfloat>(0, 0, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 10, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 30, -10), Vector3<GLfloat>(0, 0, -40), Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void run_down_back(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(45.0f, 0.0f, -50.0f),
			Vector3<GLfloat>(0.0f, -120.0f, 5.0f),
			Vector3<GLfloat>(0.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(90, -45, 0), Vector3<GLfloat>(0, 0, -45),
			Vector3<GLfloat>(0, 0, -80), Vector3<GLfloat>(0, 0, -105), Vector3<GLfloat>(0, 0, -75),
			Vector3<GLfloat>(0, 0, -90), Vector3<GLfloat>(0, 0, -98), Vector3<GLfloat>(0, 0, -70),
			Vector3<GLfloat>(0, 10, -85), Vector3<GLfloat>(0, 0, -95), Vector3<GLfloat>(0, 0, -100),
			Vector3<GLfloat>(0, 30, -90), Vector3<GLfloat>(20, 0, -90), Vector3<GLfloat>(0, 0, -95)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void run_down_front(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(7.5f, 0.0f, -55.0f),
			Vector3<GLfloat>(0.0f, -122.5f, -22.5f),
			Vector3<GLfloat>(-25.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

			Vector3<GLfloat> fing_ang[14] = {
				Vector3<GLfloat>(90, -45, 0), Vector3<GLfloat>(0, 0, -45),
				Vector3<GLfloat>(0, 0, -80), Vector3<GLfloat>(0, 0, -105), Vector3<GLfloat>(0, 0, -75),
				Vector3<GLfloat>(0, 0, -90), Vector3<GLfloat>(0, 0, -98), Vector3<GLfloat>(0, 0, -70),
				Vector3<GLfloat>(0, 10, -85), Vector3<GLfloat>(0, 0, -95), Vector3<GLfloat>(0, 0, -100),
				Vector3<GLfloat>(0, 30, -90), Vector3<GLfloat>(20, 0, -90), Vector3<GLfloat>(0, 0, -95)
			};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void run_up_back(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(-30.0f, 0.0f, -60.0f),
			Vector3<GLfloat>(0.0f, -125.0f, -50.0f),
			Vector3<GLfloat>(-50.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(90, -45, 0), Vector3<GLfloat>(0, 0, -45),
			Vector3<GLfloat>(0, 0, -80), Vector3<GLfloat>(0, 0, -105), Vector3<GLfloat>(0, 0, -75),
			Vector3<GLfloat>(0, 0, -90), Vector3<GLfloat>(0, 0, -98), Vector3<GLfloat>(0, 0, -70),
			Vector3<GLfloat>(0, 10, -85), Vector3<GLfloat>(0, 0, -95), Vector3<GLfloat>(0, 0, -100),
			Vector3<GLfloat>(0, 30, -90), Vector3<GLfloat>(20, 0, -90), Vector3<GLfloat>(0, 0, -95)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void run_up_front(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(7.5f, 0.0f, -55.0f),
			Vector3<GLfloat>(0.0f, -122.5f, -22.5f),
			Vector3<GLfloat>(-25.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

			Vector3<GLfloat> fing_ang[14] = {
				Vector3<GLfloat>(90, -45, 0), Vector3<GLfloat>(0, 0, -45),
				Vector3<GLfloat>(0, 0, -80), Vector3<GLfloat>(0, 0, -105), Vector3<GLfloat>(0, 0, -75),
				Vector3<GLfloat>(0, 0, -90), Vector3<GLfloat>(0, 0, -98), Vector3<GLfloat>(0, 0, -70),
				Vector3<GLfloat>(0, 10, -85), Vector3<GLfloat>(0, 0, -95), Vector3<GLfloat>(0, 0, -100),
				Vector3<GLfloat>(0, 30, -90), Vector3<GLfloat>(20, 0, -90), Vector3<GLfloat>(0, 0, -95)
			};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void patronum_stay_right(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(-30.0f, 0.0f, -70.0f),
			Vector3<GLfloat>(60.0f, -100.0f, 10.0f),
			Vector3<GLfloat>(30.0f, 0.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(0, -45, -40), Vector3<GLfloat>(0, 50, -10),
			Vector3<GLfloat>(0, -10, -5), Vector3<GLfloat>(0, 0, -30), Vector3<GLfloat>(0, 0, -30),
			Vector3<GLfloat>(0, 0, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 10, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 30, -10), Vector3<GLfloat>(0, 0, -40), Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void patronum_stay_left(){
		Vector3<GLfloat> arm_ang[3] = {
			Vector3<GLfloat>(7.5f, 0.0f, -70.0f),
			Vector3<GLfloat>(0.0f, -80.0f, -30.0f),
			Vector3<GLfloat>(-100.0f, 30.0f, 0.0f)
		};  for (int i = 0; i < 3; i++)arm_joint_angle[i] = arm_ang[i];

		Vector3<GLfloat> fing_ang[14] = {
			Vector3<GLfloat>(0, -45, -40), Vector3<GLfloat>(0, 50, -10),
			Vector3<GLfloat>(0, -10, -5), Vector3<GLfloat>(0, 0, -30), Vector3<GLfloat>(0, 0, -30),
			Vector3<GLfloat>(0, 0, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 10, -10), Vector3<GLfloat>(0, 0, -35), Vector3<GLfloat>(0, 0, -32),
			Vector3<GLfloat>(0, 30, -10), Vector3<GLfloat>(0, 0, -40), Vector3<GLfloat>(0, 0, -30)
		};  for (int i = 0; i < 14; i++)finger_joint_angle[i] = fing_ang[i];
	}

	void interpolation(Arm & narm, int f, int n){
		for (int i = 0; i < 14; i++){
			for (int j = 0; j < 3; j++){
				finger_joint_angle[i][j] += (GLfloat)(narm.finger_joint_angle[i][j] - finger_joint_angle[i][j]) /(GLfloat)(f - n);
			}
		}

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				arm_joint_angle[i][j] += (GLfloat)(narm.arm_joint_angle[i][j] - arm_joint_angle[i][j]) /(GLfloat)(f - n);
			}
		}
	}

	void draw(void){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			
			glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
			glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

			glMultMatrixf(Mirrer_Matrix);
			// first arm joint
			glColor3ubv(arm_joint_color.toArray());
			glutSolidSphere(size*arm_joint_size, 30, 30);
			glRotateXYZ(arm_joint_angle[0]);
			//.....

			glTranslatef(size *arm_side, 0, 0);
			glTranslatef(size*arm_Length / 2, 0, 0);

			//upper arm
			glPushMatrix(); 
			{
				glColor3ubv(arm_color.toArray());
				glutMySolidCylinder(size*arm_width, size*arm_Length, 30, 30, 0);
			}
			glPopMatrix();
			//.....

			glTranslatef(size*arm_Length / 2, 0, 0);
			glTranslatef(size*arm_side, 0, 0);

			// second arm joint
			glColor3ubv(arm_joint_color.toArray());
			glutSolidSphere(size*arm_joint_size, 30, 30);
			glRotateXYZ(arm_joint_angle[1]);
			//.....

			glTranslatef(size*arm_side, 0, 0);
			glTranslatef(size*arm_Length / 2, 0, 0);

			//lower arm
			glPushMatrix();
			{
				glColor3ubv(arm_color.toArray());
				glutMySolidCylinder(size*arm_width, size*arm_Length, 30, 30, 0);
			}
			glPopMatrix();
			//.....

			glTranslatef(size*arm_Length/2, 0, 0);
			glTranslatef(size*arm_side, 0, 0);

			// third arm joint
			glColor3ubv(arm_joint_color.toArray());
			glutSolidSphere(size*arm_joint_size, 30, 30);
			glRotateXYZ(arm_joint_angle[2]);
			//.....

			//hand
			glColor3ubv(hand_color.toArray());
			glTranslatef(size*hand_side, 0, 0);
			glTranslatef(size*hand_size / 2, 0, 0);
			glutMySolidCylinder(size * hand_size, size * hand_height, 30, 30, 1);
			//.....

			glPushMatrix();
			{
				glTranslatef(0, size*hand_height / 2, 0);
				glColor3ubv(arm_joint_color.toArray());
				glutMySolidSphere(size*hand_back_size, size*hand_back_size*0.5f, size*hand_back_size, 30, 30);
			}
			glPopMatrix();

			// first finger
			glPushMatrix();
			{
				glRotateXYZ(0.0f, finger_dist[0], 0.0f);
				glTranslatef(size*hand_size, 0.0f, 0.0f);
				glRotateXYZ(0.0f, -finger_dist[0], 0.0f);
				glRotateXYZ(finger_joint_angle[0]);

				//first joint
				glColor3ubv(finger_joint_color.toArray());
				glutSolidSphere(size * finger_joint_size,30,30);
				
				glTranslatef(size*finger_joint_size*finger_side, 0, 0);
				glTranslatef(size*finger_joint_size * finger_Length[0]/2, 0, 0);

				//finger
				glColor3ubv(finger_color.toArray());
				glutMySolidCylinder(size*finger_joint_size*finger_width, size*finger_joint_size*finger_Length[0],30,30,0);

				glTranslatef(size*finger_joint_size*finger_side, 0, 0);
				glTranslatef(size*finger_joint_size * finger_Length[0] / 2, 0, 0);

				//second joint
				glColor3ubv(finger_joint_color.toArray());
				glutSolidSphere(size * finger_joint_size, 30, 30);
				glRotateXYZ(finger_joint_angle[1]);

				glTranslatef(size*finger_joint_size*finger_side, 0, 0);
				glTranslatef(size*finger_joint_size * finger_Length[1] / 2, 0, 0);

				//finger
				glColor3ubv(finger_color.toArray());
				glutMySolidCone(size*finger_joint_size*finger_width, size*finger_joint_size*finger_Length[1], 30, 30, 0);

			}
			glPopMatrix();

			draw_finger(finger_dist[1], 1); //second finger
			draw_finger(finger_dist[2], 2); //third finger
			draw_finger(finger_dist[3], 3); //4th finger
			draw_finger(finger_dist[4], 4); // 5th finger
		}
		glPopMatrix();
	}

	void draw_finger(GLfloat ang, int n){
		glPushMatrix();
		{
			glRotateXYZ(0.0f, ang, 0.0f);
			glTranslatef(size*hand_size, 0.0f, 0.0f);
			glRotateXYZ(0.0f, -ang, 0.0f);
			glRotateXYZ(finger_joint_angle[ 2+(n-1)*3 ]);

			//first joint
			glColor3ubv(finger_joint_color.toArray());
			glutSolidSphere(size * finger_joint_size, 30, 30);

			glTranslatef(size*finger_joint_size*finger_side, 0, 0);
			glTranslatef(size*finger_joint_size * finger_Length[2+(n-1)*3] / 2, 0, 0);

			//finger
			glColor3ubv(finger_color.toArray());
			glutMySolidCylinder(size*finger_joint_size*finger_width, size*finger_joint_size*finger_Length[2 + (n - 1) * 3], 30, 30, 0);

			glTranslatef(size*finger_joint_size*finger_side, 0, 0);
			glTranslatef(size*finger_joint_size * finger_Length[2 + (n - 1) * 3] / 2, 0, 0);

			//second joint
			glColor3ubv(finger_joint_color.toArray());
			glutSolidSphere(size * finger_joint_size, 30, 30);
			glRotateXYZ(finger_joint_angle[2 + (n - 1) * 3+1]);

			glTranslatef(size*finger_joint_size*finger_side, 0, 0);
			glTranslatef(size*finger_joint_size * finger_Length[2 + (n - 1) * 3+1] / 2, 0, 0);

			//finger
			glColor3ubv(finger_color.toArray());
			glutMySolidCylinder(size*finger_joint_size*finger_width, size*finger_joint_size*finger_Length[2 + (n - 1) * 3+1], 30, 30, 0);

			glTranslatef(size*finger_joint_size*finger_side, 0, 0);
			glTranslatef(size*finger_joint_size * finger_Length[2 + (n - 1) * 3+1] / 2, 0, 0);

			//second joint
			glColor3ubv(finger_joint_color.toArray());
			glutSolidSphere(size * finger_joint_size, 30, 30);
			glRotateXYZ(finger_joint_angle[2 + (n - 1) * 3+2]);

			glTranslatef(size*finger_joint_size*finger_side, 0, 0);
			glTranslatef(size*finger_joint_size * finger_Length[2 + (n - 1) * 3+2] / 2, 0, 0);

			//finger
			glColor3ubv(finger_color.toArray());
			glutMySolidCone(size*finger_joint_size*finger_width, size*finger_joint_size*finger_Length[2 + (n - 1) * 3+2], 30, 30, 0);

		}
		glPopMatrix();
	}
};