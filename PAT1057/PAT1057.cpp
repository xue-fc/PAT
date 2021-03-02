/*
    排序而已，比较简单，注意调整两个vector的长度即可
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;

const int MAX = 1000;
// set<int> sorted;
vector<int> s;
vector<int> v;
int main(){
    int n;
    scanf("%d",&n);
    char str[MAX];
    string cmd;
    vector<int> tosort;
    for(int i=0;i<n;i++){
        scanf("%s",str);
        // cmd = string(str);
        if(str[1]=='o'){
            if(s.size()==0){
                printf("Invalid\n");
            }
            else{
                printf("%d\n",*(s.end()-1));
                s.pop_back();
            }
            continue;
        }
        if(str[1]=='u'){
            int tmp;
            scanf("%d",&tmp);
            // printf("%d\n",tmp);
            s.push_back(tmp);
            continue;
        }
        if(str[1]=='e'){
            if(s.size()==0){
                printf("Invalid\n");
            }
            else{
                tosort = vector<int>(s);
                partial_sort(tosort.begin(),tosort.begin()+(tosort.size()+1)/2,tosort.end());
                printf("%d\n",tosort[(tosort.size()+1)/2-1]);
            }
        }
    }


    return 0;
}
