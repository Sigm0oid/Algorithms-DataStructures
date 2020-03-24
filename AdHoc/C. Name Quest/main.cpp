#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string name,s;
int main()
{
    cin>>name>>s;
    string first,last;

    int i=0;
    int j=s.length();
    int cmp_mot1=0;
    int cmp_mot2=name.length()-1;

    while(i<j&&!(first==name&&last==name)){
    //cout<<i<<" "<<j<<endl;
    if(s[i]==name[cmp_mot1])
    first+=s[i],cmp_mot1++;
    if(s[j]==name[cmp_mot2])
    last=s[j]+last,cmp_mot2--;;
    if(last!=name)
    j--;
    if(first!=name)
    i++;
    if(first==name&&last==name)
    break;
    }
    //cout<<" first "<<first <<" last "<<last<<endl;
    cout<<max(0,j-i)<<endl;


    return 0;
}
