#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);



    int T;
    cin>>T;
    for(int i=0;i<T;i++){
            int kJP[3][3]={0};
            int kPS[3][3]={0};
            int kJS[3][3]={0};
            vector<int> res;

            int j,p,s,k;

    cin>>j>>p>>s>>k;
    int cmp=0;
    for(int a=0;a<j;a++){
            for(int l=0;l<p;l++){
                 for(int m=0;m<s;m++){
                    //cout<<a+1<<" "<<l+1<<" "<<m+1<<endl;
                    if((kJP[a][l]<k)&&(kPS[l][m]<k)&&(kJS[a][m]<k)){
                        kJP[a][l]++;
                        kPS[l][m]++;
                        kJS[a][m]++;
                        cmp++;
                        res.push_back((100*(a+1))+(10*(l+1))+m+1);
                    }
            }
            }
    }
    cout<<"Case #"<<i+1<<": "<<cmp<<endl;
    for(int b=0;b<res.size();b++){
        cout<<res[b]/100<<" ";
        cout<<(res[b]%100)/10<<" ";
        cout<<(res[b]%10);
        cout<<endl;


    }

    }

        return 0;
}
