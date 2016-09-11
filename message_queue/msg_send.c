/**
	@file msg_send.c
	@desc Program to send message to another process
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include "msg_recv.h"


int main() {
	/**
		Memory allocation to msg Q ID struct and  message to be sent
	*/
	char *msg;
	messageQID objMessageQID;
	objMessageQID = nullMessageQID;
	msg = (char *)malloc(MSG_SIZE);
	if(msg==NULL) {
		perror("Memeory allocation failed");
		goto shutdown;
	}

	/**
		Create message Queue
	*/
	createMsgQ();

	/**
		Send message
	*/
	sendMsg();
	return 0;
shutdown:
	return -1;
} 
