#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
int vis[101];
int level[101];
 //int res[101][101];
// void dfs(int u,int x,vector<vii> Adjlist) {
//     vis[u]=1;
//     if(x!=u){
//     for(int j=0;j<(int)Adjlist[u].size();j++){
//    ii v = Adjlist[u][j];
//    if(vis[v.first]==0){
//          //  cout<<v.first<<" visited"<<endl;
//        dfs(v.first,x,Adjlist);
//    }
//     }
//     }
// }
 void bfs(int u,int x,vector<vii> Adjlist) {
     queue<int> q;
     q.push(u);
     vis[u]=1;
     level[u]=0;
     while(!q.empty()){
         u=q.front();
         q.pop();
         if(u!=x){
    for(int j=0;j<(int)Adjlist[u].size();j++){
    ii v = Adjlist[u][j];
    if(vis[v.first]==0){
            vis[v.first]=1;
            level[v.first]=level[u]+1;
            //cout<<v.first<<" visited at level "<<level[u]+1<<endl;
       q.push(v.first);
            }
        }
         }
     }

 }

int main()
{
      std::ios::sync_with_stdio(false);

   freopen("in.in","r",stdin);
   freopen("out.out","w",stdout);

    int t;
    cin>>t;
    for(int f=0;f<t;f++){
            memset(vis,0,sizeof vis);
            memset(level,0,sizeof vis);

        int n;
        cin>>n;
       int vis1[101];
        vector<vii> Adjlist(n);
        cout<<"Case "<<f+1<<":"<<endl;
        string s="+";
        for(int i=0;i<n;i++){

            s+="--";


            for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(x==1){
                Adjlist[i].push_back(make_pair(j,1));
            }
            }
        }

         s[s.length()-1]='+';
         cout<<s<<endl;
        bfs(0,INF,Adjlist);


         memcpy(vis1, vis, sizeof vis);
              for(int x=0;x<n;x++){
                 cout<<"|";
              if(x==0){
               for(int y=0;y<n;y++){
                    if(vis[y]==1){
                    cout<<"Y";
                    }
                    else{cout<<"N";}
                     cout<<"|";
                }
        cout<<endl<<s<<endl;
            }else{
                memcpy(vis,vis1,sizeof vis);
            if(vis1[x]==1){
                memset(vis,0,sizeof vis);
                bfs(0,x,Adjlist);
            }

                for(int y=0;y<n;y++){
                    if((vis[y]!=vis1[y])||((y==x)&&(vis1[x]==1))){
                    cout<<"Y";
                    }
                    else{cout<<"N";}
                     cout<<"|";
                }
        cout<<endl<<s<<endl;
            }
          //memcpy(vis1, vis, sizeof vis);
         }


    }
return 0;
    }


