#include <iostream>
//#include "two.hpp"
#include <string>
#include "median.hpp"
using namespace std;




int main()
{
    cout<<"Hello world"<<endl;
//    cout<<std::to_string(2)<<endl;
    Solution s;
    s.Insert(1);
    s.Insert(2);
    s.Insert(4);
    s.Insert(3);
//    s.Insert(5);
    cout<<s.GetMedian()<<endl;

    cout<<s.maxx.top()<<" "<<s.minx.top()<<endl;
    cout<<endl;
    while( !s.minx.empty()){
        cout<<s.minx.top();
        s.minx.pop();
    }
    cout<<endl;
    while( !s.maxx.empty()){
        cout<<s.maxx.top();
        s.maxx.pop();
    }
    cout<<endl;
    return 0;
}
