#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib, "ws2_32.lib")

//（1）服务端
//
//1、加载套接字库，创建套接字（WSAStartup() / socket()）;
//
//2、绑定套接字到一个IP地址和一个端口上（bind()）;
//
//3、将套接字设置为监听模式等待连接请求（listen()）；
//
//4、请求到来后，接受连接请求，返回一个新的对应于此次连接的套接字（accept()）；
//
//5、用返回的套接字和客户端进行通信（send() / recv()）；
//
//6、返回，等待另一个连接请求；
//
//7、关闭套接字，关闭加载的套接字库（closesocket() / WSACleanup()）；

int main(int argc, char *argv[])
{
	// initialize
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
		return 0;

	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}

	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	while (true)
	{
		printf("等待连接...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}
		printf("接收到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));

		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			printf(revData);
			printf("\n");
		}

		const char *sendData = "你好， TCP客户端！\n";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);

	}
	closesocket(slisten);
	WSACleanup();
	return 0;
}