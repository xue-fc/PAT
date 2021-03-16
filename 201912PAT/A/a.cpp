#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<string> t(7);
    vector<vector<string>> captials(26,t);
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            string tmp;
            cin>>tmp;
            captials[i][j] = tmp;
        }
    }
    char str[200];
    getchar();
    string in;
    do{
        cin.getline(str,200);
        in = string(str);
    } while(in.size()==0);
    vector<string> res(7);
    bool start = true;
    bool flag=true;
    int num=0;
    for(auto it=in.begin();it!=in.end();it++){
        if(*it>='A' && *it<='Z'){
            start = false;
            if(!flag)
                printf("\n");
            for(int i=0;i<7;i++){
                res[i] = res[i] + " " + captials[*it-'A'][i]; 
            }
            flag = true;
        }
        else{
            if(!flag)
                continue;
            if(!start)
                flag = false;
            if(res[0].size()==0)
                continue;
            if(num!=0)
                cout<<endl;
            for(int i=0;i<7;i++){
                res[i].erase(res[i].begin());
                if(i!=6)
                    printf("%s\n",res[i].c_str());
                else
                    printf("%s",res[i].c_str());
                res[i].clear();
            }
            num++;
        }
    }
    if(res[0].size()==0)
        return 0;
    if(num!=0)
        cout<<endl;
    for(int i=0;i<7;i++){
        res[i].erase(res[i].begin());
        if(i!=6)
            printf("%s\n",res[i].c_str());
        else
            printf("%s",res[i].c_str());
        res[i].clear();
    }
    // cout<<endl;
    return 0;
}