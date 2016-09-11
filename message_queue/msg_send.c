/**
	@file msg_send.c
	@desc Program to send message to another process
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include "msg_send.h"


int main() {
	/**
		Memory allocation to msg Q ID struct and  message to be sent
	*/

	messageQID objMessageQID;
	objMessageQID = nullMessageQID;

	messageBuf objMessageBuf;
	objMessageBuf = nullMessageBuf;

	/**
		Create message Queue
	*/
	createMsgQ(&objMessageQID);

	/**
		Send message
	*/
	sendMsg(&objMessageQID, &objMessageBuf);
	return 0;
shutdown:
	return -1;
} 


/**
	Function to open message Queue
*/

int createMsgQ(messageQID *objMessageQID) {
	int response;

	response = msgget((key_t)TEST_MSG_KEY);
	
	return SUCCESS;
}


/**
	Function to send message over the message Queue
*/


