#include <bits/stdc++.h>

using namespace std;

int mat[25][25];
 int money,c;

 int memo[250][25];
 int dp(int m,int lvl){
    if(m<0){return -10000;}
     if(lvl==c){
        return money-m;
     }



     //the majic of DP (make difference between dp and bactrack
     if(memo[m][lvl]!=-1){return memo[m][lvl];}
     //



     int mx=-1;
 for(int i=1;i<=mat[lvl][0];i++){
  if(m>=mat[lvl][i]){
    mx=max(mx,dp(m-mat[lvl][i],lvl+1));
  }
 }
 return memo[m][lvl]=mx;
 }

int main()
{
    //freopen("out.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
            memset(mat,-1,sizeof mat);
            memset(memo,-1,sizeof memo);

        cin>>money>>c;
        for(int i=0;i<c;i++){
            int x;
            cin>>x;
            mat[i][0]=x;
            for(int j=1;j<x+1;j++){
                cin>>mat[i][j];
            }
        }

        int ans=dp(money,0);
        if(ans<0){
            cout<<"no solution"<<endl;
        }
        else{
            cout<<ans<<endl;
        }


    }
    return 0;
}
