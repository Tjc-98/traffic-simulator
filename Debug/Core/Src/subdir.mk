################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/595_chip_control.c \
../Core/Src/gpio.c \
../Core/Src/io_shield_func.c \
../Core/Src/io_shield_func_tests.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/task1.c \
../Core/Src/task1_tests.c \
../Core/Src/task2.c \
../Core/Src/task2_tests.c \
../Core/Src/tasks_common_func.c 

OBJS += \
./Core/Src/595_chip_control.o \
./Core/Src/gpio.o \
./Core/Src/io_shield_func.o \
./Core/Src/io_shield_func_tests.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/task1.o \
./Core/Src/task1_tests.o \
./Core/Src/task2.o \
./Core/Src/task2_tests.o \
./Core/Src/tasks_common_func.o 

C_DEPS += \
./Core/Src/595_chip_control.d \
./Core/Src/gpio.d \
./Core/Src/io_shield_func.d \
./Core/Src/io_shield_func_tests.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/task1.d \
./Core/Src/task1_tests.d \
./Core/Src/task2.d \
./Core/Src/task2_tests.d \
./Core/Src/tasks_common_func.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/595_chip_control.cyclo ./Core/Src/595_chip_control.d ./Core/Src/595_chip_control.o ./Core/Src/595_chip_control.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/io_shield_func.cyclo ./Core/Src/io_shield_func.d ./Core/Src/io_shield_func.o ./Core/Src/io_shield_func.su ./Core/Src/io_shield_func_tests.cyclo ./Core/Src/io_shield_func_tests.d ./Core/Src/io_shield_func_tests.o ./Core/Src/io_shield_func_tests.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/task1.cyclo ./Core/Src/task1.d ./Core/Src/task1.o ./Core/Src/task1.su ./Core/Src/task1_tests.cyclo ./Core/Src/task1_tests.d ./Core/Src/task1_tests.o ./Core/Src/task1_tests.su ./Core/Src/task2.cyclo ./Core/Src/task2.d ./Core/Src/task2.o ./Core/Src/task2.su ./Core/Src/task2_tests.cyclo ./Core/Src/task2_tests.d ./Core/Src/task2_tests.o ./Core/Src/task2_tests.su ./Core/Src/tasks_common_func.cyclo ./Core/Src/tasks_common_func.d ./Core/Src/tasks_common_func.o ./Core/Src/tasks_common_func.su

.PHONY: clean-Core-2f-Src

