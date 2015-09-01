#include <vector>
#include <queue>

using namespace std;

/**
 *
 * 数据流中的中位数
 *
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 *
 *
 * 使用两个堆，左边使用最大堆，右边使用最小堆
 *
 * 分情况插入
 *
 */

class Solution {
public:
    void Insert(int num)
    {
        //奇数
        if((minx.size() + maxx.size() ) & 1 != 0){
            if(minx.size() > 0 && num > minx.top()){
                minx.push(num);
                num = minx.top();
                minx.pop();
            }
            maxx.push(num);
        }else{
            if(maxx.size() > 0 && num < maxx.top()){
                maxx.push(num);
                num = maxx.top();
                maxx.pop();

            }
            minx.push(num);
        }
    }

    double GetMedian()
    {
        if((minx.size() + maxx.size() ) & 1  != 0)
            return minx.top();
        return (maxx.top() + minx.top()) / 2. ;

    }
//private:
    priority_queue<int, vector<int>, greater<int> > minx;
    priority_queue<int, vector<int>, less<int> > maxx;

};