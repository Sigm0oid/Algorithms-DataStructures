#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main()
{
    int tab[4][11];
    memset(tab,0,sizeof tab);
    int k;
    cin>>k;
    for(int i=0;i<11&&k>0;i++){
    for(int j=0;j<4&&k>0;j++){

        if(j==2&&i!=0)
        continue;
        //cout<<" i "<<i<<" j "<<j<<endl;
        tab[j][i]=1;
        k--;

    }

    }
    cout<<"+------------------------+"<<endl;
    for(int i=0;i<4;i++){
        cout<<"|";
        for(int j=0;j<11;j++){
            if(i==2&&j>0)
            {
                cout<<"..";
                continue;
            }
            if(tab[i][j]==0)
            cout<<"#.";
            else
            cout<<"O.";


        }
        if(i==0)
        cout<<"|D|)";
        if(i==3)
        cout<<"|.|)";
        if(i==1)
        cout<<"|.|";
        if(i==2)
        cout<<"..|";
        cout<<endl;

    }
    cout<<"+------------------------+"<<endl;

    return 0;
}
