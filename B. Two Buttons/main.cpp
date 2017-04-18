#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll  dp[20000][20000];

ll fiind(int n,int m){

if(n>=m)
return dp[n][m]=(n-m) ;
int res=0;
while(n<m/2){
n*=2;
res++;
}
int sol1=0,n1=n;
int sol2=0,n2=n;
while(n1<m){
n1*=2;
sol1++;
}
sol1+=(n-m);

while(n2>(m/2)){
n2--;
sol2++;
}
sol2++;
return min(res+sol1,res+sol2);
}

int main()
{
    memset(dp,-1,sizeof dp);
    int n,m;
    cin>>n>>m;
    int res=fiind(n,m);
    cout<<res<<endl;
    return 0;
}
