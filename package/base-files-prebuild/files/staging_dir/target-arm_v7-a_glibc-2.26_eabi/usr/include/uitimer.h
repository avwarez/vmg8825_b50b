/** 
 *  @brief		user interface of timer.
 *  @details	user interface of timer.
 *  @author
	- unknown(porting from ZyNOS)
 *  @copyright
.

 
 *  Copyright (C) 2013 ZyXEL Communications, Corp.
 *  All Rights Reserved.
 *
 *  ZyXEL Confidential; 
 *  Protected as an unpublished work, treated as confidential, 
 *  and hold in trust and in strict confidence by receiving party. 
 *  Only the employees who need to know such ZyXEL confidential information 
 *  to carry out the purpose granted under NDA are allowed to access. 
 * 
 *  The computer program listings, specifications and documentation 
 *  herein are the property of ZyXEL Communications, Corp. and shall 
 *  not be reproduced, copied, disclosed, or used in whole or in part 
 *  for any reason without the prior express written permission of 
 *  ZyXEL Communications, Corp. 
 *  @file				uitimer.h
 */


#include <stdio.h>
#include <stdint.h>
#include "timer_list.h"

#define IDLE_TIME 10000
#define EDIT_TIMER 0x99
#define IDLE_TIMER 0x199
#define VOL_TIMER 0x201
#define SD_TIMER 0x299
#define CON_TIMER 0x399
#define SWITCH_TIMER 0x498
#define RESTORE_TIMER 0x499

#define TIMER_STOP_FAIL			(-1)
#define TIMER_STOP_SUCCESS		0
#define TIMER_STOP_NOT_FOUND	1	//Timer-ID is NOT in the Timer List.

#define IDLE_STATUS	0
#define PROC_STATUS	1
#define DEL_STATUS	2

#define ONE_SHOT_TIMER 0
#define PERIODIC_TIMER 1

typedef int (*TMRFUNC)(int,void *);

/*new a time structure for longer timeout, ZyXEL*/
struct timeval_t {
	uint32_t		tv_sec;		/* seconds */
	uint32_t		tv_usec;	/* microseconds */
};

typedef struct CMTimer_t {
	int TimerID;
	void *data;		/* private data of timer */
	uint32_t TimerLen; /*change "timerLen" type to uint32 for longer timeout, ZyXEL*/
	struct timeval_t	timeout;		/* timeout time of timer */
	unsigned char status; //IDLE_STATUS, PROC_STATUS, DEL_STATUS
	TMRFUNC fn;
	pthread_mutex_t timerMutex;
}CMTimer_t;

typedef struct proc_element_t {
	unsigned char type;
	void *element;
	timer_list_iterator_t iter;
}proc_element_t;

void UITimer_Init(void);
void UITimer_Destory(void);
/*change "timerLen" type to uint32 for longer timeout, ZyXEL*/
int UIAddTimer(int id,uint32_t timerLen,TMRFUNC timefn,void *privdata);
int UIDelTimer(int id, void **dataptr);
int UIDelAllTimer(void);
int UIAddPeriodicTimer(int id,int timerLen,TMRFUNC timefn,void *privdata);
int UIDelPeriodicTimer(int id, void **dataptr);
int getSystemUptime(struct timeval_t *timeout);
void zyTms_get(struct timespec *tms);

enum { 
	saveConfigTimerID = 1,
	syncDHCP4SrvTimerID,
	wifiDiagRunningTimerID,
	syncBrSetMacAddrLearningTimerID,
	rebootTimerID
};


