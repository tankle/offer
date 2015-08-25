#include <iostream>
#include <cstdio>
#include "tree.hpp"
using namespace std;


int main(){
    BiTree a1(1), a3(3), a5(5), a7(7);
    BiTree a2(2, &a1, &a3), a6(6, &a5, &a7);
    BiTree a4(4, &a2, &a6);

    preorder(&a4); printf("\n"); //4 2 1 3 6 5 7
//    preorder2(&a4); printf("\n"); //4 2 1 3 6 5 7
//    preorder3(&a4); printf("\n"); //4 2 1 3 6 5 7
    printf("\n");

    inorder(&a4); printf("\n"); //1 2 3 4 5 6 7
//    inorder2(&a4); printf("\n"); //1 2 3 4 5 6 7
//    inorder3(&a4); printf("\n"); //1 2 3 4 5 6 7
    printf("\n");

    postorder(&a4); printf("\n"); //1 3 2 5 7 6 4
//    postorder2(&a4); printf("\n"); //1 3 2 5 7 6 4
//    postorder3(&a4); printf("\n"); //1 3 2 5 7 6 4
    return 0;
}