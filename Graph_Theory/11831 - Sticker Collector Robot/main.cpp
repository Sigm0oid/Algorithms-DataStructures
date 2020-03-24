#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,directin,xrobot,yrobot;
//direction N=1,S=2,L=3,O=4;
ll s;
char tab[110][110];
int x[4]={1,0,0,-1};
int y[4]={0,1,-1,0};
bool inbound(int x,int y){
return ((x<n)&&(y<m)&&(x>=0)&&(y>=0)&&(tab[x][y]!='#'));}





int main()
{
    freopen("out.out","w",stdout);
    while((cin>>n>>m>>s)&&(s!=0||m!=0||n!=0)){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        char a;
        cin>>a;
        if(a=='N'){xrobot=i;yrobot=j;directin=0;tab[i][j]='.';}
        else if(a=='S'){xrobot=i;yrobot=j;directin=2;tab[i][j]='.';}
        else if(a=='L'){xrobot=i;yrobot=j;directin=3;tab[i][j]='.';}
        else if(a=='O'){xrobot=i;yrobot=j;directin=1;tab[i][j]='.';}
        else {tab[i][j]=a;}

            }
        }
        char movement[s];
        for(int i=0;i<s;i++){cin>>movement[i];}
    int     i=0;
    ll res=0;
    while(i<s+1){
          //  cout<<"x "<<xrobot<<"y "<<yrobot<<endl;

            if(tab[xrobot][yrobot]=='*'){
                res++;
                tab[xrobot][yrobot]='.';
            }
    if(movement[i]=='E'){directin=((directin+1)%4);}
    if(movement[i]=='D'){
            if(directin==0){directin=3;}else {directin-=1;}}
    if(movement[i]=='F'){
            if((directin==0)&&inbound(xrobot-1,yrobot)){xrobot--;}
            if((directin==1)&&inbound(xrobot,yrobot-1)){yrobot--;}
            if((directin==2)&&inbound(xrobot+1,yrobot)){xrobot++;}
            if((directin==3)&&inbound(xrobot,yrobot+1)){yrobot++;}
        }

    i++;
    }
  //  cout<<"x "<<xrobot<<"y "<<yrobot<<endl;
    cout<<res<<endl;
    }
    return 0;
}
