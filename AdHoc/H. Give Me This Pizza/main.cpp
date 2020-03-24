#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main()
{
    freopen("in.in","r",stdin);
    ll n;
    cin>>n;
    vector<ll> tab;
    vector<ll> res;
    vector<ll>indice(51);

    res.assign(n,-1);
    indice.assign(51,n+1);
    for(ll i=0;i<n;i++)
    {
    ll x;
    cin>>x;
    tab.push_back(x);
    }
    for(ll i=tab.size()-1;i>=0;i--){
        ll tmp=n+1;
        for(ll j=tab[i]+1;j<51;j++){
           tmp=min(tmp,indice[j]);
        }
        indice[tab[i]]=i;
        (tmp!=n+1)?res[i]=tab[tmp]:res[i]=-1;
    }
    for(ll i=0;i<n;i++)
    {if(i!=0)
    cout<<" ";
    cout<<res[i];}
    return 0;

}
