#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;

ll n,sz;
ll p[100010];
ll parent[100010];





void dfs(int u){
   // cout<<" u "<<u<<endl;
    ll ans=1;
    p[u]=1;
    ll sum=0;
    for(ll i=0;i<(ll)Adjlist[u].size();i++){
        ll v=Adjlist[u][i].first;
        if(parent[v]!=u){
        parent[v]=u;
        dfs(v);
        p[u]+=(p[v]*Adjlist[u][i].second);
        }
        }
        cout<<" p avant  for u"<<u<<" "<<p[u]<<endl;

    for(ll i=0;i<(ll)Adjlist[u].size();i++){
    if(parent[Adjlist[u][i].first]!=u){
        for(ll j=0;j>=0;j--){
            p[u]+=(p[Adjlist[u][i].first]*p[Adjlist[u][j].first]);
        }
    }

    }
    }



int main()
{
        cin>>n;
        Adjlist.resize(n);
        for(ll i=0;i<(n-1);i++){
            ll a,b,c;
            cin>>a>>b>>c;
            a--;
            b--;
            Adjlist[a].push_back(ii(b,c));
            Adjlist[b].push_back(ii(a,c));
            }


        memset(p,0,sizeof p);
        memset(parent,-1,sizeof parent);
        dfs(0);

        cout<<p[0]<<endl;
    return 0;
}

