#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[100010];
ll a[100010];
ll l,r;
void precalc(){
for(ll i=0;i<=100000;i++){
    int nb_1=0;
    for(int j=0;j<20;j++){
    if(i&(1<<j))
    nb_1++;}
    if(a[nb_1]==0&&nb_1>1)
    dp[i]=1;
    if(i>0)
    dp[i]+=dp[i-1];
}


}
int main()
{

        ll t;
        scanf("%lld",&t);
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        for (ll x = 2; x <= 100000; x++) {
            if (a[x]) continue;
                for (ll u = 2*x; u <= 100000; u += x) {
                a[u] = x;
                }
            }
        precalc();
        while(t--){
            scanf("%lld %lld",&l,&r);
            ll res=dp[r]-dp[l];
            int nb_1=0;
                for(int j=0;j<20;j++){
                if(l&(1<<j))
                nb_1++;
                }
                if(a[nb_1]==0&&nb_1>1)
                res++;
            printf("%lld\n",res);

        }
    return 0;
}
