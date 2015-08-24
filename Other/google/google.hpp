
#include <string>
#include <vector>
#include <cstdio>

class Solution{
public:
    /**
     * 这题题意就是，有N个时间点，每个时间点，Kaylin可以吃掉一定数量的mushroom，Bartholomew可以放入任意数量的mushroom。

    现在给出N个时间点分别有多少mushroom。

    问：若Kaylin每个时间点可以吃任意数量的mushroom，那为了配合每个时间点的mushroom，Kaylin最少要吃掉多少蘑菇。

    问：若Kaylin已恒定速度吃mushroom（即在每个时间点间吃的数量相同，若盘子空了则暂停进食），那为了配合每个时间点的mushroom，Kaylin最少要吃掉多少蘑菇。


    看懂题目就是水题，第一问，只要吃掉下一个时间点相对于当前时间点减少的mushroom数量。

    第二问，只要保证吃的速度要大于等于所有时间点mushroom减少的数量，即取需求速度最大值。
     */
    void MushroomMonster(){
        int t;
        scanf("%d", &t);
        int n;
        int array[1001];
        for(int c=1; c <= t; c++){
            scanf("%d", &n);
            int i;
            for(i=0; i<n; i++)
                scanf("%d", &array[i]);
            int res1 = 0;
            int rate = 0.0;
            for(i=0; i<n-1; i++){
                if(array[i] > array[i+1]) {
                    res1 += array[i] - array[i + 1];
                    rate = max(rate, array[i] - array[i+1]);
                }
            }
            int res2 = 0;
            for(i=0; i<n-1; i++){
                res2 += min(rate, array[i]);
            }
            //Case #1: 15 25
            printf("Case #%d: %d %d\n",c, res1, res2);
//            cout<<"Case #"<<c<<": "<<res1<<" "<<res2<<endl;
        }
    }


};

void googlerun(){
    //A-large-practice  A-small-practice.in
    //google code jam 只要提交答案即可
    freopen("D:\\Github\\offer\\Other\\google\\A-large-practice.in", "r", stdin);
    freopen("D:\\Github\\offer\\Other\\google\\A-large-practice.out", "w", stdout);
    Solution s;
    s.MushroomMonster();
}