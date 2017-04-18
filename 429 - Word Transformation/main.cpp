#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vector<string> dic;
vi vis,lvl;
int diff(string s1,string s2){
if (s1.length()!=s2.length())
    return 1000;
    int d=0,i=0;
    while(i<s1.length() ){
        if(s1[i]!=s2[i]){
            d++;
        }
        i++;
    }
    return d;
}


int getindex(string s){
int idx=-1,i=0;
while(i<dic.size()&&idx==-1){
        if(dic[i].length()==s.length()){
            if(diff(dic[i],s)==0)
            {idx=i;}
            }
    i++;
    }

return idx;
}

int bfs(string src,string dist){
        cout<<src<<" "<<dist<<" ";
vis[getindex(src)]=1;
lvl[getindex(src)]=0;
queue<int>q;
int res=0;
q.push(getindex(src));
while(!q.empty()) {
    int s=q.front();q.pop();
    if(getindex(dist)==s){
        res= lvl[s];
    }
    for(int i=0;i<(int)Adjlist[s].size();i++){
        if(vis[Adjlist[s][i].first]==0){
            vis[Adjlist[s][i].first]=1;
            q.push(Adjlist[s][i].first);
            lvl[Adjlist[s][i].first]=1+lvl[s];
        }
    }
}
return res;
}
int main()
{
//   freopen("out.out","w",stdout);
//   freopen("in.in","r",stdin);
    int k=0;
    int n;
    cin>>n;
    string l;

    while(n--){
    if(k==0){getline(cin,l); k++;}
    else{cout<<endl;}
    dic.clear();
    Adjlist.clear();
    Adjlist.resize(200);

    string s;
    while(cin>>s&&s!="*"){
        dic.push_back(s);
        for(int i=0;i<dic.size()-1;i++){
        if(diff(dic[i],s)==1){
            Adjlist[i].push_back(ii(dic.size()-1,1));
            Adjlist[dic.size()-1].push_back(ii(i,1));
            }
        }

    }
    string src="",dist="",ligne;
    getline(cin,ligne);
    while(getline(cin,ligne)&&ligne.length()>0){
            src="";dist="";
    int i=0;
    int space=0;
    while(i<ligne.length()){

        if(ligne[i]==' '){space++;}
        else{
            if(space==0){src+=ligne[i];}
            else{dist+=ligne[i];
        }
    }

    i++;
    }
    lvl.clear();
    vis.clear();
    lvl.resize(dic.size());
    vis.resize(dic.size());
    cout<<bfs(src,dist)<<endl;
//    lvl.clear();
//    vis.clear();
//    lvl.resize(dic.size());
//    vis.resize(dic.size());
    }




    }
    return 0;
}
