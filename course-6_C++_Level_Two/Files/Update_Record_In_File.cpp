#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void loadDataFromFileToVector(string FilePath, vector<string> &vFileContent)
{
    fstream MyFile;
    MyFile.open(FilePath, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string line;

        while (getline(MyFile, line))
        {
            vFileContent.push_back(line);
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

void saveVectorToFile(vector<string> &fileContent, string FilePath)
{
    fstream MyFile;

    MyFile.open(FilePath, ios::out);

    if (MyFile.is_open())
    {

        for (string &line : fileContent)
        {
            if (line != "")
            {
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }
}
void UpdateRecordInFile(string filePath, string Record,string RecordTo)
{

    vector<string> vfileContent;
    
    loadDataFromFileToVector(filePath, vfileContent);

    for (string &line : vfileContent)
    {
        if (line == Record)
        {
            line = RecordTo;
        }
    }

    saveVectorToFile(vfileContent, filePath);
}

int main()
{

    cout << "File Content Before Updating The Record:" << endl;
    PrintFileContent("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp");

    UpdateRecordInFile("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp", "ali","khalid");

    cout << "File Content After Updating The Record:" << endl;
    PrintFileContent("f:/Programing/C++/ProgramingAdvices/course-6/myfile.cpp");

    return 0;
}