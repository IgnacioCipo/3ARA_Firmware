#include "cmsis_os.h"
#include "main.h"
#include "tim.h"
#include "arm_math.h"

#define MAX_INTEGRAL_VALUE 5			// Integral limit value


class PID{
	public:
		// Constructor for PID class
		PID(float kp, float kd, float ki, float max_output, float min_output, float update_rate);

		// Function that calcule the value of the PID output
		float updatePID(float setpoint_position, float current_position);

	private:
		float kp_, kd_, ki_, pid_update_seconds;
		float max_integral_limit = 5;
		float min_pid_output_, max_pid_output_;
		float error_, output;
		arm_pid_instance_f32 pid_;
};
