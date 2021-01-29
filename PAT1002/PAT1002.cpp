/*
string.h里的strtok_r是strtok的线程安全版本，需要三个参数
保留小数的头文件和函数要记住
*/
#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<iomanip>

using namespace std;

const int MAXSIZE = 1000;

int main(){
    char str1[MAXSIZE],str2[MAXSIZE];
    char *token1,*token2,*savepter1,*savepter2;
    cin.getline(str1,MAXSIZE);
    cin.getline(str2,MAXSIZE);
    
    double e[100]={-1},c[100]={0};
    int i=0;
    token1 = strtok_r(str1," ",&savepter1);
    token1 = strtok_r(NULL," ",&savepter1);
    token2 = strtok_r(str2," ",&savepter2);
    token2 = strtok_r(NULL," ",&savepter2);
    while(token1 != NULL && token2 != NULL){
        if(atof(token1)==atof(token2)){
            e[i] = atof(token1);
            token1 = strtok_r(NULL," ",&savepter1);
            token2 = strtok_r(NULL," ",&savepter2);
            c[i] = atof(token1) + atof(token2);
            token1 = strtok_r(NULL," ",&savepter1);
            token2 = strtok_r(NULL," ",&savepter2);
            if(c[i]==0)
                continue;
        }
        else{
            if(atof(token1)>atof(token2))
            {
                e[i] = atof(token1);
                token1 = strtok_r(NULL," ",&savepter1);
                c[i] = atof(token1);
                token1 = strtok_r(NULL," ",&savepter1);
            }
            else
            {
                e[i] = atof(token2);
                token2 = strtok_r(NULL," ",&savepter2);
                c[i] = atof(token2);
                token2 = strtok_r(NULL," ",&savepter2);
            }
        }
        i++;
    }
    while(token1 != NULL){
        e[i] = atof(token1);
        token1 = strtok_r(NULL," ",&savepter1);
        c[i] = atof(token1);
        token1 = strtok_r(NULL," ",&savepter1);
        i++;
    }
    while(token2 != NULL){
        e[i] = atof(token2);
        token2 = strtok_r(NULL," ",&savepter2);
        c[i] = atof(token2);
        token2 = strtok_r(NULL," ",&savepter2);
        i++;
    }
    cout<<i;
    for(int j=0;j<i;j++){
        cout<<' '<<setiosflags(ios::fixed)<<setprecision(0)<<e[j]<<' ';
        cout<<setiosflags(ios::fixed)<<setprecision(1)<<c[j];
    }
    return 0;
}