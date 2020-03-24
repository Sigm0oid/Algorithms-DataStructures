#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bitset<30> rw,ld,rd;
int cmp=0;
    int t;

char board[16][16];
//bool place(int r,int c){
//for(int i=0;i<c;i++){
//    if((row[i]==r)||((abs(i-c)==abs(row[i]-r)))){
//        return false;
//    }
//}
//    return true;
//
//}
void backtrack(int c){
if((c==t)){
    //cout<<"solution"<<endl;
    cmp++;
}

for(int i=0;i<t;i++){
    if((board[c][i]!='*')&&(!rw[i])&&(!ld[i+c])&&(!rd[i-c+t-1])){
            ld[i+c]=true;
            rd[i-c+t-1]=true;
            rw[i]=true;
        backtrack(c+1);
        ld[i+c]=false;
            rd[i-c+t-1]=false;
            rw[i]=false;
    }
}

}

int main()
{
    rd=false;
    ld=false;
    rw=false;
    memset(board,'.',sizeof board);
    cin>>t;
for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
        cin>>board[i][j];
        }
}
backtrack(0);
cout<<cmp<<endl;
    return 0;
}
