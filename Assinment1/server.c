#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define port 8989

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("socket not working");
    }
    
    struct sockaddr_in Saddr,Caddr;
    socklen_t clilen;
    clilen = sizeof(Caddr);
    Saddr.sin_family = AF_INET;
    Saddr.sin_port = htons(port);
   Saddr.sin_addr.s_addr = INADDR_ANY;

int bd = bind(sockfd, (struct sockaddr *) &Saddr, sizeof(Saddr));
	  
	  if(bind < 0)
		 printf("bind not working"); 

	  int lis = listen(sockfd,5);
	  if(lis < 0)
		  printf("listen not working");

	  int tempfd = accept(sockfd, (struct sockaddr *)&Caddr,&clilen);
	  if(tempfd<0)
		  printf("accept not working");

}

