#include <iostream>
#include <cctype>
using namespace std;


int main(){
    char x;
    char w;

    x = toupper('a');
    w = tolower('A');

    cout << "converting a to A: " << x << endl;
    cout << "converting A to a: " << x << endl;

    // uppercase (A to Z)
    //  return zero if not , and none zero if yes
    cout << "isupper('A) :" << isupper('A') << endl;
    
    // lowerCase
    //  return zero if not , and none zero if yes
    cout << "islower('a') : " << islower('a') << endl;
    
    // Digit (0 to 9)
    //  return zero if not , and none zero if yes
    cout << "isdigit('9')" << isdigit('9') << endl;
    
    // punctuation characters are !*&^$#@%()|_-,<>?:;~[]{\}+
    //  return zero if not , and none zero if yes
    cout << "ispunct(':'): " << ispunct(':') << endl;

    return 0;
}