//client
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


using namespace std;

int main(){
	cout<<"Enter you want to connect IP Address:";
	char IP_Address[20];
	cin>>IP_Address;
	int clt_sock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serv_addr;
	memset(&serv_addr,
	0,
	sizeof (serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(721);
	inet_pton(AF_INET, IP_Address, &serv_addr.sin_addr);
	
	if (connect(clt_sock,
	(struct sockaddr*)&serv_addr,
	sizeof (serv_addr))!=0){
		cout <<"connect failure"<<endl;
	}
	cout<<"Message:";
	char *buf;
	cin>>buf;
	
	write(clt_sock,
	buf,sizeof (buf));
	cout <<buf;
	close(clt_sock);
	return 0;
}