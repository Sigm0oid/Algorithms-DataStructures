#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       string s;
      cin>>s;
      bool found=false;
      int j=0;
      while(!found&&j<s.length())
      {
          char minn=s[j];
          for(int k=i+1;k<s.length();k++){
            if(s[k]<s[j]){
                minn=s[k];
            }
          }
          if(minn!=s[j]){
            found=true;
          }
          else{j++;}

      }
      char mx=s[j];
      for(int a=0;a<s.length();a++){
        if(s[a]==mx){
            cout<<s[j];
        }
        else  if(s[a]==s[j])
            {

                cout<<mx;
            }
            else{
                cout<<s[a];
            }
        }
        cout<<endl;
      }

    return 0;
}
