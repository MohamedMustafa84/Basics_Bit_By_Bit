#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void saveVectorToFile( vector <string> &vContent, string FilePath){
    fstream MyFile;

    MyFile.open(FilePath, ios::out);

    if(MyFile.is_open()){

        for(string &line:vContent){
            if(line!=""){
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }

}

void PrintFileContent(string FilePath)
{
    fstream Myfile;
    Myfile.open(FilePath, ios::in); // Read Mode

    if (Myfile.is_open())
    {

        string Line;
        while (getline(Myfile, Line))
        {
            cout << Line << endl;
        }

        Myfile.close();
    }
}

int main(){
    vector<string> vContent = {"Ahmed", "ali", "Mohamed", "nader", "fatima"};

    saveVectorToFile(vContent, "f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp");

    PrintFileContent("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp");

    return 0;
}