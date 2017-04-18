#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
vi parent;
vi raank;

int n,m;
map<int,map<int,int> > employees;
int findset(int i)
{
    if(parent[i]==i)
    return i;
    else
    return parent[i]=(findset(parent[i]));
}
bool Sameset(int x,int y){
return(findset(x)==findset(y));
}

void unionSet(int i,int j){
if(!Sameset(i,j)){
    int x=findset(i);
    int y=findset(j);
    if(raank[x]>raank[y])
        parent[y]=x;
    else
        parent[x]=y;
    if(raank[x]==raank[y])
    raank[y]++;
}
}

int main()
{
    cin>>n>>m;
    raank.assign(n,0);
    parent.resize(n);
    for(int i=0;i<n;i++)
    parent[i]=i;
    bool one_language_exist=false;
    for(int i=0;i<n;i++){
    int k;
    cin>>k;
    if(k>0)
    one_language_exist=true;
    for(int j=0;j<k;j++){
        int x;
        cin>>x;
        employees[i][x]++;
    }
    }
    int res=0;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            for(auto it=employees[i].begin();it!=employees[i].end();it++)
            {
                if(employees[j].find(it->first)!=employees[j].end()){
                    {
                    unionSet(i,j);
                    break;
                    }

                }
            }

        }
    }
    map<int,int> groups;
    for(int i=0;i<n;i++)
    groups[findset(i)]++;
    if(one_language_exist)
    cout<<groups.size()-1<<endl;
    else{
    cout<<n<<endl;
    }
    return 0;
}
