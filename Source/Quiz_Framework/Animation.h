#pragma once

#define ACTION_WALK_UP 111
#define ACTION_WALK_DOWN 112
#define ACTION_RUN_UP_BACK 121
#define ACTION_RUN_UP_FRONT 122
#define ACTION_RUN_DOWN_BACK 123
#define ACTION_RUN_DOWN_FRONT 124
#define ACTION_PATRONUM_STAY 131
#define ACTION_PATRONUM_BEGIN 132
#define ACTION_PATRONUM_APPEAR 133
#define ACTION_MAGICCIRCLE_DISAPPEAR 134
#define STOP_ACTION 99

class Animation{
public:
	int frame;
	int now;
	bool enable;
	int kind;
	bool animation_disable = 0;
	

	Animation(){ frame = 0; now = 0; }

	int action(){
		if (frame == now)return 0;
		left_arm.interpolation(nleft_arm, frame, now);
		right_arm.interpolation(nright_arm, frame, now);
		left_leg.interpolation(nleft_leg, frame, now);
		right_leg.interpolation(nright_leg, frame, now);
		body.interpolation(nbody_pos_up, nbody_pos_down, nbody_tilt, frame, now, K);
		body.spoon_interpolation(flyingspoon, frame, now);
		magiccircle.interpolation(nmagiccircle, frame, now);
		now++;
		return 1;
	}

	void start(int f, int n){
		frame = f;
		now = n;
		enable = true;
	}

	void walk_up(){
		if (animation_disable)return;
		nleft_arm.walk_up();
		nright_arm.walk_down();
		nleft_leg.walk_down();
		nright_leg.walk_up();

		nbody_pos_up = body.walk_up;
		nbody_pos_down = body.walk_down;
		nbody_tilt = body.walk_tilt;
		K = body.walk_K;

		kind = ACTION_WALK_UP;
	}

	void walk_down(){
		if (animation_disable)return;
		nleft_arm.walk_down();
		nright_arm.walk_up();
		nleft_leg.walk_up();
		nright_leg.walk_down();

		nbody_pos_up = body.walk_up;
		nbody_pos_down = body.walk_down;
		nbody_tilt = body.walk_tilt;
		K = body.walk_K;
		
		kind = ACTION_WALK_DOWN;
	}

	void run_up_back(){
		if (animation_disable)return;
		nleft_arm.run_up_back();
		nright_arm.run_down_back();

		nleft_leg.run_up_back();
		nright_leg.run_down_back();

		nbody_pos_up = body.run_up;
		nbody_pos_down = body.run_down;
		nbody_tilt = body.run_up_tilt;
		K = body.run_K;

		kind = ACTION_RUN_UP_BACK;
	}

	void run_up_front(){
		if (animation_disable)return;
		nleft_arm.run_up_front();
		nright_arm.run_down_front();

		nleft_leg.run_up_front();
		nright_leg.run_down_front();

		nbody_pos_down = body.run_up;
		nbody_pos_up = body.run_down;
		nbody_tilt = body.run_up_tilt;
		K = body.run_K;

		kind = ACTION_RUN_UP_FRONT;
	}

	void run_down_back(){
		if (animation_disable)return;
		nleft_arm.run_down_back();
		nright_arm.run_up_back();

		nleft_leg.run_down_back();
		nright_leg.run_up_back();

		nbody_pos_up = body.run_up;
		nbody_pos_down = body.run_down;
		nbody_tilt = body.run_down_tilt;
		K = body.run_K;

		kind = ACTION_RUN_DOWN_BACK;
	}

	void run_down_front(){
		if (animation_disable)return;
		nleft_arm.run_down_front();
		nright_arm.run_up_front();

		nleft_leg.run_down_front();
		nright_leg.run_up_front();

		nbody_pos_down = body.run_up;
		nbody_pos_up = body.run_down;
		nbody_tilt = body.run_down_tilt;
		K = body.run_K;

		kind = ACTION_RUN_DOWN_FRONT;
	}

	void init_pos(){
		if (animation_disable)return;
		nleft_arm.init_pos();
		nright_arm.init_pos();
		
		nleft_leg.init_pos();
		nright_leg.init_pos();

		nbody_tilt = Vector3<GLfloat>(0,0,0);
		nbody_pos_up = 0.0f;
		nbody_pos_down = 0.0f;

		kind = STOP_ACTION;
	}

	void patronum_stay(){
		nleft_arm.patronum_stay_left();
		nright_arm.patronum_stay_right();

		nleft_leg.init_pos();
		nright_leg.init_pos();

		nbody_tilt = Vector3<GLfloat>(0, 0, 0);
		nbody_pos_up = 0.0f;
		nbody_pos_down = 0.0f;

		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);

		kind = ACTION_PATRONUM_STAY;
	}

	void patronum_begin(){
		nleft_arm.patronum_stay_left();
		nright_arm.patronum_stay_right();

		nleft_leg.init_pos();
		nright_leg.init_pos();

		nbody_tilt = Vector3<GLfloat>(0, 0, 0);
		nbody_pos_up = 0.0f;
		nbody_pos_down = 0.0f;

		magiccircle.enable = 1;
		nmagiccircle.appear();
		kind = ACTION_PATRONUM_BEGIN;
	}

	void patronum_appear(){
		nleft_arm.patronum_stay_left();
		nright_arm.patronum_stay_right();

		nleft_leg.init_pos();
		nright_leg.init_pos();

		body.enable_flying_teaspoon = 1;
		body.appear();
		nbody_tilt = Vector3<GLfloat>(0, 0, 0);
		nbody_pos_up = 0.0f;
		nbody_pos_down = 0.0f;
		
		magiccircle.enable = 1;
		nmagiccircle.appear();

		flyingspoon.init();
		kind = ACTION_PATRONUM_APPEAR;
	}

	void magiccircle_disappear(){
		nleft_arm.patronum_stay_left();
		nright_arm.patronum_stay_right();

		nleft_leg.init_pos();
		nright_leg.init_pos();

		nbody_tilt = Vector3<GLfloat>(0, 0, 0);
		nbody_pos_up = 0.0f;
		nbody_pos_down = 0.0f;

		magiccircle.enable = 1;
		nmagiccircle.disappear();

		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT2);

		kind = ACTION_MAGICCIRCLE_DISAPPEAR;
	}
};