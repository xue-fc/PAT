#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 10000;

void print_time(int t,int need);

int main(){
    int N,M,K,Q,i;
    int tmp;
    cin>>N>>M>>K>>Q;
    queue<int> q;
    vector<queue<int>> window(N,q);
    vector<int> need_time;
    vector<int> f_time(K);
    vector<int> w_time(N,0);
    vector<int>::iterator it;
    for(i=0;i<N*M && i<K;i++){
        cin>>tmp;
        need_time.push_back(tmp);
        if(i<N)
        {
            w_time[i] += tmp;
        }
        window[i%N].push(i);
    }

    for(;i<K;i++){
        cin>>tmp;
        need_time.push_back(tmp);
        it = min_element(w_time.begin(),w_time.end());
        int pos = it - w_time.begin();

        f_time[window[pos].front()] = w_time[pos];
        window[pos].pop();
        window[pos].push(i);
        w_time[pos] += need_time[window[pos].front()];
    }

    for(int pos = 0;pos<N;pos++){
        while(!window[pos].empty()){
            f_time[window[pos].front()] = w_time[pos];
            window[pos].pop();
            if(!window[pos].empty())
                w_time[pos] += need_time[window[pos].front()];
        }
    }
    getchar();

    for(int j=0;j<Q;j++){
        cin>>tmp;
        print_time(f_time[tmp-1],need_time[tmp-1]);
    }

    return 0;
}

void print_time(int t,int need){
    if(t - need >= 540)
    {    
        cout<<"Sorry"<<endl;
        return;
    }
    int HH = 8 + t/60;
    if(HH<10)
    {
        cout<<'0'<<HH<<':';
    }
    else 
        cout<<HH<<':';
    if(t%60 < 10)
        cout<<'0'<<t%60<<endl;
    else
        cout<<t%60<<endl;
}

