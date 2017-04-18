#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main()
{
    ll n,m;
    vector<ii> ai;
    vector<ll> bi;

    scanf("%lld",&m);
    bi.resize(m);
    for(ll i=0;i<m;i++)
    cin>>bi[i];

    scanf("%lld",&n);
    vector<ll> tab(n);
    ai.resize(n);
    for(ll i=0;i<n;i++)
    {
    ll x;
    scanf("%lld",&x);
    ai[i].first=x;
    ai[i].second=i;
    }

    sort(ai.begin(),ai.end());
    sort(bi.begin(),bi.end());
    ll i=0,j=0;
    while(i<n&&j<m){
    if(ai[i].first<=bi[j]){
    tab[ai[i].second]=bi[j];
    i++;
    }
    else
    j++;
    }
    for(ll i=0;i<n;i++)
    if(tab[i]==0)
    printf("Dr. Samer cannot take any offer :(.\n");
    else
    printf("%lld\n",tab[i]);


    return 0;
}
