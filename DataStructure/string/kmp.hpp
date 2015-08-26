#include <string>
using namespace std;

/**
 * 获得Next数组
 * 问题是：已知next [0, ..., j]，如何求出next [j + 1]呢？
 *     对于P的前j+1个序列字符：
 *     若p[k] == p[j]，则next[j + 1 ] = next [j] + 1 = k + 1；
 *     若p[k ] ≠ p[j]，如果此时p[ next[k] ] == p[j ]，则next[ j + 1 ] =  next[k] + 1，
 *     否则继续递归前缀索引k = next[k]，而后重复此过程。
 *     相当于在字符p[j+1]之前不存在长度为k+1的前缀"p0 p1, …, pk-1 pk"跟后缀“pj-k pj-k+1, …, pj-1 pj"相等，
 *     那么是否可能存在另一个值t+1 < k+1，使得长度更小的前缀 “p0 p1, …, pt-1 pt” 等于长度更小的后缀 “pj-t pj-t+1, …, pj-1 pj” 呢？
 *     如果存在，那么这个t+1 便是next[ j+1]的值，此相当于利用已经求得的next 数组（next [0, ..., k, ..., j]）进行P串前缀跟P串后缀的匹配。
 */
void getNext(string pattern, int next[])
{
    int plen = pattern.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < plen){
        //
        if(k == -1 || pattern[k] == pattern[j]){
            k++;
            j++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}
/**
 *http://blog.csdn.net/v_july_v/article/details/7041827
 *
 * 假设现在文本串S匹配到 i 位置，模式串P匹配到 j 位置
 *  如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++，继续匹配下一个字符；
 *  如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]。此举意味着失配时，模式串P相对于文本串S向右移动了j - next [j] 位。
 *  换言之，当匹配失败时，模式串向右移动的位数为：失配字符所在位置 - 失配字符对应的next 值（next 数组的求解会在下文的3.3.3节中详细阐述）
 *  ，即移动的实际位数为：j - next[j]，且此值大于等于1。
 *
 * 失配时，模式串向右移动的位数为 = 已匹配字符数 - 失配字符的上一位字符所对应的最大长度值
 *
 */
int KMP(string src, string pattern)
{
    int next[pattern.size()];

    getNext(pattern, next);

    int slen = src.size();
    int plen = pattern.size();

    int i =0, j = 0;
    while(i < slen && j < plen){
        if(j == -1 || src[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }

    if(j == plen)
        return i - j;

    return -1;
}

