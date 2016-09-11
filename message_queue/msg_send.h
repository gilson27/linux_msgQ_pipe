/**     
	file msg_send.h
	@desc Header file for message send
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/errno.h>
#include <sys/types.h>

/**
	Macros
*/

#define TEST_MSG_KEY 9
#define TEST_MSG_TYPE 9999
#define MSG_SIZE 256

#define SUCCESS 0
#define FAILURE -1

/**
	Structure declarations
*/

typedef struct MessageQID {
	int msgID;
}messageQID;

typedef struct MessageBuf {
	char msg[MSG_SIZE];
	long mtype;
}messageBuf;

/**
	Function Declarations
*/

int createMsgQ(messageQID *);
int sendMsg(messageQID *);

/**
	Null structure definitions
*/

static messageQID nullMessageQID;
static messageBuf nullMessageBuf;
