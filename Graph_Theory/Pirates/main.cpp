#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<int,ii> viii;
int n,m,q;
bool inbound(int i,int j){
return (i>=0&&i<n&&j>=0&&j<m);
}
int x8[8]={0,-1,-1,-1,0,1,1,1};
int y8[8]={1,1,0,-1,-1,-1,0,1};

char mat[1010][1010];
int dis[1010][1010];

void dijkstra(int i,int j){
dis[i][j]=0;
priority_queue <iii,vector<iii>, greater<iii> > pq;
//pq.push(make_pair(0,ii(i,j)));
while(!pq.empty()){
cout<<"c"<<endl;
iii v=pq.top();pq.pop();
if(dis[v.second.first][v.second.second]<v.first)
continue;
for(int k=0;k<8;k++){
int xi=x8[k]+v.second.first;
int yi=y8[k]+v.second.second;
if(inbound(xi,yi)){
if(dis[xi][yi]>dis[v.second.first][v.second.second]){
dis[xi][yi]=dis[v.second.first][v.second.second]+1;
if (mat[xi][yi]=='~'&&mat[v.second.first][v.second.second]=='O')
 dis[xi][yi]+=1;
pq.push(make_pair(dis[xi][yi],ii(xi,yi)));
}
}

}

}
}

int main()
{
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){
        cin>>mat[i][j];
        dis[i][j]=INT_MAX;

            }
        }



    for(int i=0;i<q;i++){
    memset(dis,INT_MAX,sizeof dis);
    int x,y;
    cin>>x>>y;
    x--;y--;
    dijkstra(x,y);
    int xdi,ydi;
    cin>>xdi>>ydi;
    xdi--;ydi--;
    cout<<dis[xdi][ydi]<<endl;
    }
    return 0;
}
