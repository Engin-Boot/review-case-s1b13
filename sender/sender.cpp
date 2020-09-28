#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include<sys/stat.h>
#include "Sender.h"
using namespace std;

void Sender::isFileNamePassed(string& SecondArgument)
{
    string s2 = ".csv";
    if (!(SecondArgument.find(s2) != string::npos)) 
    {
        cout << "File Name Not passed" << '\n';
        exit(0);
    }
}

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

int main(int argc,char *argv[])
{
    Sender s;
    fstream fin; 
    string FileName = argv[1];
    s.isFileNamePassed(FileName);
    s.CheckIfTheFileExists(FileName);
    s.isFileOpen(fin,FileName);
    if(argc==2 && (FileName.find(".csv") != string::npos))
    {
        s.IfNoColumnFilterPassed(fin);
    }
    else
    {
       s.IfColumnFilterPassed(fin,argv);
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
    string MyString;
    string TempMyString;
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
   cout<<MyString<<" ";
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
