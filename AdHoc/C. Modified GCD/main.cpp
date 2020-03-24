#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
 set <ll> aDivisors ;
 set <ll> bDivisors ;
 vector <ll> aFactors;
 vector <ll> bFactors;
vector<ll> factors(ll n) {
vector<ll> f;
for (ll x = 2; x*x <= n; x++) {
while (n%x == 0) {
f.push_back(x);
n /= x;
}
}
if (n > 1) f.push_back(n);
return f;
}

void genera(ll pos,ll prod){
    if(pos==aFactors.size())
    return ;

    for(ll i=pos;i<aFactors.size();i++){
        aDivisors.insert(prod*aFactors[i]);
        genera(i+1,prod*aFactors[i]);
    }

}

void generb(ll pos,ll prod){
    if(pos==bFactors.size())
    return ;
    for(ll i=pos;i<bFactors.size();i++){
        bDivisors.insert(prod*bFactors[i]);
        generb(i+1,prod*bFactors[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll a,b ;
    cin >> a >> b ;
    ll n ;
    cin >> n ;
    aFactors = factors(a) ;
    aFactors.push_back(1) ;
    bFactors = factors(b) ;
    bFactors.push_back(1) ;
    genera(0,1);
    generb(0,1);

    vector<ll> v_intersection;
    set_intersection(aDivisors.begin(), aDivisors.end(),
                          bDivisors.begin(), bDivisors.end(),
                          back_inserter(v_intersection));
    /*for (ll i=0;i<v_intersection.size();i++)
    {
        cout << v_intersection[i] << endl ;
    }*/
     /*for (auto i: aDivisors)
        cout << i << endl ; */
    for (ll i=0;i<n;i++)
    {
        ll low,high ;
        cin >> low >> high ;
        ll j=0 ;
        ll ans=-1 ;
        while (v_intersection[j] <low&& j<v_intersection.size())
        {
            j++ ;
            //cout << v_intersection[j] << endl ;
        }
        while (v_intersection[j] <=high&& j<v_intersection.size())
        {
            ans=v_intersection[j] ;
            j++ ;
            //cout << v_intersection[j] << endl ;
        }
        cout << ans << endl ;
    }

}
