#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;


class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        /**
         * 使用动态规划， k = max(result[i][j-1], result[i-1][j]),
         * result[i][j] = k+1 if A[i-1] == C[k] or B[j-1] == C[k] #当前能匹配
         * result[i][j] = 0 不能匹配
         */
        int result[101][101];
        memset(result, 0, sizeof(int)*101*101);
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 && j > 0){
                    if(B[j-1] == C[result[i][j-1]])
                        result[i][j] = result[i][j-1] + 1;
                    else
                        result[i][j] = 0;
                }
                else if(j == 0){
                    if(A[i - 1] == C[result[i-1][j]])
                        result[i][j] = result[i-1][j] + 1;
                    else
                        result[i][j] = 0;
                }
                else{
                    int tmp = max(result[i][j-1], result[i-1][j]);
                    if(B[j-1] == C[tmp] || A[i-1] == C[tmp])
                        result[i][j] = tmp + 1;
                    else
                        result[i][j] = 0;
                }
            }
        }
        if(result[n][m] == v)
            return true;
        return false;
    }
};


class Cards {
public:
    int cardGame(vector<int> A, int n) {
        if(n == 0 || A.size() == 0)
            return 0;
        return max(f(A, 0, n-1), s(A, 0, n-1));
    }
    //先拿
    int f(vector<int> A, int i, int j){
        if(i == j)
            return A[i];
        return max(A[i] + s(A, i+1, j), A[j] + s(A, i, j-1));
    }
    //后拿
    int s(vector<int> A, int i, int j){
        if(i == j)
            return 0;
        //对手留给剩下的最少钱数
        return min(f(A, i+1, j), f(A, i, j-1));
    }
};