#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 10000;
 int vis[50][50];
 //int lvl[50][50];
int x[8]={1,1,1,-1,-1,-1,0,0};
int y[8]={0,1,-1,0,1,-1,1,-1};
bool inbound(int x,int y,int h,int w){
    if((x>=h)||(x<0)||(y>=w)||(y<0)){
        return false;
    }
    return true;
}
int fuck(char tab[50][50],int j,int k,int h,int w){
    vis[j][k]=1;
    int res=0;
    for(int i=0;i<8;i++){
            if(inbound(j+x[i],k+y[i],h,w)){
                if(tab[j+x[i]][k+y[i]]-tab[j][k]==1){
                        if(vis[j+x[i]][k+y[i]]!=1){
                        //cout<<tab[j+x[i]][k+y[i]]<<" ";
                        res=max(1+fuck(tab,j+x[i],k+y[i],h,w),res);
                        }
                }
            }

    }
    return res;
}

int main()
{

    int h,w;
    int t=0;
    while(cin>>h>>w &&(h!=0)&&(w!=0)){
    t++;

    char tab[50][50];
    memset(vis,0,sizeof vis);

    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            cin>>tab[j][k];
        }
    }

    int res=0;
     for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            if(tab[j][k]=='A'){
                   //   cout<<"A ";
                res=max(res,1+fuck(tab,j,k,h,w));
                //cout<<res<<endl;
            }
        }
    }
    cout<<"Case "<<t<<": "<<res<<endl;

    }



    return 0;
}
