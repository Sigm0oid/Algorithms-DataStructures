#include <bits/stdc++.h>
#define MAX 100000000000000
using namespace std;
typedef long long ll;
ll n;
vector<ll> ci;
vector<string> tab;
ll dp[100010][2];
ll match (int pos){
ll res=MAX;
if(pos==n){
return 0;
}
ll call1,call2;

 if(tab[pos-1]>tab[pos])
 {
    call1=MAX;
 }
 else{
 if(dp[pos][0]!=-1)
 call1=dp[pos][0];
 else{
    call1=match(pos+1);
    dp[pos][0]=call1;
    }
 }
//cout<<" before "<<tab[pos]<<" ";
reverse(tab[pos].begin(),tab[pos].end());
//cout<<" after "<<tab[pos]<<endl;
  if(tab[pos-1]>tab[pos])
 {
    call2=MAX;
 }
 else{
    if(dp[pos][1]!=-1)
    call2=dp[pos][1];
    else{
    call2=match(pos+1)+ci[pos];
    dp[pos][1]=call2;
    }
 }
reverse(tab[pos].begin(),tab[pos].end());
return (min(call1,call2));

}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    tab.resize(n);
    ci.resize(n);
    for(ll i=0;i<n;i++){
    cin>>ci[i];
    }
    for(ll i=0;i<n;i++){
    cin>>tab[i];
    }
    ll res=match(1);
    reverse(tab[0].begin(),tab[0].end());
     res=min(res,match(1)+ci[0]);
     reverse(tab[0].begin(),tab[0].end());
    if(res>=MAX)
    cout<<"-1"<<endl;
    else
    cout<<res<<endl;

    return 0;
}
