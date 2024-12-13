################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER/Timer.c 

OBJS += \
./MCAL/TIMER/Timer.o 

C_DEPS += \
./MCAL/TIMER/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER/%.o MCAL/TIMER/%.su MCAL/TIMER/%.cyclo: ../MCAL/TIMER/%.c MCAL/TIMER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Smart Egat/Temperaturesensor/HAL/LM35" -I"F:/Smart Egat/Temperaturesensor/HAL/LDR" -I"F:/Smart Egat/Temperaturesensor/HAL/NODE" -I"F:/Smart Egat/Temperaturesensor/HAL/JsonHandling" -I"F:/Smart Egat/Temperaturesensor/HAL/Relay" -I"F:/Smart Egat/Temperaturesensor/MCAL/TIMER" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-TIMER

clean-MCAL-2f-TIMER:
	-$(RM) ./MCAL/TIMER/Timer.cyclo ./MCAL/TIMER/Timer.d ./MCAL/TIMER/Timer.o ./MCAL/TIMER/Timer.su

.PHONY: clean-MCAL-2f-TIMER
