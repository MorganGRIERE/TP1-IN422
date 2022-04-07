#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS  3

void *PrintSentence(void *threadid)
{
    cout << "Thread ID : "<<    *(int *) threadid <<endl;
    int i = *(int*) threadid;
    cout<<"Je suis le TRAITEMENT "<<i<<endl<<"Je suis actif...\n" ;
    //pthread_exit(NULL);
}

int main ()
{
  pthread_t TH1,TH2,TH3;
  int rc;
  char TT;

  int MyThreadID;

// CREAT THE THREAD HERE
    rc =  pthread_create(&TH1,NULL,PrintSentence,&MyThreadID);
    pthread_join(TH1,NULL);
	//cout<<"The thread ID is: "<< MyThreadID<<endl<<endl;

	//rc =  pthread_create(&TH2,NULL,PrintSentence,NULL);
    //pthread_join(TH2,NULL);
	//cout<<"The thread ID is: "<< MyThreadID<<endl<<endl;

	//rc =  pthread_create(&TH3,NULL,PrintSentence,NULL);
    //pthread_join(TH3,NULL);
	//cout<<"The thread ID is: "<< MyThreadID<<endl<<endl;

    cout<<"rc is : "<<rc<<endl;
    if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }

        cout<<"\nProgram END "<<endl<<"write a letter to end your program\n";
      // pthread_exit(NULL);
        cin>>TT;

   pthread_exit(NULL);

}
