## 前言

这一节，主要是Leetcode中的数学基础算法。

## 7.整数反转

地址:[7. 整数反转 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-integer/description/)

>  2025/10/31 个人思路
>
> 最开始的思路：将这个整数转化为字符串，然后用一个字符串倒序记录，最后再将这个字符串转化为整数。

代码:

```c++
int reverse(int x){
    std::string _tempStr = std::to_string(x);
    std::string realStr;
    char _tempChar[] = "";
    for(long long i = _tempStr.size()-1;i >=0;i--) 
    realStr += _tempStr[i];
    
    int result = std::stoi(realStr);
    return (x < 0) ? (-1 * result) : result;
   
    }
```

好，然后我因为没有注意到题干中: 

> 如果反转后整数超过 32 位的有符号整数的范围 `[−231, 231 − 1]` ，就返回 0。

没有对过大数的处理，去返回0，导致报错`terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi`，很显然，转化的数字超出了`stoi`的处理范围，导致抛出异常。



解决办法呢?

我丢给AI后，AI给出的答案是:

```c++
int reverse(int x){

    std::string _tempStr = std::to_string(x);
    std::string realStr;
    char _tempChar[] = "";
    for(long long i = _tempStr.size()-1;i >=0;i--) 
    realStr += _tempStr[i];
    
    try {
        int result = std::stoi(realStr);
        return (x < 0) ? (-1 * result) : result;
    }
    catch (const std::out_of_range& e) {
        return 0;
    }

    }
```

直接用`Try Catch`捕获异常，然后返回。

这个解法可以正确通过测试，但是后果是时间复杂度与空间复杂度均为O(N)。算是不错的了。

然后看大佬题解：

> 反转数字，我们首先想到的就是**取余**，但是可能会遇到反转后，数字超过了最大限制或最小限制。
>
> 所以我们可以**一边反转，一边检测**，这样做的话，若遇到问题，将会立即停止。
>

我和大佬的差距是如此之大！！！

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

作者：御三五 🥇
链接：https://leetcode.cn/problems/reverse-integer/solutions/657471/tu-jie-guan-fang-tui-jian-ti-jie-zheng-s-rh6b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

关于大佬思路中的:`7和 -8`

- `INT_MAX = 2147483647`，个位数是7
- `INT_MIN = -2147483648`，个位数是8

## 8.回文数

地址：[9. 回文数 - 力扣（LeetCode）](https://leetcode.cn/problems/palindrome-number/description/)

> 思路：因为数学的取余和除法可以取得整数的某位上的数，所以用这个方法来分解整数，然后再用一个整数去复原倒过来的整数。
>
> 就是将 123 转化为 321
>
> 不过第一次提交时，忘记考虑0，负数和整数大小范围了

```c++
bool isPalindrome(int x) {
    long long temp = 0; //long long 是为了整数的大小
    long long _bx = x; //用unsigned int 会消去负号啊!
    while(x != 0){
        temp = temp*10 + x%10;
        x/=10;
    }
    
    return (_bx>=0)? (_bx== temp):0; //为了应对负数和0
}
```

## 1805.字符串中不同整数的数目

```c++
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<set>

class Solution {
public:

    bool CalcChar(char val) {
        return (val >= 97 && val <= 122) ? 1 : 0;
    }

    int numDifferentIntegers(std::string word) {
    
        std::vector<std::string> tempVec;
        tempVec.reserve(1024);
        std::string tempStr = "";

        for (int i = 0; i <= word.length(); i++) {

            if (CalcChar(word[i]) || i == word.length()) {
                if (tempStr.length() != 0) {
                    tempVec.push_back(tempStr);
                }
                tempStr = "";
                word[i] = ' ';
                continue;
            }

            tempStr += word[i];
        }
        for (int i = 0; i < tempVec.size();i++) {
            int tempIndex = tempVec[i].find_first_not_of('0');
           
            tempVec[i].replace(0, tempIndex, (tempIndex != std::string::npos ?"":"0"));
        }
        
        std::sort(tempVec.begin(), tempVec.end());
        auto vx = std::unique(tempVec.begin(), tempVec.end());
        tempVec.erase(vx, tempVec.end());

       return tempVec.size();

    }
};



int main(){
    Solution s;
    std::string str = "000a";
    std::cout<< s.numDifferentIntegers(str);
    }
```

