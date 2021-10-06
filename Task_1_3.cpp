#include <iostream>
#include <string>
#include <math.h>




std::string normalizeText(std::string text) {
    std::string normString;
    for (auto ch: text) {
        if (isalpha(ch)) {
            normString.push_back(tolower(ch));
        }
    }
    return normString;
}
struct Shape
{
    int col = 0;
    int str = 0;
};
Shape findShape(int number){
    Shape shape;
    shape.str = shape.col = std::round(sqrt(number));
    if (number > shape.str * shape.col) {
        shape.col++;
    }
    return shape;
}

int main() {
    std::string text;
    std::cout << "enter text:";
    std::getline(std::cin, text);
    text = normalizeText(text);
    std::cout << "\nnormalized text:" << text << "\n";
    

    return 0;
}