#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <map>
#include <vector>
#include "../receiver/receiver.h"
#include "../catch.hpp"

using namespace std;
TEST_CASE("inserting the word and word count when the word is not present in the map ") {
 map<std::string, int> M;
  std::vector<string> words={"one","two"};
  std::map<std::string, int> result;
  result.insert(make_pair("one", 1));
  result.insert(make_pair("two", 1));
 
    REQUIRE(Receiver::InsertWords(M,words)==result);
    
}
TEST_CASE("inserting the word and word count when the word is already present in the map") {
 map<std::string, int> M;
   M.insert(make_pair("one", 1));
  std::vector<string> words={"one","one"};
  std::map<std::string, int> result;
  result.insert(make_pair("one", 3));
 
    REQUIRE(Receiver::InsertWords(M,words)==result);
    
}
TEST_CASE("passing empty string vector for insertion to map") {
 map<std::string, int> M;
   M.insert(make_pair("one", 1));
  std::vector<string> words={};
  std::map<std::string, int> result;
  result.insert(make_pair("one", 1));
 
    REQUIRE(Receiver::InsertWords(M,words)==result);
    
}


TEST_CASE("sending a string that contains letters other than alphabets then it should not be added to the vector of words")
{
 vector<string> words={"one","comment"};

REQUIRE(Receiver::checkforalphabets("79NOSL",words)==words);
}
TEST_CASE("sending a string that contains only alphabets then it should be added to the vector of words")
{
 vector<string> words={"one","comment"};
 vector<string> result={"one","comment","two"};

REQUIRE(Receiver::checkforalphabets("two",words)==result);
}
TEST_CASE("sending an empty string then it should return same vector of words")
{
 vector<string> words={"one","comment"};

REQUIRE(Receiver::checkforalphabets("",words)==words);
}

TEST_CASE("disintergrate the line and add each words to the map")
{
 
  map<std::string, int> M;
  M.insert(make_pair("one", 1));
 M.insert(make_pair("two", 2));
 string line="one of these is not required";
 map<std::string, int> result;
 result.insert(make_pair("one", 2));
 result.insert(make_pair("two", 2));
 result.insert(make_pair("of", 1));
 result.insert(make_pair("these", 1));
 result.insert(make_pair("is", 1));
 result.insert(make_pair("not", 1));
 result.insert(make_pair("required", 1));
 REQUIRE( Receiver::countWords(M,line)==result);
}
TEST_CASE("when sending empty line the map should not be updated")
{
  map<std::string, int> M;
  M.insert(make_pair("one", 1));
 M.insert(make_pair("two", 2));
 REQUIRE( Receiver::countWords(M,"")==M);
}

TEST_CASE("check for removal of stop words")
{
 map<std::string, int> M,result;
  M.insert(make_pair("one", 11));
  M.insert(make_pair("me", 32));
  result.insert(make_pair("one", 11));
 REQUIRE(Receiver::RemoveStopWords(M)==result);
}

TEST_CASE("no stop words in the map then same map should be returned")
{
 map<std::string, int> M;
  M.insert(make_pair("one", 11));
  M.insert(make_pair("two", 32));
 REQUIRE(Receiver::RemoveStopWords(M)==M);
}
TEST_CASE("when empty map is passed as argument then empty map should be ")
{
 map<std::string, int> M;
 REQUIRE(Receiver::RemoveStopWords(M)==M);
}

