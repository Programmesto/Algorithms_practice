#include <iostream>
#include <string>


int main() {
    std::string str;
    std::cin >> str;
    int n;
    std::cin >> n;
    
    std::string substr;
    for (int i = 0; i < str.length() - (n-1); i++) {
        for (int j = 0; j < n; j++) {
            substr.push_back(str[i+j]);
        }
        substr.push_back(' ');
        //std::cout << str.substr(i, n) << " ";
    }
    std::cout << substr;

    return 0;
}