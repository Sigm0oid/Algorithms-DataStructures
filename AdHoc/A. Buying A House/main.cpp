#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> tab;
    ll res=LLONG_MAX;
    m--;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x!=0&&x<=k){
            res=min(res,abs(m-i));
        }
    }
    cout<<res*10<<endl;
    return 0;
}
