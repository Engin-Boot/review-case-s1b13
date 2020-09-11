#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


using namespace std;
void IfNoArgumentsPassed(fstream&);
void IfArgumentsPassed(fstream&  ,char**);
void CommaCounter(string ,int);
void PrintSelectedColumn(int ,int ,string ,int);

int main(int argc,char *argv[])
{
    fstream fin; 
    fin.open("sample-review/review-report.csv", ios::in);
    if(argc==1)
    {
        IfNoArgumentsPassed(fin);
    }
    else
    {
       IfArgumentsPassed(fin,argv);
    }    
    
}
void IfNoArgumentsPassed(fstream& fin)
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
void IfArgumentsPassed(fstream& fin,char *argv[])
{
    string line; 
    
    int SelectedColumn = atoi(argv[1])-1;
    
    
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
