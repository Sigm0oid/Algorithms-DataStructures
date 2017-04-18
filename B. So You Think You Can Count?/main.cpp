#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
string s;
ll dp[10000][10000];

ll calcul(ll from,ll to ){

    if(from>=to)
    return 1;
    ll res=0;
    bitset<10> nums;
    for(ll i=from;i<to;i++)
    {
        if(nums[s[i]-'a']!=0){
                break;
        }
        res+=calcul(from,i)*calcul(i+1,to);
    }
    return res;
}
int main()
{
        cin>>n>>s;
        memset(dp,-1,sizeof dp);
        cout<<calcul(0,n);

    return 0;
}
