#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll dp[5000];
using namespace std;
string s;

ll solve(bitset<12> used){
if(dp[used.to_ulong()]!=-1)
return dp[used.to_ulong()];


ll res=0;
for(int i=0;i<10;i++){
//cout<< i<<endl;
    if(used[i]==1&&used[i+1]==1&&used[i+2]==0)   {

            bitset<12> tmp=used;
            tmp[i+2]=1;
            tmp[i]=0;
            tmp[i+1]=0;
            res=max(res,1+solve(tmp));
        }
    if(used[i]==0&&used[i+1]==1&&used[i+2]==1) {

            bitset<12> tmp=used;
            tmp[i]=1;
            tmp[i+1]=0;
            tmp[i+2]=0;
            res=max(res,1+solve(tmp));
    }

}
return dp[used.to_ullong()]=res;

}

int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>s;
    bitset<12> used;
    for(int i=0;i<12;i++){
    if(s[i]=='o')
    used[i]=1;
    }
    memset(dp,-1,sizeof dp);
    cout<<used.count()-solve(used)<<endl;

    }
    return 0;
}
