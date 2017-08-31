//Socket
//Server
//#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int NET_SOCKET;
int NET_CLT_SOCKET;
struct sockaddr_in NET_SERVER_IP;
struct sockaddr_in NET_CLT_IP;


int CreateSocket(char* IP_ADDR,int IP_PORT){
	NET_SOCKET=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	memset(&NET_SERVER_IP,0,sizeof (NET_SERVER_IP));
	
	NET_SERVER_IP.sin_family=AF_INET;
	NET_SERVER_IP.sin_addr.s_addr=inet_addr(IP_ADDR);
	NET_SERVER_IP.sin_port=htons(IP_PORT);
	
	bind(NET_SOCKET,(struct sockaddr*)&NET_SERVER_IP,sizeof (struct sockaddr));
	
	
	
}

int LoopListen(){
	listen(NET_SOCKET,20);
	cout<<"Listen?";
	socklen_t AS_size=sizeof (NET_CLT_IP);
	NET_CLT_SOCKET=accept(NET_SOCKET,(struct sockaddr*)&NET_CLT_IP,&AS_size);
	char* str="Debug";
	
	send(NET_CLT_SOCKET,str,sizeof(str),0);
	
}

int main(int argc,char* argv[]){
	CreateSocket("127.0.0.1",1234);
	LoopListen();
	//close (NET_SERVER_IP);
	close(NET_CLT_SOCKET);
	close(NET_SOCKET);
	
	
	return 0;
}