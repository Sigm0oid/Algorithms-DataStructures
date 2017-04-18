
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
 vi vis;
 int res[101][101];
 int in[101][101];
void dfs(int u,int x,int n) {
    vis[u]=1;
    cout<<"visited"<<u<<endl;
    for(int o=0;o<n;o++){
            if(x!=o){
        if(in[u][o]==1){
            if(vis[o]==0){
                dfs(o,x,n);
            }
        }
      }
    }

}

 int main()
{
      std::ios::sync_with_stdio(false);
        int t;
        cin>>t;
        for(int f=0;f<t;f++){
            memset(res,0,sizeof res);
             memset(in,0,sizeof res);
        int n;
        cin>>n;
        vi vis1;
        cout<<"Case "<<f+1<<":"<<endl;
        string s="+";
        for(int i=0;i<n;i++){

            s+="--";

            for(int j=0;j<n;j++){

            cin>>in[i][j];

            }
        }

         s[s.length()-1]='+';
         cout<<s<<endl;
         dfs(0,10000,n);
        }
      return 0;
}
