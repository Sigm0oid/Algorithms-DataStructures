#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef  long long ll;
int x[8]={1,1,1,0,0,-1,-1,-1};
int y[8]={-1,1,0,1,-1,-1,1,0};

char tab[101][101];
int vis[101][101];
string s="ALLIZZWELL";
bool res;
    bool inbound(int i,int j,int r,int c){
    return((i>=0)&&(i<r)&&(j>=0)&&(j<c));}



    void dfs(int xi,int yi,int r,int c,int pos){
 //   cout<<"pos"<<endl;
    if(pos==10){
        res=true;
        return;
    }
    for(int i=0;i<8;i++){
            if(inbound(xi+x[i],yi+y[i],r,c)){
        //cout<<tab[xi+x[i]][yi+y[i]]<<" "<<s[pos]<<endl;
        if((vis[xi+x[i]][yi+y[i]]==0)&&(tab[xi+x[i]][yi+y[i]]==s[pos]))
            {

            vis[xi+x[i]][yi+y[i]]=1;
       // cout<<s[pos] ;
            dfs(xi+x[i],yi+y[i],r,c,pos+1);
            vis[xi+x[i]][yi+y[i]]=0;
        }
    }
    }

    }
int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("in.in","r",stdin);
  //  freopen("out.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            res=false;
        int r,c;
        cin>>r>>c;
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                cin>>tab[j][k];
            }
        }
         for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(tab[j][k]=='A'){

                    memset(vis,0,sizeof vis);
                    vis[j][k]=1;
                    dfs(j,k,r,c,1);

                }
            }
        }


        if(res){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        if(i!=t-1){
            cout<<endl;
        }


    string gg;
    getline(cin,gg);
    }

    return 0;
}
