#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    scanf("%lld",&n);
    if (n<3) printf("-1\n");
    else if (n&1)
    {
        n/=2;
        printf("%lld %lld\n",2*n*(n+1),2*n*(n+1)+1);
    }
    else
    {
        n/=2;
        printf("%lld %lld\n",n*n-1,n*n+1);
    }
    return 0;
}
