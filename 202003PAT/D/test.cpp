#include<iostream>
#include<queue>

using namespace std;

class mycomparison
{
  bool reverse;
public:
    // mycomparison();
    //这里俩构造函数冲突了
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const//记得加const
  {//要重载括号运算符才行,map也是，写个类然后重载括号运算符
    // return lhs>rhs;
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main(){
    typedef priority_queue<int,vector<int>,mycomparison> my_pq;
    greater<int> g;
    my_pq pq;
    pq.push(10);
    pq.push(5);
    pq.push(100);
    pq.push(20);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}