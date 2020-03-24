#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair < int,int > ii;
typedef vector<pair<int,ii> > viii;
typedef vector<ii> vii;
typedef vector<int> vi ;
vector<vii> Adjlist;
vi vis,maxedge;
viii Edgelist;
int  ans;
int c,s,q;
vi parent,rnk;
int FindSet(int i){
if(parent[i]==i)
    return i;
else{
    return parent[i]=FindSet(parent[i]);
}
}
bool SameSet(int i,int j){
int x=FindSet(i);
int y=FindSet(j);
return(y==x);
}

void UnionSet(int i,int j){
int x=FindSet(i);
int y=FindSet(j);

if(rnk[x]>rnk[y])
    parent[y]=x;
else{
    parent[x]=y;
    if(rnk[x]==rnk[y])
        rnk[y]++;
}

}
void dfs(int s,int mx){
    maxedge[s]=mx;
    vis[s]=1;
    for(int i=0;i<(int)Adjlist[s].size();i++){
    int v=Adjlist[s][i].first;
    if(vis[v]==0)
    dfs(v,max(mx,Adjlist[s][i].second));
}
}
int main()
{
    int cmp=1;
    while(cin>>c>>s>>q&&(c>0||s>0||q>0)){
            if(cmp>1)
            cout<<endl;
        cout<<"Case #"<<cmp<<endl;
        cmp++;
        parent.clear();
        Edgelist.clear();

        parent.resize(c);
        Adjlist.clear();
        Adjlist.resize(c);
        vis.clear();
        vis.resize(c);
        maxedge.clear();
        maxedge.assign(c,-1);
        for(int i=0;i<c;i++){
            parent[i]=i;
        }
        rnk.clear();
        rnk.resize(c);

        for(int i=0;i<s;i++){
            int a,b,d;
            cin>>a>>b>>d;
            Edgelist.push_back(make_pair(d,ii(a-1,b-1)));
        }
        sort(Edgelist.begin(),Edgelist.end());

        for(int i=0;i<q;i++){
           ans=0;
            int src,dist;
            cin>>src>>dist;
            src--;
            dist--;
            for(int j=0;j<Edgelist.size();j++){
                if(!SameSet(Edgelist[j].second.second,Edgelist[j].second.first)){
                    UnionSet(Edgelist[j].second.second,Edgelist[j].second.first);
                    Adjlist[Edgelist[j].second.second].push_back(ii(Edgelist[j].second.first,Edgelist[j].first));
                    Adjlist[Edgelist[j].second.first].push_back(ii(Edgelist[j].second.second,Edgelist[j].first));

                }
            }

        if(SameSet(src,dist)){
            vis.clear();
            vis.resize(c);
            maxedge.clear();
            maxedge.assign(c,-1);


            dfs(src,0);


            cout<<maxedge[dist]<<endl;
        }
        else{
            cout<<"no path"<<endl;
        }
        }

    }

    return 0;
}
