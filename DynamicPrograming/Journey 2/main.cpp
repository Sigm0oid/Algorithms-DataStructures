#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll k,n;

ll dp[10001][10001];

ll journey(ll j,ll pas){
     if(dp[j][pas]!=-1){
        //cout<<"Already "<<endl;
        return dp[j][pas];
        }

if(j==0){
        dp[j][pas]=1;
    return 1;

}
if(pas==0){
    dp[j][pas]=0;
    return(0);
}
else{
        dp[j][pas]=((journey(j-1,k)%1000000007)+(journey(j-1,pas-1)%1000000007));
           return dp[j][pas];



}
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
  int t;
  cin>>t;
  while(t--){
        memset(dp,-1,sizeof dp);


    cin>>n>>k;


     cout<<journey(n,k)<<endl;
    }

    return 0;
}
