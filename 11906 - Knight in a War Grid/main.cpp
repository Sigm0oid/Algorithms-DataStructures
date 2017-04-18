#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int r,c,m,n,w;
int tab[110][110];
int vis[110][110];
ll oddans;
ll evenans;
int xi[8];
int yi[8];
bool inbound(int x,int y){
return ((x>=0)&&(x<r)&&(y>=0)&&(y<c)&&(tab[x][y]==0));}
void bfs(int x,int y){
    vis[x][y]=1;
    int lclans=0;
    for(int i=0;i<8;i++){

        if(inbound(x+xi[i],y+yi[i])){

                    lclans++;

                    if(vis[x+xi[i]][y+yi[i]]==0){
                bfs(x+xi[i],y+yi[i]);

            }
        }

    }
    if(n==m||n==0||m==0){
        lclans/=2;
    }
    if(lclans & 1){oddans++;}
    else{evenans++;}
}

int main()
{
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    int cmp=1;
    while(t--){
    memset(tab,0,sizeof tab);
    memset(vis,0,sizeof vis);

    cin>>r>>c>>m>>n;
    xi[0]=m;
    xi[1]=m;
    xi[2]=n;
    xi[3]=n;
    xi[4]=-m;
    xi[5]=-m;
    xi[6]=-n;
    xi[7]=-n;


    yi[0]=n;
    yi[1]=-n;
    yi[2]=m;
    yi[3]=-m;
    yi[4]=n;
    yi[5]=-n;
    yi[6]=m;
    yi[7]=-m;


    cin>>w;
    for(int i=0;i<w;i++){
            int x,y;
    cin>>x>>y;
        tab[x][y]=1;
    }
    oddans=0;
    evenans=0;
    bfs(0,0);
    cout<<"Case "<<cmp<<": "<<evenans<<" "<<oddans<<endl;
    cmp++;

    }
    return 0;
}
