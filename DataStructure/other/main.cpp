#include <iostream>
#include <vector>
#include "heap.hpp"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int w = 3;
    vector<int> res = localMax(arr,w);
//
    for(auto it=res.cbegin(); it != res.cend(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}