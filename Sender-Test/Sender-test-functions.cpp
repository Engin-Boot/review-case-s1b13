#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include<sys/stat.h>
#include "../sender/Sender.h"
using namespace std;

inline bool Sender::exists(const std::string& filename){
  struct stat buffer;   
  return (stat (filename.c_str(), &buffer) == 0); 
}
void Sender::CheckIfTheFileExists(string& FileName)
{
    bool exist = exists(FileName);
    if(exist == false)
    {
        cout<<"File does not exists"<<endl;
        exit(0);
    }
    
}
void Sender::isFileOpen(fstream& fin,string& fileName)
{
    fin.open(fileName.c_str(),ios::in);
	if(!fin.is_open())
    {
        cout << "File cannot be opened" << endl;
		exit(0);
    }
    
}
void Sender::IfNoColumnFilterPassed(fstream& fin)
{
    string line; 
  
        while (!fin.eof()) 
        { 
            while(getline(fin,line,',')) 
            { 
                cout<<line<<" "; 
            }
      
        }
}
void Sender::IfColumnFilterPassed(fstream& fin,char *argv[])
{
    string line; 
    
    int SelectedColumn = atoi(argv[2])-1;
 
    while(getline(fin, line))
    {
        PrintSelectedColumn(line,SelectedColumn);
    }
}
string Sender::PrintSelectedColumn(string line,int SelectedColumn)
{
    int CommaCount=0;
    CommaCount=0;
    int size;
    size=line.size();
    string MyString = "";
    string TempMyString = "";
    for(int i=0;i<size;i++)
    {          
        if(line[i]==',')
        {
            CommaCount++;
            continue;
        }
        TempMyString =  ReturnSelectedColumnData(CommaCount,SelectedColumn,line,i,MyString);
        MyString = TempMyString;
        
    }
   
   //cout<<MyString<<" ";
   return MyString;
}
string Sender::ReturnSelectedColumnData(int CommaCount,int SelectedColumn,string line,int i,string MyString)
{
   if(CommaCount==SelectedColumn)
   {
        MyString.push_back(line[i]);
    }
    return MyString;
}
