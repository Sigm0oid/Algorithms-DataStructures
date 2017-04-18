#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< pair<double,ii> > viii;
viii Edgelist;
vii point;
int n,r;
vi parent,rnk;

double dist(int j,int k){

    return(sqrt(((point[j].first)-(point[k].first) ) *((point[j].first)-(point[k].first) ) + ((point[j].second)-(point[k].second) ) *((point[j].second)-(point[k].second))));

}

int findset(int i){
if(parent[i]==i)
    return i;
    else{
        return parent[i]=findset(parent[i]);
    }
}
bool isSameSet(int i,int j){
return (findset(i)==findset(j));
}
void unionSet(int i,int j)
{
    if(!isSameSet(i,j)){
            int x=findset(i);int y=findset(j);
            if(rnk[x]>rnk[y])  parent[y]=x;
            else{
                parent[x]=y;
                if(rnk[x]==rnk[y]) rnk[y]++;
            }

    }
}


int main()
{
    freopen("out.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>r;
        point.clear();
        point.resize(n);
        Edgelist.clear();
        parent.clear();
        parent.resize(n);
        rnk.clear();
        rnk.resize(n);
        for(int j=0;j<n;j++){
                parent[j]=j;
            ii pnt;
            cin>>pnt.first>>pnt.second;
            point[j]=pnt;
            for(int k=0;k<j;k++){
                Edgelist.push_back(make_pair(dist(j,k),ii(j,k)));
                //cout<<"distance "<<dist(j,k)<<endl;
            }
        }
        double roads=0.0,railroads=0.0;
        ll stats=1;
        sort(Edgelist.begin(),Edgelist.end());
        for(int j=0;j<Edgelist.size();j++)
        {
            int a=Edgelist[j].second.first;
            int b=Edgelist[j].second.second;
            if(!isSameSet(a,b)){
                unionSet(a,b);
                //cout<<"Edge From "<<point[a].first<<" "<<point[a].second <<" to "<<point[b].first<<" "<<point[b].second<<" with dist "<<Edgelist[j].first<<endl;
                if(Edgelist[j].first>r){stats++; railroads+=(Edgelist[j].first);}
                else roads+=(Edgelist[j].first);

            }
        }
        cout<<"Case #"<<i+1<<": "<<stats<<" "<<round(roads)<<" "<<round(railroads)<<endl;



    }

    return 0;
}
