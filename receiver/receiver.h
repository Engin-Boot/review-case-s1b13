#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
namespace Receiver
{
 map<string, int> Receiver::RemoveStopWords(map<string, int>);
std::map<std::string, int> countWords(std::map<std::string, int>&, string);
void printwordandwordcounts(std::map<std::string, int>);
std::map<string, int> InsertWords(std::map<string, int>, std::vector<string>);
vector<string> checkforalphabets(string,vector<string>);
}
