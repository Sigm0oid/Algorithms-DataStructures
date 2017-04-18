#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<pair<int,ii> > viii;
typedef vector<int> vi;
viii Edgelist;
vi resEdgelist;

vi parent,rnk;
int n,m;

int FindSet(int i){
if(parent[i]==i)
    return i;
else{
    return parent[i]=FindSet(parent[i]);
}
}
bool SameSet(int i,int j){
return (FindSet(i)==FindSet(j));
}

void UnionSet(int i,int j){
int x=FindSet(i);
int y=FindSet(j);

if(rnk[x]>rnk[y]){
    parent[y]=x;
}
else{parent[x]=y;
    if(rnk[x]==rnk[y])
        rnk[y]++;
                }
}

int main()
{
    freopen("out.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
            cin>>n>>m;
    Edgelist.clear();
    resEdgelist.clear();
    parent.clear();
    parent.resize(n);
    for(int k=0;k<n;k++){
        parent[k]=k;
    }
    rnk.clear();
    rnk.resize(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edgelist.push_back(make_pair(c,ii(a-1,b-1)));
    }

    sort(Edgelist.begin(),Edgelist.end());
    int s1=0,s2=0;
    for(int i=0;i<Edgelist.size();i++){
    int x=Edgelist[i].second.first;
    int y=Edgelist[i].second.second;
    if(!SameSet(x,y)){
        UnionSet(x,y);
        s1+=Edgelist[i].first;
        resEdgelist.push_back(i);
    }
    }


    int sTmp=0;
    for(int i=0;i<resEdgelist.size();i++){

            sTmp=0;
            //cout<<"msp no "<<i+1<<endl;
            parent.clear();
            parent.resize(n);
            for(int k=0;k<n;k++){
                parent[k]=k;
            }
            rnk.clear();
            rnk.resize(n);
            for(int j=0;j<Edgelist.size();j++){
                int x=Edgelist[j].second.first;
                int y=Edgelist[j].second.second;

                if(!SameSet(x,y)){
                if(j!=resEdgelist[i]){
                    UnionSet(x,y);
                    sTmp+=Edgelist[j].first;
                   // cout<<"Edge "<<x<<" to "<<y<< "used  cost "<<Edgelist[j].first<<endl;

               }
            }
           }
            if(s2==0)
                s2=sTmp;
            else{
                if(sTmp>=s1)
                s2=min(s2,sTmp);
            }
    }



    cout<<s1<<" "<<s2<<endl;


    }
    return 0;
}
