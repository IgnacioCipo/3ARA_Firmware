#include "cmsis_os.h"
#include "main.h"
#include "tim.h"

class PID{
	public:
		// Constructor for PID class
		PID();

		// Function that calcule the value of the PID output
		void executePID(float setpoint_position, float current_position);

	private:
};
