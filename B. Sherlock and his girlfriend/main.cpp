#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool isPrime(ll i){
for(ll j=2;j<=sqrt(i);j++){
    if(i%j==0)
    return false;
}
return true;

}
int main()
{
    ll n;
    cin>>n;
    string s="";
    bool found=false;
    for(ll i=2;i<=n+1;i++){
        if(isPrime(i))
        s+="1 ";
        else{
        s+="2 ";
        found=true;
        }

    }
    if(found)
    cout<<"2"<<endl<<s<<endl;
    else
    cout<<"1"<<endl<<s<<endl;
    return 0;
}
