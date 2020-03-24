#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
double d,a,b,f;


int main()
{
    ll T;
    cin>>T;
    while(T--){
    ll nb_test;
    cin>>nb_test;
    cin>>d>>a>>b>>f;
    double posA=0.0,posB=d*1.0;
    bool fly=0;
    double res=0;
    double t;
    double prev=0;
    ll o=1000;
    while(o--){
    if(fly==0)
    {

        ///from A to B
        t=(double)(posB-posA)/((f+b)*1.0);

    }
    else{
        ///from B to A
         t=(double)(posB-posA)/((f+a)*1.0);

    }

    if (fly==0)
    {
        posB-=(t*b);
        res+=(posB-posA);
        posA+=(t*a);
    }
    else{
        posA+=(t*a);
        res+=(posB-posA);
        posB-=(t*b);


    }
    fly=(1-fly);
    //cout<<" pos A "<<posA<<" pos B "<<posB<<endl;
    }
    cout<<nb_test;
    printf(" %.2f\n",res);
    }
    return 0;
}
