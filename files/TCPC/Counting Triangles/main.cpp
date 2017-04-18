#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int A_i = 0;A_i < N;A_i++){
       cin >> A[A_i];
    }
    int a=0;
    int o=0;
    int r=0;
    int i=N-1;
    int j=i-1;
    int k=j-1;
    while(i>1){



     if((A[i]*A[i])<((A[j]*A[j])+((A[k]*A[k])))){

    a++;
    k--;
    }
       else  if((A[i]*A[i])==((A[j]*A[j])+((A[k]*A[k])))){

    r++;
    k--;
    }
    else   {
    if(((A[k]+A[j])>A[i])){
    o++;
    k--;

    }
    else {

    j--;
    k=j-1;

    }}


    if(j==0){
    i--;
    j=i-1;
    k=j-1;}
    }
    if(k==-1){
    j--;
    k=j-1;}


   cout<<a<<" "<<r<<" "<<o<<" "<<endl;
     return 0;
}
