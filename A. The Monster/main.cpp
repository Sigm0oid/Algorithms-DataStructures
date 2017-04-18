#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll res=-1;

    for(ll i=0;i<=10000&&res==-1;i++){
         for(ll j=0;j<=10000&&res==-1;j++)
        if((b+(i*a))==(d+(j*c))){
            res=(b+(i*a));
        }
    }
    cout<<res<<endl;
    return 0;
}
