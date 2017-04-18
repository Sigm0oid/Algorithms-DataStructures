#include <iostream>

using namespace std;
double d,a,b,f;


int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll nb_test;
    cin>>nb_test;
    cin>>d>>a>>b>>f;
    double posA=0.0,posB=d;
    bool fly=0;
    double res=0;
    while(abs(posA-posB)>0.001){
    if(fly==0)
    {
        ///from A to B
       double t=(double)(posB-posA)/((f+b)*1.0);
    }
    else{
        ///from B to A
        double t=(double)(posB-posA)/((f+a)*1.0);

    }
    res+=(posB-posA);
    posA+=(t*a);
    posB-=(t*b);
    fly=(1-fly);
    }
    cout<<res<<endl;
    }
    return 0;
}
