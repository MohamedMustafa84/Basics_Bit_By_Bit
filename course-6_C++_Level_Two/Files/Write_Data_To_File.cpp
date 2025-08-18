#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream MyFile;

    // MyFile.open("path",ios:out ) // this is the write mode if your file exist and contain something it will open the file and remove the file content and make the file ready to the new content
    // if the file is not exist it will creat it 
    MyFile.open("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp", ios::out); 
    
    if(MyFile.is_open()){
        MyFile << "#include <iostream>\n";
        MyFile << "#include <fstream>\n";
        MyFile << "using namespace std;\n";
        MyFile << "int main(){\n";
        MyFile << "cout<<\"that is so cool \"<<endl; \n";
        MyFile << "return 0;";
        MyFile << "}";

        MyFile.close();//dont forget to close the file
    }

    return 0;
}