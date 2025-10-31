#include <iostream>
#include <string>

class Solution {
public:
    int numDifferentIntegers(std::string word) {
    std::string value = word;
    
        
    
    
    return -1;
    }
};

bool CalcChar(char val){
    return (val >= 97 && val <= 122)?1:0;
}

int main(){
    Solution s;
     //s.numDifferentIntegers("a1");
    //const char* str = "a2b34p";
    std::string str = "a1b01c001";
     for(int i = 0;i < str.length();i++){
        if(CalcChar(str[i]))str[i] = ' ';
     }
     int val = 0;
     while(val <= 3){
        std::string value = str.substr(str.find(' '));
        std::cout<<value;
      val++;
     }
     



}


