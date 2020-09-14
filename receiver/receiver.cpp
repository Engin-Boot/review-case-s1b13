
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<std::string, int> countWords(map<std::string, int>&, string);
void printwordandwordcounts(map<std::string, int>);
map<string, int> InsertWords(map<string, int>, std::vector<string>);
vector<string> checkforalphabets(string,vector<string>);

int main()
{
    map<string, int> M;
    string line = "";
    while (getline(cin, line)) {
        if (line == "") {
            break;
        }
        map<string, int> tempMap = countWords(M, line);
        M = tempMap;
    }
    printwordandwordcounts(M);
    return 0;
}
void printwordandwordcounts(map<std::string, int> M)
{

    if (M.size() > 0) {
        fstream fout;
        fout.open("sample-review/WordCount.csv", ios::out | ios::app);
        for (auto& iterator : M) {
            fout << iterator.first << "," << iterator.second << "\n";
        }
    }
    else
        cout << "Empty Input Received";
}
map<std::string, int> countWords(map<std::string, int>& M, string line)
{
    // String for storing the words
    string word = "";
    std::vector<string> words,tempwords;

    for (int i = 0; line[i] != '\0'; i++) {

        if (line[i] == ' ') {
            tempwords=checkforalphabets(word,words);
            words=tempwords;
            word = "";
        }
        else
            word += line[i];
    }
    tempwords=checkforalphabets(word,words);
     words=tempwords;
    return InsertWords(M, words);
}

map<string, int> InsertWords(map<string, int> M, std::vector<string> words)
{
    for (auto& word : words) {
        if (M.find(word) == M.end())
            M.insert(make_pair(word, 1));
        else
            M[word]++;
    }

    return M;
}
vector<string> checkforalphabets(string word,vector<string> words)
{
    int i=0;
while(word[i])
{
    if (!isalpha(word[i]))
        return words;
  
}
    words.push_back(word);
    return words;
}
