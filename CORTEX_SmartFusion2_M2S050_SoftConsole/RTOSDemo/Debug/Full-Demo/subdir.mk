################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Full-Demo/File-releated-CLI-commands.c \
../Full-Demo/File-system-demo.c \
../Full-Demo/Sample-CLI-commands.c \
../Full-Demo/UARTCommandConsole.c \
../Full-Demo/main_full.c 

OBJS += \
./Full-Demo/File-releated-CLI-commands.o \
./Full-Demo/File-system-demo.o \
./Full-Demo/Sample-CLI-commands.o \
./Full-Demo/UARTCommandConsole.o \
./Full-Demo/main_full.o 

C_DEPS += \
./Full-Demo/File-releated-CLI-commands.d \
./Full-Demo/File-system-demo.d \
./Full-Demo/Sample-CLI-commands.d \
./Full-Demo/UARTCommandConsole.d \
./Full-Demo/main_full.d 


# Each subdirectory must supply rules for building sources it contributes
Full-Demo/%.o: ../Full-Demo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\FreeRTOS-Plus-CLI-Source" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\FreeRTOS-Plus-FAT-SL-Source\api" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Full-Demo\Common-Demo-Source\include" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\include" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\portable\GCC\ARM_CM3" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo" -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS\startup_gcc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_gpio -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_hpdma -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_nvm -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_rtc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_sys_services -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_timer -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_uart -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config\sys_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS_SmartFusion2_Demo\FreeRTOS\Demo\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -Wextra -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


