#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> dividor;
    for(int i=1;i<=sqrt(n);i++){
    if(n%i==0)
    dividor.push_back(i);
    }
    if(dividor.size()==1)
    cout<<-1<<endl;
    return 0;
}
