#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<int> parent,vis,sz,problem_noeds;
int n,cmp;
void dfs(int s){
vis[s]=1;
sz[s]=0;
if(problem_noeds[s]==1)
sz[s]++;
for(int i=0;i<Adjlist[s].size();i++){
int v=Adjlist[s][i].first;
if(!vis[v])
{
    parent[v]=s;
    dfs(v);
    sz[s]+=sz[v];

}
}
if(sz[s]==1&&problem_noeds[s]==1)
cmp++;
}
int main()
{
    cin>>n;
    cmp=0;
    Adjlist.resize(n);
    parent.resize(n);
    vis.resize(n);
    sz.resize(n);
    problem_noeds.resize(n);
    for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    Adjlist[a].push_back(ii(b,c));
    Adjlist[b].push_back(ii(a,c));
    if(c==2){
    problem_noeds[b]=1;
    problem_noeds[a]=1;}
    }

    parent[0]=-1;
    dfs(0);
    cout<<cmp<<endl;
    for(int i=n-1;i>=0;i--)
    if(sz[i]==1)
    cout<<i+1<<" ";
    cout<<endl;




    return 0;
}

