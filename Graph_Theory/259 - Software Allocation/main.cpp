#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int INF=INT_MAX;
int res[40][40];
int f,mf,s,t;
vi parent;
int nbuser=0;

void augment(int v,int minEdge){

if(v==s){f=minEdge;return;}
else if(parent[v]!=-1){
augment(parent[v],min(minEdge,res[parent[v]][v]));

res[parent[v]][v]-=f;res[v][parent[v]]+=f;
}
}

int main()
{
freopen("in.in","r",stdin);
freopen("out.out","w",stdout);
int nbNoeds=38;
s=0;t=37;

do{

 memset(res,0,sizeof res);
        for(int i=27;i<37;i++){
        res[i][37]=1;
        }
        nbuser=0;
string str;
while(getline(cin,str)&&str.length()>0)
            {
            char src=str[0];
            res[0][src-'A'+1]+=(str[1]-'0');
            nbuser+=str[1]-'0';
            for(int i=3;i<str.length()-1;i++){
                res[src-'A'+1][str[i]-'0'+27]=INF;
                }


            }

                mf=0; //max flow to 0
            while(1){
                f=0; //initialize flow t 0
                //run bfs and stop when u found a path to t
                vi dis(nbNoeds,INF); dis[s]=0;queue<int> q;q.push(s);
                parent.assign(nbNoeds,-1);
                while(!q.empty()){
                int u=q.front();q.pop();
                if(u==t) break; //stop bfs directly
                for(int i=0;i<nbNoeds;i++){
                if(res[u][i]>0&&dis[i]==INF){
                dis[i]=dis[u]+1;q.push(i);parent[i]=u;}
                }

            }

            augment(t,INF);
            if(f==0)break;
            mf+=f;



        }

        if(mf<nbuser)
        cout<<'!'<<endl;
        else
        {
        vector<char> r;
        r.assign(10,'_');
        for(int i=1;i<27;i++){
        for(int j=27;j<37;j++){

        if(res[j][i]==1)
        r[j-27]=char('A'+i-1);


        }

        }
        for(int i=0;i<10;i++)
        cout<<r[i];
        cout<<endl;

        }


}while(!cin.eof());

return 0;
}


