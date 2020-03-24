#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi ni,mi;
ll n,m,k,w;
ll MOD=pow(10,9)+7;

ll dp1[15010];
ll dp2[15010];
void generate1(){

    dp1[0]=1;
    ll currentSum =0;
    for (ll i = 0; i < ni.size(); i++)
    {
        currentSum += (ni[i]%MOD);
        currentSum%=MOD;
        for (ll j = min(w, currentSum); j >= ni[i]; j--){
            dp1[j] += (dp1[j - ni[i]]%MOD);
            dp1[j]%=MOD;
            }
    }

return ;
}
void generate2(){

    dp2[0]=1;

    ll currentSum =0;
    for (ll i = 0; i < mi.size(); i++)
    {
       currentSum += (mi[i]%MOD);
        currentSum%=MOD;
        for (ll j = min(w, currentSum); j >= mi[i]; j--)
        {
            dp2[j] +=(dp2[j - mi[i]]%MOD);
            dp2[j]%=MOD;
        }

    }

    return ;
}

ll isibizi(){

ll res=0;
for(ll i=0;i<=w;i++){
if(abs((w-i)-i)>k)
continue;
//cout<<" i can generate "<<dp1[i]<<" "<<i<<"from subset 1 and "<<dp2[w-i]<<" "<<w-i<<" from subset 2"<<endl;
//cout<<" i can generate "<<dp1[w-i]<<" "<<w-i<<"from subset 1 and "<<dp2[i]<<" "<<i<<" from subset 2"<<endl;
res+=((dp1[i]*dp2[w-i])%MOD);
//res+=((dp1[w-i]*dp2[i])%MOD);
}
return (res%MOD);

}

int main()
{
    //freopen("in.in","r",stdin);
    ll t;
    scanf("%lld",&t);
    while(t--){
    ni.clear();
    mi.clear();
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    scanf("%lld %lld %lld %lld",&n,&m,&k,&w);


    for(ll i=0;i<n;i++)
    {
        ll x;
        scanf("%lld",&x);
        ni.push_back(x);
    }
    for(ll i=0;i<m;i++)
    {
        ll x;
        scanf("%lld",&x);
        mi.push_back(x);
    }
    generate1();
    generate2();


    printf("%lld\n",isibizi());
    }

    return 0;
}
