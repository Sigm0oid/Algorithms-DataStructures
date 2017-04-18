#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi p;
int mf,f,s=0,t=330;
int res[331][331];
int capacity[331][331];
char tab[40][40];
int x,y,o;
int num=1;
bool inbound(int i,int j){
return(i<x&&j<y&&i>=0&&j>=0);
}
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};

//int xi[8]={1,1,0,-1,-1,-1,0,1};
//int yi[8]={0,1,1,1,0,-1,-1,-1};

void augment(int v,int minEdge){

if(v==s){f=minEdge;return;}
else if(p[v]!=-1){
//cout<<"augment using "<<v<<endl;
                 augment(p[v],min(minEdge,res[p[v]][v]));
                res[p[v]][v]-=f;res[v][p[v]]+=f;
}
}
void Edmon(){
mf=0;
while(1){
f=0;
vi dis;
dis.assign(340,INT_MAX); dis[0]=0;
p.assign(340,-1);
queue<int> q;q.push(s);
while(!q.empty()){
int u=q.front();q.pop();
//cout<<" im in "<<u<<endl;
if(u==t) { break;}
for(int i=0;i<=330;i++)
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
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    string s;
    while(getline(cin,s)){
    if(s.length()!=0){
    memset(res,0,sizeof res);
    memset(capacity,1000,sizeof capacity);
    stringstream ss;
    ss.str(s);
    string token;
    vector<string> v;
    while(getline(ss,token,' ')){
    v.push_back(token);
    }
    x=atoi(v[0].c_str());
    y=atoi(v[1].c_str());
    o=atoi(v[2].c_str());
     for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
        cin>>tab[i][j];
        if(tab[i][j]=='~')
        capacity[i][j]=0;
        if(tab[i][j]=='*'||tab[i][j]=='.')
        capacity[i][j]=1;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
         if(tab[i][j]!='~'){
            for(int k=0;k<4;k++)
            {
            int newx=i+xi[k];
            int newy=j+yi[k];


            if(inbound(newx,newy)){
                if(tab[i][j]=='.')
                res[10*i+j+1][10*newx+newy+1]=1;
                 if(tab[i][j]=='@')
                res[10*i+j+1][10*newx+newy+1]=1000;
                 if(tab[i][j]=='*'&&tab[newx][newy]!='*')
                res[10*i+j+1][10*newx+newy+1]=1;
                if(tab[i][j]=='#')
                res[10*i+j+1][10*newx+newy+1]=1000;
            }
            }
         }
         if(tab[i][j]=='#')
            res[10*i+j+1][t]=o;
         if(tab[i][j]=='*')
            res[0][10*i+j+1]=1;
        }
    }
    Edmon();
    cout<<mf<<endl;
    }
    }
    return 0;
}
