#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,k;

    vector<ll> holes(1e6+10);
    cin>>n>>m>>k;
    for(ll i=0;i<m;i++){
    ll x;
    cin>>x;
    holes[x]=1;
    }
    ll res=1;
    bool inhole=(holes[1]==1);
    while(k--){
    if(inhole)
    break;
    ll a,b;
    cin>>a>>b;
    if((res==a||res==b)&&(!inhole)){
    if(res==a)
    {
    res=b;
    inhole=holes[b];
    }
    else
    {
    res=a;
    inhole=holes[a];
    }
    }
    }
    cout<<res<<endl;
    return 0;
}
