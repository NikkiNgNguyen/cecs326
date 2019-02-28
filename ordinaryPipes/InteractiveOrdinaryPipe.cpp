#include <sys/types.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(){
	string write_msg, msg_read;
	char msg_write[25];
	char read_msg[25];
	int fd[2];
	pid_t pid;
	pipe( fd );
	pid = fork();
	if( pid > 0 ){	// in parent
			close( fd[0] );	// close unused Read End
		while( write_msg != "done" ){
			cout << "Enter a message to send: ";
			cin >> write_msg;
			cout << "In parent, sending: " << write_msg << endl;
			unsigned int size = write_msg.length();
			write_msg.copy( msg_write, write_msg.length(), 0 );
			write( fd[1], msg_write, size );
		}
		close( fd[1] );	// all done, close the pipe!
	}
	else{
		close( fd [1] );	// close unused write end
		while( msg_read != "done" ){
			read( fd[0], read_msg, 25 );
			cout << "In child, msg read: " << read_msg << endl;
			msg_read = read_msg;
		}
		close( fd[0] );	// all done, close the pipe!
	}
	exit(0);
}
