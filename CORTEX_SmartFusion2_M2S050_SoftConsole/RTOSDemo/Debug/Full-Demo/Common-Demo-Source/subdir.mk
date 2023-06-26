################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Full-Demo/Common-Demo-Source/BlockQ.c \
../Full-Demo/Common-Demo-Source/GenQTest.c \
../Full-Demo/Common-Demo-Source/PollQ.c \
../Full-Demo/Common-Demo-Source/blocktim.c \
../Full-Demo/Common-Demo-Source/countsem.c \
../Full-Demo/Common-Demo-Source/death.c \
../Full-Demo/Common-Demo-Source/dynamic.c \
../Full-Demo/Common-Demo-Source/flash_timer.c \
../Full-Demo/Common-Demo-Source/integer.c \
../Full-Demo/Common-Demo-Source/recmutex.c \
../Full-Demo/Common-Demo-Source/semtest.c 

OBJS += \
./Full-Demo/Common-Demo-Source/BlockQ.o \
./Full-Demo/Common-Demo-Source/GenQTest.o \
./Full-Demo/Common-Demo-Source/PollQ.o \
./Full-Demo/Common-Demo-Source/blocktim.o \
./Full-Demo/Common-Demo-Source/countsem.o \
./Full-Demo/Common-Demo-Source/death.o \
./Full-Demo/Common-Demo-Source/dynamic.o \
./Full-Demo/Common-Demo-Source/flash_timer.o \
./Full-Demo/Common-Demo-Source/integer.o \
./Full-Demo/Common-Demo-Source/recmutex.o \
./Full-Demo/Common-Demo-Source/semtest.o 

C_DEPS += \
./Full-Demo/Common-Demo-Source/BlockQ.d \
./Full-Demo/Common-Demo-Source/GenQTest.d \
./Full-Demo/Common-Demo-Source/PollQ.d \
./Full-Demo/Common-Demo-Source/blocktim.d \
./Full-Demo/Common-Demo-Source/countsem.d \
./Full-Demo/Common-Demo-Source/death.d \
./Full-Demo/Common-Demo-Source/dynamic.d \
./Full-Demo/Common-Demo-Source/flash_timer.d \
./Full-Demo/Common-Demo-Source/integer.d \
./Full-Demo/Common-Demo-Source/recmutex.d \
./Full-Demo/Common-Demo-Source/semtest.d 


# Each subdirectory must supply rules for building sources it contributes
Full-Demo/Common-Demo-Source/%.o: ../Full-Demo/Common-Demo-Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\FreeRTOS-Plus-CLI-Source" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\FreeRTOS-Plus-FAT-SL-Source\api" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\Common-Demo-Source\include" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\include" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\portable\GCC\ARM_CM3" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo" -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS\startup_gcc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_gpio -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_hpdma -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_nvm -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_rtc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_sys_services -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_timer -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_uart -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config\sys_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -Wextra -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


