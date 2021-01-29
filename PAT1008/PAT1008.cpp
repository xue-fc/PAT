#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 10000;

int main(){
    int n,tmp;
    int cur = 0;
    int time = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp >= cur)
        {
            time += (tmp-cur)*6;
        }
        else
        {
            time += (cur-tmp)*4;
        }
        cur = tmp;
    }
    time += n*5;

    cout<<time;

    return 0;
}

