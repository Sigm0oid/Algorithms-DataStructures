#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
//vector<vii>Adjlist;
//vector<vi> dist;
#define INF 1000000000
int tab[1001][1001];
long long  dist[1001][1001];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

bool inbound(int i,int j,int r,int c){
return((i>=0)&&(i<r)&&(j>=0)&&(j<c));
}

void  costumbfs(int xs,int ys,int r,int c){
 queue<int> q;
 q.push(xs);
 q.push(ys);
 dist[xs][ys]=0;
 while(!q.empty()){
      //  cout<<"cc"<<endl;
    int xi=q.front();
    q.pop();
    int yi=q.front();
    q.pop();
    for(int i=0;i<4;i++){
       // cout<<xi+x[i]<<" "<<yi+y[i]<<" "<<dist[xi+x[i]][yi+y[i]]<<endl;
            if((tab[xi+x[i]][yi+y[i]]!=-1)&&(inbound(xi+x[i],yi+y[i],r,c))&&(dist[xi+x[i]][yi+y[i]]==-1)){
               dist[xi+x[i]][yi+y[i]]=dist[xi][yi]+1;

               q.push(xi+x[i]);
               q.push(yi+y[i]);

               }

    }
 }

}

int main()
{
    int r,c;
    while((cin>>r>>c)&&(r!=0)&&(c!=0)){
            memset(tab,0,sizeof tab);
            memset(dist,-1,sizeof dist);
            int bomb;
            cin>>bomb;
            for(int i=0;i<bomb;i++){
                int row,nbbombs;
                cin>>row>>nbbombs;
                for(int j=0;j<nbbombs;j++){
                    int col;
                    cin>>col;
                    tab[row][col]=-1;
                }

            }
    int xs,ys,xd,yd;
    cin>>xs>>ys>>xd>>yd;
    costumbfs(xs,ys,r,c);
    cout<<dist[xd][yd]<<endl;
    }
    return 0;
}
