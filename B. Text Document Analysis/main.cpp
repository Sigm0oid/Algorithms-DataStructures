#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int nbinside=0,outside=0;
    bool iminside=false;
    int cmp=0;
    for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cmp>0){
                 outside=max(outside,cmp);
                cmp=0;
                }
                iminside=true;
               }
            else if(s[i]==')'){
                iminside=false;
                if(cmp>0){
                     nbinside++;
                }
                cmp=0;
               }
               else if(s[i]=='_'){

                if(iminside&&cmp>0){
                    nbinside++;

                }
                if(!iminside&&cmp>0){
                    outside=max(outside,cmp);
                }
                cmp=0;

               }
               else{
                cmp++;
               }

    }
    if(iminside&&cmp>0){
        nbinside++;
    }
    if(!iminside&&cmp>0){
        outside=max(outside,cmp);
    }
    cout<<outside<<" "<<nbinside<<endl;
    return 0;
}
