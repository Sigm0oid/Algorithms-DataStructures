#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[3][100010];
ll dp[3][100010];
ll sum[100010];

int n;
 void  dfs(){
 dp[0][1]=a[0][1];
 dp[1][1]=a[0][1]+a[1][1];
 dp[2][1]=a[0][1]+a[1][1]+a[2][1];
 for(int i=2;i<=n;i++){
    for(int j=0;j<3;j++){
        if(j==1){
            dp[j][i]=max(dp[j][i-1],max(dp[j-1][i-1]+a[j-1][i],dp[j+1][i-1]+a[j+1][i]));
        }
        else{
            dp[j][i]=max(dp[j][i-1],max(dp[1][i-1]+a[1][i],max(sum[i]-a[j][i]+dp[2-j][i-1],dp[2-j][i-2]+sum[i-1]+sum[i]-a[j][i])));
        }
        dp[j][i]+=a[j][i];
    }

 }

 return ;
}

int main()
{
    memset(a,0,sizeof a);
    memset(sum,0,sizeof sum);
    memset(dp,0,sizeof dp);

    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            sum[j]+=a[i][j];

        }
    }
      dfs();
    cout<<dp[2][n]<<endl;


    return 0;
}
