
#include<fstream>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<std::string,int> countWords(map<std::string,int>,string );
void printwordandwordcounts(map<std::string,int>);
map<string,int> InsertWords(map<string,int>,std::vector<string>);
map<string, int> InsertlastWord(map<string, int>,string);
bool ifwordfound(map<string, int>,string) ;
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
    string word = ""; std::vector<string> words;
  
    for (int i = 0;line[i]!='\0'; i++) { 
  
     
        if (line[i] == ' ') { 
  
            // If the current word 
            // is not found then insert 
            // current word with frequency 1 
            /*if (ifwordfound(M,word) { 
                M.insert(make_pair(word, 1)); 
                word = ""; 
            } 
  
            // update the frequency 
            else { 
                M[word]++; 
                word = ""; 
            } */
         words.push_back(word);
         word="";
        } 
  
        else
            word += line[i]; 
    } 
 words.push_back(word);
   
 return InsertWords(M,words);
}

map<string,int> InsertWords(map<string,int> M,std::vector<string> words) 
{ 
    // Key is not present 
 for (auto& word : words) { {
    if (M.find(word) == M.end()) 
     M.insert(make_pair(word, 1)); 
  else
   M[word]++;
 }  
  
    return M; 
}
/*map<string, int> InsertlastWord(map<string, int> M,string word)
{
 if (M.find(word) == M.end()) 
        M.insert(make_pair(word, 1)); 
  
    // Update the frequency 
    else
        M[word]++; 
 return M;
}*/
