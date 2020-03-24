#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vi dfs_num,dfs_low,s,visited;

vector<vii> Adjlist;
int dfsNumbercounter,numSCC;
void tarjanSCC(int u){
    dfs_low[u]=dfs_num[u]=dfsNumbercounter++;
    s.push_back(u);
    visited[u]=1;
    for(int i=0;i<(int)Adjlist[u].size();i++){
            ii v=Adjlist[u][i];
        if(dfs_num[v.first]==0){
            tarjanSCC(v.first);
        }
        if(visited[v.first]==1)
            dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);

    }
        if(dfs_low[u]==dfs_num[u]){
            cout<<"SSC "<<++numSCC;
            while(1){
                int v=s.back();
                s.pop_back();
                visited[v]=0;
                cout<<v;
                if(u==v)break;}
                cout<<endl;


    }
}
int main()
{

dfs_num.assign(5,0);
dfs_low.assign(5,0);
visited.assign(5,0);
numSCC=dfsNumbercounter=0;
Adjlist.resize(5);
Adjlist[0].push_back(ii(1,1));
Adjlist[1].push_back(ii(3,1));
Adjlist[2].push_back(ii(1,1));
Adjlist[3].push_back(ii(2,1));
Adjlist[3].push_back(ii(4,1));
    for(int i=0;i<5;i++){
        if(dfs_num[i]==0){
            tarjanSCC(i);
        }
    }
    for(int i=0;i<5;i++){
        cout<<dfs_num[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<dfs_low[i]<<" ";
    }
    cout<<endl;

    return 0;
}
