/*	$NetBSD: netdb.h,v 1.5 1995/07/03 22:59:12 jtc Exp $	*/

/*-
 * Copyright (c) 1980, 1983, 1988 Regents of the University of California.
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)netdb.h	5.15 (Berkeley) 4/3/91
 */

#ifndef _NETDB_H_
#define _NETDB_H_

/* Amiga - 48.3: */
#include <sys/types.h>

#define	_PATH_HEQUIV		"/etc/hosts.equiv"
#define	_PATH_HOSTS		"/etc/hosts"
#define _TCP_PATH_NETWORKS  	"/AmiTCP/db/networks"
#define	_PATH_NETWORKS		"/etc/networks"
#define	_PATH_PROTOCOLS		"/etc/protocols"
#define _TCP_PATH_PROTOCOLS 	"/AmiTCP/db/protocols"
#define	_PATH_SERVICES		"/etc/services"
#define _TCP_PATH_SERVICES 	"/AmiTCP/db/services"

/*
 * Structures returned by network data base library.  All addresses are
 * supplied in host order, and returned in network order (suitable for
 * use in system calls).
 */
struct	hostent {
	char	*h_name;	/* official name of host */
	char	**h_aliases;	/* alias list */
	int	h_addrtype;	/* host address type */
	int	h_length;	/* length of address */
	char	**h_addr_list;	/* list of addresses from name server */
#define	h_addr	h_addr_list[0]	/* address, for backward compatiblity */
};

/*
 * Assumption here is that a network number
 * fits in 32 bits -- probably a poor one.
 */
struct	netent {
	char		*n_name;	/* official name of net */
	char		**n_aliases;	/* alias list */
	int		n_addrtype;	/* net address type */
	unsigned long	n_net;		/* network # */
};

struct	servent {
	char	*s_name;	/* official service name */
	char	**s_aliases;	/* alias list */
	int	s_port;		/* port # */
	char	*s_proto;	/* protocol to use */
};

struct	protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
 * (left in extern int h_errno).
 */

extern int h_errno;

#define	HOST_NOT_FOUND	1 /* Authoritative Answer Host not found */
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define	NO_DATA		4 /* Valid name, no data record of requested type */
#define	NO_ADDRESS	NO_DATA		/* no address, look for MX record */


/* Amiga - 48.3: addrinfo stuff*/
/*
 * Error codes.
 */
#define EAI_ADDRFAMILY	1
#define EAI_AGAIN	2
#define EAI_BADFLAGS	3
#define EAI_FAIL	4
#define EAI_FAMILY	5
#define EAI_MEMORY	6
#define EAI_NONAME	7
#define EAI_OVERFLOW	8
#define EAI_SERVICE	9
#define EAI_SOCKTYPE	10
#define EAI_SYSTEM	11

/*
 * Flags for getaddrinfo().
 */
#define AI_ADDRCONFIG	0x0001
#define AI_ALL		0x0002
#define AI_CANONNAME	0x0004
#define AI_NUMERICHOST	0x0008
#define AI_NUMERICSERV	0x0010
#define AI_PASSIVE	0x0020
#define AI_V4MAPPED	0x0040
#define AI_DEFAULT	(AI_V4MAPPED | AI_ADDRCONFIG)

/*
 * Flags for getnameinfo().
 */
#define NI_DGRAM	0x0001
#define NI_NAMEREQD	0x0002
#define NI_NOFQDN	0x0004
#define NI_NUMERICHOST	0x0008
#define NI_NUMERICSCOPE	0x0010
#define NI_NUMERICSERV	0x0020

/*
 * Maximum length of FQDN and servie name for getnameinfo().
 */
#define NI_MAXHOST	1025
#define NI_MAXSERV	32

/*
 * Address families and Protocol families.
 */
#ifndef AF_UNSPEC
#define AF_UNSPEC AF_INET
#endif
#ifndef PF_UNSPEC
#define PF_UNSPEC PF_INET
#endif

/*
 * struct addrinfo.
 */
struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    char *ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfo *ai_next;
};


#include <sys/cdefs.h>

__BEGIN_DECLS
void		endhostent __P((void));
void		endnetent __P((void));
void		endprotoent __P((void));
void		endservent __P((void));
struct hostent	*gethostbyaddr __P((const char *, int, int));
struct hostent	*gethostbyname __P((const char *));
struct hostent	*gethostent __P((void));
struct netent	*getnetbyaddr __P((long, int)); /* u_long? */
struct netent	*getnetbyname __P((const char *));
struct netent	*getnetent __P((void));
struct protoent	*getprotobyname __P((const char *));
struct protoent	*getprotobynumber __P((int));
struct protoent	*getprotoent __P((void));
struct servent	*getservbyname __P((const char *, const char *));
struct servent	*getservbyport __P((int, const char *));
struct servent	*getservent __P((void));
void		herror __P((const char *));
char		*hstrerror __P((int));
void		sethostent __P((int));
/* void		sethostfile __P((const char *)); */
void		setnetent __P((int));
void		setprotoent __P((int));
void		setservent __P((int));

/* Amiga - 48.3: addrinfo stuff */
/*
 * Functions.
 */
const char *gai_strerror __P((int));
void freeaddrinfo __P((struct addrinfo *));
int getaddrinfo __P((const char *, const char *, const struct addrinfo *, struct addrinfo **));
int getnameinfo __P((const struct sockaddr *, socklen_t, char *, socklen_t, char *, socklen_t, int));
__END_DECLS

#endif /* !_NETDB_H_ */
