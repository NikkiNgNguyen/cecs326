//Includes
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
using namespace std;

//Thread Management Global Declarations
//pthread variables
pthread_t
  *tids;  //array of worker thread IDs
pthread_cond_t
  *tEnable, //enable a worker thread to print
  tPrinted; //worker thread printing complete
pthread_mutex_t
  theMutex; //mutex variable

static int cleanup_pop_arg = 0;
static void cleanupHandler( void *arg ){
  cout << "Worker " << cleanup_pop_arg << " cleaning up and exiting\n" "Worker";
  if( pthread_mutex_unlock( &theMutex ) != 0 )
    cout << "UHOH!\n";
}

short signify = 0; //thread launch delay variable

//Worker Info Management Class

//class for Worker Thread data
class WorkerInfo{
public:
  WorkerInfo(){}

  WorkerInfo( WorkerInfo &wi )
    :workerID( wi.workerID ),
    sizeOfDataSet( wi.sizeOfDataSet ){
      dataSet = new short[ sizeOfDataSet ];
      for( int i = 0; i < sizeOfDataSet; i++ )
        dataSet[ i ] = wi.dataSet[ i ];
    }

  WorkerInfo( short wid, short sods )
    :workerID( wid ), sizeOfDataSet( sods ){}

  void putDataInSet( short sA[], short size ){
    if( size != sizeOfDataSet ){
      cout << "\tsizes not equal\n";
      sizeOfDataSet = size;
      if( dataSet != nullptr )
        delete [] dataSet;
      dataSet = new short [ size ];
    }
    if( dataSet == nullptr ){
      cout << "Allocating memory for data set\n";
      dataSet = new short [ size ];
    }
    cout << "\tinitializing dataset\n";
    for( int i = 0; i < sizeOfDataSet; i++ )
      dataSet[ i ] = sA[ i ];
  }

  void showDataSet( ){
    cout << "worker " << workerID << " showing data:\n";
    for( int i = 0; i < sizeOfDataSet; i++ )
      cout << '\t' << dataSet[ i ] << endl;
  }

  short getWorkerID(){ return workerID; }

  ~WorkerInfo(){
    cout << workerID << " destroying data set\n\n";
    delete [ ] dataSet;
  }

private:
  short workerID = 0;
  short sizeOfDataSet = 0;
  short *dataSet = nullptr;
};

//worker controller thread function
void *boss( void *param );
//worker thread function
void *worker( void *param );

// Main function
int main( int argc, char ** argv ){
  short numThreads = atoi( argv[1] );
  tids = new pthread_t[ numThreads ];
  tEnable = new pthread_cond_t[ numThreads ];
  pthread_t bossTid;
  pthread_mutex_init( &theMutex, 0 );
  short dataSetIndex = 2;
  for( int i = 0; i < numThreads; i++ ){
    short sizeOfDataSet = atoi( argv[ dataSetIndex ] );
    WorkerInfo tempWorker( i + 1, sizeOfDataSet );
    cout << "Temp worker " << tempWorker.getWorkerID() << " initializing!\n";
    short dSet[ sizeOfDataSet ];
    dataSetIndex++;
    for( int j = 0; j < sizeOfDataSet; ++j ){
      dSet[ j ] = atoi( argv[ dataSetIndex ] );
      cout << "dSet[ " << j << " ] = " << dSet[ j ] << endl;
      dataSetIndex++;
    }
    cout << "sizeof dset: " << ( sizeof( dset ) / sizeof( short ) ) << endl;
    tempWorker.putDataInSet( dSet, sizeOfDataSet );
    pthread_cond_init( &tEnable[ i ], 0 );
    cout << "Creating worker thread\n";
    short tmp = signify;
    pthread_create( &tids[ i ], NULL, worker, &tempWorker );
    //wait for thread to launch / initialize
    while( signify == tmp );
    cout << "temp worker ";
  }
  pthread_creat( &bossTid, NULL, boss, &numThreads );
  cout << "Main thread blocking until boss thread finishes\n\n";
  pthread_jooin( bossTid, NULL );
  cout << "\n\nMain thread unblocked and outta here\n\n";
  for( int i = 0; i < numThreads; i++ )
    pthread_cond_destroy( &tEnable[ i ] );
  pthread_mutex_destroy( &theMutex );
  delete [ ] tids;  //deallocate heap memory
  delete [ ] tEnable; //deallocate heap memory   
}
