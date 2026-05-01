#include <iostream>
using namespace std; 
#include "ClsMyString.h"




int main(){

    cout << "\n\n\n\t\t\t\\t Undo/Redo Project \n";

    clsMyString S1;

    S1.SetValue("mohamed1") ;

    cout <<"S1 = "<< S1.Value() << "\n";
    
    S1.SetValue("mohamed2");
    
    cout <<"S1 = "<< S1.Value() << "\n";
    
    S1.SetValue("mohamed3");
    
    cout <<"S1 = "<< S1.Value() << "\n";

    cout << "\n------------------------------\n";
    cout << "\n\nUndo : ";
    
    S1.Undo();
    
    cout << "\nS1 After Undo = " << S1.Value() << "\n";

    S1.Undo();

    cout << "\nS1 After Undo = " << S1.Value() << "\n";
    S1.Undo();

    cout << "\nS1 After Undo = " << S1.Value() << "\n";

    cout << "\n------------------------------\n";
    cout << "\n\nRedo : ";

    S1.Redo();

    cout << "\nS1 After Redo = " << S1.Value() << "\n";

    S1.Redo();

    cout << "\nS1 After Redo = " << S1.Value() << "\n";

    S1.Redo();

    cout << "\nS1 After Redo = " << S1.Value() << "\n";


    return 0;
}