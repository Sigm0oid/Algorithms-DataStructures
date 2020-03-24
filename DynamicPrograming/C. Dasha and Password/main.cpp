#include <bits/stdc++.h>

using namespace std;
vector<string> tab;
int n,m;
int global_score=INT_MAX;
int dp[55][3];
char t[3]={'a','5','&'};
void isibizi(int pos ){
int speci=51;
int alph=51;
int dig=51;
string s=tab[pos];
for(int i=0;i<s.length();i++){
if(isalpha(s[i]))
    {
    if(islower(s[i]))
    alph=min(alph,i);
    }
     if (s[i]>='0'&&s[i]<='9'){

    dig=min(dig,i);
    }
     if(s[i]=='#'||s[i]=='&'||s[i]=='*')
    speci=min(speci,i);

     if(isalpha(s[n-i-1]))
    {
        if(islower(s[n-i-1]))
    alph=min(alph,i+1);
    }
     if (s[n-i-1]>='0'&&s[n-i-1]<='9'){

    dig=min(dig,i+1);
    }
     if(s[n-i-1]=='#'||s[n-i-1]=='&'||s[n-i-1]=='*')
    speci=min(speci,i+1);

}
dp[pos][0]=alph;
dp[pos][1]=dig;
dp[pos][2]=speci;
//cout<< dp[pos][0]<<" "<<dp[pos][1]<<" "<<dp[pos][2]<<endl;

return;

}
int type (char c){
if(isalpha(c))
    {
    if(islower(c))
        //cout<<c<< " is lower case "<<endl;
       return 1;
    }
if (c>='0'&&c<='9')
     return 2;
return 3;
}
bool verify(string s){
int speci=0;
int alph=0;
int dig=0;
for(int i=0;i<s.length();i++){

if(isalpha(s[i]))
    {
    if(islower(s[i]))
    alph++;
    }
    else if (s[i]>='0'&&s[i]<='9'){

    dig++;
    }
    else if(s[i]=='#'||s[i]=='&'||s[i]=='*')
    speci++;
}
return(speci>0&&dig>0&&alph>0);
}


int main()
{

   scanf("%d %d",&m,&n);
    tab.resize(m);
    for(int i=0;i<m;i++)
    {
    cin>>tab[i];
    isibizi(i);

    }
    int res=INT_MAX;
    string s="";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
            if(i!=j&&j!=k&&k!=i){
                res=min(res,dp[i][0]+dp[j][1]+dp[k][2]);
                res=min(res,dp[i][1]+dp[j][2]+dp[k][0]);
                res=min(res,dp[i][2]+dp[j][0]+dp[k][1]);
                }
            }
        }

    }

    printf("%d \n",res);
    return 0;
}
