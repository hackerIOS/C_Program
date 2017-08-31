//clt Socket

#include <iostream>
//#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;
int NET_CLT_SOCKET;
int main(){
    //创建套接字
    int NET_CLT_SOCKET = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    if (connect(NET_CLT_SOCKET, (struct sockaddr*)&serv_addr, sizeof(serv_addr))){
    	cout<<"success";
    }
   
    //读取服务器传回的数据
    char buffer[40];
    read(NET_CLT_SOCKET, buffer, sizeof(buffer)-1);
   
    //printf("Message form server: %s\n", buffer);
   cout<<buffer;
    //关闭套接字
    close(NET_CLT_SOCKET);
    return 0;
}