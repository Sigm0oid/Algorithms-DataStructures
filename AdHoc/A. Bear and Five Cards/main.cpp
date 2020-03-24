#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    map<ll,ll> mp;
    ll maax=0,sum=0;
    for(int i=0;i<5;i++){
    ll x;
    cin>>x;
    mp[x]++;
    sum+=x;
    if(mp[x]>1)
    maax=max(maax,min(mp[x],3LL)*x);
    }

    cout<<sum-maax<<endl;
    return 0;
}
