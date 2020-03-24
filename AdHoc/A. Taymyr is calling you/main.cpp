#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,z;
    cin>>n>>m>>z;
    map<int,int> ariste;
    for(int i=1;i<=z&&i*m<=z;i++){
    ariste[m*i]++;
    }
    for(int i=1;i<=z&&i*n<=z;i++){
    ariste[n*i]++;
    }
    int res=0;
    for(auto i=ariste.begin();i!=ariste.end();i++){
    if(i->second>1)
    res++;
    }
    cout<<res<<endl;
    return 0;
}
