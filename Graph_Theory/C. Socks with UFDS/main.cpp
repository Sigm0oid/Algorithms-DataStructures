#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi color,vis;
int n,k,m;
 map<int,int> mapp;
 int nbnoed;

 void dfs(int i){
 nbnoed++;
 vis[i]=1;
 mapp[color[i]]++;
 for(int j=0;j<Adjlist[i].size();j++){
 int v=Adjlist[i][j].first;

 if(vis[v]==0){
 dfs(v);
 }
 }
 }

int main()
{
//freopen("in.in","r",stdin);
    cin>>n>>m>>k;
    color.resize(n);
    vis.resize(n);
    Adjlist.resize(n);
    for(int i=0;i<n;i++)
    cin>>color[i];
    for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;

    a--;b--;
    //cout<<a<<" "<<b<<endl;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    //cout<<Adjlist[a][Adjlist[a].size()-1].first<<" "<<Adjlist[b][Adjlist[b].size()-1].first<<endl;
    }
    ll res=0;

    for(int i=0;i<n;i++){
    if(vis[i]==0){

    mapp.clear();
    nbnoed=0;
    dfs(i);
    int mx=0;
    for( map<int,int>::iterator j=mapp.begin();j!=mapp.end();j++){
    if(j->second>mx){mx=j->second; }
    }
    res+=nbnoed-mx;

    }
    }
    cout<<res<<endl;
    return 0;
}
