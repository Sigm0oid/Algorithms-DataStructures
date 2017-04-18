#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll rest=240-k;
    ll res=0,somme=0;
    for(ll i=1;i<=n;i++){
        if(somme+(i*5)>rest)
            break;
        somme+=(i*5);
        res++;
    }
    cout<<res<<endl;

    return 0;
}
