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

int main(){
    string a,b;
    int N;
    cin>>N>>a>>b;
    
    return 0;
}
