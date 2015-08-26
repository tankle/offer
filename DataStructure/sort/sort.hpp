#include <iostream>
#include <vector>
#include <boost/foreach.hpp>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

using namespace std;

class Solution{
private:
    vector<int> arr={49,38,65,97,76,13,27,49,78,34,12,64,5,4,62,99,98,54,56,17,18,23,34,15,35,25,53,51};


public:

    //参考 http://blog.csdn.net/qy1387/article/details/7752973

    /**
     * 插入排序
     * 基本思想：寻找到可以插入的位置
     */
    vector<int> InsertSort(vector<int> result){
        int tmp = 0;
        for(int i=1; i<result.size(); i++){
            int j= i-1;
            tmp = result[i];
            while(j >= 0 && tmp < result[j]){
                result[j+1]= result[j];
                j--;
            }
            result[j+1] = tmp;
        }
        return result;
    }

    /**
     * 希尔排序
     * 基本思想：
     *  算法先将要排序的一组数按某个增量d（n/2,n为要排序数的个数）分成若干组，
     * 每组中记录的下标相差d.对每组中全部元素进行直接插入排序，
     * 然后再用一个较小的增量（d/2）对它进行分组，在每组中再进行直接插入排序。
     * 当增量减到1时，进行直接插入排序后，排序完成。
     */
    vector<int> ShellSort(vector<int> result){

        int tmp = 0;
        double d1 = result.size();

        while(true){
            d1 = ceil(d1/2);
            int d = (int)d1;
            for(int i=0; i<d; i++){
                //增量为d的插入排序
                for(int j=i+d; j<result.size(); j+=d){
                    int k = j - d;
                    tmp = result[j];
                    while(k >= 0 && result[k] > tmp){
                        result[k+d] = result[k];
                        k = k - d;
                    }
                    result[k+d] = tmp;
                }
            }
            if(d == 1)
                break;
        }
        return result;
    }
    /**
     * 选择排序：
     * 基本思想：
     *      在要排序的一组数中，选出最小的一个数与第一个位置的数交换；
     * 然后在剩下的数当中再找最小的与第二个位置的数交换，如此循环到倒数第二个数和最后一个数比较为止。
     */
    vector<int> SelectSort(vector<int> result){
        for(int i=0; i<result.size()-1; i++){
            int k = i;
            for(int j=i+1; j<result.size(); j++){
                if(result[k] > result[j] )
                    k = j;
            }
            if( k != i){
                int tmp = result[k];
                result[k] = result[i];
                result[i] = tmp;
            }
        }
        return result;
    }

    //*************************************************
    //堆排序
    /**
     * 重新构建堆，使之符合堆的规则
     */
    void __fixdwon(vector<int>& arr,int root, int lastIndex){
        int i = root;
        int tmp = arr[root];
        int j = 2*i + 1;
        while(j < lastIndex){

            if(j + 1 < lastIndex && arr[j+1] > arr[j])
                j++;
            //找到比根节点小的值
            if(arr[j] <= tmp)
                break;
            //移动到父节点
            arr[i] = arr[j];
            i = j;
            j = 2*i + 1;
        }
        arr[i] = tmp;
    }

    //建堆
    void  __buildMaxHeap(vector<int>& arr, int lastindex){
        for(int i=lastindex/2-1; i>=0; i--){
            this->__fixdwon(arr, i, lastindex);
        }
    }
    /**
     * 堆排序
     *
     */
    vector<int> HeapSort(vector<int> arr){
        this->__buildMaxHeap(arr, arr.size());
        for(int i=arr.size()-1; i>=0; i--){
            int tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;
            this->__fixdwon(arr, 0, i);
        }
        return arr;
    }

    /**
     *  冒泡排序
     *  相邻比较
     */
    vector<int> BubbleSort(vector<int> arr){
        for(int i=0; i<arr.size(); i++){
            for(int j=1; j<arr.size()-i; j++){
                if(arr[j] < arr[j-1]){
                    int tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;
                }
            }
        }
        return arr;
    }

    /**
     * 冒泡排序算法的优化1
     *
     * 设置一个标志flag，当某一趟完全没有进行交换，就不需要进行下一轮的排序
     */
    vector<int> BubbleSort1(vector<int> arr){
        bool flag = true;
        int k = arr.size();
        while(flag && k >0 ) {
            flag = false;
            for (int i = 1; i < k; i++) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                    flag = true;
                }
            }
            k--;
        }
        return arr;
    }


    /**
     * 快速排序
     */
    /**
     * 切分函数，以第一个作为枢纽
     */
    int __partition(vector<int>& arr, int first, int last){
        int key = arr[first];
        while(first < last){
            while(first < last && arr[last] >= key){
                last--;
            }
            arr[first] = arr[last];
            while(first < last && arr[first] <= key){
                first++;
            }
            arr[last] = arr[first];

        }
        arr[first] = key;
        return first;
    }
    /**
     * 递归排序
     */
    void __quickSort(vector<int>& arr, int start, int end){
        if(start < end){
            int middle = this->__partition(arr, start, end);
            __quickSort(arr, start, middle-1);
            __quickSort(arr, middle+1, end);
        }
    }

    vector<int> QuickSort(vector<int> arr){
        __quickSort(arr,0, arr.size()-1);
        return arr;
    }

