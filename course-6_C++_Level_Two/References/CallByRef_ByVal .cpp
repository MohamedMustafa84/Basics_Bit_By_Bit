#include <iostream>
using namespace std;

void addOneToNumber(int byValue){
    byValue++;
}
 void addTwoToNumber(int &x){
     x+= 2;
 }

int main(){
    
    // -----------ByVal
    int byValue = 10;
    addOneToNumber(byValue);
    cout <<"the number value is after addingOneFunction is " <<byValue <<" coz it send by value the value not changed " <<endl;
    
    // ------------------ Byref
    // when use by Ref the compiler go to the same variable location at the memory and give it alias and you can use the alias name to access the same variable and modifier it 

    int ByRef = 10;
    addTwoToNumber(ByRef);
    cout <<"the number value is addTwoToNumber Function is " <<byValue <<" coz it send by Ref the " <<endl;
    // the location in memory represent by Ox Number 
    cout << "The Variable Location at The Memory is  " << &ByRef << endl; 

    return 0;
}
