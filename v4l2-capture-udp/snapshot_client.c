
/*
    Simple udp server
*/
#include "snapshot_client.h"
// #include "capture.h"

int snapshotServerInit(int port)
{
    slen = sizeof(g_sourceAddr);
    memset(recvBuff, '0',sizeof(recvBuff));

    //create a UDP socket
    if ((iSockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }
    memset(&g_servAddr, '0', sizeof(g_servAddr)); 

    g_servAddr.sin_family = AF_INET;
    g_servAddr.sin_port = htons(port);
    g_servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to port
    if( bind(iSockfd , (struct sockaddr*)&g_servAddr, sizeof(g_servAddr) ) == -1)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    return 0;
}

int serverMainLoop()
{
    char buf[BUFLEN];
    int len;
    printf("serverMainLoop\n");
    do {
        fflush(stdout);
         
        //try to receive some data, this is a blocking call
        if ((len = recvfrom(iSockfd, buf, BUFLEN, 0, (struct sockaddr *) &g_sourceAddr, &slen)) == -1)
        {
            printf("\n Error : recvfrom() Failed \n");
            return 1;
        }
        if(strcmp(buf,"Snapshot\n")==0)
        {
            // g_takeSnapshot = 1;
            printf("Snapshot recvd\n");
            //start_capturing();
            // g_takeSnapshot = 0;
        }
        if(strcmp(buf,"StopStream\n")==0)
        {
            MISSION_ACTIVE = 0;
        }
        else 
        {
            printf("%s\n",buf);
        }
        printf("end of loop\n");
    }while(MISSION_ACTIVE);
}


int main(void)
{
    snapshotServerInit(5000);
    serverMainLoop();
}