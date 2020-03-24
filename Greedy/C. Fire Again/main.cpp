#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int tab[2010][2010];
int dis[2010][2010];
int n,m,k;
map<ii,int> burning;
int distance(int x1,int y1,int x2,int y2){
//cout<<" distance from "<<x1 <<" "<<y1<<" to "<<x2<<" "<<y2<<" "<<abs(x1-x2)+abs(y1-y2)<<endl;
return(abs(x1-x2)+abs(y1-y2));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
    int x,y;
    cin>>x>>y;
    burning[ii(x-1,y-1)]++;
    }
    ii res=ii(0,0);
    int mindisance=0;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int dist=INT_MAX;
        for(auto it=burning.begin();it!=burning.end();it++){
            dist=min(dist,distance(i,j,it->first.first,it->first.second));
        }
        if(dist>mindisance){
       // cout<<" change it to "<<i<<" "<<j<<endl;
        mindisance=dist;
        res=ii(i,j);
        }
    }
    }
    cout<<res.first+1<<" "<<res.second+1<<endl;
    return 0;
}

