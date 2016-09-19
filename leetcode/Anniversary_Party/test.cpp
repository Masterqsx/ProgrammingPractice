#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int treeDP(vector<int> &, unordered_set<int> &, vector<int> &, int);
struct node//树节点
{
    bool flag;//用于标记该节点是否是根节点
    vector<node> vecnode;//用于存放每个几点的子几点
    int dp[2];//dp[1]表示该节点参加宴会的愉悦度；dp[0]表示该节点不参加宴会的愉悦度
};
int max(int a,int b)
{
    return a>b?a:b;
}
//treedp函数用动态从叶子节点到根节点求解宴会的最大愉悦程度
void treedp(node &root)
{
    //如果该节点是叶子节点，直接返回
    if(0==root.vecnode.size())
        return;
    //递归求解每个节点的愉悦度
    for(vector<node>::iterator iter=root.vecnode.begin();iter!=root.vecnode.end();iter++)
    {
        treedp(*iter);
        //状态转换方程
        root.dp[0]+=max((*iter).dp[0],(*iter).dp[1]);
        root.dp[1]+=(*iter).dp[0];
    }
}
int main()
{
    int n;
    cin>>n;
    node *N=new node[n];
    vector<int> tree = vector<int>(n, 0);
    for (int i=0;i<n;i++) tree[i] = i;
    vector<int> val = vector<int>(n, 0);
    unordered_set<int> leaves;
    //初始化
    for(int i=0;i<n;i++)
    {
        N[i].flag=true;
    }
    for(int i=0;i<n;i++)
    {
        cin>>N[i].dp[1];
        val[i] = N[i].dp[1];
        N[i].dp[0]=0;
    }
    int parent,child;
    //输入宴会参与者的关系
    for(int i=0;i<n-1;i++)
    {
        cin>>child>>parent;
        N[parent-1].vecnode.push_back(N[child-1]);
        N[child-1].flag=false;
        tree[child-1] = parent-1;
    }
    for (int i=0;i<n;i++){
      if (N[i].vecnode.empty()) leaves.insert(i);
    }
    node root;
    //寻找根节点
    for(int i=0;i<n;i++)
        if(true==N[i].flag)
            root=N[i];

    //求解宴会最大愉悦度
    treedp(root);
    cout<<treeDP(tree, leaves, val, n)<<endl;
    cout<<max(root.dp[0],root.dp[1])<<endl;
}
