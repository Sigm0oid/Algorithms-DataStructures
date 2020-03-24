#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii positions;
vector<vii> Adjlist;
vi parent,raank;
int n;
int findset(int i)
{
    if(parent[i]==i)
    return i;
    return parent[i]=findset(parent[i]);
}
bool sameset(int i,int j){
    return (findset(i)==findset(j));
}
void unionfind(int i,int j){
    if(!sameset(i,j)){
        int x=findset(i);
        int y=findset(j);
        parent[y]=x;
        if(raank[x]==raank[y])
        raank[y]++;
    }
}



int main()
{
    cin>>n;
    raank.assign(n,0);
    for(int i=0;i<n;i++){
    parent.push_back(i);
    int x,y;
    cin>>x>>y;
    positions.push_back(ii(x,y));
    for(int j=i-1;j>=0;j--){
        if(positions[i].first==positions[j].first||positions[i].second==positions[j].second)
        unionfind(i,j);
    }

    }
    map<int,int> groups;
    for(int i=0;i<n;i++)
    groups[findset(parent[i])]++;
    cout<<groups.size()-1<<endl;
//    parent[i]=i;
    return 0;
}
