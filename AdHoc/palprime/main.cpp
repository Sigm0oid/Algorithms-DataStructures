#include <bits/stdc++.h>

using namespace std;
long long bintodec(long long a){
long long res=0;
for(int j=0;j<((a/10)+1);j++){
    res+=pow(2,j);
    cout<<pow(2,j)<<endl;
}
return res;
}
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++){
    int x;
    cin>>x;
    cout<<bintodec(x)<<endl;

}   return 0;
}
