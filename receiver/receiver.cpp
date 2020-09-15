#include "receiver.h"
#include<algorithm>
using namespace std;
int main()
{
    map<string, int> Mapofwordandwordcount;
    string line = "";
    while (getline(cin, line)) {
        if (line == "") {
            break;
        }
        map<string, int> tempMap = Receiver::countWords(Mapofwordandwordcount, line);
        Mapofwordandwordcount = tempMap;
    }
    Receiver::printwordandwordcounts(Receiver::RemoveStopWords(Mapofwordandwordcount));
    return 0;
}
void Receiver::printwordandwordcounts(map<std::string, int> Mapofwordandwordcount)
{
    if (Mapofwordandwordcount.size() > 0) {
        fstream fout;
        fout.open("sample-review/WordCount.csv", ios::out | ios::app);
        for (auto& iterator : Mapofwordandwordcount) {
            fout << iterator.first << "," << iterator.second << "\n";
            cout << iterator.first << "," << iterator.second << "\n";
        }
    }
    else
        cout << "Empty Input Received";
}
map<std::string, int> Receiver::countWords(map<std::string, int>& Mapofwordandwordcount, string line)
{
    string word = "";
    std::vector<string> words,tempwords;
    for (int iterator = 0; line[iterator] != '\0'; iterator++) {
        if (line[iterator] == ' ') {
            tempwords=Receiver::checkforalphabets(word,words);
            words=tempwords;
            word = "";
        }
        else
            word += line[iterator];
    }
    tempwords=Receiver::checkforalphabets(word,words);
     words=tempwords;
    return Receiver::InsertWords(Mapofwordandwordcount, words);
}

map<string, int> Receiver::InsertWords(map<string, int> Mapofwordandwordcount, std::vector<string> words)
{
    for (auto& word : words) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (Mapofwordandwordcount.find(word) == Mapofwordandwordcount.end())
        {
             
            Mapofwordandwordcount.insert(make_pair(word, 1));
        }
        else
            Mapofwordandwordcount[word]++;
    }
    return Mapofwordandwordcount;
}
vector<string> Receiver::checkforalphabets(string word,vector<string> words)
{
    int iterator=0;
while(word[iterator])
{
    if (!isalpha(word[iterator]))
        return words;
    iterator++;  
}
   
    return Receiver::pushbackword(word,words);
}
vector<string> Receiver::pushbackword(string word,vector<string> words)
{
    if(word=="")
     return words;
    else
        return  words.push_back(word);
}
map<string, int> Receiver::RemoveStopWords(map<string, int> Mapofwordandwordcount)
{
    map<string, int> tempMap=Mapofwordandwordcount;
    vector<string> mostcommonstopwords={"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
    for (auto& iterator : Mapofwordandwordcount) {
        std::vector<string>::iterator itr;
        string searchkey=iterator.first;
         transform(searchkey.begin(), searchkey.end(), searchkey.begin(), ::tolower);
            itr=std::find(mostcommonstopwords.begin(),mostcommonstopwords.end(),searchkey);
        if(itr!=mostcommonstopwords.end())
        {
            tempMap.erase(iterator.first);
        }
    }
    return tempMap;       
}
