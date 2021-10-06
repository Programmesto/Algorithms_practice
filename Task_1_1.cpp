#include <iostream>
#include <string>

bool isIsogram(std::string str) {
    
    for (int i = 0; i < str.length(); i++) {
        str[i] = std::tolower(str[i]);
        if (std::isalpha(str[i])) {         //((str[i] > 'a') && (str[i] < 'z'))
            for (int j = 0; j < i; j++) {
                if (str[i] == str[j]) 
                    return false;
            }
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << isIsogram(str) <<std::endl;
    
}