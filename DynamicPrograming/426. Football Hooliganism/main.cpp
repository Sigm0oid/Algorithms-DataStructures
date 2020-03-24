#include <bits/stdc++.h>

using namespace std;
int tab[10010][2];
int dp[10010][120];
int  n,t;
int fuck(int ligne,int previous_merged,int prev_left,int prev_right){

if(dp[ligne][100*previous_merged+10*prev_left+1*prev_right]!=-1)
return dp[ligne][100*previous_merged+10*prev_left+1*prev_right];

int res=1000000;

    if(ligne==n){

    return dp[ligne][100*previous_merged+10*prev_left+1*prev_right]=(2-(prev_left+prev_right));

    }

    if(ligne==0){
    if(tab[0][0]==tab[0][1])
    res=fuck(ligne+1,1,1,1);
    res=min(res,fuck(ligne+1,0,0,0));
    return dp[ligne][100*previous_merged+10*prev_left+1*prev_right]=res;
    }

    //try to merge the horizontal way//
    if(tab[ligne][0]==tab[ligne][1])
    res=min(2-(prev_left+prev_right)+fuck(ligne+1,1,1,1),res);

    //merge left with previous left and add 1-prev_right to score
    if(tab[ligne][0]==tab[ligne-1][0]&&previous_merged==0)
    res=min(1-(prev_right)+fuck(ligne+1,0,1,0),res);

    //merge left with previous right and add 1-prev_left to score
    if(tab[ligne][1]==tab[ligne-1][1]&&previous_merged==0)
    res=min(1-(prev_left)+fuck(ligne+1,0,0,1),res);

    //merge the two if possible
    if(tab[ligne][0]==tab[ligne-1][0]&&tab[ligne][1]==tab[ligne-1][1]&&previous_merged==0)
    res=min(fuck(ligne+1,0,1,1),res);

    // if prev_left != left && prev_rigth diff right //
    if(tab[ligne][0]!=tab[ligne-1][0]&&tab[ligne][1]!=tab[ligne-1][1])
    res=min(2-(prev_left+prev_right)+fuck(ligne+1,0,0,0),res);

    //if prev merged and tab[ligne][0]!=tab[ligne][1]
    // if prev_left != left && prev_rigth diff right //
    if(tab[ligne][0]!=tab[ligne][1]&&previous_merged==1)
    res=min(fuck(ligne+1,0,0,0),res);


return dp[ligne][100*previous_merged+10*prev_left+1*prev_right]=res;

}


int main()
{
    cin>>t;
    while(t--){
    memset(tab,0,sizeof tab);
    memset(dp,-1,sizeof dp);
    cin>>n;
   for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            tab[i][0]=c-'0';
            cin>>c;
            tab[i][1]=c-'0';

        }

    cout<<fuck(0,0,0,0)<<endl;
    }

    return 0;
}
