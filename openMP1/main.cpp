#include <bits/stdc++.h>
#include<sys/time.h>
#include<unistd.h>
#include<omp.h>
typedef long long ll;
using namespace std;
double A[5000][5000];
double X[5000][5000];
double Y[5000][5000];
int N=1000;
void remplire(){

/* initialize random seed: */
  srand (time(NULL));
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
    A[i][j]=rand()%20;
    X[i][j]=rand()%20;
   // cout<<A[i][j]<<" "<<X[i][j]<<endl;
  }
  }
}
void calcul(){

    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
        Y[i][j]=0;
        for(ll k=0;k<N;k++){
            Y[i][j]+=(A[i][k]*X[k][j]);

        }
      }
    }
}

void parralell_calcul(){

#pragma omp parallel for
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
        Y[i][j]=0;
        for(ll k=0;k<N;k++){
            Y[i][j]+=(A[i][k]*X[k][j]);

        }
      }
    }

}
int main()
{

    ///nbr threads max ?
//    const int maxNumThreads = omp_get_max_threads();
//    printf("Maximum number of threads for this machine: %i\n", maxNumThreads);

    ///changer nbr threads
    omp_set_num_threads(4);
    struct timeval start,ennd;
    long mtime,seconds,useconds;

    ///fill matrix with random values
    N=5000;
    remplire();
    gettimeofday(&start,NULL);
    calcul();
    gettimeofday(&ennd,NULL);

    seconds=ennd.tv_sec-start.tv_sec;
    useconds=ennd.tv_usec-start.tv_usec;
    mtime=((seconds)*1000+useconds/1000.0);
    cout<<"Sequanciel  Version :"<<mtime <<" milliseconds"<<endl;

    gettimeofday(&start,NULL);
    parralell_calcul();
    gettimeofday(&ennd,NULL);

    seconds=ennd.tv_sec-start.tv_sec;
    useconds=ennd.tv_usec-start.tv_usec;
    mtime=((seconds)*1000+useconds/1000.0);
    cout<<"Parrralell Version :"<<mtime <<" milliseconds"<<endl;


    /*
    run using terminal
    g++ main.cpp -o obj/Debug/main.o -fopenmp
    then
    ./obj/Debug/main.o
    */
    return 0;
}
