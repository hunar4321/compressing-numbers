#include "digit_length.h"

int main(int argc, const char* argv[]) {

    std::vector<int32_t> numbers = { 1,2,3,54,3,5667,23,1,2,4,56, 39484, 492837, 2,3,45,7263, 476, 2,1,20 ,0, 0, 230, 94, 2930, 3948, 4,5, 6, 3,40,6 };

    std::vector<int8_t> lengths = DigitLengths(numbers);
    auto string_digits = NumToString(numbers);
    auto compressed = CompactVec(string_digits);

    int32_t uncompressed_size = numbers.size() * 32;
    int32_t compressed_size = compressed.size() * 32 + lengths.size() * 8;

    std::cout << "ratio: " << (double)compressed_size / (double)uncompressed_size << std::endl;

    // reconstructing numbers
    string_digits = NumToString(compressed);
    auto numbers2 = StringToNums(&string_digits, &lengths);

    // test:
    bool passed = true;
    if (numbers.size() == numbers2.size()) {
        for (int i = 0; i < numbers2.size(); i++) {
            if (numbers[i] != numbers2[i]) {
                passed = false;
                break;
            }
        }
    }
    else { passed = false; }

    std::cout << "Test Passed?:" << passed << std::endl;


    //for (auto a : numbers2) {
    //    std::cout << a << std::endl;
    //}


    return 0;
}
