#include<iostream>
#include<cstring>
#include<string>
#include<math.h>

using namespace std;

const int MAX = 10000;

int to10(string num,int radix);

int main(){
    char str[MAX];
    cin.getline(str,MAX);
    char *token;
    token = strtok(str," ");
    string num1 = string(token);
    token = strtok(NULL," ");
    string num2 = string(token);
    token = strtok(NULL," ");
    int tag = atoi(token);
    token = strtok(NULL," ");
    int radix = atoi(token);
    // cout<<(tag==1 ? to10(num1,radix) : to10(num2,radix))<<endl;
    
    int a = (tag==1 ? to10(num1,radix) : to10(num2,radix));
    string b = string((tag==1 ? num2 : num1));

    for(int i=1;i<100;i++){
        if(a==to10(b,i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}

int to10(string num,int radix){
    int sum = 0;
    for(int i=0;i<num.length();i++){
        if(num[i]>='0' && num[i]<='9')
        {
            if(num[i]-'0'>=radix) return -1;
            sum += (num[i] - '0')*pow(radix,num.length()-i-1);
        }
        else if(num[i]>='a' && num[i]<='z')
        {
            if(num[i]-'a'>=radix) return -1;  
            sum += (num[i] - 'a' + 10) * pow(radix,num.length()-i-1); 
        }
    }
    return sum;
}