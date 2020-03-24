#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<pair<double,ii> > viii;
typedef vector<int> vi;
vector< pair<int,int> > point;

viii Edgelist;
int s,p;
vi parent,rnk;
int FindSet(int i){
if(parent[i]==i)
    return i;
    else{
        return parent[i]=FindSet(parent[i]);
    }
}

bool SameSet(int i,int j){
return(FindSet(i)==FindSet(j));

}
void UnionSet(int i,int j){
int x=FindSet(i);
int y=FindSet(j);
if(rnk[x]>rnk[y]){
    parent[y]=x;
}
else{
    parent[x]=y;
    if(rnk[x]==rnk[y])
        rnk[y]++;
}
}

int main()
{
    int t;
    cin>>t;
    while(t--){
            cin>>s>>p;

            point.clear();
            Edgelist.clear();
            parent.clear();
            parent.resize(p);
            for(int i=0;i<p;i++){
                parent[i]=i;
            }
            rnk.clear();
            rnk.resize(p);
    for(int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        point.push_back(ii(x,y));
        for(int j=0;j<i;j++){
        double dist=sqrt(((point[i].first-point[j].first)*(point[i].first-point[j].first))+((point[i].second-point[j].second)*(point[i].second-point[j].second)));

        //cout<<"cc"<<endl;
        Edgelist.push_back(make_pair(dist,ii(i,j)));
        }
    }
    sort(Edgelist.begin(),Edgelist.end());
    int nbrset=p,i=0;
    double res=0;
    while(nbrset>s){
           // cout<<nbrset<<endl;

            int x=Edgelist[i].second.first;
            int y=Edgelist[i].second.second;
            if(!SameSet(x,y)){
                UnionSet(x,y);
            nbrset--;
            res=max(res,Edgelist[i].first);

            }
            i++;


    }
    cout<<fixed<<setprecision(2)<<res<<endl;

    }


    return 0;
}

