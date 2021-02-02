#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
struct book{
    string id;
    string name;
    string author;
    vector<string> keys;
    string publisher;
    int year;
};
const int MAX = 10000;

int main(){
    int N;
    char str[MAX];
    cin >> N;
    getchar();
    vector<book> bs;
    for(int i=0;i<N;i++){
        cin.getline(str,MAX);
        book tmp;
        tmp.id = string(str);
        
        cin.getline(str,MAX);
        tmp.name = string(str);
        
        cin.getline(str,MAX);
        tmp.author = string(str);
        
        cin.getline(str,MAX);
        char *token;
        vector<string> k;
        token = strtok(str," ");
        while(token != NULL){
            k.push_back(string(token));
            token = strtok(NULL," ");
        }
        tmp.keys = k;
        
        cin.getline(str,MAX);
        tmp.publisher = string(str);
        
        // cin.getline(str,MAX);
        int a;
        cin >> a;
        tmp.year = a;
        bs.push_back(tmp);
        getchar();
    }
    int M;
    cin >> M;
    getchar();
    vector<vector<string>> outs;
    for(int i=0;i<M;i++){
        vector<string> output;
        cin.getline(str,MAX);
        int type = *str - '0';
        output.push_back(string(str));
        string t = string(str+3);
        for(vector<book>::iterator it = bs.begin();it!=bs.end();it++){
            if(type==1){
                if(t.compare(it->name) == 0)
                    output.push_back(it->id);
            }
            if(type==2){
                if(t.compare(it->author) == 0)
                    output.push_back(it->id);
            }if(type==3){
                if(find(it->keys.begin(),it->keys.end(),t) != it->keys.end())
                    output.push_back(it->id);
            }if(type==4){
                if(t.compare(it->publisher) == 0)
                    output.push_back(it->id);
            }if(type==5){
                if(t.compare(to_string(it->year)) == 0)
                    output.push_back(it->id);
            }
        }
        sort(output.begin()+1,output.end());
        outs.push_back(output);
    }
    for(vector<vector<string>>::iterator it=outs.begin();it!=outs.end();it++){
        vector<string> output = *it;
        if(output.size()==1)
        {   
            cout<<(*it)[0]<<endl; 
            cout<<"Not Found"<<endl;
        }else{
            for(vector<string>::iterator it = output.begin();it!=output.end();it++){
                cout<<*it<<endl;
            }
        }
    }
    return 0;
}


