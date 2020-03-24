#include <bits/stdc++.h>

using namespace std;

int main()
{

int n;
cin>>n;
int tab [n];
for(int i=0;i<n;i++)
{
    cin>>tab[i];
}
    string s;
 getline(cin,s);
bool ok=true;
    for(int i=0;i<n;i++){
        getline(cin,s);
        //cout<<s<<endl;
        int nbvoy=0;
        for(int j=0;j<s.length();j++)
        {
            if((s[j]=='a')||(s[j]=='e')||(s[j]=='i')||(s[j]=='o')||(s[j]=='u')||(s[j]=='y')){
                nbvoy++;
            }
        }
        if(nbvoy!=tab[i]){
            ok=false;
        }
    }
    if(ok){
        cout<<"YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
