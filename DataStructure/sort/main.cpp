#include <iostream>
#include <vector>
#include "sort.hpp"
using namespace std;

int bisearch(vector<int> arr, int target, int start, int end)
{
    while(start <= end){
        int mid = (end + start)/2;
        if(arr[mid] > target)
            end = mid - 1;
        else if(arr[mid] < target)
            start = mid + 1;
        else{
            if(mid + 1 <= end && arr[mid + 1] == target)
                start = mid + 1;
            else
                return mid;
        }

    }
    return -1;
}


int main() {
    //测试结果
//    testResult();

    //测试效率
//    testSort();

    vector<int> arr = {1,2,2,2,2,2,4,5, 6,6,6,7,8,8,9};
    cout<<bisearch(arr, 2, 0, arr.size())<<endl;
    cout<<bisearch(arr, 8, 0, arr.size())<<endl;
    int x = 10, y = 3;
    printf("%d", y = x/y);
    return 0;
}