#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
int vis[100][100];
int vis1[100][100];

bool found;
int cmp;
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
bool inbound(int a,int b,int m,int n){
    return((a<m)&&(a>=0)&&(b<n)&&(b>=0));
}
bool onedge(int a,int b,int m,int n){
    return((a==m-1)||(a==0)||(b==n-1)||(b==0));
}
void dfs(int a,int b,char tab[100][100],int m,int n){
vis[a][b]=1;
for(int i=0;i<8;i++){
if((vis[a+x[i]][b+y[i]]==0)&&inbound(a+x[i],b+y[i],m,n)){
    if(tab[a+x[i]][b+y[i]]=='.'){
            if(onedge(a+x[i],b+y[i],m,n)){cmp++;}
            dfs(a+x[i],b+y[i],tab,m,n);
    }
}
}
}

int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
int t;
cin>>t;
while(t--){

    int m,n;
    found=false;
        cmp=0;
        int eadgeopninig=0;
        memset(vis1,0,sizeof vis);
        memset(vis,0,sizeof vis);


    cin>>m>>n;
    char tab[100][100];
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
            cin>>tab[i][j];
    }
    }
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

        if((i==0)||(i==m-1)||(j==0)||(j==n-1)){
                // cout<<i<<" "<<j<<endl;
    if(tab[i][j]=='.'){
        eadgeopninig++;
        if( vis1[i][j]==0){
        vis1[i][j]=1;
        memset(vis,0,sizeof vis);
        dfs(i,j,tab,m,n);
           // cout<<"dfs from "<<0<<" "<<i<<endl;

            }

    }
//    if(tab[m-1][i]=='.'){
//              if( vis1[m-1][i]==0){
//            vis1[m-1][i]=1;
//       memset(vis,0,sizeof vis);
//        dfs(m-1,i,tab,m,n);
//                     cout<<"dfs from "<<m-1<<" "<<i<<endl;
// }
//    }
//    if(tab[i][0]=='.'){
//              if( vis1[i][0]==0){
//        vis1[i][0]=1;
//        memset(vis,0,sizeof vis);
//        dfs(i,0,tab,m,n);
//                     cout<<"dfs from "<<i<<" "<<0<<endl;
//}
//    }
//    if(tab[n-1][i]=='.'){
//              if( vis1[n-1][i]==0){
//        vis1[n-1][i]=1;
//        memset(vis,0,sizeof vis);
//        dfs(n-1,i,tab,m,n);
//                      cout<<"dfs from "<<n-1<<" "<<i<<endl;
//}
  //  }
    }
        }
   }
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<vis[i][j]<<" ";
//        }
//        cout<<endl;
//    }
   // cout<<cmp<<endl;
    if((cmp!=2)||(eadgeopninig!=2)){
    cout<<"invalid"<<endl;
    }else{
    cout<<"valid"<<endl;
    }


}    return 0;
}
