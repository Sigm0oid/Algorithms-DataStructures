#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
int n;
vi color,vis;
void dfs(int s){
vis[s]=1;
for(int i=0;i<Adjlist[s].size();i++){
if(vis[Adjlist[s][i].first]==0&&color[s]==color[Adjlist[s][i].first])
dfs(Adjlist[s][i].first);
}
}
int main()
{
    cin>>n;
    vis.resize(n);
    color.resize(n);
    Adjlist.resize(n);
    for(int i=0;i<n;i++)
    cin>>color[i];
    for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    }
    int nbwhite=0;
    int nbblack=0;
    for(int i=0;i<n;i++){
    if(vis[i]==0)
    {
    //cout<<"connected comp at "<<i+1<<" with color "<< color[i]<<endl ;
    if(color[i]==0)
    nbblack++;
    else
    nbwhite++;
    dfs(i);}
    }
    cout<<min(nbwhite,nbblack)<<endl;
    return 0;
}
