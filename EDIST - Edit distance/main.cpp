// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];

int editDistDP(string str1, string str2 )
{
    if(str1.length()==0)
    return str2.length();

    if(str2.length()==0)
    return str1.length();
    int &r=dp[str1.length()][str2.length()];
    if(r!=-1)
    return r;
    if(str1[0]==str2[0])
        return dp[str1.length()][str2.length()]=editDistDP(str1.substr(1,str1.size()-1),str2.substr(1,str2.size()-1));

    int res1= 1+min(editDistDP(str1,str2.substr(1,str2.size()-1)),editDistDP(str1.substr(1,str1.size()-1),str2));///remove & insert
    int res2 =1+editDistDP(str1.substr(1,str1.size()-1),str2.substr(1,str2.size()-1));///repllace
    return dp[str1.length()][str2.length()]=min(res1,res2);
}

 int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    string str1,str2;
    cin>>str1>>str2;
    memset(dp,-1,sizeof dp);
    printf("%d\n",editDistDP( str1 , str2 ));
    }
    return 0;
}
