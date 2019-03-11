#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

#include <time.h>

#include <iostream>
using namespace std;

// compile with: g++ writerOfInts.cpp -o 2_writer.out -lrt


int main(int argc, char * argv[]){
	const int SIZE = 128;

	const char *name = "ReadWriteInts";	// name of shared memory region

	int shm_fd;	// file descriptor variable
	void *ptr;	// shared memory pointer

	// create, truncate shared memory region
	// shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	shm_fd = shm_open(name, O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	// point to shared memory region
	ptr = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
	// sequence = 8;	// test

	do{
		cout << "Input a numerical positive short integer value to send to shared memory: ";
		short x;
		cin >> x;
		cout << "1: Value to write into shared memory: " << x << endl;
		*((short *)ptr) = x;			
		if( x < 0 ){
			cout << "Negative value encountered, exiting!\n";
			break;
		}
		
	}while( 1 );
	

	if(shm_unlink(name) == -1){
		cout << "1: ERROR: Error removing shared memory region: " << name << endl;
		exit(-1);
	}
	cout << "1: Successfully closed shared memory region" << endl;
	
	return 0;

}
