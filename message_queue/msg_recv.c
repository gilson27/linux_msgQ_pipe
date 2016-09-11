/**
	@file msg_recv.c
	@desc Program to recv message to another process
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include "msg_recv.h"


int main() {
	int response;
	/**
		Memory allocation to msg Q ID struct and  message to be sent
	*/

	messageQID objMessageQID;
	objMessageQID = nullMessageQID;

	messageBuf objMessageBuf;
	objMessageBuf = nullMessageBuf;
	objMessageBuf.mtype = TEST_MSG_TYPE;

	/**
		Create message Queue
	*/
	response = createMsgQ(&objMessageQID);
	if(response == FAILURE) {
		goto shutdown;
	}

	/**
		Send message
	*/
	response = recvMsg(&objMessageQID, &objMessageBuf);
	if(response == FAILURE) {
		goto shutdown;
	}
	return 0;
shutdown:
	return -1;
}


/**
	Function to open message Queue
*/

int createMsgQ(messageQID *objMessageQID) {
	int response;

	objMessageQID->msgID = msgget((key_t)TEST_MSG_KEY, IPC_CREAT | 0666);
	if(response == FAILURE) {
		perror("Failed to create message Queue");
		return FAILURE;
	}
	
	return SUCCESS;
}


/**
	Function to send message over the message Queue
*/
int recvMsg(messageQID *objMessageQID, messageBuf *objMessageBuf) {
	int response;
	fprintf(stdout, "Receiving from id = %d\n", objMessageQID->msgID);
	response = msgrcv(objMessageQID->msgID, objMessageBuf, sizeof(objMessageBuf), TEST_MSG_TYPE, MSG_NOERROR | IPC_NOWAIT);
	if(response == FAILURE) {
		perror("Failed to recv message");
		return FAILURE;
	}
	fprintf(stdout, "Message Received %s\n", objMessageBuf->msg);
	return SUCCESS;
}

