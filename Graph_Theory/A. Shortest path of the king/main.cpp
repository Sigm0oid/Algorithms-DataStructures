#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool inbound(int i,int j){
return(i<8&&j<8&&i>=0&&j>=0);
       }
int xi[8]={1,0,-1,-1,1,0,1,-1};
int yi[8]={1,1,1,0,0,-1,-1,-1};
string moves[8]={"RD","R","RU","U","D","L","LD","LU"};
pair<int,int>parent[8][8];

int mat[8][8];
int vis[8][8];
int dis[8][8];

int is,js,id,jd;

void bfs(int i,int j ){
dis[i][j]=0;
vis[i][j]=1;

queue<pair<int,int> > q;
q.push(make_pair(i,j));
while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
for(int k=0;k<8;k++){
    int x=i+xi[k];
    int y=j+yi[k];
    if(inbound(x,y)){
        if(vis[x][y]==0){
            vis[x][y]=1;
             dis[x][y]=dis[i][j]+1;
           q.push(make_pair(x,y));
           //cout<<x<<" "<<y<<endl;
           mat[x][y]=k;
           parent[x][y]=make_pair(i,j);

        }

        }
    }

}
}




int main()
{
    string s,d;
    cin>>s>>d;
    is=8-(s[1]-'0');
    id=8-(d[1]-'0');
    js=s[0]-'a';
    jd=d[0]-'a';
    memset(vis,0,sizeof vis);
    memset(mat,0,sizeof mat);
    memset(dis,100,sizeof dis);

    bfs(is,js);
    cout<<dis[id][jd]<<endl;
    int cmp=dis[id][jd];
    vector<string> v;
while(cmp>0){
    v.push_back(moves[mat[id][jd]]);
     int a=parent[id][jd].first;
     int b=parent[id][jd].second;
     id=a;
     jd=b;
     cmp--;

}

for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<endl;

}


    return 0;
}

