#include <fstream>
#include <iostream>
#include <map>
#include <vector>
namespace receiver
{
map<std::string, int> countWords(map<std::string, int>&, string);
void printwordandwordcounts(map<std::string, int>);
map<string, int> InsertWords(map<string, int>, std::vector<string>);
vector<string> checkforalphabets(string,vector<string>);
}
