#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long res=0;
    int k1,k2,k3,k4;
    cin>>k1>>k2>>k3>>k4;
    int nb1=min(k1,k3);
    nb1=min(nb1,k4);
    k1-=nb1;
    k3-=nb1;
    k4-=nb1;
    res+=(256*nb1);
    int nb2=min(k1,k2);
    k1-=nb2;
    k2-=nb2;
    res+=(32*nb2);
    cout<<res<<endl;
    return 0;
}
