#include <iostream>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <algorithm>
#include <time.h>

using namespace std;

#define NUM_THREADS  3
#define MAX_TAILLE 150


void *Visualization(void *value)
{
    char str[MAX_TAILLE];
    char * str_inter = (char*) value;

    int j = 0;
    int t = strlen(str_inter);

    for (int i = t - 1; i >= 0; i--)
    {
      str[j++] = str_inter[i];
    }

   cout<<"La chaine inverse est : "<<str<<endl;
   pthread_exit(NULL);
}

void *PrintSentence(void *value)
{
    cout<<endl<<"La chaine transmise est : "<< (char*) value<<endl;
    pthread_exit(NULL);
}

void *Timer(void *value)
{
    time_t debut;
    time_t fin;
    char* TT = (char*)value;
    while(true)
    {
        time(&debut);
        time(&fin);
        while(fin - debut<5.0){
            time(&fin);
        }
        cout<<endl<<"5 secondes ... Text : ";
    }


    pthread_exit(NULL);
}

void *Saisie(void *value)
{
    pthread_t TH;
    int rc;
    char* TT = (char*)value;
    cout<<"\nText : ";
    rc = pthread_create(&TH, NULL, Timer, NULL);
    if (rc){
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    cin>>TT;
    pthread_cancel(TH);
    pthread_exit(NULL);
}


int main ()
{
    cout << "--- TP 1 EXO 3/4 ---" << endl;
    pthread_t TH1,TH2,TH3;
    int rc;

    char TT[MAX_TAILLE];		// Chaine de caractere

    //time_t debut;	//Nb de secondes entre le 1er Janvier 1970 0:00 et la demande de saisie
    //time_t fin;		//Nb de secondes entre le 1er Janvier 1970 0:00 et la saisie

    rc = pthread_create(&TH1, NULL, Saisie, &TT);
    pthread_join(TH1,NULL);
    if (rc){
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    rc=pthread_create(&TH2, NULL, PrintSentence, &TT);
    pthread_join(TH2,NULL);
    if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }
    rc=pthread_create(&TH3, NULL, Visualization, &TT);
    pthread_join(TH3,NULL);
    if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
    }

    cout<<"\nFin du programme \n";

    return 0;
    }
