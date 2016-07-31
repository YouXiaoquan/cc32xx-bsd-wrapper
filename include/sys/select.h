/** \copyright
 * Copyright (c) 2015, Stuart W Baker
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are  permitted provided that the following conditions are met:
 * 
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \file include/freertos_select/sys/select.h
 * This file imlements POSIX select() prototypes.
 *
 * @author Stuart W. Baker
 * @date 26 January 2015
 */

#ifndef _SYS_SELECT_H_
#define _SYS_SELECT_H_

/* This is very nasty and polutes our namespace.  However, we have little
 * choice given the current SimpleLink Header structure.
 */
#include "socket.h"

#ifdef __cplusplus
extern "C" {
#endif

/** convert SimpleLink namespace to POSIX namespace */
typedef struct SlFdSet_t fd_set;

struct timeval;

/** POSIX select().
 * @param nfds highest numbered file descriptor in any of the three, sets plus 1
 * @param readfds fd_set of file descritpors to pend on read active
 * @param writefds fd_set of file descritpors to pend on write active
 * @param exceptfds fd_set of file descritpors to pend on error active
 * @param timeout timeout value to wait, if 0, return immediately, if NULL
 *                wait forever
 * @return on success, number of file descriptors in the three sets that are
           active, 0 on timeout, -1 with errno set appropriately upon error.
 */
int select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout);


#ifdef FD_CLR
#undef FD_CLR
#endif
#define FD_CLR SL_FD_CLR

#ifdef FD_ISSET
#undef FD_ISSET
#endif
#define FD_ISSET SL_FD_ISSET

#ifdef FD_SET
#undef FD_SET
#endif
#define FD_SET SL_FD_SET

#ifdef FD_ZERO
#undef FD_ZERO
#endif
#define FD_ZERO SL_FD_ZERO

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SELECT_H_ */
