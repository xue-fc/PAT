#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 10000;

int main(){
    double odds[3][3];
    double max,tmp;
    char games[3] = {'W','T','L'};
    double profit = 0.65;
    for(int i=0;i<3;i++){
        max = 0; 
        int index = 0;
        for(int j=0;j<3;j++)
        {
            cin >> tmp;
            if(tmp > max)
                max = tmp,index=j;
        }
        profit = profit*max;
        cout<<games[index]<<' ';
    }
    printf("%.2f",(profit-1)*2);

    return 0;
}

