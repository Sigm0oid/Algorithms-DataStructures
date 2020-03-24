#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector< pair<ll,ii> > viii;
viii Edgelist;
vi parent,rnk;
vector<ll> res;


int n,m;

int FindSet(int i){
if(parent[i]==i)return i;
else {
        return parent[i]=FindSet(parent[i]);
     }
}

bool SameSet(int x,int y){
return (FindSet(x)==FindSet(y));}

void unionSet(int i,int j){
//cout<<"union of "<<i<< " "<<j<<endl;
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
//cout<<FindSet(i)<< " "<<FindSet(j)<<endl;

}

int main()
{
    freopen("in.in","w",stdout);
    while(cin>>n>>m&&(n>0||m>0))
    {
        Edgelist.clear();
        res.clear();
        parent.clear();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rnk.clear();
        rnk.resize(n);
        for(int i=0;i<m;i++){
                int a,b;
                ll c;
                cin>>a>>b>>c;
                Edgelist.push_back(make_pair(c,ii(a,b)));
        }
        sort(Edgelist.begin(),Edgelist.end());
        for(int i=0;i<Edgelist.size();i++){
            int x=Edgelist[i].second.first;
            int y=Edgelist[i].second.second;

            if(!SameSet(x,y)){

                unionSet(x,y);


            }
            else{

                res.push_back(Edgelist[i].first);
            }
        }
        if(res.size()==0){
            cout<<"forest"<<endl;
        }
        else{
            sort(res.begin(),res.end());
            for(int i=0;i<res.size();i++){
                cout<<res[i];
                if(i!=res.size()-1){cout<<" ";}
            }
            cout<<endl;
        }


    }

    return 0;
}

