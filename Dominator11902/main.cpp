#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
int n;
int domination[110][110];
int vis1[110];
int vis[110];

void bfs(){
    vis1[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0;i<Adjlist[a].size();i++){
            if(vis1[Adjlist[a][i].first]==0 ){
            vis1[Adjlist[a][i].first]=1;
            q.push(Adjlist[a][i].first);
            }
        }
    }
}
void bfs1(int j){
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        if(a==j)

        continue;

        for(int i=0;i<Adjlist[a].size();i++){
            if(vis[Adjlist[a][i].first]==0 ){
            vis[Adjlist[a][i].first]=1;
            q.push(Adjlist[a][i].first);
            }
        }
    }
}
int main()
{
//freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    memset(domination,0,sizeof domination);
    cin>>n;
    Adjlist.clear();
    Adjlist.resize(n);
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            int x;
            cin>>x;
            if(x!=0)
            Adjlist[j].push_back(ii(k,1));

        }
    }
    memset(vis1,0,sizeof vis1);

    bfs();
    for(int j=0;j<n;j++)
    {
          if(vis1[j]!=0){
           memset(vis,0,sizeof vis);
          bfs1(j);
          for(int k=0;k<n;k++)
          domination[j][k]=(vis[k]!=vis1[k]);
          domination[j][j]=1;
          }


    }
    string line="+";
    for(int k=0;k<2*n-1;k++)
    line+="-";
    line+="+";
    cout<<"Case "<<i+1<<":"<<endl;
    for(int j=0;j<n;j++){
    cout<<line<<endl;
    for(int k=0;k<n;k++){
    cout<<"|";
    if(domination[j][k]==1)
    cout<<"Y";
    else
    cout<<"N";
    }
    cout<<"|"<<endl;
    }
    cout<<line<<endl;

    }
    return 0;
}
