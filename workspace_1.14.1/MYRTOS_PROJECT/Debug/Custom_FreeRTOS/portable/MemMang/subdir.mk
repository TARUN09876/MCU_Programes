################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom_FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./Custom_FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./Custom_FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Custom_FreeRTOS/portable/MemMang/%.o Custom_FreeRTOS/portable/MemMang/%.su Custom_FreeRTOS/portable/MemMang/%.cyclo: ../Custom_FreeRTOS/portable/MemMang/%.c Custom_FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/tarun/STM32CubeIDE/workspace_1.14.1/MYRTOS_PROJECT/Custom_FreeRTOS/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Custom_FreeRTOS-2f-portable-2f-MemMang

clean-Custom_FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./Custom_FreeRTOS/portable/MemMang/heap_4.cyclo ./Custom_FreeRTOS/portable/MemMang/heap_4.d ./Custom_FreeRTOS/portable/MemMang/heap_4.o ./Custom_FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-Custom_FreeRTOS-2f-portable-2f-MemMang

