 #include <bits/stdc++.h>
#include<string>
#define GREY 1
#define WHITE 0
#define BLACK 2

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<string> AdjMat;
vector<vii> Adjlist;
int n;
vi parent,color;
string res="";
bool ok=false;
void detect_cycle(int src,int dis,string s){
if(ok)
return;
int cmp=0;
while(src!=parent[dis]&&src!=-1)
{
        //cout<<src+1<<" ";
        cmp++;
        std::ostringstream ss;
        ss << src+1;
        s=ss.str()+" "+s;

        src=parent[src];

}
//cout<<endl;

//cout<<cmp<<endl;
if(cmp==3){
res=s;
ok=true;
}
return;
}

void dfs(int u){
if(ok)
return;
for(int i=0;i<n;i++){
     if(AdjMat[u][i]=='1'){

     if(color[i]==WHITE){
        parent[i]=u;
        color[i]=GREY;
     dfs(i);
     }
     else if(color[i]==GREY){
     string s="";
     //cout<<" found cycle going from "<<u+1<<" to "<<v.first+1<<endl;
     detect_cycle(u,i,s);
     }
    }
}
color[u]=BLACK;
}


int main()
{
    cin>>n;
  // memset(AdjMat,0,sizeof AdjMat);
    color.assign(n,WHITE);
    parent.assign(n,-1);
    Adjlist.resize(n);
    for(int i=0;i<n;i++){
    string s;
    cin>>s;
    AdjMat.push_back(s);
    }
    for(int i=0;i<n;i++)
    if(color[i]==WHITE)
    {
    color[i]=GREY;
    dfs(i);
    }

    if(!ok)
    cout<<"-1"<<endl;
    else
    cout<<res<<endl;

    return 0;
}
