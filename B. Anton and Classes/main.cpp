#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
ll n,m;
    ll MINR1 = LLONG_MAX ;
    ll MAXL1 = 0 ;
    ll MAXL2 = 0 ;
    ll MINR2 = LLONG_MAX ;
    vi v2 ;
    vi v1 ;

int main()
{
    cin >> n ;


    for (ll i=0;i<n;i++)
    {
        ll x,y ;
        cin >> x >> y ;
        MINR1 = min(MINR1,y) ;
        MAXL1 = max(MAXL1,x);
    }


    cin >> m ;

    for (ll i=0;i<m;i++)
    {
        ll x,y ;
        cin >> x >> y ;
        MAXL2 = max(MAXL2,x);
        MINR2 = min(MINR2,y) ;
    }
    ll diff1,diff2 ;
    if (MINR1<MAXL2) diff1 = MAXL2-MINR1 ;

        else diff1=0 ;
    if (MINR2<MAXL1) diff2 = MAXL1-MINR2 ;

        else diff2=0 ;
    ll ans = max(diff1,diff2);
    cout << ans << endl ;
}
