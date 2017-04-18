#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("out.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int k;
    bool flag=false;

    while((cin>>k)&&(k>0)){
            if(flag){cout<<endl;}
            if(!flag)flag=true;
//cout<<k<<endl;
    int tab[k];
    for(int i=0;i<k;i++){
        cin>>tab[i];
    }
    for(int a = 0; a< k - 5;a++)
            for(int b = a + 1; b < k - 4;b++)
                for(int  c = b +  1 ; c < k -  3; c++)
                    for(int d = c+1; d< k-2; d++)
                        for(int e = d+1 ; e< k-1; e++)
                            for(int  f= e+1 ; f< k; f++)
                                cout<<tab[a]<<" "<<tab[b]<<" "<<tab[c]<<" "<<tab[d]<<" "<<tab[e]<<" "<<tab[f]<<endl;



    }

    return 0;
}
