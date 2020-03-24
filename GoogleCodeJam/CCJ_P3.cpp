#include<bits/stdc++.h>
using namespace std;
unsigned long long tobase(string s,int base){
 unsigned long long  res=0;
 unsigned long long p=1;
for(int j=s.length()-1;j>=0;j--){
//cout<<s[j]<<" "<<p<<" ";
if(s[j]!='0'){
res+=p;}
p*=base;
}
return res;
}
 unsigned long long isprime( unsigned long long d){
unsigned long long b=-1;
for(int i=2;i<=sqrt(d);i++){
if((b==-1)&&(d%i==0)){
b=i;}
}
return b;}


string tobin( long long x){
string s="";
while(x>0){
int a=x%2;
stringstream ss;
ss << a;
s=ss.str()+s;
x=x/2;
}
return s;
}

int main()
{
//freopen("C-C-small-attempt1","r",stdin);
//freopen("C-C-small-attempt1.out","w",stdout);
int T;
cin>>T;
for(int i=0;i<T;i++){
int j,n;
cout<<"Case #1:"<<endl;
cin>>n>>j;
string s="1";
while(s.length()<n-1){
s=s+'0';
}
s+='1';
 unsigned long long nbr=tobase(s,2);
//cout<<nbr<<endl;
do{
cout<<s<<endl;
//cout<<tobase(s,2)<<" "<<tobase(s,3)<<" "<<tobase(s,4)<<" "<<tobase(s,5)<<" "<<tobase(s,6)<<" "<<tobase(s,7)<<" "<<tobase(s,8)<<" "<<tobase(s,9)<<" "<<tobase(s,10)<<" "<<endl;

// unsigned long long inbase2=isprime(tobase(s,2));
//if(inbase2!=-1){cout<<"ok"<<endl;}
   /* long long inbase3=isprime(tobase(s,3));
        if(inbase3!=-1){
        long long inbase4=isprime(tobase(s,4));
                if(inbase4!=-1){
            long long inbase5=isprime(tobase(s,5));
                    if(inbase5!=-1){
                    long long inbase6=isprime(tobase(s,6));
                        if(inbase6!=-1){
                            long long inbase7=isprime(tobase(s,7));
                                if(inbase7!=-1){
                                    long long inbase8=isprime(tobase(s,8));
                                    if(inbase8!=-1){
                                    long long inbase9=isprime(tobase(s,9));
                                        if(inbase9!=-1){
                                            long long inbase10=isprime(tobase(s,10));
                                                if(inbase10!=-1){
                                                                    cout<<"ok"<<endl;
                                                                    j--;

        }

        }

        }

        }

        }

        }

            }
        }
}*/
//unsigned long long inbase3=isprime(tobase(s,3));
 //unsigned long long inbase4=isprime(tobase(s,4));
 //unsigned long long inbase5=isprime(tobase(s,5));
 //unsigned long long inbase6=isprime(tobase(s,6));
 //unsigned long long inbase7=isprime(tobase(s,7));
 //unsigned long long inbase8=isprime(tobase(s,8));
 //unsigned long long inbase9=isprime(tobase(s,9));
 //unsigned long long inbase10=isprime(tobase(s,10));
//if((inbase2!=-1)&&(inbase3!=-1)&&(inbase4!=-1)&&(inbase5!=-1)&&(inbase6!=-1)&&(inbase7!=-1)&&(inbase8!=-1)&&(inbase9!=-1)&&(inbase10!=-1)){
//cout<<s<<" "<<inbase2<<" "<<inbase3<<" "<<inbase4<<" "<<inbase5<<" "<<inbase6<<" "<<inbase7<<" "<<inbase8<<" "<<inbase9<<" "<<inbase10<<endl;
//j--;
//}
nbr+=2;
s=tobin(nbr);
}while((s.length()==n)&&(j>0));

//int base=2;
//bool b=true;
//vector<long long>v;
//while((b==true)&&(b<=10)){
//long long b2=tobase(s,base);
//if(isprime(b2)!=-1){
//b=false;}
//else{
//v.push_back(isprime(b2))}
//base++;
//}




//}


}
return 0;}

