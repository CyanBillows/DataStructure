#include <iostream>

using namespace std;
void get_next(const char patt[],int next[],int length){
    int i=1;
    next[0] = 0; //next首位默认0
    int pre_length = 0;
    while(i < length){
        if(patt[pre_length] == patt[i]){ //从第二位开始寻找最大相同前后缀，i只右移，pre_length变动
            ++pre_length;
            next[i] = pre_length;
            ++i;
        } else {
            if(pre_length == 0) {
                next[i] = 0;
                ++i;
            } else { //通过已知最大前后缀跳过重复检查
                pre_length = next[pre_length - 1];
            }
        }
    }
}

int kmp(const char str[],char patt[],int s_len,int p_len)
{
    int i=0,j=0;
    int next[p_len];
    get_next(patt,next,p_len);
    for(int k=0;k<p_len;k++){
        cout << "next:" << next[k] << endl;
    }
    while(i < s_len) {
        if(patt[j] == str[i]){
            i++;
            j++;
        } else if (j > 0) { //非首字符不匹配
            j = next[j-1];
        } else { //开始首字符就不匹配,只右移主串指针
            i++;
        }
        if(j == p_len) { //匹配成功
            return i-j;
        }
    }
    return -1;
}

int main() {
    char str[20] = "aaacaaaab";
    char patt[10] = "aaaab";
    cout << kmp(str,patt,9,5);
    return 0;
}
