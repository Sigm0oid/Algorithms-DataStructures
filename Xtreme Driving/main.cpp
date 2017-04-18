#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef  vector<ii> vii;
typedef  vector<int> vi;
char tab1[1010];
char tab2[1010];
int n;
int conv(char ch,char ch1){
if(ch==ch1){
if(ch=='A')
return 40;
if(ch=='T'||ch=='K'||ch=='Q'||ch=='R')
return 30;
return (2*(ch-'0'));
}
else{
char notjoke,joke;
if(ch!='J')
{notjoke=ch;joke=ch1;}
else
{notjoke=ch1;joke=ch;}

if(notjoke==joke)
{return 50;}
else{
if(notjoke=='A')
return 40;
if(notjoke=='T'||notjoke=='K'||notjoke=='Q'||notjoke=='R')
return 30;
return (2*(notjoke-'0'));
}

}
}

int fuck(int pos_tab1,int pos_tab2){
if(pos_tab1==n||pos_tab2==n)
return 0;
int res=0;
for(int i=pos_tab2;i<n;i++){
if(tab2[i]==tab1[pos_tab1]||tab2[i]=='J'||tab1[pos_tab1]=='J'){
char tmp=tab2[i];
res=max(res,conv(tab2[i],tab2[pos_tab1])+fuck(pos_tab1+1,i+1));
}
}
if(res==0)
res=fuck(pos_tab1+1,pos_tab2);

return res;
}

int main()
{
    while(cin>>n&&n>0){
    for(int i=0;i<n;i++){
    cin>>tab1[i];
    }
    for(int i=0;i<n;i++){
    cin>>tab2[i];
    }
    cout<<fuck(0,0)<<endl;





    }

    return 0;
}
