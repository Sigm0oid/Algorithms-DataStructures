#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <vii>Adjlist;
bool Bipartial;
void dfs(int s,vi vis,vi color){
vis[s]=1;
for(int i=0;i<(int) Adjlist[s].size();i++){
    if(vis[Adjlist[s][i].first]==-1){
        vis[Adjlist[s][i].first]=1;
        color[Adjlist[s][i].first]=1-color[s];
        dfs(Adjlist[s][i].first,vis,color);
    }
    else{
        if(color[s]==color[Adjlist[s][i].first]){
            Bipartial=false;
            return;
        }
    }
}
}

int main()
{ int V;
  cin>>V;
    do{
            Bipartial=true;

            int E;
            cin>>E;

            Adjlist.resize(V);
            for(int i=0;i<E;i++){
                int a,b;
                cin>>a>>b;
                Adjlist[a].push_back(make_pair(b,1));
                Adjlist[b].push_back(make_pair(a,1));

            }
            vi vis(V,-1);
            vi color(V,-1);
            dfs(0,vis,color);
//            bool Bipartial=true;
//            queue<int> q;
//            q.push(0);
//            while((!q.empty())&&(Bipartial)){
//                int u=q.front();
//                q.pop();
//                for(int i=0;i<(int)Adjlist[u].size();i++){
//                    if(vis[Adjlist[u][i].first]==-1){
//                            vis[Adjlist[u][i].first]=1;
//                        q.push(Adjlist[u][i].first);
//                        color[Adjlist[u][i].first]=1-color[u];
//
//
//                    }else{
//                        if(color[u]==color[Adjlist[u][i].first]){
//                            Bipartial=false;
//                        }
//                    }
//                }
//            }

if(Bipartial){
    cout<<"BICOLORABLE."<<endl;
}
else{
    cout<<"NOT BICOLORABLE."<<endl;
}
    cin>>V;
    Adjlist.clear();
    color.clear();
    vis.clear();
      }while(V!=0);
    return 0;
}
