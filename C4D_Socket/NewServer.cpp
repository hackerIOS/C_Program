//last Socket
//Server
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;
int main(int argc,char*argv[]){
	cout<<"Welcome to Socket IM"<<endl;
	system("ifconfig");
	//string IP_Address
	int serv_sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	struct sockaddr_in serv_addr={0};
	
	
	//memset(&serv_addr,0,sizeof (serv_addr));
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(721);
	//serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	cout<<"Waiting..."<<endl;
	
	
	
	bind(serv_sock,
	(struct sockaddr*)&serv_addr,
	sizeof (serv_addr));
	listen(serv_sock,1024);
	
	struct sockaddr_in clt_addr;
	socklen_t clt_addr_size=sizeof (clt_addr);
	int clt_sock=accept(serv_sock,
	(struct sockaddr*)&clt_addr,
	&clt_addr_size);
	
	char str[1024];
	inet_ntop(AF_INET,
	&clt_addr.sin_addr,str,sizeof (str));
	ntohs(clt_addr.sin_port);
	
	read(clt_sock,str,1024);
	cout<<str;
	
	close (clt_sock);
	close (serv_sock);
	//memset();
	
	return 0;
}