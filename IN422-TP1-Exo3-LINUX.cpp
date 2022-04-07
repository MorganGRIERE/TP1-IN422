#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>

using namespace std;

#define NUM_THREADS  3

void *PrintSentence(void *tt)
{
    char * value = (char*) tt;
    cout<<"La chaine transmise est : "<<value<<endl;
    cout<<"La chaine transmise est : "<< (char*) tt<<endl;

    pthread_exit(NULL);
}

int main ()
{  pthread_t TH1;
  int rc;
  char texte;

  char TT[150]="Bonjour";		// Chaine de caractere

  rc = pthread_create(&TH1, NULL, PrintSentence, &TT);
  pthread_join(TH1,NULL);


  if (rc){
     cout << "Error:unable to create thread," << rc << endl;
     exit(-1);
  }

  cout<<"\nFin du programme \nsaisir une lettre pour fermer\n";

  cin>>texte;
  pthread_exit(NULL);
}
