################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LM35/LM35.c 

OBJS += \
./HAL/LM35/LM35.o 

C_DEPS += \
./HAL/LM35/LM35.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LM35/%.o HAL/LM35/%.su HAL/LM35/%.cyclo: ../HAL/LM35/%.c HAL/LM35/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Smart Egat/Temperaturesensor/HAL/LM35" -I"F:/Smart Egat/Temperaturesensor/HAL/LDR" -I"F:/Smart Egat/Temperaturesensor/HAL/NODE" -I"F:/Smart Egat/Temperaturesensor/HAL/JsonHandling" -I"F:/Smart Egat/Temperaturesensor/HAL/Relay" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-LM35

clean-HAL-2f-LM35:
	-$(RM) ./HAL/LM35/LM35.cyclo ./HAL/LM35/LM35.d ./HAL/LM35/LM35.o ./HAL/LM35/LM35.su

.PHONY: clean-HAL-2f-LM35

