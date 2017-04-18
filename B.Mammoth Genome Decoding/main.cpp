#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tab[4]={0,0,0,0};
    string tab_char="ACGT";
    string s;
    int n;
    cin>>n;
    cin>>s;
     for(int  i=0;i<n;i++){
    char c;
    c=s[i];
    if(c=='A')
    tab[0]++;
    if(c=='C')
    tab[1]++;
    if(c=='G')
    tab[2]++;
    if(c=='T')
    tab[3]++;
    }
    for(int  i=0;i<n;i++){
    char c;
    c=s[i];
    if(c=='?'){
            int miin=1000,idx_miin=0;
            for(int j=0;j<4;j++)
                {
                if(tab[j]<miin){
                miin=tab[j];
                idx_miin=j;
                }
                }
                tab[idx_miin]++;
                s[i]=tab_char[idx_miin];
    }
    }
    bool ok=true;
    for(int i=0;i<3;i++){
    //cout<<tab[i]<<tab[i+1]<<endl;
    if(tab[i]!=tab[i+1])
    {
    ok=false;
    }
    }
    if(ok)
    cout<<s<<endl;
    else
    cout<<"==="<<endl;

    return 0;
}
