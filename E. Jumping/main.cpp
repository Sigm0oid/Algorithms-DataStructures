#include <bits/stdc++.h>
using namespace std;
long long tab[100010];
long long dp[100010];
long long n;

void fuck(long long i, long long cmp){
    if ((i>n-1)||(i<0)||(dp[i]!=-1)) return;
    dp[i] = cmp;
    fuck(i+tab[i],cmp+1);
    fuck(i-tab[i],cmp+1);
}

int main()
{
    freopen("jumping.in","r",stdin);
    //ios_base::sync_with_stdio(false);
    long long T;
    scanf("%d",&T);
    for (long long t=0;t<T;t++)
    {
           scanf("%I64d",&n);
        for (long long i=0;i<n;i++)
        {
            scanf("%I64d",&tab[i]);
            dp[i]=-1;
        }
        fuck(n-1,0);
        for (long long i=0;i<n;i++) {
            printf("%I64d \n",dp[i]);
        };
    }
    return 0;
}
