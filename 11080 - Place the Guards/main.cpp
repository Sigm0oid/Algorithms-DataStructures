#include <bits/stdc++.h>

using namespace std;
 typedef long long ll;
 typedef pair<int,int> ii;
 typedef vector <ii> vii;
 typedef vector <int> vi;
 vector<vii> Adjlist;
 vi vis;
 vi color;
 int v,e;
 int m,color1,color2;



 void dfs(int src){

 for(int i=0;i<Adjlist[src].size();i++){
    if(vis[Adjlist[src][i].first]==0){
        vis[Adjlist[src][i].first]=1;
        color[Adjlist[src][i].first]=1-color[src];
        if(1-color[src]==0){color1++;}
        else{color2++;}
        dfs(Adjlist[src][i].first);
    }
    else{
    if(color[Adjlist[src][i].first]==color[src]){

            m=-1;}
    }
 }

 }

int main()
{
    freopen("out.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
            m=color1=color2=0;

        cin>>e>>v;
        Adjlist.clear();
        color.clear();
        vis.clear();
        Adjlist.resize(e);
        color.resize(e);
        vis.resize(e);
        for(int i=0;i<v;i++){
            int f,t;
            cin>>f>>t;
            Adjlist[f].push_back(ii(t,1));
            Adjlist[t].push_back(ii(f,1));
        }

        int ans=0,tmp=-1;
        for(int i=0;i<e;i++){

           if(vis[i]==0){
            color1=color2=0;
            vis[i]=1;
            color[i]=0;
            color1++;

            dfs(i);
            if(m==-1){
            break;
            }else{
            tmp=min(color1,color2);
            if(tmp==0){tmp=color1+color2;}
            ans+=tmp;

            }



           }
        }
        if(m==-1)
        cout<<m<<endl;
        else{
            cout<<ans<<endl;
        }


    }
    return 0;
}
