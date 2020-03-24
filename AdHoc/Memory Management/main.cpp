#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<ii> queuee,stackk;

int existqueue(int i){
int e=-1;
int j=0;
while(j<queuee.size()){
if(i==queuee[j].second)
{
    e=j;  break;
    }
    j++;
    }
    return e;
    }

int existstack(int i){
int e=-1;
int j=0;
while(j<stackk.size()){
if(i==stackk[j].second)
{ e=j;  break;}
j++;
}
return e;
}



int main()
{
    int t;cin>>t;
    while(t--){
    stackk.clear();
    queuee.clear();
    int p,s,n;
    cin>>p>>s>>n;

    vector<int> pages;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pages.push_back(floor(x/s));
        //cout<<(x/s)<<endl;
    }
    int res1=0,res2=0,indxqueue=0,indxstack=0;
    for(int i=0;i<n;i++){
   //cout<<existqueue(pages[i])<<" "<<pages[i]<<endl;
    if(existqueue(pages[i])==-1){
        if(indxqueue>=p){
        res1++;
        queuee.erase(queuee.begin());
        queuee.push_back(ii(i,pages[i]));
        }
        else{
        queuee.push_back(ii(i,pages[i]));
        indxqueue++;
        }

        }


        if(indxstack>=p){
        //cout<<existstack(pages[i])<<" "<<pages[i]<<endl;
            if(existstack(pages[i])==-1) {
            res2++;
            stackk.erase(stackk.begin());
            }
            else
            {
                stackk.erase(stackk.begin()+existstack(pages[i]));
             }
        stackk.push_back(ii(i,pages[i]));
        }
         else{
         //cout<<indxstack<<" "<<pages[i]<<endl;
        if(existstack(pages[i])==-1) {
            indxstack++;
                        }
            else
            {
                 stackk.erase(stackk.begin()+existstack(pages[i]));
             }
        stackk.push_back(ii(i,pages[i]));

        }

        }
    if(res1<=res2){cout<<"no ";}
    else cout<<"yes ";
    cout<<res1<<" "<<res2<<endl;
    }



    return 0;
}
