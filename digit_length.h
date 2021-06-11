
#include <iostream>
#include <vector>
#include <string>

std::string NumToString(std::vector<int32_t> numbers){
    std::string dict = "";
    for(int32_t i=0; i<numbers.size(); i++){
        dict += std::to_string(numbers[i]);
    }
    return dict;
}

std::vector<int32_t> CompactVec(std::string strnum){
    int shift = 9;
    std::vector<int32_t> vec;
    int32_t c = 0;
    while(c < strnum.size()){
        if(c+shift >= strnum.size()){
            shift = strnum.size()-c; // final shift
        }
        
        auto cs = strnum[c];
        if(cs == '0'){
            vec.push_back(0);
            c++;
        }else{
            std::string chunk = "";
            for(int i=0; i<shift; i++){
                chunk += strnum[c+i];
            }
            c += shift;
            vec.push_back(std::stoi(chunk));
        }
    }
    return vec;
}

std::vector<int32_t> StringToNums(std::string *str, std::vector<int8_t> *poses){
    
    int32_t c = 0;
    std::vector<int32_t> numbers2;
    for(int32_t i= 0; i < poses->size(); i++){
        std::string temp = "";
        for(int j=0; j< (*poses)[i]; j++){
            temp += (*str)[c];
            c++;
        }
        numbers2.push_back(std::stoi(temp));
    }
    return numbers2;
}

short int DigitLength(int32_t digit){
    short int digit_length = 0;
    do{
        ++digit_length;
        digit /= 10;
    }while(digit);
    return digit_length;
}

std::vector<int8_t> DigitLengths(std::vector<int32_t> digits){
    std::vector<int8_t> lens;
    for(int32_t i=0; i<digits.size(); i++){
        int short len = DigitLength(digits[i]);
        lens.push_back(len);
    }
    return lens;
}


