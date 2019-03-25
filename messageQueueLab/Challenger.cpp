#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <errno.h>
using namespace std;

void errnoChecker();

int main(){
  int qid = msgget(ftok(".",'u'), IPC_EXCL | IPC_CREAT | 0600);
  if(qid < 0){
    cout << "Challenger, Q create FAIL!\n";
  qid = msgget(ftok(".",'u'), IPC_EXCL | 0600);
    if(qid < 0){
      cout << "Challenger, Q access FAIL!\n";
      exit(-1);
    }
  }
  else{
    cout << "Challenger, Q create SUCCESS!\n";
  }
  struct buf{
    long mtype;
    char g[5];
  };

  buf msg;

  int size = sizeof(msg) - sizeof(long);
  msg.mtype = 0;

  cout << "Challenger, checking queue...\n";
  msgrcv(qid, (struct msgbuf *) &msg, size, msg.mtype, 0);
  cout << "Challenger, Received: " << msg.mtype << endl;
  if (msg.mtype % 2 == 1){
    msg.mtype = (3 * msg.mtype) + 1;
  }
  else if (msg.mtype % 2 == 0){
    msg.mtype = msg.mtype/2;
  }
  cout << "Challenger, Sending: " << msg.mtype << endl;
	if(msgsnd(qid, (struct msgbuf *) &msg, size, 0) < 0){
		cout << "Challenger, send fail\n";
	}

  do{
	if (msg.mtype % 2 == 1){
      msg.mtype = (3 * msg.mtype) + 1;
    }
    else if (msg.mtype % 2 == 0){
      msg.mtype = msg.mtype/2;
    }
	cout << "Chalenger, Checking queue...\n";
	msgrcv( qid, (struct msgbuf * ) &msg, size, msg.mtype, 0);
	
      cout << "Challenger, Received: " << msg.mtype << endl;
      if (msg.mtype % 2 == 1){
        msg.mtype = (3 * msg.mtype) + 1;
      }
      else if (msg.mtype % 2 == 0){
        msg.mtype = msg.mtype/2;
      }
      cout << "Challenger, Sending: " << msg.mtype << endl;

	if(msgsnd(qid, (struct msgbuf *) &msg, size, 0) < 0){
	      cout << "Challenger, send fail\n";
    	}
  }while(msg.mtype != 1);
	
	cout << "Challenger, Removing Q\n";
  if( msgctl (qid, IPC_RMID, NULL) )
	    cout << "Challenger, Q remove FAIL!\n";
  else
	    cout << "Challenger, Q remove SUCCESS!\n";
	exit(0);

}
