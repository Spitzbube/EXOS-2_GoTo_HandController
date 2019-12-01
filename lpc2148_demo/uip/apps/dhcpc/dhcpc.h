//
//  $Id: dhcpc.h 275 2008-11-02 18:23:49Z jcw $
//  $Revision: 275 $
//  $Author: jcw $
//  $Date: 2008-11-02 13:23:49 -0500 (Sun, 02 Nov 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/uip/apps/dhcpc/dhcpc.h $
//

/*
 * Copyright (c) 2005, Swedish Institute of Computer Science
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the uIP TCP/IP stack
 *
 * @(#)$Id: dhcpc.h 275 2008-11-02 18:23:49Z jcw $
 */
#ifndef __DHCPC_H__
#define __DHCPC_H__

#include "../../uip/uip_timer.h"
#include "../../uip/pt.h"

//
//
//
#define DHCPC_SERVER_PORT  67
#define DHCPC_CLIENT_PORT  68

//
//
//
typedef struct dhcpcState_s
{
  struct pt pt;
  char state;
  struct uip_udp_conn *conn;
  struct timer timer;
  u16_t ticks;
  const void *mac_addr;
  int mac_len;
  
  u8_t serverid [4];
  u16_t lease_time [2];
  u16_t ipaddr [2];
  u16_t netmask [2];
  u16_t dnsaddr [2];
  u16_t default_router [2];
  u16_t sntpaddr [2];
  n32_t timeoffset;
}
dhcpcState_t;

typedef dhcpcState_t uip_udp_appstate_dhcpc;

//
//
//
void dhcpc_init (const void *mac_addr, int mac_len);
void dhcpc_request (void);
void dhcpc_appcall (void);
void dhcpc_configured (const dhcpcState_t *s);

#ifndef UIP_UDP_APPCALL
#define UIP_UDP_APPCALL dhcpc_appcall
#endif

#endif /* __DHCPC_H__ */
