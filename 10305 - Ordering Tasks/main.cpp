#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef vector <ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi lvl;
vi used;
int n,m;
vector<string > restab;
  string NumberToString ( int Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void dfs(int x,int cmp){
  //  cout<<"dfs call with "<<res<<endl ;
    if(cmp==n){

            return ;
    }
    else{

        for(int i=0;i<Adjlist[x].size();i++){
            lvl[Adjlist[x][i].first]--;
        }
        for(int i=0;i<n;i++){
            if(lvl[i]==0&& used[i]==0){
                used[i]=1;
                cout<<" "<<i+1;
                 dfs(i,cmp++);
               break;
            }
        }
//        for(int i=0;i<Adjlist[x].size();i++){
//            lvl[Adjlist[x][i].first]++;
//        }
    }
//used[x]=0;
}

int main()
{
    //freopen("out.out","w",stdout);
    while(cin>>n>>m&&(n>0||m>0)){
    Adjlist.clear();
    Adjlist.resize(n);
    lvl.clear();
    lvl.resize(n);

    used.clear();
    used.resize(n);
    for(int i=0;i<m;i++){
        int src,dist;
        cin>>src>>dist;

        Adjlist[src-1].push_back(ii(dist-1,1));
        //cout<<src-1<<dist-1<<endl;
        lvl[dist-1]++;
    }
    for(int i=0;i<n;i++){

        if(lvl[i]==0){

            used[i]=1;
            cout<<i+1;
           dfs(i,1);

           cout<<endl;
            //used[i]=0;

        break;
        }

    }

//    for(int i=0;i<restab[0].length();i++){
//        char d=restab[0][i];
//        d+=1;
//        cout<<d;
//        if(i!=restab[0].length()){cout<<" ";}
//    }
//    cout<<endl;

    }
    return 0;
}
