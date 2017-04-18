#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n,m,w;
vi p;
int mf,f,s=0,t=209;
int res[210][210];
bool sol_weap[110][110];
bool sol_places[110][110];
bool places_weap[110][110];
void augment(int v,int minEdge){

    if(v==s){f=minEdge;return;}
    else if(p[v]!=-1){augment(p[v],min(minEdge,res[p[v]][v]));
                       res[p[v]][v]-=f;res[v][p[v]]+=f;
    }
}

void Edmons(){
mf=0;
while(1){
    f=0;
    vi dis(210,INT_MAX); dis[s]=0;
    p.assign(210,-1);
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
       // cout<<u<<" u "<<endl;

        if(u==t)
        break;

        for(int i=0;i<210;i++){
            if(res[u][i]>0&&dis[i]==INT_MAX){
                dis[i]=dis[u]+1,q.push(i),p[i]=u;

                }
        }
    }
    augment(t,INT_MAX);
    if(f==0) break;
    mf+=f;
}

}
int main()
{
    int T;
    cin>>T;
    while(T--){
    cin>>n>>m>>w;
    memset(res,0,sizeof res);
    memset(sol_places,0,sizeof sol_places);
    memset(sol_weap,0,sizeof sol_weap);
    memset(places_weap,0,sizeof places_weap);

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++)
        {
        int x;
        cin>>x;
        sol_places[i][x-1]=1;
        }
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++)
        {
        int x;
        cin>>x;
        sol_weap[i][x-1]=1;
        }
    }
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        for(int j=0;j<y;j++){
            int k;
            cin>>k;
                places_weap[i][k-1]=1;
        }

    }

    for(int i=0;i<n;i++){
            res[s][i+1]=1;
        for(int j=0;j<m;j++){
                res[102+j][t]=1;
             if(sol_places[i][j]==1){
                for(int k=0;k<w;k++){
                    if(places_weap[j][k]==1&&sol_weap[i][k]==1)
                    {
                        //cout<< "there is a match soldier "<< i+1<<" can go "<<j+1<<endl;
                        res[i+1][102+j]=INT_MAX;
                    }
                }
            }
        }
    }

    Edmons();
    cout<<mf<<endl;
    }
    return 0;
}
