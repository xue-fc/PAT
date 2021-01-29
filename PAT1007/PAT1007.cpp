#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 10000;

int main(){
    int n;
    int tmp,gsum=0,rsum=0;
    cin >> n;
    vector<int> l;
    for(int i=0;i<n;i++){
        cin >> tmp;
        l.push_back(tmp);
    }
    int index=0,start=0;
    int pos[2] = {0};
    for(vector<int>::iterator it = l.begin();it!=l.end();it++,index++){
        int nsum = rsum + *it;
        if(nsum <= 0){
            rsum = 0;
            start = index + 1;
        }
        else
        {
            rsum = nsum;
            if(gsum < nsum)
            {    
                gsum = nsum;
                pos[0] = start;// + (start==0 ? 0 : 1);
                pos[1] = index;
            }
        }
    }
    if(gsum==0)
        cout<<gsum<<' '<<l[0]<<' '<<l[n-1]<<endl;
    else
        cout<<gsum<<' '<<l[pos[0]]<<' '<<l[pos[1]]<<endl;
    return 0;
}

