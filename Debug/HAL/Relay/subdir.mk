################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Relay/RELAY.c 

OBJS += \
./HAL/Relay/RELAY.o 

C_DEPS += \
./HAL/Relay/RELAY.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Relay/%.o HAL/Relay/%.su HAL/Relay/%.cyclo: ../HAL/Relay/%.c HAL/Relay/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Smart Egat/Temperaturesensor/HAL/LM35" -I"F:/Smart Egat/Temperaturesensor/HAL/LDR" -I"F:/Smart Egat/Temperaturesensor/HAL/NODE" -I"F:/Smart Egat/Temperaturesensor/HAL/JsonHandling" -I"F:/Smart Egat/Temperaturesensor/HAL/Relay" -I"F:/Smart Egat/Temperaturesensor/MCAL/TIMER" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Relay

clean-HAL-2f-Relay:
	-$(RM) ./HAL/Relay/RELAY.cyclo ./HAL/Relay/RELAY.d ./HAL/Relay/RELAY.o ./HAL/Relay/RELAY.su

.PHONY: clean-HAL-2f-Relay

