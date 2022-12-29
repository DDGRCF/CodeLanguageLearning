#include <vector>
#include <iostream>
#include <string>
#include <ctime>

using std::string;
using std::vector;
using std::cout;
using std::endl;

template<typename T>
string join(vector<T> input, string delim) {
    string output = "";
    int i = 0;
    for (auto & elem : input) {
        i++;
        if (i == input.size()) {
            output += std::to_string(elem);
        } else {
            output += (std::to_string(elem) + delim);
        }
    }
    return output;
}


vector<int> rand_vector(size_t len, const size_t max = 10) {
    std::vector<int> input(len);
    for (auto i = 0; i < len; i++) {
        input[i] = std::rand() % max;
    }
    return input; 
}