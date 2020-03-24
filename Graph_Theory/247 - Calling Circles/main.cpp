#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi dfs_num,dfs_low,vis,tab;
int n,m,dfsNumCmp,cmp;
vector<string> names;
vector<vector<string> > res;
int getindex(string s){
int res=-1;
bool found=false;
int i=0;
while(i<names.size()&&!found){
    if(names[i]==s){
        found=true;
        res=i;

    }
    i++;
}

return res;
}

void TarjanSCC(int s){
    dfs_low[s]=dfs_num[s]=dfsNumCmp++;
    tab.push_back(s);
    vis[s]=1;
    for(int i=0;i<(int)Adjlist[s].size();i++){
        int v=Adjlist[s][i].first;
        if(dfs_num[v]==-1){
            TarjanSCC(v);
        }
        if(vis[v]==1){
            dfs_low[s]=min(dfs_low[s],dfs_low[v]);
        }
    }

    if(dfs_low[s]==dfs_num[s]){
        vector<string> tmp;
        while(1){

            int v=tab.back();tab.pop_back();vis[v]=0;

            //names[v];
            tmp.push_back(names[v]);
            if(s==v)
            break;
             //else{cout<<", ";}

        }
        res.push_back(tmp);

    }

}

int main()
{

    cmp=1;
    freopen("out.out","w",stdout);
    while(cin>>n>>m&&(n>0||m>0)){
            if(cmp>1){cout<<endl;}
        Adjlist.clear();
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_num.clear();
        dfs_num.assign(n,-1);
        vis.clear();
        vis.resize(n);
        res.clear();

        names.clear();
        dfsNumCmp=0;
        tab.clear();

        for(int i=0;i<m;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(getindex(s1)==-1){
                names.push_back(s1);
            }
            if(getindex(s2)==-1){
                names.push_back(s2);
            }
            int a=getindex(s1);
            int b=getindex(s2);
            Adjlist[a].push_back(ii(b,1));
           // Adjlist[b].push_back(ii(a,1));


        }
        cout<<"Calling circles for data set "<<cmp<<":"<<endl;
        for(int i=0;i<n;i++){
            if(dfs_num[i]==-1)
               TarjanSCC(i);
        }
        for(int i=res.size()-1;i>=0;i--){
            for(int j=res[i].size()-1;j>=0;j--){
                    cout<<res[i][j];
            if(j!=0){cout<<", ";}

            }
            cout<<endl;
        }
        cmp++;



    }

    return 0;
}
