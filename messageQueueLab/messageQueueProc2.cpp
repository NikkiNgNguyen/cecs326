#include <errno.h>
#include <sys/types.h>	// getpid
#include <unistd.h>		// getpid
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
using namespace std;

void errnoChecker();

int main(){
	int qid = msgget( ftok( ".", 'Z' ), 0 );
	
	// declare message buffer structure
	struct buf{
		long mtype;
		char message[ 100 ];
	};
	buf msg;
	int size = sizeof( msg ) - sizeof( long );
	
	msg.mtype = 111;
	strcpy( msg.message, "type 111: message 1" );
	cout << "SEND: " << msg.message << "\nof type: " << msg.mtype << endl;
	if( 
		msgsnd( qid, (struct msgbuf * ) &msg, size, 0 )
	< 0 ){
		cout << "ERROR: SEND message of type: " << msg.mtype << endl;
	}
	
	msg.mtype = 113;
	strcpy( msg.message, "type 113: message 2" );
	cout << "Process " << getpid() << " SEND: " << msg.message << "\nof type: " << msg.mtype << endl;
	if(	msgsnd( qid, ( struct msgbuf * ) &msg, size, 0 )
	< 0 ){
		cout << "ERROR: SEND message of type: " << msg.mtype << endl;
	}
	
	strcpy( msg.message,  "type 117: message 3" );
	msg.mtype = 117;
	cout << "Process " << getpid() << " SEND: " << msg.message << "\nof type: " << msg.mtype << endl;
	if( 
	msgsnd( qid, ( struct msgbuf * ) &msg, size, 0 )
	< 0 ){
		cout << "ERROR: SEND message of type: " << msg.mtype << endl;
	}

	msg.mtype = 314;
	if( 
	msgrcv( qid, ( struct msgbuf * ) &msg, size, 314, 0 )
	< 0 ){
		int errsv = errno;
		cout << errsv << endl;
		cout << "ERROR: RECEIVE message of type: " << msg.mtype << endl;
	}
	cout << "Process " << getpid() << " RECEIVE: " << msg.message << "\nof type: " << msg.mtype << endl;

	strcpy( msg.message,  "type 117: message 4" );
	msg.mtype = 117;
	cout << "Process " << getpid() << " SEND: " << msg.message << "\nof type: " << msg.mtype << endl;
	if( 
	msgsnd( qid, ( struct msgbuf * ) &msg, size, 0 )
	< 0 ){
		cout << "ERROR: SEND message of type: " << msg.mtype << endl;
	}
}

void errnoChecker(){
	
}