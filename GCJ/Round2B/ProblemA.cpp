#include<bits/stdc++.h>
using namespace std;
bool finished (string s){
bool b=true;
for (int k=0;k<s.length();k++){
if(s[k]!='0')
{b=false;}
}
return b;
}

void Find (string tab[],string s,vector<int>res,int b){
while(!finished(s)){
string test=s;
bool NumberFounded=false;
int cmpNum=0;
while(!NumberFounded){
        string num=tab[cmpNum];
        int i=0;
        bool found=true;
            while((found==true)&&(i<num.length())){
            char c=num[i];
            found=false;

                        for(int j=0;j<test.length();j++){
                        if((c==test[j])&&(found==false)){
                        test[j]='0';
                        found=true;
                        }
                        }
                        i++;
                    }

                cout<<tab[cmpNum]<<" "<<i<<" "<<test<<endl;

                if(i<=num.length()&&(found==true)){
                NumberFounded=true;
                cout<<tab[cmpNum]<<" match "<<endl;
             }
                else{
                cmpNum++;
                test=s;
                }


        }
        res.push_back(cmpNum);
        s=test;


}
sort(res.begin(),res.end());
cout<<"Case #"<<b+1<<": ";
for(int j=0;j<res.size();j++){
cout<<res[j];
}
cout<<endl;
}



int main()
{
string tab[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> res;
freopen("A-small-attempt.in","r",stdin);
freopen("A-small-attempt.out","w",stdout);
int T;
cin>>T;
cout<<T<<endl;
for(int i=0;i<T;i++){
string s;
cin>>s;
Find(tab,s,res,i);
}
return 0;

}
