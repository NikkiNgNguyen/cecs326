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

int main(int argc, char * argv[]){
	const int SIZE = 128;
	const char *name = "ReadWriteInts"; //name of shared memory region

	int shm_fd; //file descriptor variable
	void *ptr; //shared memory pointer
	
	//
	
	//create, truncate shared memory region
	//shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	shm_fd = shm_open(name, O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	//point to shared memory region
	ptr = mmap(0, SIZE, PROT_WRITE | PROT_HEAD, MAP_SHARED, shm_fd, 0);
	//sequence = 8; //test
	
	short newValue = 0;
	short value = 0;
	cout << "2: FIRST Value Received: " << value << endl;
	do{
		cout << "2: Value to write into shared memory: " << newValue<< endl;
		cout << "2: Awaiting new data in shared memory region" << endl;
		cout << "2: Value Received: " <<newValue<< endl;
		//Hailstone sequence

		if(newValue == 2){ //win
			cout << "2: I WIN!" << endl;
			cout << "2: About to close the shared memory region" << endl;
			if(shm_unlink(name) == -1){
				cout << "reader: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
			}
			else{
			cout << "2: Successfully closed shared memory region" << endl;
			}
		}

	}while(newValue > 0);

	if(shm_unlink(name) == -1){
		cout << "reader: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	else
		cout << "reader: Successfully closed shared memory region" << endl;
	
	
	return 0;
}
