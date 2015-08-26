#include <queue>
#include <vector>
using namespace std;

struct Node{
    int val;
    int index;
    Node(int v, int idx):val(v),index(idx){}
};

struct mycomp
{

    bool operator()(const Node* left, const Node* right) const{
        //大的在前面，左边大，不需要交换
        if(left->val > right->val)
            return 0;
        else if(left->val < right->val)
            return 1;
            //下标大的再前面
        else if(left->index > right->index)
            return 0;
        else if(left->index < right->index)
            return 1;
        return 0;
    }
};
/**
 * 生成窗口最大值数组
 * 有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
 * 例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时：

[4 3 5] 4 3 3 6 7 窗口中最大值为5
4 [3 5 4] 3 3 6 7 窗口中最大值为5
4 3 [5 4 3] 3 6 7 窗口中最大值为5
4 3 5 [4 3 3] 6 7 窗口中最大值为4
4 3 5 4 [3 3 6] 7 窗口中最大值为6
4 3 5 4 3 [3 6 7] 窗口中最大值为7

 * 如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。
 * 请实现一个函数，给定一个数组arr，窗口大小w。
 * 返回一个长度为n-w+1的数组res,res[i]表示每一种窗口状态下的最大值。以本题为例，结果应该返回[5,5,5,4,6,7]。
 */
vector<int> localMax(vector<int> arr, int w)
{
    priority_queue<Node*,vector<Node*>, mycomp> que;

    vector<int> res;
    //输出化第一个w中的优先队列
    for(int i=0; i<w; i++)
        que.push(new Node(arr[i],i));

    for(int i=w; i<arr.size(); i++){
        Node* cur = que.top();
        res.push_back(cur->val);
        //将index大于窗口w的的值从大到小删掉
        while( cur->index <= i - w){
            Node * tmp = que.top();
            que.pop();
            delete tmp;
        }

        que.push(new Node(arr[i], i));
    }
    res.push_back(que.top()->val);

    return res;
}

