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
void PrintSelectedColumn(string ,int);

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
    string line, word,temp; 
  
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
        PrintSelectedColumn(line,SelectedColumn);
    }
}
void PrintSelectedColumn(string line,int SelectedColumn)
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
        if(CommaCount==SelectedColumn)
        cout<<line[i];
        
    }
    cout<<endl;
}
