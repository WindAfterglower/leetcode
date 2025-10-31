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






