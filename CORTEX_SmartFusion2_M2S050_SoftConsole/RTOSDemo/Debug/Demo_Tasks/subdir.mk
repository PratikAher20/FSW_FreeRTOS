################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demo_Tasks/demo_tasks.c 

OBJS += \
./Demo_Tasks/demo_tasks.o 

C_DEPS += \
./Demo_Tasks/demo_tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Demo_Tasks/%.o: ../Demo_Tasks/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\include" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\FreeRTOS-Source\portable\GCC\ARM_CM3" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo" -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS\startup_gcc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_gpio -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_hpdma -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_nvm -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_rtc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_sys_services -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_timer -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_uart -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config\sys_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -Wextra -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


