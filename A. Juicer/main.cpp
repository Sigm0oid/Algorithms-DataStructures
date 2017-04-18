#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 10000


int main()
{
    ios_base::sync_with_stdio(false);
ll n,b,d;
ll sommeorange=0;
ll res=0;
cin>>n>>b>>d;
for(ll i=0;i<n;i++){

    ll orange;
    cin>>orange;
    if(orange<=b){
            sommeorange+=orange;

    }
    if(sommeorange>d){
            sommeorange=0;
            res++;
        }

}
    cout<<res<<endl;
    return 0;
}
