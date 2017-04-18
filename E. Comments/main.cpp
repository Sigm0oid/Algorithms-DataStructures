#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vector<string> >depth;
int j=0;
vector<vii>Adjlist;
int max_level=-1;
vector<string> v;

void dfs(int current_level,int indice){
max_level=max(current_level,max_level);
//cout<<v[indice]<<" visited at level "<<current_level<<endl;
depth[current_level].push_back(v[indice]);
//cout<<" i haave "<<atoi(v[indice+1].c_str())<<" children "<<endl;
for(int i=0;i<atoi(v[indice+1].c_str());i++){
dfs(current_level+1,j+=2);
}

}

int main()
{

    ios_base::sync_with_stdio(false);
    depth.resize(1000010);
    string s;
    cin>>s;

    stringstream ss;
    ss.str(s);
    string token;

    while(getline(ss,token,',')){
    v.push_back(token);
    }


    dfs(0,j);
    while((j+2)<v.size()){
    j+=2;
    dfs(0,j);
    }
    cout<<max_level+1<<endl;
    for(int i=0;i<max_level+1;i++)
        {for(int k=0;k<depth[i].size();k++)
        cout<<depth[i][k]<<" ";
        cout<<endl;
        }


    return 0;
}
