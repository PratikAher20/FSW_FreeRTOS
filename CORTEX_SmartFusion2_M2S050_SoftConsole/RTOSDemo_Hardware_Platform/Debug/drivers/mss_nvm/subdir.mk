################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mss_nvm/mss_nvm.c 

OBJS += \
./drivers/mss_nvm/mss_nvm.o 

C_DEPS += \
./drivers/mss_nvm/mss_nvm.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mss_nvm/%.o: ../drivers/mss_nvm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Tracelyzer\config" -I"C:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo\Tracelyzer\include" -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\CMSIS\startup_gcc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_gpio -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_hpdma -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_nvm -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_rtc -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_sys_services -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_timer -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers\mss_uart -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\drivers_config\sys_config -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3 -IC:\Users\S-SPACE\Desktop\Pratik\FreeRTOS\FreeRTOS_SC_v3.5\FSW_FreeRTOS\CORTEX_SmartFusion2_M2S050_SoftConsole\RTOSDemo_Hardware_Platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


