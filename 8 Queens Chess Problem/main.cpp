#include <bits/stdc++.h>
using namespace std;
typedef pair< int,int > ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int row[8];
int nbrsolution=0;
int c=0;
int a,b;

bool place(int r,int c){
    for(int prev=0;prev<c;prev++){
        if((row[prev]==r)||abs(row[prev]-r)==abs(prev-c)){
            return false;
        }

    }
    return true;

}
void backtrack(int c){
    //cout<<c<<endl;
if((c==8)){
        //cout<<row[a]<<" "<<b<<endl;
        if(nbrsolution<9){cout<<" ";}
    cout<<++nbrsolution<<"     ";
    for(int i=0;i<8;i++){
        cout<<" "<<row[i]+1;
    }
    cout<<endl;
}
if(c==a){
    if(place(b,c)){
        row[c]=b;
        backtrack(c+1);
    }
}
else{
for(int r=0;r<8;r++){

    if(place(r,c)){
        row[c]=r;
        backtrack(c+1);
    }
}
}
}

int main()
{
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
cin>>b>>a;
a-=1;
b-=1;
memset(row,0,sizeof row);
nbrsolution=0;
cout<<"SOLN       COLUMN"<<endl;
cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
backtrack(0);

    if(i!=t-1){cout<<endl;}
    }
    return 0;
}
