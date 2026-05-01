#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream MyFile;

    // MyFile.open("path",ios:app ) // this is the append mode if your file exist and contain something it will open the file and append your new content to the file without remove the old content
    //when you use append the file file should be exist

    // MyFile.open("path",ios:out | ios:app ) if your file not exist it will creat it and append the content  without remove the old one

    MyFile.open("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp", ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << "#include <iostream>\n";
        MyFile << "using namespace std;\n";
        MyFile << "int main(){\n";
        MyFile << "cout<<\"that is so cool \"<<endl; \n";
        MyFile << "return 0;";
        MyFile << "}";

        MyFile.close(); // dont forget to close the file
    }

    return 0;
}