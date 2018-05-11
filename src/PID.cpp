#include "PID.h"

#include <iostream>
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double KpInit, double KiInit, double KdInit){
	Kp = KpInit;
	Ki = KiInit;
	Kd = KdInit;
	max_steering =  1.0;
	min_steering = -1.0;
	cte_int = 0.0;
	is_initialized = true;
	is_first_pid_loop = false;
}

double PID::ComputeSteering(double cte){
	if (is_first_pid_loop){
		cte_prev = cte;
		is_first_pid_loop = false;
	}
	double cte_diff = cte - cte_prev;
	cte_int += cte;
	//compute PID steering
	steering = - Kp * cte - Kd * cte_diff - Ki * cte_int;
	cte_prev = cte;
	if (steering < min_steering){
		steering = min_steering;
	}else if (steering > max_steering){
		steering = max_steering;
	}
	return steering;
}



