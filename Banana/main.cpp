#include <bits/stdc++.h>

using namespace std;
string tab1[150];
string tab2[150];
int n;
string getstr(string s){
int i=0;
int found=-1;
while((i<n)&&(found==-1)){
    if(tab1[i]==s){
      found=i;
    }
    i++;
}
if(found!=-1){
    return tab2[found];
}
else{
    return " ";
}
}

int main()
{

   cin>>n;

   for(int i=0;i<n;i++){
    string s1,egal,s2;
    cin>>s1>>egal>>s2;

    tab1[i]=s1;
    tab2[i]=s2;

   }
   int t;
   cin>>t;
   while(t--){
        int k;
   cin>>k;
    for(int i=0;i<k;i++){
            string s1;
            cin>>s1;
        cout<<getstr(s1);
        if(i!=k-1){cout<<" ";}
    }
    cout<<endl;

   }

    return 0;
}
