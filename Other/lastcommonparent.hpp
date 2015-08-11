#include <vector>
#include <stack>
using namespace std;

/**
 * 有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
测试样例：
2，3
返回：1
解题思路： 由于该二叉树是一个满二叉树，所以可以直接根据该性质，分别求得两个节点到根节点的路劲，保存到栈中；最后遍历两个栈，直到最后一个相等的值为止，
 则该值即为所求的最近公共祖先。
 */
int LastCommonParent(int one, int two){
    stack<int> s1;
    stack<int> s2;
    while(one > 0){
        s1.push(one);
        one /= 2;
    }
    while(two > 0){
        s2.push(two);
        two /= 2;
    }
    int result = -1;
    while( !s1.empty() && !s2.empty() && s1.top() == s2.top()){
        result = s1.top();
        s1.pop();
        s2.pop();
    }
    return result;
}

void LastCommonParent(){
    int a = 2, b = 3;
    int res = LastCommonParent(a, b);
    cout<<res<<endl;

    a = 2;
    b = 7;
    res = LastCommonParent(a, b);
    cout<<res<<endl;

    a = 2;
    b = 9;
    res = LastCommonParent(a, b);
    cout<<res<<endl;

    a = 4;
    b = 10;
    res = LastCommonParent(a, b);
    cout<<res<<endl;
}