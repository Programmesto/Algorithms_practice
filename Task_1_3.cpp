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
    int rows = 0;
    void swap() {
        int t = rows;
        rows = col;
        col = t;
    }
};
Shape findShape(std::string text){
    int number = text.length();
    Shape shape;
    shape.rows = shape.col = std::round(sqrt(number));
    if (number > shape.rows * shape.col) {
        shape.col++;
    }
    return shape;
}
void fillEmptySpaces(std::string text, Shape shape, char filler = '*') {
    while (text.length() < shape.col*shape.rows) {
        text.push_back(filler);
    }
}

std::string encryptText(std::string text, Shape& shape) {
    std::cout << "\nEncryption started...\ngiven text:\n";
    for (int i = 0; i < shape.rows; i++) {
        for (int j = 0; j < shape.col; j++) {
            std::cout << text[i*shape.col + j] << " ";
        }
        std::cout <<"\n";
    }
    std::string encryptedText;
    for (int i = 0; i < shape.col; i++) {
        for (int j = 0; j < shape.rows; j++) {
            encryptedText.push_back(text[j*shape.col + i]);
        }
        encryptedText.push_back(' ');
    }
    
    std::cout << "encrypted text:\n" << encryptedText << "\n";
    shape.swap();
    return encryptedText;
}

int main() {

    std::string text;
    std::cout << "enter text:";
    std::getline(std::cin, text);

    for (int i = 0; i < 4; i++) {
        text = normalizeText(text);
        std::cout << "\nnormalized text:" << text << "\n";
        Shape shape = findShape(text);
        fillEmptySpaces(text, shape, ' ');

    
        text = encryptText(text, shape);

        text = normalizeText(text);
        std::cout << "\nnormalized text:" << text << "\n";
        Shape shape = findShape(text);
        fillEmptySpaces(text, shape, ' ');

        text = encryptText(text, shape);
    }


    return 0;
}