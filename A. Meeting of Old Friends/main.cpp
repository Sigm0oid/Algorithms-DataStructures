#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll l1,l2,r1,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    ll a,b;
    a=max(l1,l2);
    b=min(r1,r2);

    if(b<a){cout<<0<<endl;}
    else{
    ll res=b-a+1;

    if((k>=a)&&(k<=b)){res--;}
    cout<<res<<endl;
    }


    return 0;
}

