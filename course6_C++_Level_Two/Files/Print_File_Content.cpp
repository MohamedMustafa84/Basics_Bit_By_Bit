#include <iostream>
#include <fstream>
using namespace std;



void PrintFileContent(string FilePath){
    fstream Myfile;
    Myfile.open(FilePath, ios::in); // Read Mode

    if(Myfile.is_open()){

        string Line;
        while(getline(Myfile,Line)){
            cout << Line << endl;
        }

        Myfile.close();
    }
}

int main(){
    PrintFileContent("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp");
    return 0;
}
