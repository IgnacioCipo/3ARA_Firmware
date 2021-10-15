################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../APP/Src/Task/PID/PID.cpp \
../APP/Src/Task/PID/PID1.cpp \
../APP/Src/Task/PID/PID2.cpp \
../APP/Src/Task/PID/PID3.cpp 

OBJS += \
./APP/Src/Task/PID/PID.o \
./APP/Src/Task/PID/PID1.o \
./APP/Src/Task/PID/PID2.o \
./APP/Src/Task/PID/PID3.o 

CPP_DEPS += \
./APP/Src/Task/PID/PID.d \
./APP/Src/Task/PID/PID1.d \
./APP/Src/Task/PID/PID2.d \
./APP/Src/Task/PID/PID3.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Src/Task/PID/PID.o: ../APP/Src/Task/PID/PID.cpp APP/Src/Task/PID/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/APP/Inc" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"APP/Src/Task/PID/PID.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
APP/Src/Task/PID/PID1.o: ../APP/Src/Task/PID/PID1.cpp APP/Src/Task/PID/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/APP/Inc" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"APP/Src/Task/PID/PID1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
APP/Src/Task/PID/PID2.o: ../APP/Src/Task/PID/PID2.cpp APP/Src/Task/PID/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/APP/Inc" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"APP/Src/Task/PID/PID2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
APP/Src/Task/PID/PID3.o: ../APP/Src/Task/PID/PID3.cpp APP/Src/Task/PID/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/APP/Inc" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP" -I"G:/Repositorios/3ARA_Firmware/3ARA-Firmware/Drivers/CMSIS/DSP/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"APP/Src/Task/PID/PID3.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

