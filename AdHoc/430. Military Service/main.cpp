#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--){
    ll n,k;
    cin>>n>>k;
    ll nb_periodes=(n/(k+1));
    if(n%(k+1)>0)
    nb_periodes++;
    cout<<n-nb_periodes<<endl;
    }
    return 0;
}
