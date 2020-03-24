#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int v;
vector<vii>Adjlist;
vi vis;
vi color;
bool test;
void dfs(int s){

for(int i=0;i<Adjlist[s].size();i++){
    if(vis[Adjlist[s][i].first]==0)
    {
        vis[Adjlist[s][i].first]=1;
        color[Adjlist[s][i].first]=1-color[s];
        dfs(Adjlist[s][i].first);

    }
    else{
        if(color[Adjlist[s][i].first]==color[s]){test=false;}
    }
}

}

int main()
{
    freopen("out.out","w",stdout);
    while(cin>>v&&v>0){
            test=true;
            Adjlist.clear();
            vis.clear();
            color.clear();
            Adjlist.resize(v);
            vis.resize(v);
            color.resize(v);

            int a,b;
            while(cin>>a>>b&&(a>0||b>0)){
            Adjlist[a-1].push_back(ii(b-1,1));
            Adjlist[b-1].push_back(ii(a-1,1));
            }

        vis[0]=1;
        color[0]=0;
        dfs(0);
        if(test){cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}



    }

    return 0;
}
