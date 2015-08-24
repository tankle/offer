#include <string>


/**
 *
 * 字符串替换题目
 * char* replace(const char* orginal,
            const char* sub,
            const char* replace);
            /**
            orginal="abcabc1234"
            sub="ab",
            replace="xyz"
            将orginal中出现sub串替换为replace串

 */
string replace(const string& str, const string& sub, const string repstr){
    string tmp;
    string::size_type len1 = sub.size();
    string::size_type pre = 0;
    string::size_type pos = 0;
    while ((pos = str.find(sub, pos)) != string::npos){ //寻找下一个sub串的起始位置
        tmp += str.substr(pre, pos - pre);//求字串
        tmp += repstr;
        pos += len1;
        pre = pos;
    }
    tmp += str.substr(pre, str.size() - pre);
    return tmp;
}