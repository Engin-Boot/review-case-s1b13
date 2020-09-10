#include <iostream>
#include <string>                               // for strings
#include <cstring>                              // for strtok()
#include <fstream>                              // for file streams
#include<stdlib.h>                      

using namespace std;
struct RowData
{
    string date = "";
    string comment = "";
    
};
void DummyFunction(int ,char**);
void PrintSpecificFunction(int,RowData* RowArray);


int main(int argc,char *argv[])
{
    DummyFunction(argc,argv);
    
}
void DummyFunction(int argc,char *argv[])
{
    const int ARRAY_SIZE = 1000;               // used const instead of #define since the performance diff is negligible,
    
    ifstream inputFile;                         // create input file stream for reading only
    struct RowData RowArray[ARRAY_SIZE];   // array of structs to store each Row from CSV file and their respective data
   

    // open the input file to read
    inputFile.open("sample-review/review-report.csv");
    // read the file until we reach the end
    int ColumnNumber = atoi(argv[1]);
    
    while(!inputFile.eof())
    {
        
        string date = "";
        string comment = "";
        

        getline(inputFile,date,',');
        getline(inputFile,comment);
        
 
        RowArray[0].date = date;
        RowArray[0].comment = comment;
        
    if(argc==2)
    {
        PrintSpecificFunction(ColumnNumber,&RowArray[0]); 
    }else
    { 
        cout << RowArray[0].comment<<" ";
    }
    }
    
}
void PrintSpecificFunction(int ColumnNumber,RowData RowArray[])
{
    switch(ColumnNumber)
        {
            case 1:
                    cout << RowArray[0].date<<" ";
                    break;
            case 2:
                    cout<<RowArray[0].comment<<" ";
                    break;
            default:
                    cout<<RowArray[0].date<<" ";
                    cout<<RowArray[0].comment<<" ";
                    break;
        }
}
