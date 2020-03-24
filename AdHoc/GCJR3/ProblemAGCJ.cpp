#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
            cout<<"Case #"<<i+1<<": ";
            int nbr=0;
        int n;
        cin>>n;
            vector<int> t;
            t.resize(n);
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                t[j]=x;
                nbr+=x;
            }
            while(nbr>0){
            int maax=0;
            for(int k=0;k<n;k++){
            if(t[maax]<t[k]){
                maax=k;
            }
            }
            t[maax]--;
            nbr--;
            cout<<alpha[maax];
             maax=0;
            for(int k=0;k<n;k++){
            if(t[maax]<t[k]){
                maax=k;
            }
            }
            float ans = (float)t[maax] / (float)nbr;
            if(nbr>0){
            if(ans>0.5){
                t[maax]--;
                nbr--;
            cout<<alpha[maax];
            }
            }
            cout<<" ";
            }

cout<<endl;
    }

        return 0;
}
