/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <errno.h>

#include <winsock2.h>

#ifdef __cplusplus
}
#endif

#define SOCKERRNO WSAGetLastError()
#define SOCKERRSTR(ERRNO_IN) convertSocketErrorToString(ERRNO_IN)

#define socket_close(S)		closesocket(S)
#define socket_ioctl(A,B,C)	ioctlsocket(A,B,C)
typedef u_long FAR osiSockIoctl_t;
typedef int osiSocklen_t;

#define MAXHOSTNAMELEN		75
#define IPPORT_USERRESERVED	5000U

#define SOCK_EWOULDBLOCK WSAEWOULDBLOCK
#define SOCK_ENOBUFS WSAENOBUFS
#define SOCK_ECONNRESET WSAECONNRESET
#define SOCK_ETIMEDOUT WSAETIMEDOUT
#define SOCK_EADDRINUSE WSAEADDRINUSE
#define SOCK_ECONNREFUSED WSAECONNREFUSED
#define SOCK_ECONNABORTED WSAECONNABORTED
#define SOCK_EINPROGRESS WSAEINPROGRESS
#define SOCK_EISCONN WSAEISCONN
#define SOCK_EALREADY WSAEALREADY
#define SOCK_EINVAL WSAEINVAL
#define SOCK_EINTR WSAEINTR
#define SOCK_EPIPE EPIPE
#define SOCK_EMFILE WSAEMFILE
#define SOCK_SHUTDOWN WSAESHUTDOWN
#define SOCK_ENOTSOCK WSAENOTSOCK
#define SOCK_EBADF WSAENOTSOCK

/*
 *	Under WIN32, FD_SETSIZE is the max. number of sockets,
 *	not the max. fd value that you use in select().
 *
 *	Therefore, it is difficult to detemine if any given
 *	fd can be used with FD_SET(), FD_CLR(), and FD_ISSET().
 */
#define FD_IN_FDSET(FD) (1)

epicsShareFunc unsigned epicsShareAPI wsaMajorVersion ();

/*
 * WINSOCK appears to assign a different functionality for 
 * SO_REUSEADDR compared to other OS. With WINSOCK SO_REUSEADDR indicates
 * that simultaneously servers can bind to the same TCP port on the same host!
 * Also, servers are always enabled to reuse a port immediately after 
 * they exit ( even if SO_REUSEADDR isnt set ).
 */
#define SO_REUSEADDR_ALLOWS_SIMULTANEOUS_TCP_SERVERS_TO_USE_SAME_PORT
