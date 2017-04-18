#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
map<int,map<int,int> > adjlist;
bitset<110> colors[110][110];
int n,m,q;
int vis[110];
int res=0;
int dfs(int src,int dis,int color){
vis[src]=1;
if(src==dis)
return 1;
int ans=0;
for(auto i=adjlist[src].begin();i!=adjlist[src].end();i++){
int v=i->first;
    if(vis[v]==0&&colors[src][v][color]==1){
        vis[v]=1;
        ans+=dfs(v,dis,color);
    }

}
return ans;
}

int main()
{
    cin>>n>>m;
    set<int>all_color;
    memset(colors,0,sizeof colors);
    for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    adjlist[a][b]++;
    adjlist[b][a]++;
    colors[a][b][c]=1;
    colors[b][a][c]=1;
    all_color.insert(c);
    }
    cin>>q;
    while(q--){
    res=0;

    int a,b;
    cin>>a>>b;
    for(auto i=all_color.begin();i!=all_color.end();i++)
    {
    res+=dfs(a,b,*i);
    memset(vis,0,sizeof vis);
    }
    cout<<res<<endl;

    }
    return 0;
}
