#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include<sys/stat.h>
using namespace std;

class Sender
{
    public:
        void IfNoColumnFilterPassed(fstream& );
        void IfColumnFilterPassed(fstream& ,char** );
        string CommaCounter(string ,int );
        string PrintSelectedColumn(int ,int ,string ,int ,string );
        inline bool exists(const std::string& );
        void CheckIfTheFileExists(string& );
        void isFileOpen(fstream& ,string& );
        void isFileNamePassed(string& ); 
};
