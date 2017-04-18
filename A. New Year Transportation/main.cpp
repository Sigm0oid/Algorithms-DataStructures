#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi vis;

void dfs(int s){
vis[s]=1;
for(int i=0;i<(int)Adjlist[s].size();i++){
    int v=Adjlist[s][i].first;
    if(vis[v]==0){
        dfs(v);
    }
}

   }

int main()
{
    int n,dist;
    cin>>n>>dist;
    vis.resize(n);
    Adjlist.resize(n);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;

        Adjlist[i].push_back(ii(x+i,1));

    }
    dfs(0);
//    for(int i=0;i<n;i++){
//        cout<<vis[i]<<" ";
//    }
    if(vis[dist-1]==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
