#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<ll> strengths,vis;
ll start;
cin>>n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    ll maax=LLONG_MIN;
    ll indice_max=-1;
    strengths.resize(n);
    vis.resize(n);
    for(ll i=0;i<n;i++){
    cin>>strengths[i];
    if(strengths[i]>maax)
    {
        maax=strengths[i];
        indice_max=i;
    }
    }
    ll k=(n-1);

    while(k--){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));

    }



    return 0;
}
