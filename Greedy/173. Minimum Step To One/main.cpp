#include <bits/stdc++.h>

using namespace std;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll n;
ll dp[20000010];
ll isibizi(ll i){

if(dp[i]!=-1)
return dp[i];
ll res=LLONG_MAX;
if(i==1)
return 0;

if(i%3==0)
return dp[i]=1+isibizi(i/3);
if(i%2==0)
res=min(1+isibizi(i/2),res);
res=min(1+isibizi(i-1),res);
return dp[i]=res;
}

int main()
{

    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=t;i++){
        cin>>n;


        cout<<"Case "<<i<<": "<<isibizi(n)<<endl;

    }
    return 0;
}
