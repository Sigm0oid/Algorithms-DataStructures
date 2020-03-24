#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
string not_wakeup;
ll tab[26];

ll n,m;
vector<string> connections;

int main()
{
    freopen("in.in","r",stdin);
    while(cin>>n>>m){
    connections.clear() ;
    memset(tab,0,sizeof tab);
    cin>>not_wakeup;
    for(int i=0;i<not_wakeup.length();i++){
    tab[not_wakeup[i]-'A']=1;
    }
    ll tmp=m;
    while(tmp--){
    string s;
    cin>>s;
    connections.push_back(s);
    }
    ll res=0;
    bool found=true;
    vector<ll> connected_to;
    n-=not_wakeup.length();
    while(n>0&&found==true){
    found=false;
    res++;
    connected_to.assign(26,0);
    for(int i=0;i<m;i++){
    string a=connections[i];

    if(tab[a[0]-'A']==0&&tab[a[1]-'A']==1){
    connected_to[a[0]-'A']++;

    }
    else if(tab[a[0]-'A']==1&&tab[a[1]-'A']==0){
    connected_to[a[1]-'A']++;

    }
    }

    for(int i=0;i<26;i++){
    if(connected_to[i]>=3)
    {
    tab[i]=1;
    found=true;
    n--;
    }
    }

    }


    if(!found)
    cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
    else
    cout<<"WAKE UP IN, "<<res<<", YEARS"<<endl;
    string s;
    getline(cin,s);
    getline(cin,s);


    }


    return 0;
}
