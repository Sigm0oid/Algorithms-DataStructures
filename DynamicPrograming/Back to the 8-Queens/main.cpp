#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > all;
int pos[1][8];
bitset<30>ld,rd,rw;
int cmp=0;

void backtrack(int c,vector<int> v){
    if(c==8){
        all.push_back(v);
        cmp++;
    }
    for(int r=0;r<8;r++){
        if((!rw[r])&&(!ld[r+c])&&(!rd[r-c+8-1])){
            v[c]=(r);
            rw[r]=true;
            ld[r+c]=true;
            rd[r-c+8-1]=true;

            backtrack(c+1,v);
            rw[r]=false;
            ld[r+c]=false;
            rd[r-c+8-1]=false;
        }
    }

}
int main()
{
    int t=1;
    vector<int> v(8);
    backtrack(0,v);
    ld=false;
    rd=false;
    rw=false;
    //freopen("out.out","w",stdout);
    //freopen("in.in","r",stdin);
    string s;

    while((getline(cin,s))&&(s.length()>1)){
    int p=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
             pos[0][p]=s[i]-'1';
                p++;
        }

    }
    int diffmin=100;
    int diff=0;
     for(int i=0;i<92;i++){
       for(int j=0;j<8;j++){
       if(pos[0][j]!=all[i][j]){
        diff++;
       }
       }
       if(diff<diffmin){
        diffmin=diff;
       }
       diff=0;
    }
    cout<<"Case "<<t<<": "<<diffmin<<endl;
    t++;

    }
    return 0;
}
