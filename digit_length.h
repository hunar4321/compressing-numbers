
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

//int main(int argc, const char * argv[]) {
//    
//    std::vector<int32_t> numbers={1,2,3,54,3,5667,23,1,2,4,56, 39484, 492837, 2,3,45,7263, 476, 2,1,20 ,0, 0, 230, 94, 2930, 3948, 4,5, 6, 3,40,6};
//    
//    std::vector<int8_t> length = DigitLengths(numbers);
//    
//    auto dict = NumToString(numbers);
//    
//    auto compressed = CompactVec(dict);
//
//    std::cout<< "size1:" << numbers.size() << std::endl;
//    std::cout<< "size2:" << compressed.size() << std::endl;
//    
//    // reconstruct numbers
//    // backt o string
//    std::cout << "back to strings:" << std::endl;
//    auto dict2 = NumToString(compressed);
//    
//    auto numbers2 = StringToNums(&dict2, &length);
//    for(auto a: numbers2){
//        std::cout << a << std::endl;
//    }
//    
//
//    return 0;
//}
