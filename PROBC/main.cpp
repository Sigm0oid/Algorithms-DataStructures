#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

int main()
{


    ll T ;

    scanf("%lld",&T) ;
    while (T--)
    {
		ll n , k ;

		scanf("%lld %lld",&n,&k) ;
        ll left=1,right=n;
        ll middle;
       while(left<right){
        middle=(left+right)/2;
        if(((n-middle)*(n-middle)*(n-middle-1))<k)
        {
            left=middle+1;
        }
        else
        right=middle-1;
        }
        cout<<" k is in "<<middle<<endl;

		//printf("%lld %lld\n" ,x,y);
    }
}
