/*
    这个题很巧妙，如果用插入排序的方法，复杂度就是O(N^2)了，最后一个点会超时
    而利用cmp函数来排序，调用sort库函数则可以用O(NlogN)的算法来运行，就不会超时
    另外这题要注意到字符串的排序是局部的，只要知道相邻字符串间的关系即可，不需要全加起来
    此外还要意识到本质是排序
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

bool cmp(string a,string b){
    return (a+b < b+a);
}

int main(){
    int n;
    cin>>n;
    string segment;
    vector<string> res;
    for(int i=0;i<n;i++){
        cin>>segment;
        // res.push_back(segment);
        long long min=-1;
        int pos=0;
        int j;
        vector<string>::iterator it;
        for(it=res.begin();it!=res.end();it++){
            if(segment+*it < *it+segment)
                break;
        }
        res.insert(it,segment);
    }// sort(res.begin(),res.end(),cmp);
    string t="";
    for(vector<string>::iterator it=res.begin();it!=res.end();it++){
        t+=*it;
    }
    int a=0;
    string::iterator sit=t.begin();
    for(;sit!=t.end();sit++){
        if(*sit != '0')
            break;
    }
    t = string(sit,t.end());
    if(t.size()==0)
        cout<<"0"<<endl;
    else 
        cout<<t<<endl;
    return 0;
}
