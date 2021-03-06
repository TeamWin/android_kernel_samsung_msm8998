/*
 * Copyright (C) 2013 Samsung Electronics. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef FINGERPRINT_H_
#define FINGERPRINT_H_

#include <linux/clk.h>

/* fingerprint debug timer */
#define FPSENSOR_DEBUG_TIMER_SEC (10 * HZ)

/* For Sensor Type Check */
enum {
	SENSOR_UNKNOWN = -1,
	SENSOR_FAILED,
	SENSOR_VIPER,
	SENSOR_RAPTOR,
	SENSOR_EGIS,
	SENSOR_VIPER_WOG,
	SENSOR_NAMSAN,
};

#define SENSOR_STATUS_SIZE 7
static char sensor_status[SENSOR_STATUS_SIZE][10] = {"unknown", "failed",
	"viper", "raptor", "egis", "viper_wog", "namsan"};

/* For Finger Detect Mode */
enum {
	DETECT_NORMAL = 0,
	DETECT_ADM,			/* Always on Detect Mode */
};

#ifdef CONFIG_SENSORS_FINGERPRINT_DUALIZATION
extern int FP_CHECK; /* extern variable */
#endif

/* using for awake the samsung FP daemon */
extern bool fp_lockscreen_mode;
#ifdef CONFIG_SENSORS_FP_LOCKSCREEN_MODE
/* input/Keyboard/gpio_keys.c */
extern bool wakeup_by_key(void);
/* export variable for signaling */
EXPORT_SYMBOL(fp_lockscreen_mode);
#endif

#endif
