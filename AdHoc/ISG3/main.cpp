#include <bits/stdc++.h>

using namespace std;

int main()
{
    int  n;
    cin>>n;
    while (n!=0){
        vector<string> tab;
        tab.resize(n);
        int cmp1=10000;
        for(int i=0;i<n;i++){
            cin>>tab[i];
            if(tab[i].length()<cmp1){
             //   cmp1=tab[i].length()-1;
            }
        }
       int cmp=0;
        bool equall=false;
        while((!equall)){
                int i=0;
            while((i<n-1)&&(!equall)){
                    int j=i+1;
                while((j<n)&&((!equall))){

                        if((tab[i].substr(cmp)==tab[j].substr(cmp)))   {
                            equall=true;
                            cmp--;

                    }
                    if((tab[i].substr(cmp).length()==1)||(tab[j].substr(cmp).length()==1))
                        {
                            equall=true;


                    }
                j++;}
            i++;}
             cmp++;
       }
        cout<<cmp-1<<endl;



    cin>>n;}
    return 0;
}
