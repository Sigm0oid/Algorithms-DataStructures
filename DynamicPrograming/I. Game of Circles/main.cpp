#include <bits/stdc++.h>
#define debug(x) cout << #x << " : " << x << endl;
//#define MAX 100000000000100
typedef long long ll;
using namespace std;
int n;
ll MAX=LLONG_MAX/2 ;

ll dp [210][210];
ll circle [210];
ll matching[210];
ll match(int inf,int supp,int cmp)
{
    ///if(cmp >= n )
        /*for(int k=0;k<n;k++)
        {
            cout<<matching[k]+1<<"\t";

        }
        cout<<endl;*/

    if(supp<=inf)
        return 0;

    if(dp[inf][supp]!=-1){
    return dp[inf][supp];
    }
    ll res=MAX;
    int i=inf;
    for(int j=inf+1;j<=supp;j+=2){


    matching[i]=j;
    matching[j]=i;
    ll cost=((circle[i]+circle[j])*(circle[i]+circle[j]));
    /*debug(i);
    debug(j);
    debug(inf);
    debug(supp);
    cout <<"Visiting match("<<i+1<<" , "<<j-1<<")"<<endl;*/
    ll m1 = match(i+1,j-1,cmp+2);
    //cout << "Quitting match("<<i+1<<" , "<<j-1<<")"<<endl;
    //cout <<"Visiting match("<<j+1<<" , "<<supp<<")"<<endl;
    ll m2 = match(j+1,supp,cmp+2);
    //cout << "Quitting match("<<j+1<<" , "<<supp<<")"<<endl;
//    if(i==0&&j==3)
//    cout<<" m1 "<<m1<<" m2 "<<m2<<endl;

    res=min(res,cost+ m1 + m2 );
    //if((cmp+2)==n)
    //{

    //}
    matching[j]=-1;
    matching[i]=-1;
    }
    return dp[inf][supp]=res ;

}
int main()
{
    freopen("game.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
   // cout<<n<<endl;
    memset(circle,0,sizeof circle);
    memset(matching,-1,sizeof (matching));
    memset(dp,-1,sizeof dp);

        for(int i=0;i<n;i++){
        cin>>circle[i];
    }
    printf("%lld\n",match(0,n-1,0));


    }
    return 0;
}
