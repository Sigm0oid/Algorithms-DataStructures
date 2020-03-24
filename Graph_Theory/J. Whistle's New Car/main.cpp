#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
vi vis,depth,fuel,dis,res;
ll n;

void dfs(ll x ,ll dep){
    depth[dep]=x;
    vis[x]=1;
    if(x!=0)
    for(ll j=0;j<dep;j++)
    {
        if(fuel[depth[j]]>=dis[dep]-dis[j])
        res[dep[j]]++;
    }
    for(ll i=0;i<Adjlist[x].size();i++){
        ii u=Adjlist[x][i];
        if(!vis[u.first])
        dis[depth+1]=dis[dep]+u.second,dfs(u.first,dep+1);

    }


}

int main()
{
    //freopen("car.in","r",stdin);
    ios_base::sync_with_stdio(false);

    ll t;
    cin>>t;
    while(t--){
        Adjlist.clear();
        depth.clear();
        vis.clear();
        fuel.clear();
        dis.clear();
        res.clear();
        cin>>n;
        Adjlist.resize(n);
        depth.resize(n);
        dis.resize(n);
        vis.resize(n);
        fuel.resize(n);
        res.resize(n);
            for(ll i=0;i<n;i++){cin>>fuel[i];}
            for(ll i=0;i<(n-1);i++){
                ll a,b,c;
                cin>>a>>b>>c;
                a--,b--;
                Adjlist[a].push_back(ii(b,c));
                Adjlist[b].push_back(ii(a,c));
                }
    dfs(0,0);
    for(ll i=0;i<n;i++)cout<<res[i]<<" ";
    cout<<endl;
    }


    return 0;
}
