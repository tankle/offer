#include <vector>
#include <stack>
#include <queue>

using namespace std;



class Solution {
public:
    /**
     * 寻找旋转最小数
     */
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;

        int start = 0, end = rotateArray.size()-1;
        int mid = start;
        while(rotateArray[start] >= rotateArray[end]){
            if(start + 1 == end){
                mid = end;
                break;
            }

            mid = (start + end )/2;
            //顺序查找
            if(rotateArray[start] == rotateArray[end] &&
               rotateArray[start] == rotateArray[mid]){
                return minInOrder(rotateArray, start, end);
            }


            //二分查找
            if(rotateArray[mid] >= rotateArray[start])
                start = mid;
            else if(rotateArray[mid] <= rotateArray[end])
                end = mid;
        }

        return rotateArray[mid];
    }

    int minInOrder(vector<int> array, int s, int e){
        int result = array[s];
        for(int i=s+1; i<e; i++)
            if(array[i] < result)
                result = array[i];
        return result;
    }

};