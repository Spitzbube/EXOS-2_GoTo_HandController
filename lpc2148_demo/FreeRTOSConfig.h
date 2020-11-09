//
//  $Id: FreeRTOSConfig.h 328 2008-11-09 05:00:23Z jcw $
//  $Revision: 328 $
//  $Author: jcw $
//  $Date: 2008-11-09 00:00:23 -0500 (Sun, 09 Nov 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/FreeRTOSConfig.h $
//

/*
	FreeRTOS.org V4.3.1 - Copyright (C) 2003-2007 Richard Barry.

	This file is part of the FreeRTOS.org distribution.

	FreeRTOS.org is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	FreeRTOS.org is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with FreeRTOS.org; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	A special exception to the GPL can be applied should you wish to distribute
	a combined work that includes FreeRTOS.org, without being obliged to provide
	the source code for any proprietary components.  See the licensing section 
	of http://www.FreeRTOS.org for full details of how and when the exception
	can be applied.

	***************************************************************************
	See http://www.FreeRTOS.org for documentation, latest information, license 
	and contact details.  Please ensure to read the configuration and relevant 
	port sections of the online documentation.

	Also see http://www.SafeRTOS.com for an IEC 61508 compliant version along
	with commercial development and support options.
	***************************************************************************
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <lpc214x.h>

//
// Application specific definitions.
//
#define configUSE_PREEMPTION		  1
#define configUSE_IDLE_HOOK			  0
#define configUSE_TICK_HOOK			  0
#ifdef SKYVISION_JOC
#define configCPU_CLOCK_HZ			  ((unsigned portLONG) 48000000) //44236800)	// =11.0592MHz xtal multiplied by 4 using the PLL.
#else
#define configCPU_CLOCK_HZ			  ((unsigned portLONG) 48000000)	// =12.0000MHz xtal multiplied by 4 using the PLL.
#endif
#define configTICK_RATE_HZ			  ((portTickType) 100)
#define configMAX_PRIORITIES		  ((unsigned portBASE_TYPE) 4)
#define configMINIMAL_STACK_SIZE	((unsigned portSHORT) 128)
#define configTOTAL_HEAP_SIZE		  ((size_t) (25 * 1024))
#define configMAX_TASK_NAME_LEN		(8)
#define configUSE_TRACE_FACILITY	1
#define configUSE_16_BIT_TICKS		0
#define configIDLE_SHOULD_YIELD		1

#define configUSE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES 1
#define configUSE_TIMERS              1
#define portTICK_PERIOD_MS            portTICK_RATE_MS
#define INCLUDE_xTaskGetSchedulerState 1
typedef unsigned int StackType_t;

//
//  Co-routine definitions
//
#define configUSE_CO_ROUTINES 		      0
#define configMAX_CO_ROUTINE_PRIORITIES (2)

//
// Set the following definitions to 1 to include the API function, or zero
// to exclude the API function.
//
#define INCLUDE_vTaskPrioritySet		        1
#define INCLUDE_uxTaskPriorityGet		        1
#define INCLUDE_vTaskDelete				          1
#define INCLUDE_vTaskCleanUpResources	      0
#define INCLUDE_vTaskSuspend			          1
#define INCLUDE_vTaskDelayUntil			        1
#define INCLUDE_vTaskDelay				          1
#define INCLUDE_vPortUsedMem                1
#define INCLUDE_uxTaskGetStackHighWaterMark 1

//
//  If CFG_INTONLY enabled in the top-level Makefile, these are remapped to 
//  the integer-only version.  CFG_GPS disables this because it prints
//  the latitude and longtitude as floats.  Remember that if you try to
//  print floats or doubles...
//
#ifdef CFG_INTONLY
#define printf iprintf
#define sprintf siprintf
#define snprintf sniprintf
#endif

#endif /* FREERTOS_CONFIG_H */
