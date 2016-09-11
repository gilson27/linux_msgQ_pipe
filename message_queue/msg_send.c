/**
	@file msg_send.c
	@desc Program to send message to another process
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include "msg_send.h"


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
	strcpy(objMessageBuf.msg, TEST_MSG);

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
	response = sendMsg(&objMessageQID, &objMessageBuf);
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
int sendMsg(messageQID *objMessageQID, messageBuf *objMessageBuf) {
	int response;

	response = msgsnd(objMessageQID->msgID, objMessageBuf, sizeof(objMessageBuf->msg), IPC_NOWAIT);
	if(response == FAILURE) {
		perror("Failed to send message");
		return FAILURE;
	}
	
	return SUCCESS;
}

