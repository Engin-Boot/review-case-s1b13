
#include "receiver.h"
using namespace std;
int main()
{
    map<string, int> M;
    string line = "";
    while (getline(cin, line)) {
        if (line == "") {
            break;
        }
        map<string, int> tempMap = Receiver::countWords(M, line);
        M = tempMap;
    }
    Receiver::printwordandwordcounts(Receiver::RemoveStopWords(M));
    return 0;
}
void Receiver::printwordandwordcounts(map<std::string, int> M)
{
    if (M.size() > 0) {
        fstream fout;
        fout.open("sample-review/WordCount.csv", ios::out | ios::app);
        for (auto& iterator : M) {
            fout << iterator.first << "," << iterator.second << "\n";
            cout << iterator.first << "," << iterator.second << "\n";
        }
    }
    else
        cout << "Empty Input Received";
}
map<std::string, int> Receiver::countWords(map<std::string, int>& M, string line)
{
    string word = "";
    std::vector<string> words,tempwords;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {
            tempwords=Receiver::checkforalphabets(word,words);
            words=tempwords;
            word = "";
        }
        else
            word += line[i];
    }
    tempwords=Receiver::checkforalphabets(word,words);
     words=tempwords;
    return Receiver::InsertWords(M, words);
}

map<string, int> Receiver::InsertWords(map<string, int> M, std::vector<string> words)
{
    for (auto& word : words) {
        if (M.find(word) == M.end())
            M.insert(make_pair(word, 1));
        else
            M[word]++;
    }
    return M;
}
vector<string> Receiver::checkforalphabets(string word,vector<string> words)
{
    int i=0;
while(word[i])
{
    if (!isalpha(word[i]))
        return words;
    i++;  
}
    words.push_back(word);
    return words;
}
map<string, int> Receiver::RemoveStopWords(map<string, int> M)
{
    map<string, int> tempMap=M;
    vector<string> mostcommonstopwords={"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};
    for (auto& iterator : M) {
        std::vector<string>::iterator itr;
            itr=std::find(mostcommonstopwords.begin(),mostcommonstopwords.end(),iterator.first);
        if(itr!=mostcommonstopwords.end())
        {
            tempMap.erase(iterator.first);
        }
    }
    return tempMap;       
}
