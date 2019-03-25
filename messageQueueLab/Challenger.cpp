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
    cout << "Challenger, Q access SUCCESS!\n";
  }
  struct buf{
    long mtype;
    char message[5];
  };
  buf msg;

  int size = sizeof(msg) - sizeof(long);
  msg.mtype = 0;
  long value = 0;
  long newValue = 0;
  strcpy (msg.message, "From Challenger");

  cout << "Challenger, checking queue...\n";
  if(msgrcv(qid, (struct msgbuf *) &msg, size, 0, 0) < 0){
    cout "Error: " << msg.mtype << endl;
  }
  else{
    bool oldData = true;
    while(oldData){
      newValue = msg.message;
      if(newValue != value){
        oldData = false;
      }
    }
    value = newValue;
    cout << "Challenger, Received: " << msg.message << "of type " << msg.mtype << endl;
    value = msg.message
    if (value % 2 == 1){
      value = (3 * value) + 1;
      msg.message = value;
    }
    else if (value % 2 == 0){
      value = value/2;
      msg.message = value;
    }
    cout << "Challenger, Sending: " << value << endl;
    cout << "Challenger, checking queue...\n";

  }
  do{
    bool oldData = true;
    while(oldData){
      newValue = msg.message;
      if(newValue != value){
        oldData = false;
      }
    }

    value = newValue;
    if(msgrcv(qid, (struct msgbuf *) &msg, size, 0, 0) < 0){
      cout "Error " << msg.mtype << endl;
    }
    else{
      value = msg.message
      cout << "Challenger, Received: " << msg.message << "of type " << msg.mtype << endl;
      if ((value == 1) || (value == 2)){
        msg.message = value;
        break;
      }
      else if (value % 2 == 1){
        value = (3 * value) + 1;
        msg.message = value;
      }
      else if (value % 2 == 0){
        value = value/2;
        msg.message = value;
      }
      cout << "Challenger, Sending: " << value << endl;
      cout << "Challenger, checking queue...\n";

  }while((value != 1) || (value != 2));
  if (newValue == 2){
    cout << "Challenger, Failed Removing" << endl;
  }
  else if(newValue == 1){
		cout <<"Challenger, Removing Q\n" << endl;
	}
  if( msgctl (qid, IPC_RMID, NULL) < 0 )
	    cout << "Challenger, Q remove FAIL!\n";
  else
	    cout << "Challenger, Q remove SUCCESS!\n";
	exit(0);

}
