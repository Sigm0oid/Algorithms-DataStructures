#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
typedef vector<ii> vii;
typedef vector <int> vi;
vector<vii> Adjlist;
vi parent,dfs_low,dfs_num,articulationPoint;
int n,m,root,Dfs_num_cmp,rootChildren;
vii points;

bool compare(ii p1,ii p2){
    if(p1.second!=p2.second){
        return p1.second>p2.second;
    }
    else{
        return p1.first<p2.first;
    }
}
void FindArticulationPoint(int s){
dfs_num[s]=dfs_low[s]=Dfs_num_cmp++;
for(int i=0;i<(int)Adjlist[s].size();i++){
    int v=Adjlist[s][i].first;
    if(dfs_num[v]==-1){
            parent[v]=s;
        if(s==root){rootChildren++;}

        FindArticulationPoint(v);

        if(dfs_low[v]>=dfs_num[s]){
            articulationPoint[s]++;
        }
        dfs_low[s]=min(dfs_low[s],dfs_low[v]);

    }
    else{
        if (v!=parent[s]){
            dfs_low[s]=min(dfs_low[s],dfs_num[v]);
        }
    }
}


}
int main()
{
    while(cin>>n>>m&&(n>0||m>0)){
        //clear everything
        root=rootChildren=Dfs_num_cmp=0;
        Adjlist.clear();
        Adjlist.resize(n);
        parent.clear();
        parent.resize(n);
        dfs_low.clear();
        dfs_num.clear();
        dfs_low.resize(n);
        dfs_num.assign(n,-1);
        articulationPoint.clear();
        articulationPoint.resize(n);
        points.clear();

        //start reading adjlist
        int a,b;
        while(cin>>a>>b&&(a>=0||b>=0)){
            Adjlist[a].push_back(ii(b,1));
            Adjlist[b].push_back(ii(a,1));
        }
        FindArticulationPoint(root);
        articulationPoint[root]=(rootChildren>1);
        for(int i=0;i<n;i++){
            if(articulationPoint[i]>0){
                points.push_back(ii(i,articulationPoint[i]+1));
            }
            else{
                 points.push_back(ii(i,1));
            }
        }
        sort(points.begin(),points.end(),compare);
        for(int i=0;i<m;i++){
            cout<<points[i].first<<" "<<points[i].second<<endl;
        }

    cout<<endl;}

    return 0;
}
