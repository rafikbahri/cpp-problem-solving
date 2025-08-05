#include <iostream>

using namespace std;

int main(){
    double x = 9.99;
    long y = 9000L; // needs the L to tell the compiler it's a long number
    int a = 1;
    float b = 3.33f; // same with the f to tell it's a float, if we don't put f, the compiler treat it as a double
    char letter = 'a';
    bool isValid = true;
    auto aut = false; // the compiler ifers the type
    // brace initalizer
    int number {}; // initialized to 0
    int randomInitialized; // randomly intilialized
    cout << number << endl;
    cout << randomInitialized << endl;
    const int constantInt = 100;
    int binaryNumber = 0b111111;
    cout << binaryNumber << endl;
    int hexNumber = 0xff;
    cout << hexNumber << endl;
    // narrowing
    int million = 1'000'000;
    short shortMillion = million; // results in faulty conversion because short can't contain 1 million
    // short shMillion{million}; // brace initialize prevents it -> error;
    cout << shortMillion << endl;
    // cout << shMillion << endl;
    return 0;
}