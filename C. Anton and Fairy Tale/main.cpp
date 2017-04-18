#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
bool can(ll k) {
return (n>=(((k*(k+1)/2))));

}
int main()
{
cin>>n>>m;

ll lo = 0, hi = 3*1e9, mid = 0, ans = 0;
for (ll i = 0; i < 1000; i++) {

mid = (lo + hi) / 2;
if (can(mid)) { ans = mid; hi = mid; }
else
lo = mid;

}
cout<<ans<<endl;
    return 0;
}
