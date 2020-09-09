#include <iostream>
#include <string>                               // for strings
#include <cstring>                              // for strtok()
#include <fstream>                              // for file streams

using namespace std;

struct enrollee
{
    string date = "";
    string comment = "";
    
};

int main()
{
    const int ENROLL_SIZE = 1000;               // used const instead of #define since the performance diff is negligible,
    //const int numCols = 2;                    // while const allows for greater utility/debugging bc it is known to the compiler ,
                                                // while #define is a preprocessor directive
    ifstream inputFile;                         // create input file stream for reading only
    struct enrollee enrollArray[ENROLL_SIZE];   // array of structs to store each enrollee and their respective data
   

    // open the input file to read
    inputFile.open("sample-review/review-report.csv");
    // read the file until we reach the end
    while(!inputFile.eof())
    {
        //string inputBuffer;                         // buffer to store input, which will hold an entire excel row w/ cells delimited by commas
                                                    // must be a c string since strtok() only takes c string as input
       //string tokensArray[numCols];
        string date = "";
        string comment = "";
        

        getline(inputFile,date,',');
        getline(inputFile,comment);
        
 
        enrollArray[0].date = date;
        enrollArray[0].comment = comment;
        

        //cout << "date is: " << enrollArray[0].date;
        cout << enrollArray[0].comment;
        
    }
}
