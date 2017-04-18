#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n,m;
//vector<int> distance;
vector<string> tab;
int vis[1010][1010];
int dis[1010][1010];
ii start;
int my_dis=0;
bool inbound(int i,int j){
return(i<n&&j<m&&i>=0&&j>=0);
}
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};

void dijkstra(int i,int j){
vis[i][j]=1;
dis[i][j]=0;
queue<ii> pq;
pq.push(ii(i,j));
while(!pq.empty()){
ii u=pq.front();
pq.pop();
for(int k=0;k<4;k++){
    int x=u.first+xi[k];
    int y=u.second+yi[k];
    if(inbound(x,y)&&vis[x][y]==0&&tab[x][y]!='T'){
    vis[x][y]=1;
    dis[x][y]=dis[u.first][u.second]+1;
    if(tab[x][y]=='S')
    my_dis=dis[x][y];
    pq.push(ii(x,y));
    }
}
}
return;
}
int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        tab.push_back(s);
        for(int j=0;j<m;j++){
        if(s[j]=='E')
        start=ii(i,j);
        }
    }
    memset(vis,0,sizeof vis);
    fill(dis[0],dis[0]+1000000,1000010);
     //fill(dp[i], dp[i] + MAX, );
    dijkstra(start.first,start.second);
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
       // cout<<vis[i][j]<<" ";
            if(dis[i][j]<=my_dis&&tab[i][j]>'0'&&tab[i][j]<='9'&&vis[i][j]==1)
            res+=(tab[i][j]-'0');
        }
       // cout<<endl;
    }
    cout<<res<<endl;
    return 0;
}
