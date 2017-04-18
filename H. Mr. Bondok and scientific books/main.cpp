#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
int n,m,buget;
vector<vii> Adjlist;
vi p;
vector<ll> cost;
vector<ll> benifits;
vector<ll> rannnk;
vector<ll> vis;
ll dfs(int u,ll remain_buget ){
//cout<<" cc"<<endl;
if(buget==0)
return 0;
vis[u]=1;
ll res=benifits[u];
for(int i=0;i<(int)Adjlist[u].size();i++){
    ii v=Adjlist[u][i];
    if(cost[v.first]<=remain_buget&&vis[u]==0){
    p[v.first]=u;
    res=max(res,dfs(v.first,remain_buget-cost[v.first]));
    }
}
res+=dfs(p[u],remain_buget);

return res;


}


int main()
{
    //freopen("tree.in","r",stdin);
    cin>>n>>m>>buget;
    cost.resize(n);
    benifits.resize(n);
    p.assign(n+1,-1);
    rannnk.resize(n+1);
    Adjlist.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<n;i++)
    cin>>cost[i];
    for(int i=0;i<n;i++)
    cin>>benifits[i];
    while(m--){
    int a,b;
    cin>>a>>b;
    Adjlist[b].push_back(ii(a,1));
    rannnk[a]++;
    }
    for(int i=1;i<=n;i++)
    if(rannnk[i]==0)
    Adjlist[0].push_back(ii(i,1));

    set<int> books;
    cout<<dfs(0,books,buget)<<endl;

    return 0;
}

