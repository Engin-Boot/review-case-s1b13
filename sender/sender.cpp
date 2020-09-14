#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include<sys/stat.h>

using namespace std;
void IfNoColumnFilterPassed(fstream&);
void IfColumnFilterPassed(fstream&  ,char**);
void CommaCounter(string ,int);
void PrintSelectedColumn(int ,int ,string ,int);
inline bool exists(const std::string& filename){
  struct stat buffer;   
  return (stat (filename.c_str(), &buffer) == 0); 
}
void CheckIfTheFileExists(string& FileName)
{
    bool exist = exists(FileName);
    if(exist == false)
    {
        cout<<"File does not exists"<<endl;
        exit(0);
    }
    
}
void isFileOpen(fstream& fin,string& fileName)
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
    fstream fin; 
    string FileName = argv[1];
    CheckIfTheFileExists(FileName);
    isFileOpen(fin,FileName);
    
    if(argc==2)
    {
        IfNoColumnFilterPassed(fin);
    }
    else
    {
       IfColumnFilterPassed(fin,argv);
    }    
    
}
void IfNoColumnFilterPassed(fstream& fin)
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
void IfColumnFilterPassed(fstream& fin,char *argv[])
{
    string line; 
    
    int SelectedColumn = atoi(argv[2])-1;
 
    while(getline(fin, line))
    {
        CommaCounter(line,SelectedColumn);
    }
}
void CommaCounter(string line,int SelectedColumn)
{
    int CommaCount=0;
    CommaCount=0;
    int size;
    size=line.size();

    for(int i=0;i<size;i++)
    {          
        if(line[i]==',')
        {
            CommaCount++;
            continue;
        }
        PrintSelectedColumn(CommaCount,SelectedColumn,line,i);
        
    }
   cout<<" ";
}
void PrintSelectedColumn(int CommaCount,int SelectedColumn,string line,int i)
{
    
   if(CommaCount==SelectedColumn)
        cout<<line[i];
    
}
