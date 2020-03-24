#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll dp[1010][1010];
string s1,s2;
ll LCS(ll i,ll j){
if(j>=s2.length()||i>=s1.length())
return  0;
if(dp[i][j]!=-1)
return dp[i][j];


if(s1[i]==s2[j])
return dp[i][j]=1+(LCS(i+1,j+1));
else{
return dp[i][j]=max(LCS(i,j+1),(LCS(i+1,j)));
}
}

int main()
{

    //freopen("in.in","r",stdin);
    while(getline(cin,s1)){
    memset(dp,-1,sizeof dp);
    getline(cin,s2);
    cout<<LCS(0,0)<<endl;

    }

    return 0;
}
