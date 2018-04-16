#ifndef _SNAPSHOT_CLIENT_H_
#define _SNAPSHOT_CLIENT_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#define BUFLEN 512  //Max length of buffer

int iSockfd = 0, n = 0;
char recvBuff[1024];
int slen;
struct sockaddr_in g_servAddr, g_sourceAddr; 
int MISSION_ACTIVE = 1;

int snapshotServerInit(int port);

int serverMainLoop();

#endif /* _SNAPSHOT_CLIENT_H_ */