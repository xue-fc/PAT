#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

const int MAX = 10000;

int main(){
    char str[MAX];
    cin.getline(str,MAX);
    long long sum=0;
    for(int i=0;i<MAX;i++){
        if(str[i]=='\000')
            break;
        else
            {
                sum += str[i] - '0';        
            }
    }
    
    stack<int> s;
    while(sum!=0){
        s.push(sum%10);
        sum = sum / 10;
    }

    while(!s.empty()){
        switch (s.top())
        {
        case 0:
            cout<<"zero";
            break;
        case 1:
            cout<<"one";
            break;
        case 2:
            cout<<"two";
            break;
        case 3:
            cout<<"three";
            break;
        case 4:
            cout<<"four";
            break;
        case 5:
            cout<<"five";
            break;
        case 6:
            cout<<"six";
            break;
        case 7:
            cout<<"seven";
            break;
        case 8:
            cout<<"eight";
            break;
        case 9:
            cout<<"nine";
            break;
        }
        s.pop();
        if(!s.empty())
            cout<<' ';
    }
    return 0;
}

