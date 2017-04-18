#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<ll>  vis;
bool ok=true;
ll N,m;

ll nb_noed=0,nb_edge=0;
void  dfs(ll u){
vis[u]=1;
    nb_noed++;
    for(ll i=0;i<Adjlist[u].size();i++){
        nb_edge++;
        if(vis[Adjlist[u][i].first]==0){
            dfs(Adjlist[u][i].first);
        }
    }
}



int main()
{
    cin>>N>>m;
    Adjlist.resize(N);
    vis.clear();
    vis.resize(N);
    while(m--){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    }

    for(ll i=0;i<N&&ok;i++){
        if(!vis[i]){
        nb_edge=0,nb_noed=0,dfs(i);
        nb_edge/=2;
        if(nb_edge!=(nb_noed*(nb_noed-1)/2))
        ok=false;
        }
    }
    if(!ok)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;

    return 0;
}

