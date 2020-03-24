#include <bits/stdc++.h>

using namespace std;
vector<vector<int>  > combos;
vector<int> current;
int col[8];
bool i_can_place(int quene,int column){

for(int i=column-1;i>=0;i--){
    if(col[i]==quene)
    return false;
    if(abs(col[i]-quene)==abs(i-column))
    return false;
}
return true;
}
void generate_all(int pos ){
if(pos==8)
{
    vector<int> tmp;
    for(int i=0;i<8;i++){
   // cout<<col[i]<<" ";
    tmp.push_back(col[i]);
    }
    //cout<<endl;
    combos.push_back(tmp);
    return ;
}
for(int i=0;i<8;i++){
    if(i_can_place(i,pos)){
        col[pos]=i;
        generate_all(pos+1);
    }
}


}

int Find_best(vector<int> current){
int min_diif=INT_MAX;
for(int i=0;i<combos.size();i++){
    int res=0;
    for(int j=0;j<8;j++){
        if(combos[i][j]!=current[j]){
        res++;
        //cout<<" difference between  "<<combos[i][j]<<" and "<<current[j]<<endl;
        }
    }
    min_diif=min(min_diif,res);
}
return min_diif;

}
int main()
{

    generate_all(0);
    int cmp=0;
    int x;
    while(cin>>x){
    cmp++;
    current.clear();
    current.push_back(x-1);
    for(int i=1;i<8;i++){
        cin>>x;

        current.push_back(x-1);
    }
    cout<<"Case "<<cmp<<": "<<Find_best(current)<<endl;
    }
    return 0;
}
