#include<bits/stdc++.h>
using namespace std;
void add(int test[11],int tab[11][11],int n){
cout<<test[0]<<" "<<test[1]<<" "<<test[2]<<endl;
bool b=false;
for(int i=0;i<n;i++){
if(tab[i][0]!=-1){
        if(tab[i][0]>=test[0])
        {
        cout<<"here"<<endl;
        b=true;}
}
if((b==false)&&((tab[i][0])>0)){
    for(int j=0;j<n;j++){
    tab[i][j]=test[j];}
    }
}
}
int main()
{
//freopen("A-large.in","r",stdin);
//freopen("A-large.out","w",stdout);
int T;
cin>>T;
for(int i=0;i<T;i++){
int n;
cin>>n;
int res[n];
int tab[11][11];
//int vis[n]={0};
vector<vector<int> > mat;
mat.resize((2*n)-1);
cout<<(2*n)-1<<endl;
for(int j=0;j<(2*n)-1;j++){
for(int k=0;k<n;k++){
int x;
cin>>x;
mat[j].push_back(x);
}
}
sort(mat.begin(),mat.end());
for(int j=0;j<(2*n-1);j++){
int test[11];
for(int k=0;k<n;k++){
test[k]=mat[j][k];
//cout<<mat[j][k]<<" ";

}
//cout<<endl;
add(test,tab,n);

}
for(int j=0;j<n;j++){
for(int k=0;k<n;k++){
cout<<tab[j][k]<<" ";
}
cout<<endl;
}

cout<<"Case #"<<i+1<<": "<<endl;
}

return 0;
}
