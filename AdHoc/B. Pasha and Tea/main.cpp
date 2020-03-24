#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,w;
    cin>>n>>w;
    vector<double> tab(2*n);
    for(ll i=0;i<(2*n);i++)
    cin>>tab[i];
    sort(tab.begin(),tab.end());

    double ammount=w/(3.0*n);
    ammount=min(ammount,min(tab[0]/1.0,tab[n]/2.0));
    printf("%.6f\n",ammount*3.0*n);


    return 0;
}
