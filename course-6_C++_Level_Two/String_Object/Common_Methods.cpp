#include <iostream>
#include <string>
using namespace std;


int main(){
    string S1 = "My Name IS Mohamed Mustafa ,I Love Programming ";


    // print the length og the string
    cout << "string Length :" << S1.length();

    // return the letter at position 3
    cout << "\nthe letter at position 3 :" << S1.at(3);

    // add string to the end
    S1.append(" @ProgrammingAdvices");
    cout << S1 << endl;
    
    // insert Ali at position 7
    S1.insert(7, " Ali ");
    cout << S1 << endl;
    
    // print all next character from position 16
    cout << S1.substr(16, 8) << endl;
    
    //add one character to the end of the string
    S1.push_back('X');
    cout << S1 << endl;
    
    // remove one character from the end of the string
    S1.pop_back();
    cout << S1 << endl;

    // find Ali in the string case sensetive
    cout << S1.find("Ali")<<endl;
    
    // find Ali in the string
    cout << S1.find("ali") << endl;
    
    if(S1.find("ali")==S1.npos)//if ali  unexists[no position]
    {
        cout << "Ali is Not Found";
    }
    //Clear All String Letters
    S1.clear();

    cout << S1 << endl;

    return 0;
}