#define CATCH_CONFIG_MAIN  
#include "../catch.hpp"
#include "../sender/Sender.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
Sender s;
inline bool exists(const std::string& filename){
  struct stat buffer;   
  return (stat (filename.c_str(), &buffer) == 0); 
}
bool CheckIfTheFileExists(string& FileName)
{
    bool exist = exists(FileName);
    if(exist == false)
    {
        cout<<"File does not exists"<<endl;
        
    }
    return exist;
}

TEST_CASE("WHEN we pass to function a CSV line containing date & comment and if we need comment part THEN it returns Comment part")
{    
    string ExampleCSVString = "10/23/45 23:45,No additional comments";    
    string return_string = s.CommaCounter(ExampleCSVString,1);    
    REQUIRE(return_string == "No additional comments");
}
TEST_CASE("WHEN we pass to function a CSV line containing date & comment and if we need date part THEN it returns date part")
{    
    string ExampleCSVString = "10/23/45 23:45,No additional comments";    
    string return_string = s.CommaCounter(ExampleCSVString,0);    
    REQUIRE(return_string == "10/23/45 23:45");
}
TEST_CASE("WHEN we pass the filename to the function THEN it returns if the file exists or not")
{
    string FileName = "sample-review/review-report.csv";
    bool FileExists = CheckIfTheFileExists(FileName);
    REQUIRE(FileExists == true);
}
TEST_CASE("WHEN we pass the filename to the function THEN it returns if the file  not")
{
    string FileName = "sample-review/review-report1.csv";
    bool FileExists = CheckIfTheFileExists(FileName);
    REQUIRE(FileExists == false);
}

 
