#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector <int> vi;
typedef vector< pair<int,ii> > viii;
viii Edgelist;
vector<vii> Adjlist(26);
vi vis,dis,parent,rnk,vertix;
  int s;








int main()
{
    string name;
    while(cin>>name){
        if(name!="deadend"){

            s=name[0]-'a';
            Adjlist[name[0]-'a'].push_back(ii(name[name.length()-1]-'a',name.length()));
            Adjlist[name[name.length()-1]-'a'].push_back(ii(name[0]-'a',name.length()));

        }
        else{

                vis.clear();
                vis.resize(26);
                dis.clear();
                dis.assign(26,100000);

            vis[s]=1;
            res=dfs(s,0,1);


            // what to do ?? Euler  circle

            Adjlist.clear();
            Adjlist.resize(26);
             Adjlist1.clear();
            Adjlist1.resize(26);
            nbvertix=0;
            vertix.clear();
            cout<<res<<endl;

        }
    }


    return 0;
}
