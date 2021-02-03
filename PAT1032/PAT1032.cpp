/*
    cin读到string里是以空格为界限的
    想直接读一行到string里可以用getline(cin,t,'\n')，或者getline(cin,t)
    注意与cin.getline(str,MAX)的区别
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

struct node{
    string s;
    string next;
};
map<string,node> m;
int main(){
    string s1,s2;
    int n;
    cin>>s1>>s2>>n;
    getchar();
    string ts,tmp,next;
    for(int i=0;i<n;i++){
        cin>>tmp;
        cin>>ts;
        cin>>next;
        node a;
        a.next = next;
        a.s = ts;
        m[tmp] = a;
    }
    string a = s1;
    int l1=0,l2=0;
    while(a.compare("-1")!=0){
        a = m[a].next;
        l1++;
    }
    a = s2;
    while(a.compare("-1")!=0){
        a = m[a].next;
        l2++;
    }

    for(int i=0;i<l1-l2;i++){
        s1 = m[s1].next;        
    }
    for(int i=0;i<l2-l1;i++){
        s2 = m[s2].next;        
    }
    
    // string str1=m[s1].s;
    // string str2=m[s2].s;
    while(s1 != s2){
        s1 = m[s1].next;
        s2 = m[s2].next;
        // str1=m[s1].s;
        // str2=m[s2].s;
    }

    cout<<s1<<endl;



    return 0;
}
