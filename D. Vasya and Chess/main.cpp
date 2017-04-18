#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll n;
bool ok=false;
bool inbound(ll x,ll y){
    return (x>0&&y>0&&x<n&&y<n);
}
void solve(){

}
int main()
{
    cin>>n;
    ll nb_powns=n*n;
    solve();
    if(ok)
    cout<<"white"<<endl<<*(moves.begin())<<endl;
    else
    cout<<"black"<<endl;
    return 0;
}
