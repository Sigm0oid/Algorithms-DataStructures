#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi p;
int mf=0,f=0,s=0,t=39;
int res[40][40];
void augment( int v,int minEdge){
if(v==s){f=minEdge; return ;}
else if(p[v]!=-1){augment(p[v],min(minEdge,res[p[v]][v]));
                    res[p[v]][v]-=f;res[v][p[v]]+=f;
                    }
}

void Edmon(){

mf=0;
while(1){
f=0;
vi dis(40,INT_MAX);
dis[s]=0;
p.assign(40,-1);
queue<int> q; q.push(s);
while(!q.empty()){
int u=q.front();
q.pop();
if(u==t)
break;
    for(int i=0;i<40;i++)
        if(res[u][i]>0&&dis[i]==INT_MAX)
        dis[i]=dis[u]+1,q.push(i),p[i]=u;

}
augment(t,INT_MAX);
if(f==0)
break;
mf+=f;
}
}
int main()
{
    string backup="aaa";
    while(1){
    int need=0;
    string s;
    memset(res,0,sizeof res);
    while(getline(cin,s)&&s.length()>0){
    backup=s;
        stringstream ss;
        ss.str(s);
        string token;
        vector<string> v;
        while(getline(ss,token,' '))
        {
            v.push_back(token);
        }
        res[0][v[0][0]-'A'+1]=v[0][1]-'0';
        need+=v[0][1]-'0';
        for(int i=0;i<v[1].length()-1;i++)
        res[v[0][0]-'A'+1][v[1][i]-'0'+27]=INT_MAX;
     }
     if(backup.length()==0&&s.length()==0)
     break;
     backup=s;
     for(int i=27;i<38;i++)
     res[i][39]=1;
     Edmon();
     if(mf<need)
     cout<<'!'<<endl;
     else{
     vector<char> occupied_by;
    //cout<<" max flow is "<<mf<<endl;
     occupied_by.assign(11,'_');
        for(int i=27;i<38;i++){
            for(int j=1;j<28;j++){
            if(res[i][j]>0)
            {
            occupied_by[i-27]=(char)('A'+(j-1));

            }
        }
        }
        for(int i=0;i<10;i++)
        cout<<occupied_by[i];
        cout<<endl;
     }
     //getline(cin,s);
    }
    return 0;
}