/////////////////////////////////////////////////////////////////////
    /**
     * 归并排序
     */
    void __merge(vector<int>&arr, int start, int mid, int end){
        vector<int> tmp;
        int left = start;
        int right = mid + 1;
        while(left <= mid && right <= end){
            if(arr[left] < arr[right])
                tmp.push_back(arr[left++]);
            else
                tmp.push_back(arr[right++]);
        }
        while(left <= mid){
            tmp.push_back(arr[left++]);
        }
        while(right <= end){
            tmp.push_back(arr[right++]);
        }
        for(int i=start; i<=end; i++){
            arr[i] = tmp[i-start];
        }
    }
    void __sort(vector<int>& arr, int start, int end){
        if(start < end){
            int mid = (start + end)/2;
            __sort(arr, start, mid);
            __sort(arr, mid+1, end);
            __merge(arr, start, mid, end);
        }

    }
    vector<int> MergeSort(vector<int> arr){
        __sort(arr, 0, arr.size()-1);
        return arr;
    }



    /**
     * 打印结果
     */
    void print(vector<int> result){
        BOOST_FOREACH(int i, result){
            cout<< i<< " ";
        }
        cout<<endl;
    }
};



vector<int> generateArray(int num){
    /* initialize random seed: */
    srand (time(NULL));

    vector<int> result(num);
    for(int i=0; i<num; i++){
        result[i] = rand() % num*10 + 1;
    }
    return result;
}

void testEqual(vector<int> old, vector<int> result, string str){
    for(int i=0; i<old.size(); i++){
        if(old[i] != result[i])
        {
            cout<<"Not Equal!!!"<<endl;
            cout<<str<<endl;
            throw;
        }
    }
}

void testSort(){
    typedef std::chrono::high_resolution_clock Clock;

    Solution s;
    for(int i=10000; i<1000001; i *= 10){
        cout<<"Number is "<<i<<"\t(milliseconds)"<<endl;
        vector<int> test = generateArray(i);

        Clock::time_point start = Clock::now();
        vector<int> insert = s.InsertSort(test);
        Clock::time_point end = Clock::now();
        cout<<"InsertSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        start = Clock::now();
        vector<int> shell = s.ShellSort(test);
        end = Clock::now();
        cout<<"ShellSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        start = Clock::now();
        vector<int> select = s.SelectSort(test);
        end = Clock::now();
        cout<<"SelectSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;


        start = Clock::now();
        vector<int> heap = s.HeapSort(test);
        end = Clock::now();
        cout<<"HeapSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        start = Clock::now();
        vector<int> quick = s.QuickSort(test);
        end = Clock::now();
        cout<<"QuickSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;


        start = Clock::now();
        vector<int> bubble = s.BubbleSort(test);
        end = Clock::now();
        cout<<"BubbleSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        start = Clock::now();
        vector<int> bubble1 = s.BubbleSort1(test);
        end = Clock::now();
        cout<<"BubbleSort1\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        start = Clock::now();
        vector<int> merge = s.MergeSort(test);
        end = Clock::now();
        cout<<"MergeSort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;


        start = Clock::now();
        sort(test.begin(), test.end());
        end = Clock::now();
        cout<<"Sort\t" <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<endl;

        testEqual(test, insert, "insert");
        testEqual(test, shell,"shell");
        testEqual(test, select, "select");
        testEqual(test, bubble,"bubble");
        testEqual(test, bubble1,"bubble");
        testEqual(test, quick, "quick");
        testEqual(test, merge,"merge");
        testEqual(test, heap,"heap");

        cout<<endl;
    }
}


void testResult(){
    vector<int> test={49,38,65,97,76,13,27,49,78,34,12,64,5,4,62,99,98,54,56,17,18,23,34,15,35,25,53,51};

    Solution s;


    vector<int> result = s.InsertSort(test);

    s.print(result);

    vector<int> two = s.ShellSort(test);
    s.print(two);


    vector<int> three = s.SelectSort(test);
    s.print(three);

//    s.__buildMaxHeap(test, test.size());
//    s.print(test);
    vector<int> four = s.HeapSort(test);
    s.print(four);

    vector<int> five = s.BubbleSort(test);
    cout<<"BubbleSort: "<<endl;
    s.print(five);


    vector<int> six = s.QuickSort(test);
    cout<<"QuickSort: "<<endl;
    s.print(six);

    vector<int> seven = s.MergeSort(test);
    cout<<"MergeSort: "<<endl;
    s.print(seven);


    sort(test.begin(), test.end());
    s.print(test);
}
