
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

int main() {

	int qid = msgget(
	        ftok(".",'u'), 
	        IPC_EXCL | IPC_CREAT | 0600
	        );
    if( qid < 0 ){
        cout << "A, Q create FAIL!\n";
	    qid = msgget(
	        ftok(".",'u'), 
	        IPC_EXCL | 0600
	        );
        if( qid < 0 ){
            cout << "A, Q access FAIL!\n";
            exit( -1 );
        }
		else{
			cout << "Q access SUCCESS\n";
		}
    }
	else{
		cout << "Q create SUCCESS\n";
	}


	cout << "Removing queue\n";
	if( msgctl (qid, IPC_RMID, NULL) )
	    cout << "A, Q remove FAIL!\n";
    else
	    cout << "A, Q remove SUCCESS!\n";
	exit(0);
}
