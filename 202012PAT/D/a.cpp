#include<iostream>
#include<vector>
using namespace std;

bool in[110];
char str[10000];
vector<int> need;
struct equ{
    vector<int> fyw;
    int out;

    bool operator<(const equ &b) const{
        for(int i=0;i<this->fyw.size() && i<b.fyw.size();i++){
            if(this->fyw[i] < b.fyw[i])
                return true;
            else if(this->fyw[i] > b.fyw[i])
                return false;
        }
    }

    bool operator==(const equ &b) const{
        for(int i=0;i<this->fyw.size() && i<b.fyw.size();i++){
            if(this->fyw[i] != b.fyw[i])
                return false;
        }
        return true;
    }
};
vector<int> path;
vector<vector<int>> paths;
vector<equ> equs;
void printequ(equ e);
void dfs(int s){
    for(auto it=equs.begin();it!=equs.end();it++){
        if(it->out == need[s]){
            bool flag=false;
            for(auto lit=it->fyw.begin();lit!=it->fyw.end();lit++){
                if(!in[*lit])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                continue;
            else{
                for(auto lit=it->fyw.begin();lit!=it->fyw.end();lit++)
                    in[*lit]=false;
            }
            path.push_back(it-equs.begin());
            if(s==need.size()-1){
                paths.push_back(path);
            }
            else{
                dfs(s+1);
            }
            path.pop_back();
            for(auto lit=it->fyw.begin();lit!=it->fyw.end();lit++)
                    in[*lit]=true;
        }
    }
}
int main(){
    fill(in,in+110,false);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        in[tmp] = true;
        equ etmp;
        etmp.fyw.push_back(tmp);
        etmp.out=tmp;
        equs.push_back(etmp);
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        need.push_back(tmp);
    }
    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        bool flag=true;
        equ tmp;
        tmp.fyw = vector<int>();
        while(1){
            scanf("%s",str);
            if(flag)
            {
                if(str[0]>= '0' && str[0]<='9'){
                    tmp.fyw.push_back(atoi(str));
                }
                else if(str[0]=='+'){
                    continue;
                }
                else if(str[0]=='-'){
                    flag = false;
                }
            }
            else{
                tmp.out = atoi(str);
                break;
            }
        }
        equs.push_back(tmp);
    }

    dfs(0);
    vector<int> res=paths[0];
    for(auto it=paths.begin();it!=paths.end();it++){
        int i=0;
        for(auto lit=(*it).begin();lit!=(*it).end();lit++,i++){
            if(*lit==res[i])
                continue;
            else{
                if(equs[*lit] < equs[res[i]]){
                    res = *it;
                    break;
                }
            }
        }
        // printf("\n");
    }
    for(auto lit=res.begin();lit!=res.end();lit++){
        printequ(equs[*lit]);
    }
    // printf("\n");
    return 0;
}

void printequ(equ e){
    printf("%02d",e.fyw[0]);
    for(auto it=e.fyw.begin()+1;it!=e.fyw.end();it++){
        printf(" + %02d",*it);
    }
    printf(" -> %02d\n",e.out);
}