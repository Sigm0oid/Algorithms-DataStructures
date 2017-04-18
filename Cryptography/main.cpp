#include <bits/stdc++.h>

using namespace std;

int main()
{
ofstream fout("output.txt");
ifstream fin ("input.txt");
int t;
fin>>t;
for(int i=0;i<t;i++){
    int n,m;
    fin>>n>>m;
    for(int j=0;j<n;j++){
    if(j!=0){fout<<" ";}
    string ch;
    fin>>ch;
    for(int k=0;k<ch.length();k++){
     if((ch[k])<91){
    ch[k]=ch[k]+32;
    //ch[k]=ch[k]+(m)%26;
    if((ch[k]+(m)%26)>122){
    ch[k]=96+(m%26-(122-ch[k]));}
    else{ch[k]=ch[k]+(m)%26;}
    }
    else{
    ch[k]=(ch[k]-32);
    ch[k]=ch[k]+(m)%26;
    if(ch[k]>90){
    ch[k]=64+(ch[k]-90);}
    }



    }
    fout<<ch;}



fout<<endl;}
    return 0;
}
