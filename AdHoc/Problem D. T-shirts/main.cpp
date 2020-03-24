#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,d,c;
int main()
{
        ll t;
        scanf("%lld",&t);
        ll res=0;
        for(ll i=1;i<=t;i++){
           map<ll,ll> tshirts;
            scanf("%lld %lld %lld",&n,&d,&c);
            res=(d*n);
                for(ll j=0;j<n;j++){
                    ll x;
                    scanf("%lld",&x);
                   tshirts[x]++;
                }
                ll cmp=0;
                for(auto j=tshirts.begin();j!=tshirts.end();j++){
                cmp+=j->second;
                res=min(res,((c*j->first)*cmp)+(n-cmp)*d);
                }
            cout<<"Case "<<i<<": "<<res<<endl;
        }
    return 0;
}
