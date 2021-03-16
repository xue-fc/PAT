#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string,string> m; 

vector<int> tree(1010);

void helper(int s){
    while(s!=1 && tree[s] > tree[s/2]){
        int tmp = tree[s];
        tree[s] = tree[s/2];
        tree[s/2] = tmp;
        s = s/2;
    }
}

int main(){
    fill(tree.begin(),tree.end(),9999999);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        tree[i] = tmp;
        helper(i);
    }
    string s;
    getchar();
    for(int i=0;i<M;i++){
        // getchar();
        getline(cin,s,'\n');
        if(s.find("root") != string::npos ){
            auto it=s.begin();
            while(*it != ' ') it++;
            int r = stoi(string(s.begin(),it));
            if(r!=tree[1])
                cout<<"0";
            else
                cout<<"1";
        } else if(s.find("siblings") != string::npos){
            auto it=s.begin();
            while(*it != ' ') it++;
            int a = stoi(string(s.begin(),it));
            it=it+5;
            auto tmpit=it;
            while(*it != ' ') it++;
            int b = stoi(string(tmpit,it));
            int apos=-1,bpos=-1;
            for(int i=1;i<=N;i++){
                if(tree[i]==a)
                    apos = i;
                if(tree[i]==b)
                    bpos = i;
            }
            // int apos = find( tree.begin(),tree.end(),a ) - tree.begin();
            // int bpos = find(tree.begin(),tree.end(),b) - tree.begin();
            if(apos==-1 || bpos==-1 || apos/2 != bpos/2)
                cout<<"0";
            else
                cout<<"1";
        } else if(s.find("parent") != string::npos){
            auto it=s.begin();
            while(*it!=' ') it++;
            int a = stoi(string(s.begin(),it));
            it = s.end()-1;
            while(*it!=' ') it--;
            int b = stoi(string(it+1,s.end()));
            int apos=-1,bpos=-1;
            for(int i=1;i<=N;i++){
                if(tree[i]==a)
                    apos = i;
                if(tree[i]==b)
                    bpos = i;
            }
            if(apos==-1 || bpos==-1 || bpos/2 != apos)
                cout<<"0";
            else
                cout<<"1";
        } else if(s.find("left") != string::npos){
            auto it=s.begin();
            while(*it!=' ') it++;
            int a = stoi(string(s.begin(),it));
            it = s.end()-1;
            while(*it!=' ') it--;
            int b = stoi(string(it+1,s.end()));
            int apos=-1,bpos=-1;
            for(int i=1;i<=N;i++){
                if(tree[i]==a)
                    apos = i;
                if(tree[i]==b)
                    bpos = i;
            }
            if(apos==-1 || bpos==-1 || apos!=2*bpos)
                cout<<"0";
            else
                cout<<"1";
        } else if(s.find("right") != string::npos ){
            auto it=s.begin();
            while(*it!=' ') it++;
            int a = stoi(string(s.begin(),it));
            it = s.end()-1;
            while(*it!=' ') it--;
            int b = stoi(string(it+1,s.end()));
            int apos=-1,bpos=-1;
            for(int i=1;i<=N;i++){
                if(tree[i]==a)
                    apos = i;
                if(tree[i]==b)
                    bpos = i;
            }
            if(apos==-1 || bpos==-1 || apos!=2*bpos+1)
                cout<<"0";
            else
                cout<<"1";
        }
    }
    cout<<endl;
    return 0;
}