#include "main.h"
#include "tim.h"

class Motor{
	public:
		// Class constructor
		Motor(TIM_HandleTypeDef motor_timer, uint16_t motor_pin_1, uint16_t motor_pin_2);

		void turnLeft(uint32_t duty);
		void turnRight(uint32_t duty);
		void goHomePosition();

	private:

};
