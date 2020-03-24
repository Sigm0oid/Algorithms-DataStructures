#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(cin>>n){
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
    bool is_stack=true;
    bool is_queue=true;
    bool is_pq=true;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
        s.push(b);
        q.push(b);
        pq.push(b);
        }
        else{
            if(q.empty())
            {
            is_pq=false;
            is_queue=false;
            is_stack=false;
            //break;
            }
            else{
            int x=s.top();
            if(x!=b)
            is_stack=false;
             x=q.front();
            if(x!=b)
            is_queue=false;
             x=pq.top();
            if(x!=b)
            is_pq=false;
            s.pop();
            q.pop();
            pq.pop();
        }
        }
    }

    if((is_queue+is_stack+is_pq)>1){
        cout<<"not sure"<<endl;

    }
    else if((is_queue+is_stack+is_pq)==0){
        cout<<"impossible"<<endl;
    }
    else if(is_queue){
    cout<<"queue"<<endl;
    }
    else if(is_stack){
    cout<<"stack"<<endl;
    }
    else if(is_pq){
    cout<<"priority queue"<<endl;
    }

    }
    return 0;
}
