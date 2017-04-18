/*
ID: geekham1
LANG: C++11
TASK: combo
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,ans=0;
iii farmer;
iii master;
int res[110][110][110];
void accepted(int i,int j,int k){
if(res[i][j][k]>0)
{ans++;
return ;}
else{
    if((abs(i-farmer.first)<3||abs(n-abs(i-farmer.first))<3)&&(abs(j-farmer.second.first)<3||abs(n-abs(j-farmer.second.first))<3)&&(abs(k-farmer.second.second)<3||abs(n-abs(k-farmer.second.second))<3))
    {
        res[i][j][k]=1;
        ans++;
        return ;
    }
     if((abs(i-master.first)<3||abs(n-abs(i-master.first))<3)&&(abs(j-master.second.first)<3||abs(n-abs(j-master.second.first))<3)&&(abs(k-master.second.second)<3||abs(n-abs(k-master.second.second))<3))
    {
        res[i][j][k]=1;
        ans++;
        return ;
    }
}


}

int main()
{

   memset(res,0,sizeof res);


    freopen("combo.in","r",stdin);
   freopen("combo.out","w",stdout);

   cin>>n;

   cin>>farmer.first>>farmer.second.first>>farmer.second.second;
   cin>>master.first>>master.second.first>>master.second.second;
//   vector<iii> res;
   for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                accepted(i,j,k);


   }}}

    cout<<ans<<endl;
     return 0;
}
