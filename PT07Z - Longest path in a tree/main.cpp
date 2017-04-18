#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
vector<vii>Adjlist;
vi vis;
int dfs(int x,int n){
    vis[x]=1;
    int mx=0;
    for(int i=0;i<(int)Adjlist[x].size();i++){
        if(vis[Adjlist[x][i].first]==0){
                vis[Adjlist[x][i].first]=1;
             mx=max(mx,1+dfs(Adjlist[x][i].first,n));
             //cout<<mx<<endl;
        }
    }
    return mx;

}

int bfs(int x){
    vis[x]=1;
   queue<int> q;
   q.push(x);
   int u;
   while(!q.empty()){
    u=q.front();
    q.pop();
    for(int i=0;i<Adjlist[u].size();i++){
        if(vis[Adjlist[u][i].first]==0){
           vis[Adjlist[u][i].first]=1;
           q.push(Adjlist[u][i].first) ;
        }
    }

   }

    return u;

}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    Adjlist.resize(n);
    vis.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        Adjlist[u-1].push_back(make_pair(v-1,1));
        Adjlist[v-1
        ].push_back(make_pair(u-1,1));
    }


    int s=bfs(0);
    vis.clear();
    vis.resize(n);
    //cout<<s<<" ";
    cout<<dfs(s,n);
    return 0;
}
