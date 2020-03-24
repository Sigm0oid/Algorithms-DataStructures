#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int vis[100][100];
char tab[100][100];
int x[8]={1,1,1,0,0,-1,-1,-1};
int y[8]={0,-1,1,1,-1,0,-1,1};
bool inbound(int i,int j,int n,int m){
        return ((i<0)||(i>=n)||(j<0)||(j>=m));


}
int dfs(int i,int j,int n,int m){
    int res=0;
    if(tab[i][j]=='L'){
        return 0;
    }
    else{
            res=1;
    vis[i][j]=1;
    for(int a=0;a<8;a++){
              //cout<<i+x[a]<<" "<<j+y[a]<<" "<<"visited "<<endl;
        if((0==vis[i+x[a]][j+y[a]])&&(inbound(i+x[a],j+y[a],n,m))&&(tab[i+x[a]][j+y[a]]=='W')){
            res+=dfs(i+x[a],j+y[a],n,m);
        }
    }
    return res;
    }
}
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<t;i++){
            memset(tab,'W',sizeof tab);
            memset(vis,0,sizeof vis);
            int n=0,m=0;
    while((getline(cin,s)) && (s.length()>0)){
        if((s[0]=='L')||(s[0]=='W')){
                n++;
                m=s.length();
        for(int j=0;j<s.length();j++){
            tab[n-1][j]=s[j];
        }
        }
        else{
           int x=0,y=0;
           int cmp=0;
                   for(int j=s.length()-1;j>=0;j--){
                    if(s[j]!=' '){
                        x+=pow(10,cmp)*(s[j]-'0');
                        cmp++;

                    }
                    else{
                            y=x;
                            x=0;
                            cmp=0;
                    }
                   }
                   cout<<dfs(x-1,y-1,n,m)<<endl;
                    memset(vis,0,sizeof vis);


        }
       // cout<<s<<endl;
    }


    if(i!=t-1){
            cout<<endl;
            }
    }
    return 0;
}
