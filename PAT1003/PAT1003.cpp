#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

const int MAX=1000;
int d;
int mind=9999;
int tnum;

int dfs(vector<vector<int>> graph,int s, int t);

int main(){
    char str[MAX];
    char *token;
    int v_num,e_num,s,t;
    cin.getline(str,MAX);
    v_num = atoi(strtok(str," "));
    e_num = atoi(strtok(NULL," "));
    s = atoi(strtok(NULL," "));
    t = atoi(strtok(NULL," "));
    int *teams = new int [v_num];
    vector<int> line(v_num,0);
    vector<vector<int>> graph(v_num,line);

    cin.getline(str,MAX);
    for(int i=0;i<v_num;i++){
        teams[i] = i==0 ? atoi(strtok(str," ")) : atoi(strtok(NULL," "));
    }
    for(int i=0;i<e_num;i++){
        cin.getline(str,MAX);
        int a = atoi(strtok(str," "));
        int b = atoi(strtok(NULL," "));
        int c = atoi(strtok(NULL," "));
        graph[a][b] = c;
    }



    return 0;
}

int dfs(vector<vector<int>> graph,int s, int t){
    tnum += teams[s];
    if(s==t){
        if(d<mind)
        {
            mind = d;
            num++
        }
    }
    for(int i=0;i<graph.size();i++){
        if(graph[s][i]!=0)
        {
            d += graph[s][i];
            dfs(graph,i,t);
        }
    }
}

int dfs_helper(int node){

}