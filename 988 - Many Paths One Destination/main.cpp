#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi death;
int n;

int dfs(int src){

if(death[src]==1){
return 1;}
else{
ll res=0;
for(int i=0;i<Adjlist[src].size();i++){
ii v=Adjlist[src][i];
    res+=dfs(v.first);
}
return res;

}
}


int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    int cmp=0;
    while(cin>>n){
    //cout<<"nnnn "<<n<<endl;
    if(cmp>0)
    cout<<endl;
    if(cmp==0)
    {cmp++;}

    Adjlist.clear();
    Adjlist.resize(n);
    death.clear();
    death.resize(n);
    for(int i=0;i<n;i++){
    int sz;
    cin>>sz;
    if(sz==0){
    death[i]=1;}
    for(int j=0;j<sz;j++){
    int a;
    cin>>a;
    Adjlist[i].push_back(ii(a,1));

    }
    }
    ll res=0;
    int sz=Adjlist[0].size();
    for(int i=0;i<sz;i++){
    res+=dfs(Adjlist[0][i].first);
    }
    res=max(res,1LL*1);
    cout<<res<<endl;
    string s;
    getline(cin,s);
    }
    //cout<<endl;
    return 0;
}
