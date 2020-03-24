#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool intbound(int i,int j){
return(i<8&&j<8<i>=0&&j>=0);
       }
int xi[8]={1,0,-1,-1,1,0,1,-1};
int yi[8]={1,1,1,0,0,-1,-1,-1};
string moves[8]={"LD","L","LU","U","D","R","RD","RU"};
vector<vector<string> > res;

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
    if(intbound(x,y)){
        if(vis[x][y]==0){
         //   path.push_back(moves[k]);
            vis[x][y]=1;
             dis[x][y]=dis[i][j]+1;
           q.push(make_pair(x,y));
           mat[x][y]=k;
           // path.pop_back();

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
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
        cout<<mat[i][j]<<" ";
        }cout<<endl;
    }



    return 0;
}
