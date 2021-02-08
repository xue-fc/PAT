/*
    这是个错误思路，正确思路在隔壁
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int MAX = 1000;

int main(){
    int n;
    cin>>n;
    long long tmp;
    long long max=-1,min=1000000000;
    int max_pos,min_pos;
    vector<long long> l;
    vector<int> res1,res2,res;
    int head=0,rear=0;
    int num=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp>max)
        {
            max_pos = i;
            max = tmp;
        }
        if(tmp<min)
        {
            min = tmp;
            min_pos = i;
        }
        l.push_back(tmp);
    }
    if(min_pos==0)
    {
        // res1.push_back(min);
        // cout<<min;
        // num++;
        res.insert(res.begin()+(head++),min);
    }
    if(max_pos==n-1)
        // res2.push_back(max);   
        res.insert(res.end()-(rear++),max);
    if(max_pos <= min_pos)
    {
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    vector<long long>::iterator sit = l.begin()+min_pos+1;
    vector<long long>::iterator eit = l.begin()+max_pos;
    //两边都不包含
    vector<long long>::iterator st;
    vector<long long>::iterator et;
    long long lmax,rmin;
    lmax = *max_element(l.begin(),sit);
    rmin = *min_element(eit,l.end());
    while(sit!=eit){
        st = min_element(sit,eit);
        et = max_element(sit,eit);
        if(st==sit && *st>lmax && *st<rmin)
        {
            // res1.push_back(*st);
            res.insert(res.begin()+(head++),*st);
        }
        if(et!=st && et==eit-1 && *et<rmin && *et>lmax)
            // res2.push_back(*et);
            res.insert(res.end()-(rear++),*et);
        tmp = *max_element(sit,st);
        lmax = lmax>tmp ? lmax : tmp;
        tmp = *min_element(et,eit);
        rmin = rmin<tmp ? rmin : tmp;
        sit = st+1;
        eit = et;
        if(sit > eit)
            break;
    }

    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        if(i==0)
            cout<<res[i];
        else{
            cout<<' '<<res[i];
        }
    }
    cout<<endl;
    return 0;
}
