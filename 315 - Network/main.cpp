#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef  vector<ii> vii;
typedef  vector<int> vi;
vector<vii> Adjlist;
vi vis;
vi dfs_num,dfs_low,parent;
vi numbers,articulations;
int ans,dfsNumCmp,root,rootChildren;

void FindingArticulationPoint(int src){
dfs_low[src]=dfs_num[src]=dfsNumCmp++;
//cout<<src+1<<"visited"<<endl;
for(int i=0;i<(int)Adjlist[src].size();i++){
    int v=Adjlist[src][i].first;
    if(dfs_num[v]==-1){
        parent[v]=src;
        if(src==root){rootChildren++;}


        FindingArticulationPoint(v);

        if(dfs_low[v]>=dfs_num[src]){
            articulations[src]=1;
        }
        dfs_low[src]=min(dfs_low[src],dfs_low[v]);
    }
    else{
        if(parent[src]!=v)
            dfs_low[src]=min(dfs_low[src],dfs_num[v]);
    }

}

}


int n;
int main()
{
   // freopen("out.out","w",stdout);
    while(cin>>n&&n>0){
        //initialisation
        Adjlist.clear();
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_num.clear();
        dfs_low.resize(n);
        dfs_num.assign(n,-1);
        parent.clear();
        parent.resize(n);
        articulations.clear();
        articulations.resize(n);
        dfsNumCmp=root=rootChildren=0;
          ans=0;
          //

        string s;

        getline(cin,s);
        while(getline(cin,s)&&s!="0"){
        numbers.clear();
        int i;
        int d=0;
        for( i=1;i<s.length();i++){

            if(s[i]==' '){
                numbers.push_back(atoi(s.substr(d,i-d).c_str()));


                d=i+1;
            }
        }
        numbers.push_back(atoi(s.substr(d,i-d).c_str()));
        for(int j=1;j<numbers.size();j++){
            Adjlist[numbers[0]-1].push_back(ii(numbers[j]-1,1));
            Adjlist[numbers[j]-1].push_back(ii(numbers[0]-1,1));
        }

        }
        FindingArticulationPoint(0);
        articulations[root]=rootChildren>1;
        for(int j=0;j<n;j++){
            ans+=articulations[j];

        }
        cout<<ans<<endl;


    }

    return 0;
}
