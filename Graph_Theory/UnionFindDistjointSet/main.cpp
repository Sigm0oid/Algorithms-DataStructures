#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef  vector<ii> vii;
typedef  vector<iii> viii;
typedef vector<int> vi;
vi p,rank;
viii Edgelist;

int findSet(int i){
return p[i];
}
bool  SameSet(int i,int j){
return findSet(i)==findSet(j);}


void UnionSet(int i,int j){
if(!SameSet(i,j)){
int x=findSet(i);
int y=findSet(j);
if(rank[x]>rank[y]){
    p[y]=p[x];
}else{
p[x]=p[y];
if(rank[x]==rank[y])
    rank[y]++;
}
}

   }


int main()
{
    Edgelist.resize(7);
    Edgelist[0]=make_pair(4,ii(0,1));
    Edgelist[1]=make_pair(2,ii(1,2));
    Edgelist[2]=make_pair(4,ii(0,2));
    Edgelist[3]=make_pair(6,ii(0,3));
    Edgelist[4]=make_pair(8,ii(3,2));
    Edgelist[5]=make_pair(6,ii(0,4));
    Edgelist[6]=make_pair(9,ii(4,3));
    rank.resize(5);
    p.resize(5);
    for(int i=0;i<5;i++){p[i]=i;}
        int mst_cost=0;

    sort(Edgelist.begin(),Edgelist.end());
    for(int i=0;i<7;i++){
        iii front =Edgelist[i];
        if(!SameSet(front.second.first,front.second.second)){
                cout<<front.second.first<<" To "<<front.second.second<<" Added "<<endl;
            mst_cost+=front.first;
            UnionSet(front.second.first,front.second.second);
        }
    }
    cout<<mst_cost<<" the Kruskal's Way"<<endl;

    return 0;
}
