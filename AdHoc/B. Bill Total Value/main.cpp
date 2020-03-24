#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
double transformmoney(string s){
double res=0;
stringstream ss;
    ss.str(s);
    string token;
    vector<string> v;
    while(getline(ss,token,'.')){
    v.push_back(token);
    }
    if(v.size()<2){

    res=(atoi(v[0].c_str()));
    }
    else{
    //cout<<v[0]<<" "<<v[1]<<endl;
    if(v[v.size()-1].size()==3){
    for(int i=0;i<v.size();i++){
     res+=(atoi(v[i].c_str())*pow(10,(v.size()-i-1)*3));
     //cout<<pow(10,(v.size()-i-1)*3)<<endl;
     }

    }
    else{
    res+=((atof(v[v.size()-1].c_str()))/100);

     for(int i=0;i<v.size()-1;i++){
        res+=(atoi(v[i].c_str())*pow(10,(v.size()-i-2)*3));

    }
    }
    }

return res;}
void affiche(string s){


stringstream ss;
    ss.str(s);
    string token;
    vector<string> v;
    while(getline(ss,token,'.')){
    v.push_back(token);
    }

    //cout<<v.size()<<endl;
    for(int i=0;i<v[0].size();i++){

    cout<<v[0][i];
    if((v[0].length()-i-1)%3==0)
    if(i!=v[0].length()-1)
    cout<<'.';

 }
 if(v.size()>1) {
if(v[1].length()==1){
cout<<'.'<<v[1]<<'0';}
else{
 cout<<'.'<<v[1];}
 }
 cout<<endl;


}
int main()
{
    string s;
    getline(cin,s);
    //cout<<s.length()<<endl;
    double res=0;
    int i=0;
    while(i<s.length()){
    if(!(s[i]>='a'&&s[i]<='z')){
    //cout<<"cc"<<i<<endl;
    string s1="";
    int j=i;
    while(!(s[j]>='a'&&s[j]<='z')&&j<s.length()){
    s1+=s[j];
    j++;
    }
    //cout<<s1<<endl;
    i=j;
    res+=transformmoney(s1);
    }
    else{
    i++;}
    }
    stringstream ss;

    ss << setprecision(11)<<res;
    string str = ss.str();

   affiche(str);
   cout<<endl;
    return 0;
}
