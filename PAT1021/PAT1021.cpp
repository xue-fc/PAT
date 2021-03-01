/*
    树用邻接表存储，因为没有根。邻接表用vector<vector<int>>就行
    去重用set，如果不需要排序的话就用undered_set
    这题的两次dfs很妙
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;

const int inf = 10000;
vector<bool> visit;
int maxheight = 0;
vector<vector<int>> tree;
vector<int> res;
void dfs(int node,int height){
    visit[node] = true;
    bool flag = false;
    for(auto it = tree[node].begin();it!=tree[node].end();it++){
        if(!visit[*it])
        {
            flag  = true;
            dfs(*it,height+1);
        }
    }
    if(!flag)//到叶子了
    {
        if(height > maxheight){
            res.clear();
            res.push_back(node);
            maxheight = height;
        }
        else if(height == maxheight)
        {
            res.push_back(node);
        }
        
    }
    return;
}

int main(){
    int n,a,b;
    scanf("%d",&n);
    tree.resize(n+1);//定义成全局变量则不用在dfs中传参
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visit.resize(n+1);
    fill(visit.begin(),visit.end(),false);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visit[i])
        {
            cnt++;
            dfs(i,1);
        }

    }
    if(cnt!=1){
        printf("Error: %d components\n",cnt);
        return 0;
    }
    set<int> abc; //利用set去重加排序
    for(auto it=res.begin();it!=res.end();it++){
        abc.insert(*it);
    }
    int s1;
    if(res.size()!=0)
        s1 = res[0];
    res.clear();
    maxheight = 0;
    fill(visit.begin(),visit.end(),false);
    dfs(s1,1);
    for(int i=0;i<res.size();i++)
        abc.insert(res[i]);
    for(auto it=abc.begin();it!=abc.end();it++){
        printf("%d\n",*it);
    }

    return 0;
}
