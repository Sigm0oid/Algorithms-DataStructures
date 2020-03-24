#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi vis;
int quene[230];
int n;
vector<ll> dp;
int rows[20];
ll dfs(int src){
if(src==(n*n+1))
return 1;
ll res=0;
if(dp[src]!=-1)
return dp[src];
for( int i=0;i<Adjlist[src].size();i++){
    ii v=Adjlist[src][i];
    //cout<<"quene of rows "<<(v.first-1)/n<<"is  "<<rows[(v.first-1)/n]<<endl;
    if(rows[(v.first-1)/n]==-1)
    {
    res+=dfs(v.first);}
    else{
    //cout<<"there is a quene in row "<<(v.first-1)/n<<" at "<<rows[(v.first-1)/n]<<endl;

    if((v.first-1)%n==rows[(v.first-1)/n])
    {
    //cout<<"i can go to it from "<<v.first<<endl;
    if(src==0)
    res+=dfs(v.first);
    else {
    if(abs((src-1)%n-(v.first-1)%n)>1)
       {
        //cout<<" i can go to"<<(src-1)%n <<" to "<<(v.first-1)%n<<endl;
        res+=dfs(v.first);}
    }
    }
    }
}
return dp[src]=res;
}


int main()
{
//freopen("out.out","w",stdout);
    string s;
    while(cin>>s){

    dp.clear();
    dp.assign(230,-1);
    memset(rows,-1,sizeof rows);
    Adjlist.clear();
    n=s.length();
    Adjlist.resize(n*n+2);
    if(s[n-1]!='?')
    {
    if(s[n-1]>='A')
    {rows[n-1]=s[n-1]-'A'+9;}
    else
    {rows[n-1]=s[n-1]-'1';}
    }

    for(int i=0;i<s.length()-1;i++){
    if(s[i]!='?')
    {
     if(s[i]>='A')
    {rows[i]=s[i]-'A'+9;}
    else
    {rows[i]=s[i]-'1';}
    }
    for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
    if(abs(k-j)>=2)
    Adjlist[(n)*i+j+1].push_back(ii(((n*(i+1))+k+1),1));
    //cout<<"i can go from "<<n*i+j+1<<"to "<<n*(i+1)+k+1<<endl;}
    }

    }
    }
    for(int i=0;i<n;i++){
    Adjlist[0].push_back(ii(i+1,0));
    Adjlist[n*(n-1)+i+1].push_back(ii(n*n+1,0));

    }
    ll res=0;
    res+=dfs(0);
    cout<<res<<endl;

    }

    return 0;
}
