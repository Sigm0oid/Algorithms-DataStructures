#include <bits/stdc++.h>

using namespace std;

int main()
{
    int  n;
    cin>>n;
    if(n==0)
    cout<<"1"<<endl;
    else{
    n--;
    n=n%4;
   int tab[4]={8,4,2,6};
    cout<<tab[n]<<endl;
    }
    return 0;
}
