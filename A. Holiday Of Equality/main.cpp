#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    map<ll,ll> citiziens;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    ll tmp;
    cin>>tmp;
    citiziens[tmp]++;
    }
    ll somme=0;
    ll maxx=citiziens.rbegin()->first;
    for(auto i=citiziens.begin();i!=citiziens.end();i++)
    somme+=(i->second*(maxx-i->first));
    cout<<somme<<endl;
    return 0;
}
