################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s16.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s16.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s4.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8.c \
../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.c 

C_DEPS += \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s16.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s16.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s4.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8.d \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.d 

OBJS += \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s16.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_batch_matmul_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s16.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s4.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8.o \
./ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.o 

SREC += \
wode_ra8p1_CPU0.srec 

MAP += \
wode_ra8p1_CPU0.map 


# Each subdirectory must supply rules for building sources it contributes
ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/%.o: ../ra/arm/CMSIS-NN/Source/FullyConnectedFunctions/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra_gen" -I"." -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra_cfg/fsp_cfg/bsp" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra_cfg/fsp_cfg" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra_cfg/aws" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/src" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/fsp/inc" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/fsp/inc/api" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/fsp/inc/instances" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/fsp/src/rm_freertos_port" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-NN/Include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-NN" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-software/lib/layer_by_layer_profiler/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-software/lib/ethosu_monitor/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-software/lib/ethosu_profiler/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-driver/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/fsp/src/rm_ethosu" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/flatbuffers/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-DSP/PrivateInclude" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-DSP/Include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ruy" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/gemmlowp" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/tflite-micro" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-software/lib/crc/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/npu/ethos-u-core-software/lib/arm_profiler/include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-View/EventRecorder/Include" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/arm/CMSIS-View/EventRecorder/Config" -I"D:/Renesas_workspace/e2s_work/wode_ra8p1_CPU0/ra/tes/dave2d/inc" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -w -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

