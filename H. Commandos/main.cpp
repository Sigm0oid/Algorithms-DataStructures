#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int tab[15][15][15];
int dp[15][15][15];
int n;

int dfs(int f,int a,int b){
if(a>9||b>9||f<0||a<0||b<0){
return 0;}
 if(dp[f][a][b]!=-1)
 return dp[f][a][b];
int res=tab[f][a][b];
int call1=dfs(f,a,b+1);
int call2=dfs(f,a+1,b);
int call3=dfs(f-1,a,b);

int mx=max(call1,call2);
res+=max(mx,call3);



return dp[f][a][b]=res;

}


int main()
{
    //freopen("commandos.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
    memset(dp,-1,sizeof dp);
    memset(tab,0,sizeof tab);
    cin>>n;
    int f,y,x,h;
    for(int i=0;i<n;i++){
//    int a,b,c;
    cin>>f>>y>>x>>h;
    tab[f-1][x-1][y-1]=h;

    }
    //vis[9][0][0]=1;
    cout<<dfs(9,0,0)<<endl;

    }
    return 0;
}
