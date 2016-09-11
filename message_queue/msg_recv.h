/**     
	file msg_recv.h
	@desc Header file for message recv
	@author Gilson Varghese
	@date  11 Sep 2016
**/

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <sys/types.h>

/**
	Macros
*/

#define TEST_MSG_KEY 10
#define TEST_MSG_TYPE 100
#define MSG_SIZE 256
#define TEST_MSG "It works"

#define SUCCESS 0
#define FAILURE -1

/**
	Structure declarations
*/

typedef struct MessageQID {
	int msgID;
}messageQID;

typedef struct MessageBuf {
	long mtype;
	char msg[MSG_SIZE];
}messageBuf;

/**
	Function Declarations
*/

int createMsgQ(messageQID*);
int recvMsg(messageQID*, messageBuf*);

/**
	Null structure definitions
*/

static messageQID nullMessageQID;
static messageBuf nullMessageBuf;
