#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mhp,matk,mdef;
int prixhp,prixdef,prixatk;
bool win(int yhp,int yatk,int ydef)
{
int nbrRoundtoKillMonster,nbrRoundtoKillYoung;
if((yatk-mdef)<=0){nbrRoundtoKillMonster=100000;}
else{
    nbrRoundtoKillMonster=(mhp/(yatk-mdef));
if((mhp%((yatk-mdef)))>0){nbrRoundtoKillMonster++;}
}
if((matk-ydef)<=0){nbrRoundtoKillYoung=100000;}

else{
    nbrRoundtoKillYoung=(yhp/(matk-ydef));
    if((yhp%(matk-ydef))>0){nbrRoundtoKillYoung++;}

}
return (nbrRoundtoKillMonster<nbrRoundtoKillYoung);

}




int main()
{
    int yhp,yatk,ydef;
    //memset(dp,10000,sizeof dp);
   // freopen("out.out","w",stdout);
    cin>> yhp>> yatk>> ydef;
    cin>>mhp>> matk>> mdef;
    cin>> prixhp>> prixatk>> prixdef;
    int res=1000000;
    for(int i=yatk;i<=200;i++){
        for(int j=ydef;j<=200;j++){
            for(int k=yhp;k<=2000;k++){
                if(win(k,i,j))
                   {
                       //cout<<"kill monster with a tack "<<i<<" def "<<j<<" hp "<<yhp<<endl;
                       res=min(res,(((i-yatk)*prixatk)+((j-ydef)*prixdef)+((k-yhp)*prixhp)));
                       //cout<<res<<endl;

                   }
            }
        }
    }


    cout<<res<<endl;
    return 0;
}
