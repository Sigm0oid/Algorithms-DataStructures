#include <bits/stdc++.h>
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
using namespace std;

vi vis[9]=0;


 void dfs(int u,vii Adjlist) {
     dfs[u]=1;
     cout<<u<<" visited"<<endl;
     for(int j=0;j<(int)Adjlist.size();j++){
    ii v=Adjlist[u][j];
    if(vis[v.first]==0){
        dfs(v.first);
    }
     }
 }
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
