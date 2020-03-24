#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
char tab [25][25];
int vis[25][25];
int dis[25][25];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
bool inbound(int i,int j,int h,int w){
return((i>=0)&&(i<h)&&(j>=0)&&(j<w));
       }
void bfs(int i,int j,int h,int w){
dis[i][j]=0;
queue<int> q;
q.push(i);
q.push(j);
while(!q.empty()){
        int xi=q.front();
        q.pop();
        int yi=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            if(inbound(xi+x[k],yi+y[k],h,w)&&(tab[xi+x[k]][yi+y[k]]-'0'>0)&&(tab[xi+x[k]][yi+y[k]]-'0'<=9)){

                    if(dis[xi+x[k]][yi+y[k]]>(dis[xi][yi]+(tab[xi+x[k]][yi+y[k]]-'0'))){
                        dis[xi+x[k]][yi+y[k]]=(dis[xi][yi]+(tab[xi+x[k]][yi+y[k]]-'0'));
                        q.push(xi+x[k]);
                        q.push(yi+y[k]);
                    }

            }
        }

}
}

int main()
{
    ios_base::sync_with_stdio(false);
    int w,h;
    while((cin>>w>>h)&&(w!=0)&&h!=0){
            memset(dis,10000,sizeof dis);
            ii src;
            ii dist;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>tab[i][j];
                if(tab[i][j]=='S'){
                        src.first=i;
                        src.second=j;

                }
                if(tab[i][j]=='D'){
                        dist.first=i;
                        dist.second=j;

                }
            }
        }
        bfs(src.first,src.second,h,w);
//        for(int a=0;a<h;a++){
//            for(int b=0;b<w;b++){
//                cout<<dis[a][b]<<" ";
//            }
//            cout<<endl;
//        }
        int res=10000;
        for(int i=0;i<4;i++ ){

            if(inbound(dist.first+x[i],dist.second+y[i],h,w)){
                res=min(res,dis[dist.first+x[i]][dist.second+y[i]]);
            }
        }
        cout<<res<<endl;





        string s;
        getline(cin,s);
    }

    return 0;
}
