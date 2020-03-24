#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k;

int main()
{
    cin>>n>>m>>k;
    ll frodo=m/n;
    m=m%n;
        while(m>0){
        frodo++;
        m-=n;
        }
        cout<<frodo<<endl;
    return 0;
}
