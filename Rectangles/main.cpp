#include <bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
int n;
cin>>n;
int maxx=-1,maxy=-1,minx=-1,miny=-1;
for(int j=0;j<n;j++){
for(int k=0;k<4;k++)
{
int x=-1,y=-1;
cin>>x>>y;
if((minx==-1||x<minx)){
minx=x;}
if((miny==-1||y<miny)){
miny=y;}
if((maxx==-1||x>maxx)){
maxx=x;}
if((maxy==-1||y>maxy)){
maxy=y;}
}}
int res=((maxx-minx)*(maxy-miny));
cout<<res<<endl;
}
  return 0;
}
