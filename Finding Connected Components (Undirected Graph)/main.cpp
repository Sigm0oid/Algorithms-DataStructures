#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi vis;
vi visited;
vector<vii> Adjlist;

 void dfs(int u) {
     vis[u]=1;
     cout<<u<<" ";
     for(int j=0;j<(int)Adjlist[u].size();j++){
    ii v = Adjlist[u][j];
    if(vis[v.first]==0){
        dfs(v.first);
    }
     }
 }
int main()
{
    Adjlist.resize(9);
    vis.resize(9);
    Adjlist[0].push_back(make_pair(1,1));
    Adjlist[1].push_back(make_pair(2,1));
    Adjlist[1].push_back(make_pair(3,1));
    //Adjlist[3].push_back(make_pair(4,1));
    //Adjlist[2].push_back(make_pair(7,1));
    Adjlist[7].push_back(make_pair(6,1));
    Adjlist[6].push_back(make_pair(8,1));
    Adjlist[4].push_back(make_pair(5,1));
    int numCC = 0;
    for(int i=0;i<9;i++){
        if(vis[i]==0){
            cout<<"Connected component ";
            dfs(i);
            cout<<endl;
        }
    }

    return 0;
}
