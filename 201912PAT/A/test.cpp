#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <cctype>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

vector<vector<string> > letter(26);
void prt(char c,int cnt){
    cout<<letter[c-'A'][cnt];
}

int main()
{
//    freopen("1.txt","r",stdin);
    string strcin;
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            cin>>strcin;
            letter[i].push_back(strcin);
        }
    }
    string temp;
    char str[10000],c;
    int num=0;
    while((c=getchar())!=EOF){
        str[num++]=c;
    }

//    cin>>str;

    vector<string> lts;

    for(int i=0;i<strlen(str);i++){
        if(!isalpha(str[i])||(isalpha(str[i])&&str[i]-'a'<26&&str[i]-'a'>=0)){
           if(temp.size()!=0){
                lts.push_back(temp);
                temp.clear();
           }
        }else{
           temp.push_back(str[i]);
        }
    }
    if(temp.size()!=0){
        lts.push_back(temp);
        temp.clear();
    }

//    for(int i=0;i<lts.size();i++){
//        cout<<lts[i]<<endl;
//    }

    vector<vector<string> > res(lts.size());
    for(int i=0;i<lts.size();i++){
        for(int cnt=0;cnt<7;cnt++){
            for(int j=0;j<lts[i].size();j++){
                prt(lts[i][j],cnt);
                if(j!=lts[i].size()-1) printf(" ");
                else if(cnt!=6) printf("\n");
            }
        }
        if(i!=lts.size()-1) printf("\n\n");
    }

    return 0;
}
