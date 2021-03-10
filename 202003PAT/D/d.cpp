#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
    int N,M,last;
    cin>>N>>M;
    vector<int> memory;
    int cnt=0;
    for(int i=0;i<M && cnt<N;i++,cnt++){
        int tmp;
        scanf("%d",&tmp);
        memory.push_back(tmp);
    }
    // sort(memory.begin(),memory.end());
    int l=M;
    string res;
    while(cnt<N){
        res="";
        l=M;
        last=-(1<<30);
        while(cnt<N){
            auto min_pos = min_element(memory.begin()+M-l,memory.end());  
            if(*min_pos<last)
            {
                if(l==1)
                    break;
                int a=*min_pos;
                *min_pos = *(memory.begin()+M-l);
                *(memory.begin()+M-l) = a;
                l--;
                min_pos = min_element(memory.begin()+M-l,memory.end());  
            }
            int tmp;
            scanf("%d",&tmp);
            cnt++;
            res = res + to_string(*min_pos) + " ";
            last = *min_pos;
            memory.erase(min_pos);
            memory.push_back(tmp);
        }
        if(l==1){
            res.erase(res.end()-1);
            printf("%s\n",res.c_str());
        }
    }
    auto min_pos = min_element(memory.begin()+M-l,memory.end());  
    if(*min_pos<last)
    {
        int a=*min_pos;
        *min_pos = *(memory.begin()+M-l);
        *(memory.begin()+M-l) = a;
        l--;
    }
    sort(memory.begin()+M-l,memory.end());
    for(int i=M-l;i<M;i++){
        res = res+to_string(memory[i])+" ";
    }
    res.erase(res.end()-1);
    cout<<res<<endl;
    memory.erase(memory.begin()+M-l,memory.end());
    res.clear();
    if(!memory.empty())
    {
        sort(memory.begin(),memory.end());
        for(int i=0;i<memory.size();i++){
            res = res+to_string(memory[i])+" ";
        }
        res.erase(res.end()-1);
        cout<<res<<endl;
    }
    return 0;
}