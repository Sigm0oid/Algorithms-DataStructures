#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
map<string,ll> val;
int main()
{
    val["Tetrahedron"]=4;
    val["Cube"]=6;
    val["Octahedron"]=8;
    val["Dodecahedron"]=12;
    val["Icosahedron"]=20;
    cin>>n;
    ll res=0;
    for (ll i=0;i<n;i++) {
    string a;
    cin>>a;
    res+=val[a];
    }
    cout<<res<<endl;
    return 0;
}
