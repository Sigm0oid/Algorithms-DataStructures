#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

vector<vii> Adjlist ;
vi dis,lvl,duration;
int maxx;

int  dfs(int src){
int dur=duration[src];
int x=duration[src];
for(int i=0;i<Adjlist[src].size();i++){

    int u=Adjlist[src][i].first;
    int d=Adjlist[src][i].second;
    x=max(x,dur+dfs(u));
}
return x;
}



int main()
{

    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    getline(cin,s);
    for(int j=0;j<t;j++){
     maxx=0;
      Adjlist.clear();
    Adjlist.resize(26);
    dis.clear();
    dis.resize(26);
    duration.clear();
    duration.resize(26);
    lvl.clear();
    lvl.resize(26);

    while(getline(cin,s)&&s.length()>0){
    //cout<<s<<endl;


    stringstream ss;
    ss.str(s);
    string token;
    vector<string> v;
    while(getline(ss,token,' ')){
    v.push_back(token);
    }
    int dist=atoi(v[1].c_str());
    int src=v[0][0]-'A';
    //cout<<dist<<endl;
    duration[src]=dist;
    dis[src]=dist;
        // cout<<dis[src]<<" "<<duration[src]<<endl;
    if(v.size()>2){
    for(int i=0;i<v[2].length();i++)
    {
        Adjlist[v[2][i]-'A'].push_back(ii(src,dist));
        lvl[src]=max(lvl[src],lvl[v[2][i]-'A']+1);
    }
    }

     }


     for(int i=0;i<26;i++){
     if(lvl[i]==0){
     maxx=max(maxx,dfs(i));
     }
     }
         cout<<maxx<<endl;

    if(j!=t-1)
    cout<<endl;}


    return 0;
}

