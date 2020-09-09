#include<fstream>
#include<iostream>
#include<map>
using namespace std;
int main
{
std::unordered_map<string, int> wordFreq;
string line="";
while(getline(cin,line))
{
if(line=="")
{
break;
}
storeFrequencies(line,wordFreq);

}
 unordered_map<string, int>:: iterator p; 
 for (p = wordFreq.begin(); p != wordFreq.end(); p++) 
        cout << "(" << p->first << ", " << p->second << ")\n"; 

}
void storeFrequencies(const string &str,std::unordered_map<string, int> wordFreq) 
{ 
  
  
   
    stringstream ss(str); 
    string word;
    while (ss >> word) 
        wordFreq[word]++; 
   
} 
