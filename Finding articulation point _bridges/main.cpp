#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
int vis[10001];
int dfs_parent [10001];
int articulationVertex[10001];
int dfs_num [10001];
int dfs_low [10001];
int dfsNumbercount,rootChildren;
void articulation_point(int u){
    cout<<"called on "<<u<<endl;
dfs_low[u]=dfs_num[u]=dfsNumbercount++;
    for(int i=0;i<(int)Adjlist[u].size();i++){
    ii v=Adjlist[u][i];
                if(dfs_num[v.first]==-1){
                    dfs_parent[v.first]=u;
                    if(u==0) rootChildren++;


                    articulation_point(v.first);

//                    cout<<"vertex "<<u<<" and "<<v.first<<endl;
//                    cout<<"low "<<dfs_low[u]<<"num "<<dfs_num[u]<<"low "<<dfs_low[v.first]<<"num "<<dfs_num[v.first]<<endl;
                    if(dfs_low[v.first]>=dfs_num[u])
                        articulationVertex[u]=true;
                          if(dfs_low[v.first]>dfs_num[u])
                            cout<<"Edge "<<u<<" "<<v.first<<"is a articulation bridge"<<endl;
                            dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
                            }

                    else if(v.first!=dfs_parent[u])
                        dfs_low[u]=min(dfs_low[u],dfs_num[v.first]);




}
}




int main()
{
    dfsNumbercount=rootChildren=0;
    memset(dfs_num,-1,sizeof dfs_num);
    memset(vis,0,sizeof vis);
    memset(dfs_low,0,sizeof dfs_low);
    memset(dfs_parent,0,sizeof dfs_parent);
    memset(articulationVertex,0,sizeof articulationVertex);
    Adjlist.resize(6);
    Adjlist[0].push_back(ii(1,1));
    Adjlist[1].push_back(ii(0,1));
    Adjlist[1].push_back(ii(2,1));
    Adjlist[1].push_back(ii(3,1));
    Adjlist[2].push_back(ii(1,1));
    Adjlist[3].push_back(ii(1,1));
    Adjlist[4].push_back(ii(1,1));
    Adjlist[1].push_back(ii(4,1));
    Adjlist[1].push_back(ii(5,1));
    Adjlist[5].push_back(ii(1,1));
    Adjlist[4].push_back(ii(5,1));
    Adjlist[5].push_back(ii(4,1));
    cout<<"bridges "<<endl;
    articulation_point(0);
    articulationVertex[0]=(rootChildren>1);
    cout<<"Articulation vertex"<<endl;
    for(int i=0;i<6;i++){
        if(articulationVertex[i]==1){
            cout<<"vertex"<<i<<endl;
        }
    }
    return 0;
}
