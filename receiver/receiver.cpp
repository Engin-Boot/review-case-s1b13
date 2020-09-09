
#include<fstream>
#include<iostream>
#include<map>
using namespace std;
map<std::string,int> countWords(map<std::string,int>,string );

int main()
{
 map<string, int> M; 
string line="";
while(getline(cin,line))
{
if(line=="")
{
break;
}
 map<string, int> tempMap=countWords(M,line);
  M=tempMap;
    
}
 
return 0;
}
void printwordandwordcounts(map<std::string,int> M)
{
 for (auto& it : M) { 
        cout << it.first << " - "
             << it.second 
             << endl; 
    } 
}
map<std::string,int> countWords(map<std::string,int> M,string line)
{
// String for storing the words 
    string word = ""; 
  
    for (int i = 0;line[i]!='\0'; i++) { 
  
     
        if (line[i] == ' ') { 
  
            // If the current word 
            // is not found then insert 
            // current word with frequency 1 
            if (M.find(word) == M.end()) { 
                M.insert(make_pair(word, 1)); 
                word = ""; 
            } 
  
            // update the frequency 
            else { 
                M[word]++; 
                word = ""; 
            } 
        } 
  
        else
            word += line[i]; 
    } 
  
    // Storing the last word of the string 
    if (M.find(word) == M.end()) 
        M.insert(make_pair(word, 1)); 
  
    // Update the frequency 
    else
        M[word]++; 
 return M;
}

