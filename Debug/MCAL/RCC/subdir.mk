################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC/RCC_program.c 

OBJS += \
./MCAL/RCC/RCC_program.o 

C_DEPS += \
./MCAL/RCC/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC/%.o MCAL/RCC/%.su MCAL/RCC/%.cyclo: ../MCAL/RCC/%.c MCAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"F:/Smart Egat/Temperaturesensor/HAL/LM35" -I"F:/Smart Egat/Temperaturesensor/HAL/LDR" -I"F:/Smart Egat/Temperaturesensor/HAL/NODE" -I"F:/Smart Egat/Temperaturesensor/HAL/JsonHandling" -I"F:/Smart Egat/Temperaturesensor/MCAL/RCC" -I"F:/Smart Egat/Temperaturesensor/MCAL/STK" -I"F:/Smart Egat/Temperaturesensor/LIB" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-RCC

clean-MCAL-2f-RCC:
	-$(RM) ./MCAL/RCC/RCC_program.cyclo ./MCAL/RCC/RCC_program.d ./MCAL/RCC/RCC_program.o ./MCAL/RCC/RCC_program.su

.PHONY: clean-MCAL-2f-RCC

