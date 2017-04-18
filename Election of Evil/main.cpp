#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<string> u_tab;
map<string,int> v_tab;
map<string,int> vis;
map<string,int> res;
int n,t,u,m,v;
map<string,map<string,int> > Adjlist;

void dfs(string s){
vis[s]=1;
if(v_tab.find(s)!=v_tab.end())
res[s]=1;
for(map<string,int>::iterator it=Adjlist[s].begin();it!=Adjlist[s].end();it++){
string adj=it->first;
if(vis[adj]==0){
dfs(adj);
}
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
    cin>>u>>v>>m;
    u_tab.clear();
    v_tab.clear();
    u_tab.resize(u);
    res.clear();
    vis.clear();
    Adjlist.clear();


    for(int i=0;i<u;i++)
    {
    cin>>u_tab[i];
    Adjlist[u_tab[i]];
    }
    for(int i=0;i<v;i++)
    {string s;
    cin>>s;
    v_tab[s]=0;
    Adjlist[s];
    }

    for(int i=0;i<m;i++){
    string a,b;
    cin>>a>>b;
    Adjlist[a][b]=1;
    }

    for(int i=0;i<u;i++){
    if(vis[u_tab[i]]==0)
    dfs(u_tab[i]);
    }

    for(map<string,int>::iterator it=res.begin();it!=res.end();it++)
    cout<<it->first<<" ";
    cout<<endl;


    }
    return 0;
}
