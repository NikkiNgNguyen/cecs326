#include <sys/types.h>	// getpid
#include <unistd.h>		// getpid
#include <string.h>
#include <sys/ipc.h>		// message queue
#include <sys/msg.h>	// message queue
#include <iostream>
using namespace std;

int main(){
	int qid = msgget( ftok( ".", 'Z' ), IPC_EXCL | IPC_CREAT | 0600 );
	
	if( qid < 0 ){
		cout << "ERROR: Queue creation failed!\n Maybe queue exists? Trying to open...\n";
		qid = msgget( ftok( ".", 'Z' ), 0600 );
		if( qid < 0 ){
			cout << "ERROR: Queue open failed, bailing out!\n";
			exit( -1 );
		}
		cout << "Queue open success\n";
	}
	
	struct buf{
		long mtype;
		char message[ 100 ];
	};
	buf msg;
	
	int size = sizeof( msg) - sizeof( long );
	cout << getpid() << " launched, waiting for data\n";
	if( msgrcv( qid, ( struct msgbuf * ) &msg, size, 117, 0 ) < 0 ){
		cout << "ERROR: RECEIVE message of type: " << msg.mtype << endl;
	}
	cout << "RECEIVED: " << msg.message << "\nof type: " << msg.mtype << endl;

	// strcat( msg.message, " ACKNOWLEDGED by cooperating process\n" );
	strcpy( msg.message, " ACKNOWLEDGED by cooperating process" );
	msg.mtype = 314;
	cout << "SEND: " << msg.message << "\nof type: " << msg.mtype << endl;
	if( msgsnd( qid, ( struct msgbuf * ) &msg, size, 0 ) < 0 ){
		cout << "ERROR: SEND message of type: " << msg.mtype << endl;
	}
	
	if( msgrcv( qid, ( struct msgbuf * ) &msg, size, 117, 0 ) < 0 ){
		cout << "ERROR: RECEIVE message of type: " << msg.mtype << endl;
	}
	cout << "RECEIVED: " << msg.message << "\nof type: " << msg.mtype << endl;
	// don't close the queue too quickly!
	cout << "CLOSING QUEUE\n";
	if( msgctl( qid, IPC_RMID, NULL ) < 0 ){
		cout << "ERROR: queue removal failed\n";
	}

}
