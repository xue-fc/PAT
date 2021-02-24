/*
    这是柳神的代码，绝妙
    因为是完全二叉树，所以用数组来存树，不用链接树
    函数inOrder利用递归，把in中的元素从小到大依次放入level中
    递归信任
    先放左再放右，利用二叉排序树的中序遍历即从小到大的特性
*/
#include <iostream>
#include <algorithm>
using namespace std;
int in[1010], level[1010], n, t = 0;
void inOrder(int root) {
    if (root >= n) return ;
    inOrder(root * 2 + 1);
    level[root] = in[t++];
    inOrder(root * 2 + 2);
}
int main() {
    freopen("C:\\Users\\dell\\Desktop\\code\\cpp\\PAT\\test.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}