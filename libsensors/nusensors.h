/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_SENSORS_H
#define ANDROID_SENSORS_H

#include <stdint.h>
#include <errno.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <linux/input.h>

#include <hardware/hardware.h>
#include <hardware/sensors.h>

#include "mma8452_kernel.h"            // 声明驱动为 HAL 提供的功能接口. 应该用更加抽象的文件名.


//#define ENABLE_DEBUG_LOG
#include "akm8975/custom_log.h"

/*
sensor hal v1.1 add pressure and temperature support 2013-2-27
sensor hal  v1.2 add akm8963 support 2013-3-10
sensor hal  v1.3 modify akm device name from akmd8975 to akmd 2013-3-14
sensor hal  v1.4 add akm09911 support 2013-3-21
sensor hal  v1.5 add angle calculation and calibration of gsensor support 2013-9-1
*/

#define SENSOR_VERSION_AND_TIME  "sensor hal  v1.5 add angle calculation and calibration of gsensor support 2013-9-1"


#ifndef M_PI
#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h
#endif


__BEGIN_DECLS

/*****************************************************************************/

int init_nusensors(hw_module_t const* module, hw_device_t** device);

/*****************************************************************************/

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define ID_A	(0)
#define ID_M	(1)
#define ID_O	(2)

/*****************************************************************************/

#define MMA_DEVICE_NAME     GSENSOR_DEV_PATH
/** akm sensor(M 和 O sensor) 的控制设备文件路径. */
#define AKM_DEVICE_NAME     "/dev/compass"


#define EVENT_TYPE_ACCEL_X          ABS_X
#define EVENT_TYPE_ACCEL_Y          ABS_Y
#define EVENT_TYPE_ACCEL_Z          ABS_Z
#define EVENT_TYPE_ACCEL_STATUS     ABS_WHEEL

#define EVENT_TYPE_YAW              ABS_RX
#define EVENT_TYPE_PITCH            ABS_RY
#define EVENT_TYPE_ROLL             ABS_RZ
#define EVENT_TYPE_ORIENT_STATUS    ABS_RUDDER

#define EVENT_TYPE_MAGV_X           ABS_HAT0X
#define EVENT_TYPE_MAGV_Y           ABS_HAT0Y
#define EVENT_TYPE_MAGV_Z           ABS_BRAKE
#define EVENT_TYPE_MAGV_STATUS      ABS_HAT1X


/** 表征相同的 加速度物理量的时候, Android 上层使用的 数值 和 sensor 数据设备送出的 数值 的 比值. */
#define ACCELERATION_RATIO_ANDROID_TO_HW        (9.80665f / 1000000)

/*-------------------------------------------------------*/
// 720 LSG = 1G
#define LSG                         (720.0f)


// conversion of acceleration data to SI units (m/s^2)
#define CONVERT_A                   (GRAVITY_EARTH / LSG)
#define CONVERT_A_X                 (CONVERT_A)
#define CONVERT_A_Y                 (CONVERT_A)
#define CONVERT_A_Z                 (CONVERT_A)

// conversion of magnetic data (for AK8975) to uT units
#define CONVERT_M                   (1.0f*0.06f)
#define CONVERT_M_X                 (CONVERT_M)
#define CONVERT_M_Y                 (CONVERT_M)
#define CONVERT_M_Z                 (CONVERT_M)

// conversion of orientation data to degree units
#define CONVERT_O                   (1.0f/64.0f)
#define CONVERT_O_A                 (CONVERT_O)
#define CONVERT_O_P                 (CONVERT_O)
#define CONVERT_O_R                 (CONVERT_O)

#define CONVERT_B                   (1.0f/100.0f)

#define SENSOR_STATE_MASK           (0x7FFF)

/*****************************************************************************/

// #define D_ENTER()	D("Entered.")

#define D_ENTER(...)    D("Entered : " __VA_ARGS__)

#define D_EXIT(result)	D("about to Exit : " #result " = %d", result)

/*****************************************************************************/


__END_DECLS

#endif  // ANDROID_SENSORS_H
