#include<fstream>
#include<iostream>
#include<map>
using namespace std;
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

}
 for (auto& it : M) { 
        cout << it.first << " - "
             << it.second 
             << endl; 
    } 
return 0;
}
/*void storeFrequencies(const string &str,unordered_map<string,int> wordFreq) 
{ 
  
  
   
    stringstream ss(str); 
    string word;
    while (ss >> word) 
        wordFreq[word]++; 
   
} */
