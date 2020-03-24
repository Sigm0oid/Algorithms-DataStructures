#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll nb_test,n;
    cin>>nb_test>>n;

    ll pos=0,odd=0,even=0;
    //pos=(n*(n-1)/2);
    for(ll i=1;i<2*n;i++){
    if(i&2)
    even+=i;
    else
    odd+=i;
    if(i<=n)
    pos+=i;
    }
    cout<<nb_test<<" "<<pos<<" "<<odd<<" "<<even<<endl;

    }
    return 0;
}
