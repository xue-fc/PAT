#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

const int MAX = 10000;

int main(){
    char str1[MAX],str2[MAX];
    int n=0;
    cin.getline(str1,MAX);
    cin.getline(str2,MAX);
    map<int,double> pn1,pn2;
    char *token1,*token2,*saveptr1,*saveptr2;
    token1 = strtok_r(str1," ",&saveptr1);
    n = atoi(token1);
    for(int i=0;i<n;i++){
        int e = atoi(strtok_r(NULL," ",&saveptr1));
        double f = atof(strtok_r(NULL," ",&saveptr1));
        pn1[e] = f;
    }

    token2 = strtok_r(str2," ",&saveptr2);
    n = atoi(token2);
    for(int i=0;i<n;i++){
        int e = atoi(strtok_r(NULL," ",&saveptr2));
        double f = atof(strtok_r(NULL," ",&saveptr2));
        pn2[e] = f;
    }

    map<int,double>::iterator it1;
    map<int,double>::iterator it2;
    map<int,double> res;
    int exp=0;
    double cof = 0;
    for(it1 = pn1.begin();it1!=pn1.end();it1++){
        for(it2 = pn2.begin();it2!=pn2.end();it2++){
            exp = it1->first + it2->first;
            cof = it1->second * it2->second;
            res[exp] += cof;
            // if(res.count(exp)==0){
            //     res[exp] = cof;
            // }
            // else{
            //     res[exp] += cof;
            // }
        }
    }

    cout<<res.size()<<' ';
    map<int,double>::reverse_iterator rit = res.rbegin();
    while(rit!=res.rend())
    {
        cout<<rit->first<<' ';
        printf("%.1f",rit->second);
        ++rit;
        if(rit!=res.rend())
            cout<<' ';
    }
    cout<<endl;

    return 0;
}

