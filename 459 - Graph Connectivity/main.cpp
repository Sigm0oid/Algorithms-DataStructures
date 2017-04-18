#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
int vis[26];
void bfs(int u,vector<vii> Adjlist){
queue<int> q;
vis[u]=1;
q.push(u);
while(!q.empty()){
        u=q.front();
        q.pop();
    for(int i=0;i<(int)Adjlist[u].size();i++){
            ii v=Adjlist[u][i];
            if(vis[v.first]==0){
                    vis[v.first]=1;
            //cout<<v.first<<" visited"<<endl;
                q.push(v.first);
            }

        }
    }
}

int main()
{
      std::ios::sync_with_stdio(false);
      //freopen("in.in","r",stdin);
      //freopen("out.out","w",stdout);







       int t;
       cin>>t;
         string s;
        getline(cin,s);
        getline(cin,s);
       for(int v=0;v<t;v++){
        memset(vis,0,sizeof vis);

        getline(cin,s);
        int n=s[0]-'A'+1;
        vector<vii>Adjlist(n);
        int vis1[26];
        memset(vis1,0,sizeof vis);
        while (getline(cin, s) && !s.empty()) {
                Adjlist[s[0]-'A'].push_back(make_pair((s[1]-'A'),1));
                Adjlist[s[1]-'A'].push_back(make_pair((s[0]-'A'),1));
                //cout<<s[1]-'A'<<" conected to "<<s[0]-'A'<<endl;
        }
        bfs(0,Adjlist);
        int res=1;
        int indx=-1;
        //memcpy(vis,vis1,sizeof vis);
       do{
            indx=-1;
        for(int i=0;i<n;i++){
            if(vis1[i]!=vis[i]){
                vis1[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(vis1[i]==0){
                indx=i;
                }
            }
            if(indx!=-1){
                    res++;
                    bfs(indx,Adjlist);

            }


        } while(indx!=-1);


        cout<<res<<endl;
        if(v!=t-1){
            cout<<endl;
        }
       }

    return 0;
}
