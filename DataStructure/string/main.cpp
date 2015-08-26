#include <iostream>
#include <string>
#include "kmp.hpp"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    string src = "abcab";
    string pa = "cab";
    cout<<KMP(src, pa);
    return 0;
}