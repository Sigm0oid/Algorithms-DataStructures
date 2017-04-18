#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 10000
int vis[200][200];
int res[200][200];
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
bool inbound(int a,int b,int n,int m){
    return((a<n)&&(a>=0)&&(b<m)&&(b>=0));
}
void bfs(int a,int b,int n,int m,int tab[200][200]){
queue<int> q;
q.push(a);
q.push(b);
while(!q.empty()){

        int i=q.front();
        q.pop();
        int j=q.front();
        q.pop();
for( int k=0;k<4;k++){
    if((0==vis[i+x[k]][j+y[k]])&&(inbound(i+x[k],j+y[k],n,m))){
       if((tab[i+x[k]][j+y[k]]!=1)){
        //cout<<"point "<<i<<" "<<j<<" visited"<<endl;
        vis[i+x[k]][j+y[k]]=1;
        res[i+x[k]][j+y[k]]=min(res[i+x[k]][j+y[k]],res[i][j]+1);
       q.push(i+x[k]);
       q.push(j+y[k]);
       }

       }
}
}
}


int main()
{
int tab[200][200];
int t;
cin>>t;
while(t--){
        memset(vis,0,sizeof vis);
        memset(res,INF,sizeof vis);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
            string s;
        cin>>s;

        for(int j=0;j<m;j++){
            tab[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tab[i][j]==1){
                    res[i][j]=0;
                    vis[i][j]=1;
                bfs(i,j,n,m,tab);
                memset(vis,0,sizeof vis);
            }
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout<<res[i][j];
        if(j!=m-1){
            cout<<" ";
        }

        }
        cout<<endl;
        }





    string s;
    getline(cin,s);
}

    return 0;
}
