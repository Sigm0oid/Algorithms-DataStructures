#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int tab[110][110];
int vis[110][110];
int n;
map<int,int> colors;
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};

bool inbound(int i,int j){
return (i>=0&&j>=0&&i<n&&j<n);
}
int dfs(int i,int j){
int res=1;
vis[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+xi[k];
        int y=j+yi[k];
        if(inbound(x,y)&&vis[x][y]==0&&tab[i][j]==tab[x][y])
        res+=dfs(x,y);
    }
    return res;

}


int main()
{
    while(cin>>n&&n!=0){
    colors.clear();
    colors[0]=(n*n);
    string s;
    getline(cin,s);
    memset(tab,0,sizeof tab);
    memset(vis,0,sizeof vis);
    bool res=true;
    for(int i=0;i<n-1;i++){
    getline(cin,s);
    stringstream ss;
    ss.str(s);
    string token;
    vector<int> v;
    while(getline(ss,token,' ')){
    v.push_back(atoi(token.c_str()));
//    cout<<" added "<<token<<endl;
    }


        for(int j=0;j<v.size();j+=2){
            int x=v[j],y=v[j+1];
          //  cout<<x<<" "<<y<<endl;
             if(tab[x-1][y-1]==i+1)
             continue;

            tab[x-1][y-1]=i+1;
            colors[i+1]++;
            colors[0]--;
        }

    }

    for(int i=0;i<n&&res;i++){
    for(int j=0;j<n&&res;j++){
            if(vis[i][j])
            continue;
            int tmp=dfs(i,j);
            //cout<<" from "<<i<<" j "<<j<<"i can go to "<<tmp<<" and colors ="<<colors[tab[i][j]]<<endl;
            if(tmp!=colors[tab[i][j]]||colors[tab[i][j]]!=n)
            res=false;
            }

        }




    if(!res)
    cout<<"wrong"<<endl;
    else
    cout<<"good"<<endl;


    }
    return 0;
}
