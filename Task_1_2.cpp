#include <iostream>
#include <string>
bool isQuestion(std::string str) {
    return (str[str.length() - 1] == '?'); 
}
bool isScreaming(std::string str) {
    bool hasLetter = false;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            hasLetter = true;
            if (islower(str[i]))
                return false;
        }
    }
    if (hasLetter) {
        return true;
    }
    else {
        return false;
    }
}
bool isEmpty(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

void ansBob(std::string str) {
    std::cout << str << std::endl;
}
void askBob(std::string phrase) {
    std::string answer;
    if (isQuestion(phrase)) {
        if (isScreaming(phrase)) {
            ansBob("Calm down, I know what I'm doing!");
        }
        else {
            ansBob("Sure.");
        }
    }
    else {
        if (isScreaming(phrase)) {
            ansBob("Whoa, chill out!");
        }
        else {
            if (isEmpty(phrase)) {
                ansBob("Fine. Be that way!");
            }
            else {
                ansBob("Whatever.");
            }
        }
    }
}
int main() {
    std::string str;
    while (str != "Go away, Bob!") {
        std::getline(std::cin, str);
        askBob(str);
    }
    return 0;
}
