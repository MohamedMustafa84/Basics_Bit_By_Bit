#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
    char Letter;
    cout << "please Enter a Character : ";
    cin >> Letter;
    return Letter;
}
// ------- solution 1-------

bool isVowel(char character){
    switch (character)
    {
    case 'a':
        return true;

    case 'e':
        return true;
    case 'i':
        return true;
    case 'o':
        return true;
    case 'u':
        return true;

    default:
        return false;
    }
}

// ----- solution2-----
bool isVowelCharacter(char character){
    string Vowels = "aeiou";
    for(short i=0;i<Vowels.length();i++){
        if(character == Vowels[i]){
            return true;
        }
    }
    return false;
}

// ----- solution3-----

bool is_Vowel_Character(char Char)
{
    return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
}

    int
    main()
{
    
    // Problem
    // write a program to  read a character then check if  it is a vowel or not  (Vowel are : a e i o u)

    char character = ReadCharacter();

    // ----- solution1-----
    cout << (isVowel(character) ? "Yes the letter is Vowel" : "No the letter is Not Vowel") << endl;
    
    
    // ----- solution2-----
    if(isVowelCharacter(tolower(character))){
        cout << "Yes letter" <<character<<"  is Vowel" << endl;
    }else{
        cout << "No letter" <<character<<"  is Not Vowel" << endl;
    }

    // ----- solution3-----
    if (is_Vowel_Character(tolower(character)))
    {
        cout << "Yes letter" << character << "  is Vowel" << endl;
    }
    else
    {
        cout << "No letter" << character << "  is Not Vowel" << endl;
    }

    return 0;
}