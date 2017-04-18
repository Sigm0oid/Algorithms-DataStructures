#include<bits/stdc++.h>
using namespace std;
int convert (char a,char b){
int vala=0;
int valb=0;
if(a=='1'){vala=1;}
if(a=='2'){vala=2;}
if(a=='3'){vala=3;}
if(a=='4'){vala=4;}
if(a=='5'){vala=5;}
if(a=='6'){vala=6;}
if(a=='7'){vala=7;}
if(a=='8'){vala=8;}
if(a=='9'){vala=9;}



if(b=='1'){vala=1;}
if(b=='2'){vala=2;}
if(b=='3'){vala=3;}
if(b=='4'){vala=4;}
if(b=='5'){vala=5;}
if(b=='6'){vala=6;}
if(b=='7'){vala=7;}
if(b=='8'){vala=8;}
if(b=='9'){vala=9;}



if(a=='Q'||a=='K'||a=='J'){
vala=15;

}
if(a=='T'){
vala=10;

}
if(a=='A'){
vala=20;

}
if(b=='A'){
vala=20;

}
if(b=='Q'||b=='K'||b=='J'){
valb=15;

}
if(b=='T'){
valb=10;

}
if(a=='R'){
if(b=='R')
{vala=25;
valb=25;}
else{
vala=valb;}
}

if(b=='R'){

valb=vala;}

return (vala+valb);
}


 int kab (int i,int j,char t[1000],char t1[1000],int n){
if ((j>=n)||(i>=n)){
    return 0;
                    }
    if(t[i]==t1[j]){
    return ((convert(t[i],t1[j]))+kab(i+1,j+1,t,t1,n));}
     if(t[i]!=t1[j]){
     if((t[i]!='R')&&((t[i]!='R')))
   { return (max(kab(i+1,j,t,t1,n),(kab(i,j+1,t,t1,n))));}}
    else{
    int val1=(((convert(t[i],t1[j]))+kab(i+1,j+1,t,t1,n)));
    int val2 =max(kab(i+1,j,t,t1,n),(kab(i,j+1,t,t1,n)));
    return (max (val1,val2));}

}

int main()
{
int n;
cin>>n;
if(n!=0){
    char t[n];
   // t.resize(n);
    char t1[n];
   // t1.resize(n);
    for(int i=0;i<n;i++){
    cin>>t[i];}
    for(int i=0;i<n;i++){
    cin>>t1[i];}

    cout<<kab(0,0,t,t1,n)<<endl;


            }    return 0;
}
