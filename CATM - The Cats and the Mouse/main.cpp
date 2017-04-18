#include <bits/stdc++.h>

using namespace std;
int tab[100][100];
int distmouse[100][100];
int distcat1[100][100];
int distcat2[100][100];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
bool inbound (int i,int j,int n,int m){
return ((i>=0)&&(i<n)&&(j>=0)&&(j<n));}

void bfs(int i,int j,int n,int m,int dist[100][100])
{
 dist[i][j]=0;
 queue<int> q;
 q.push(i);
 q.push(j);
 while(!q.empty()){
        int xi=q.front();
        q.pop();
        int yi=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            if(inbound(xi+x[k],yi+y[k],n,m)){
                if(dist[xi+x[k]][yi+y[k]]>dist[xi][yi]+1){
                    dist[xi+x[k]][yi+y[k]]=dist[xi][yi]+1;
                    q.push(xi+x[k]);
                    q.push(yi+y[k]);

                }
            }
        }

 }

}
int main()
{
    int n,m;
    cin>>n>>m;
    int p;
    cin>>p;
    //memset(tab,0,sizeof tab);
    memset(distmouse,10000,sizeof distmouse);
    memset(distcat1,10000,sizeof distmouse);
    memset(distcat2,10000,sizeof distmouse);
    int xm,ym,xc1,yc1,xc2,yc2;
    for(int i=0;i<p;i++){
            memset(distmouse,10000,sizeof distmouse);
            memset(distcat1,10000,sizeof distmouse);
            memset(distcat2,10000,sizeof distmouse);

            cin>>xm>>ym>>xc1>>yc1>>xc2>>yc2;
//            tab[xm][ym]=1;
//            tab[xc1][yc1]=2;
//            tab[xc2][yc2]=2;



    bfs(xm-1,ym-1,n,m,distmouse);
    bfs(xc1-1,yc1-1,n,m,distcat1);
    bfs(xc2-1,yc2-1,n,m,distcat2);
    bool found=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0)||(i==n-1)||(j==0)||(j==m-1)){
               // cout<<distmouse[i][j]<<" "<<distcat1[i][j]<<" "<<distcat2[i][j]<<endl;
                if((distmouse[i][j]<distcat1[i][j])&&(distmouse[i][j]<distcat2[i][j]))
                {
                    found=true;
                }
            }
        }
    }



    if(found){
        cout<<"YES"<<endl;

    }
    else{cout<<"NO"<<endl;}

    }



    return 0;
}
