#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<string> names;
vector<string > ord;
string next_name(string s){
if(s.length()<9)
{
s+="a";
return s;
}
else {
for(int i=1;i<s.size();i++){
if(s[i]<'z'){
    s[i]=(char)s[i]+1;
    return s;
}
}

}


}
int main()
{
    ll n,k;
    cin>>n>>k;
    names.resize(n);
    ord.resize(n-k+1);
    names.assign(n,"A");
    string current="A";
    for(ll i=0;i<(n-k+1);i++){

    cin>>ord[i];
    if(ord[i]=="YES"){
            names[i]=(current);
            current=next_name(current);
        }

        }

//Aaaaaaaaaa
//Aaaaaaaaaa
//Aaaaaaa
//Aaaaaaaa
    }
    for(ll i=0;i<n;i++){
    cout<<names[i]<<" ";
    }
    cout<<endl;
    return 0;
}
