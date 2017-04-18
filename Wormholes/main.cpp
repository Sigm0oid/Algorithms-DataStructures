/*
ID: geekham1
LANG: C++11
TASK: wormhole
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ii tab[12];
vii points;
vector<vii> Adjlist;
vector<int> used;
map<ll,vii > next_X;
int n,res=0,cmp=0;

int get_next(int noed){
int x=points[noed].second;
int pos=-1;
for(int i=0;i<next_X[x].size()-1;i++){
if(next_X[x][i].second==noed)
pos=i;

}
if(pos==-1)
return pos;
else
return  next_X[x][pos+1].second ;

}

int detecter_cycle(){
vector<int> vis;
int j;
for(int i=0;i<n;i++){
vis.clear();
vis.resize(n);
//vis[i]=1;
j=i;
while(j!=-1&&vis[j]==0){
vis[j]=1;
j=Adjlist[j][0].first;
j=get_next(j);
}
if(j!=-1)
return 1;
}
return (j!=-1);

}


void match(){
    int i;

    for( i=0;i<n;i++)
    if(used[i]==0)
    break;

    if(i==n)
     res+=detecter_cycle();
    for(int j=i+1;j<n;j++){
        if(used[j]==0){
            Adjlist[i].push_back(ii(j,1));
            Adjlist[j].push_back(ii(i,1));
            used[i]=1;
            used[j]=1;
            //cout<<"matched "<<i+1<<" "<<j+1<<endl;
            match();
            used[i]=0;
            used[j]=0;
            Adjlist[i].clear();
            Adjlist[j].clear();




        }

    }


}



 int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);

    cin>>n;
    for(ll i=0;i<n;i++){
    ii hole;
    cin>>hole.first>>hole.second;
     points.push_back(hole);
     next_X[hole.second].push_back(ii(hole.first,i));
     }
     for(map<ll,vii >::iterator it=next_X.begin();it!=next_X.end();it++){
     sort(it->second.begin(),it->second.end());
     }


        Adjlist.clear();
        Adjlist.resize(n);
        used.clear();
        used.resize(n);
        match();




    cout<<res<<endl;

    return 0;
}
