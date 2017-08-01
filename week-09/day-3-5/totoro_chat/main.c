#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <process.h>
#include <stdint.h>

#include <unistd.h>

#include "server.h"

#define SERVER_IP           "127.0.0.1" //"10.27.6.113"
#define SERVER_PORT         23456
#define DATA_BUFFER_SIZE    1024


struct user_storage {
    char server_ip;
    int port;
    char name[255];
};

void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

void wsa_init()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
		handle_error("WSAStartup() ");
}

void connect_to_server(SOCKET *client_sock, unsigned int server_ip, char *server_port)
{
	// Creating client socket
	(*client_sock) = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (client_sock < 0)
		handle_error("socket() ");

	// Creating server address
	struct sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(server_port);
	addr_in.sin_addr.s_addr = inet_addr(server_ip);

	// Connecting the client socket to the server
	int connect_retval = connect(*client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));
	if (connect_retval < 0)
		handle_error("connect() ");

	printf("Connected to %s:%d\n", SERVER_IP, SERVER_PORT);
}

int send_message(SOCKET *socket)
{
	// Get the message from the user
	char msg[DATA_BUFFER_SIZE];
	printf("\nEnter the message to send: ");
	gets(msg);
	// Send the message to the servers
	int sent_bytes = send(*socket, msg, strlen(msg), 0);
	if (sent_bytes < 0)
		handle_error("send() ");

	return sent_bytes;
}
/********************/
/**Broadcast Server**/
/********************/
/*
void connect_to_broadcast_server(SOCKET *broadcast_sock)
{
	// Creating client socket ez fasza
	(*broadcast_sock) = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);  //sock_dgram, ipproto_udp
	if (broadcast_sock < 0)
		handle_error("socket() ");

	// Creating server address ez fasza
	struct sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(12345);
	addr_in.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");

     int broadcastPermission;
	 broadcastPermission = 1;
   if (setsockopt(socket, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission,sizeof(broadcastPermission)) < 0){
       fprintf(stderr, "setsockopt error");
       exit(1);
   }


   char msg[] = "TOTORO 34567";
	printf("\nBroadcast message: ");
	puts(msg);

	// Send the message to the servers
	int sent_bytes = sendto(socket, msg, strlen(msg), 0, (struct sockaddr *) &addr_in, sizeof(addr_in));
	if (sent_bytes < 0)
		handle_error("send() ");



	// Connecting the client socket to the server
	int connect_retval = connect(*client_sock, ();
	if (connect_retval < 0)
		handle_error("connect() ");
  //  puts(user[0].server_ip);
	printf("Connected to :%d\n",12345); //user[0].server_ip, user[0].port);
}
*/
/*int send_broadcast_message(SOCKET *socket)
{
	// Get the message from the user
	char msg[] = "TOTORO 34567";
	printf("\nBroadcast message: ");
	puts(msg);
	// Send the message to the servers
	int sent_bytes = sendto(socket, msg, strlen(msg), 0, (stuct sockaddr *) &addr_in, sizeof(addr_in));
	if (sent_bytes < 0)
		handle_error("send() ");

	return sent_bytes;
}*/





int main()
{
    struct user_storage user[50] = {
    {"INADDR_ANY", 12345, "broadcast"}
    };


    _beginthread(thread_server, 0, NULL);
    Sleep(500);

    wsa_init();

	// Connect to server
	SOCKET client_socket;
	connect_to_server(&client_socket, SERVER_PORT, SERVER_IP);

	//Broadcast_msg
//	SOCKET broadcast_sock;
//	connect_to_broadcast_server(&broadcast_sock);

	// Local variables used in the do-while loop
	int sent_bytes;
	int received_bytes;
	char recv_buff[DATA_BUFFER_SIZE];
	do {
		// Send data to the server
		sent_bytes = send_message(&client_socket);
		// Receive the answer if message was sent
		if (sent_bytes > 0) {
			received_bytes = recv(client_socket, recv_buff, DATA_BUFFER_SIZE, 0);
			// Error handling
			if (received_bytes < 0) {
				handle_error("recv() ");
			} else {
				// Printing out received string
				recv_buff[received_bytes] = '\0';
				printf("Received string: %s\n", recv_buff);
			}
		}
	} while (sent_bytes > 0);

	printf("Closing the socket...\n");
	closesocket(client_socket);
	printf("Cleaning up memory...\n");
	WSACleanup();
	return 0;

}


