#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

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
    char g[5];
  };
  buf msg;
  int size = sizeof(msg) - sizeof(long);
  strcpy(msg.g, "From Challenger: ");

  do{
    cout << ""
  }
}
