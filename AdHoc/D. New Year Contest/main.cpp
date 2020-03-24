#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
ll n,nb_prob=0,penality=0;
set<ii> prob;
void isibizi(ll time_left_to_mid){
//cout<<" time left "<<time_left_to_mid<<" problems left are"<<endl;
//for(auto i:prob)
//cout<<i<<" ";
//cout<<endl;

if(time_left_to_mid>0&&prob.size()>0){
    if(prob.begin()->first<time_left_to_mid){
    time_left_to_mid-=prob.begin()->first;
    prob.erase(prob.begin());
    }
    else{
    ii tmp=(*prob.begin());

    prob.erase(prob.begin());
    tmp.first-=(time_left_to_mid);
    prob.insert(tmp);
    time_left_to_mid=0;
    }
    isibizi(time_left_to_mid);
}
else{

    time_left_to_mid=360;

    while(time_left_to_mid>0&&prob.size()>0){
        if((*prob.begin()).first>time_left_to_mid){
            break;
        }
        else{

            time_left_to_mid-=prob.begin()->first;
            penality+=(360-time_left_to_mid);
            prob.erase(prob.begin());
        }
    }
}
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        prob.insert(ii(x,i));
    }

    isibizi(350);

    nb_prob=n-prob.size();
    cout<<nb_prob<<" "<<penality<<endl;
    return 0;
}
