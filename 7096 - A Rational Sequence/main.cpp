#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;


int main()
{
    int t;
    cin>>t;
    preprocessing();
    while(t--){
        ll k;
        string s;
        cin>>k>>s;
        cout<<mp[s]<<endl;
    }
    return 0;
}
