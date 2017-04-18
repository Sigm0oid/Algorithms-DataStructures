#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
int main()
{
    cin>>n>>m;
    set<ll> items;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        items.insert(x);
    }
    set<ll> buy;
    for(ll i=1;i<=1000000000&&m>=i;i++){

        if(items.find(i)==items.end())
        buy.insert(i),m-=i;
    }
    cout<<buy.size()<<endl;
    for(auto k:buy)
    cout<<k<<" ";
    cout<<endl;


    return 0;
}
