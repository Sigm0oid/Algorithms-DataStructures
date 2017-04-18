#include <bits/stdc++.h>
#define INF 100000000000
using namespace std;
typedef long long ll;
ll AdjMat[110][110];
ll dp[110][5010][2];
int Si[5010];
int Di[5010];
int N,M,K;
ll work(int current_city,int next_family,bool nb_family){
   if(next_family>K)
   return 0;
   if(AdjMat[current_city][Si[next_family]]>=INF)
   return INF;
   ll res;
   if(dp[current_city][next_family][nb_family]!=0)
   return dp[current_city][next_family][nb_family];

   if(nb_family==0){
    res=AdjMat[current_city][Si[next_family]]+work(Si[next_family],next_family+1,1);

   }
   else{
   //get off family1 and go to family 2
    ll sol1=AdjMat[current_city][Di[next_family-1]]+work(Di[next_family-1],next_family,0);
    // get in another family+ getoff this family
    ll sol2=AdjMat[current_city][Si[next_family]]+AdjMat[Si[next_family]][Di[next_family-1]]+work(Di[next_family-1],next_family+1,1);
    res=min(sol1,sol2);
    }
    return dp[current_city][next_family][nb_family]=res;


}

int main()
{
    freopen("manicmoving.in","r",stdin);
    freopen("manic_moving_output.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
    memset(dp,0,sizeof dp);

    cin>>N>>M>>K;
    //inisialisation
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
        if(i!=j)
        AdjMat[i][j]=INF;
        else
        AdjMat[i][j]=0;
        }
    }

        for(int a=0;a<M;a++){
        ll x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        AdjMat[x][y]=z;
        AdjMat[y][x]=z;
        }

        //floyed warshal
        // inside int main()
    for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
    //end warshall
    for(int i=0;i<K;i++)
        {

        cin>>Si[i]>>Di[i];
        Si[i]--;
        Di[i]--;
        }



    ll res=work(0,0,0);
    if(res>=INF)
    res=-1;
    cout<<"Case #"<<t+1<<": "<<res<<endl;
    }

    return 0;
}
