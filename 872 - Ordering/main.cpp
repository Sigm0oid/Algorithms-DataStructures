#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef  pair<int,int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi lvl;
vi vis;
vector<char> tab;
int cmp;
 vi used;
vector<string> restab;
void  dfs(int x,string word){
  //  cout<<"dfs on "<<tab[x]<<" total "<<word<<endl;
    if(word.length()==tab.size()){
        restab.push_back(word);
    }
    else{
    used[x]=1;

        string res;
        res+=word;
        for(int i=0;i<Adjlist[x].size();i++){
            ii v=Adjlist[x][i];
            lvl[v.first]--;


        }
        for(int i=0;i<lvl.size();i++){
            if(lvl[i]==0&&used[i]==0){
                dfs(i,res+tab[i]);

            }
        }
          for(int i=0;i<Adjlist[x].size();i++){
            ii v=Adjlist[x][i];
            lvl[v.first]++;

        }
    }
    used[x]=0;
}


int getindx(char x){
int i=0;
bool found=false;

while(!found){
    if(x==tab[i]){
        found=true;
    }
    else{
        i++;
    }
}
return i;
}

int main()
{
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        tab.clear();
        restab.clear();
        string s="";
        while(s.length()<2){
            getline(cin,s);
        }

        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                tab.push_back(s[i]);
            }
        }

        sort(tab.begin(),tab.end());
        lvl.clear();
        lvl.resize(tab.size());
        used.clear();
        used.resize(tab.size());
        getline(cin,s);
        Adjlist.clear();
        Adjlist.resize(tab.size());
         for(int i=0;i<s.length();i++){
            if(s[i]=='<'){
                    Adjlist[getindx(s[i-1])].push_back(ii(getindx(s[i+1]),1));
                    lvl[getindx(s[i+1])]++;

            }
        }

        for(int i=0;i<tab.size();i++){
            if(lvl[i]==0){
                    string g="";
                    g+=tab[i];
                dfs(i,g);

            }
        }
        if(restab.size()==0){
            cout<<"NO"<<endl;
        }
        else{
            for(int i=0;i<restab.size();i++){
                for(int j=0;j<restab[i].length();j++){
                    cout<<restab[i][j];
                    if(j!=restab[i].length()-1){cout<<" ";}
                }
                cout<<endl;
            }
        }
        if(t>0)cout<<endl;



    }

    return 0;
}
