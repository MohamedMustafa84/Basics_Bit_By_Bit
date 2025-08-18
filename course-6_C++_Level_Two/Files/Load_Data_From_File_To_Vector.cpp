#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void loadDataFromFileToVector(string FilePath,vector <string>& vFileContent){
    fstream MyFile;
    MyFile.open(FilePath, ios::in);//read Mode

    if(MyFile.is_open()){
        string line;

        while(getline(MyFile,line)){
            vFileContent.push_back(line);
        }
        MyFile.close();
    }
}


int main(){
    vector<string> vFileContent;

    loadDataFromFileToVector("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp", vFileContent);

    // print file content

    for(string &line :vFileContent){
        cout << line << endl;
    }
}