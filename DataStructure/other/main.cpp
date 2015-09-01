#include <iostream>
#include <vector>
#include "heap.hpp"
#include <cstdio>
#include <cstring>
using namespace std;

/**
 * 修改常量
 */
int f1(int const& a){
    return ++ ((int&)a);
}

int f2(int const& a) {
    return ++ ((int&)a);
}

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ')
            i++;
        s = s.substr(i, s.size()-i);

        int j = s.size() - 1;
        while(j >=0 && s[j] == ' ')
            j--;
        s = s.substr(0, j+1);

        if(s.size() == 0)
            return;

        reverse(s, 0, s.size()-1);

        int b = 0;
        i = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                reverse(s, b, i-1);
                while(i < s.size() && s[i] == ' ')
                    i++;
                b = i;

            }
            i++;
        }
        reverse(s, b, s.size() -1);
    }
    void reverse(string& str, int s, int e){
        while(s <= e){
            auto tmp = str[s];
            str[s] = str[e];
            str[e] = tmp;
            s++;
            e--;
        }
    }
};

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
    int a = int();
    cout<<a<<endl;

    a = 1;
    cout<<f1(a)<<endl;
    cout<<f2(a)<<endl;

//    string aa = "a";
//    cout<<aa.substr(0,aa.size()-1)<<" result"<<endl;
//    Solution s;
//    s.reverseWords(aa);
//    cout<<aa;

    char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
    return 0;
}