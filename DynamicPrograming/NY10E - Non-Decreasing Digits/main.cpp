#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[100][100];
ll isibizi(int max_already,int pos_left){
if(pos_left==0)
return 1;
ll res=0;
if(dp[max_already][pos_left]!=-1)
return dp[max_already][pos_left];
for(int i=max_already;i<=9;i++){
//cout<<i<<endl;
res+=isibizi(i,pos_left-1);
}
return dp[max_already][pos_left]=res;
}


int main()
{
    memset(dp,-1,sizeof dp);
    int t;
    cin>>t;
    while(t--){
    int x1,x2;
    cin>>x1>>x2;
    cout<<x1<<" "<<isibizi(0,x2)<<endl;
    }
    return 0;
}
