#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;


int main()
{
    ios_base::sync_with_stdio(false);

    ll n,m ;
    scanf("%lld %lld ",&n,&m);
    for (ll  t=0;t<m;t++)
    {
        bool ok=false ;
        ll k ;
        scanf("%lld",&k);
            map<ll,ll> mp ;
        for (ll i=0;i<k;i++)
        {
            ll v ;
            scanf("%lld",&v);
            if (v<0) v*=(-1) ;
            if (mp[v]==1)
            {
                ok=true ;
            }
            else
            {
                mp[v]++ ;
            }
        }
        if (ok==false)
        {
            printf("YES\n") ;
            return 0 ;
        }
    }
   printf("NO\n") ;
    return 0 ;
}
