#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> Adjlist;
vii bridges;
vi dfs_num,dfs_low,parent;
int rootCildren,root,DfsNumCmp;
ll n;

void articulationBridge(int src){
//cout<<src<<" visited"<<endl;
dfs_low[src]=dfs_num[src]=DfsNumCmp++;
for(int i=0;i<(int)Adjlist[src].size();i++){
    int v=Adjlist[src][i].first;
    if(dfs_num[v]==-1){
        parent[v]=src;
        if(src==root){rootCildren++;}

        articulationBridge(v);

        if(dfs_low[v]>dfs_num[src]){

            bridges.push_back(ii(min(src,v),max(src,v)));
        }

        dfs_low[src]=min(dfs_low[src],dfs_low[v]);



    }
    else{
            if(v!=parent[src]){
                dfs_low[src]=min(dfs_low[src],dfs_num[v]);
            }

    }
}

}
int getnum(string s){
   // cout<<(atoi((s.substr(1,s.length()-2)).c_str()))<<endl;
    return (atoi((s.substr(1,s.length()-2)).c_str()));


}


int main()
{
    //freopen("out.out","w",stdout);
    //freopen("in.in","r",stdin);
    while(cin>>n){
        //cout<<n<<endl;
        if(n>0){


        Adjlist.clear();
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_num.clear();
        dfs_num.assign(n,-1);
        parent.clear();
        parent.resize(n);
        bridges.clear();
        root=rootCildren=DfsNumCmp=0;
         while(n--){
        int src;
        string s;
        cin>>src;
        cin>>s;
        int num=getnum(s);
        for(int i=0;i<num;i++){
            int x;
            cin>>x;
            Adjlist[src].push_back(ii(x,1));
            //Adjlist[x].push_back(ii(src,1));
        }
        }
        for(int i=0;i<(int)Adjlist.size();i++){
            if(dfs_num[i]==-1){
              //      cout<<"start from "<< i<<endl;
                    root=i;rootCildren=0;
                    articulationBridge(root);
            }
        }
        cout<<bridges.size()<<" critical links"<<endl;
        sort(bridges.begin(),bridges.end());
        for(int i=0;i<bridges.size();i++){
            cout<<bridges[i].first<<" - "<<bridges[i].second<<endl;
        }




        }
        else{
            cout<<"0 critical links"<<endl;
        }
        cout<<endl;


    }
    return 0;
}
