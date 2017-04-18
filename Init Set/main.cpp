#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll gcd(ll a, ll b)
//{
//    while(b) b ^= a ^= b ^= a %= b;
//    return a;
//}
int main()
{
ios_base::sync_with_stdio(false);
    int Q ;
    cin >> Q ;
    ll mod=1000000007;
    for (int t=0;t<Q;t++)
    {
        ll a,b,n;
        cin >> n >> a >> b ;
        vector <ll> factors;
        for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0)
        {factors.push_back(i);
        //cout<<i<<endl;
        }
        }
        ll res=0;
        for (ll i=a;i<=b;i++)
        {
            res+=i;
           for(ll j=0;j<factors.size();j++){
            if(i%factors[j]==0)
            {res-=i;
            res%=mod;
            break;}

            }




        }


        cout << res << endl;
            }
    return 0;
}
