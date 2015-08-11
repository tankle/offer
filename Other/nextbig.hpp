#include <vector>
#include <stack>
using namespace std;

/**
 *    现在我们有一个int数组，请你找出数组中每个元素的下一个比它大的元素。
    给定一个int数组A及数组的大小n，请返回一个int数组，代表每个元素比他大的下一个元素,若不存在则为-1。保证数组中元素均为正整数。
    测试样例：
    [11,13,10,5,12,21,3],7
    返回：[13,21,12,12,21,-1,-1]
    http://www.nowcoder.com/questionTerminal/11ae41035eef4ed9b354d0752f5abc6f?orderByHotValue=0&questionTypes=000100&done=0&pos=32&onlyReference=false
 */
int* nextBig(int* array, int length){

    int* result = new int[length];
    stack<int> minstack;
    result[length-1] = -1;
    minstack.push(array[length-1]);
    for(int i=length-2; i>=0; i--){
        //从后往前维护一个递减的栈
        while( !minstack.empty() && array[i] >= minstack.top()){
            minstack.pop();
        }

        if(minstack.empty()){
            result[i] = -1;
        }
        else
            result[i] = minstack.top();
        minstack.push(array[i]);
    }
    return result;
}

void test_nextBig(){
    int array[] = {11,13,10,5,12,21,3};
    int result[] = {13,21,12,12,21,-1,-1};

    int len = 7;
    int* res = nextBig(array, len);
    for(int i=0; i<len; i++)
        cout<<res[i] <<" ";
    cout<<endl;
}
