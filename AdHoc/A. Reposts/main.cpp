#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
map<string,int> names;
vector<vii> Adjlist;
vector<int> depth;
vector<int> vis;
int dfs(int s){
vis[s]=1;
int res=1;
for(int i=0;i<Adjlist[s].size();i++){
    ii v =Adjlist[s][i];
    if(vis[v.first]==0)
    res=max(res,1+dfs(v.first));
}
return res;
}
string toupper(string s){
string res="";
for(int i=0;i<s.length();i++)
res+=toupper(s[i]);
return res;
}
int main()
{
    int n;
    cin>>n;
    int cmp=0;
    vis.resize(400);
    Adjlist.resize(400);
    depth.assign(400,0);
    string n1,n2,repost;
    for(int j=0;j<n;j++)
    {
        int src,dis;
        cin>>n1>>repost>>n2;
        n1=toupper(n1);
        n2=toupper(n2);
        auto i=names.find(n1);
        if(i==names.end())
        names[n1]=cmp++;
        dis=names[n1];
         i=names.find(n2);
        if(i==names.end())
        names[n2]=cmp++;
        src=names[n2];
        Adjlist[src].push_back(ii(dis,1));
        depth[dis]=depth[src]+1;
    }
    int res=-1;
    for(auto i=names.begin();i!=names.end();i++){
        if(depth[i->second]==0){
        vis.assign(400,0);
        //cout<<i->first<<" id "<<i->second<<endl;
        res=max(res,dfs(i->second));
        }
    }
    cout<<res<<endl;
    return 0;
}
