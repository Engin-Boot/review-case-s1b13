#include <iostream>
#include <string>                               // for strings
#include <cstring>                              // for strtok()
#include <fstream>                              // for file streams

using namespace std;

struct RowData
{
    string date = "";
    string comment = "";
    
};

int main()
{
    const int ARRAY_SIZE = 1000;               // used const instead of #define since the performance diff is negligible,
    
    ifstream inputFile;                         // create input file stream for reading only
    struct RowData RowArray[ARRAY_SIZE];   // array of structs to store each Row from CSV file and their respective data
   

    // open the input file to read
    inputFile.open("sample-review/review-report.csv");
    // read the file until we reach the end
    while(!inputFile.eof())
    {
        
        string date = "";
        string comment = "";
        

        getline(inputFile,date,',');
        getline(inputFile,comment);
        
 
        RowArray[0].date = date;
        RowArray[0].comment = comment;
        

        
        cout << RowArray[0].comment<<" ";
        
    }
}
