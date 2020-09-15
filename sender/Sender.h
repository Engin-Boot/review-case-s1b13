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
        void CommaCounter(string ,int );
        char PrintSelectedColumn(int ,int ,string ,int );
        inline bool exists(const std::string& );
        void CheckIfTheFileExists(string& );
        void isFileOpen(fstream& ,string& );
};
