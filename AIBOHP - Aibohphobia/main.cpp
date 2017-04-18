#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
string palin_s;
int dp[6010][6010];
ll isibizi(int i,int j){
if(i>=s.length()||j>=s.length())
return 0;

if(dp[i][j]!=-1)
return dp[i][j];
if(s[i]==palin_s[j])
return dp[i][j]=1+isibizi(i+1,j+1);

return dp[i][j]=max(isibizi(i+1,j),isibizi(i,j+1));



}
int main()
{
    int t;
    cin>>t;
    while(t--){

    cin>>s;
    palin_s=s;
    reverse(palin_s.begin(),palin_s.end());
    memset(dp,-1,sizeof dp);
    cout<<s.length()-isibizi(0,0)<<endl;

    }
    return 0;
}
