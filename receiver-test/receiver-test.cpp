#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <map>
#include <vector>
#include "../receiver/receiver.h"
#include "../catch.hpp"

using namespace std;
TEST_CASE("printing the word and word count") {
 map<std::string, int> M;
   M.insert(make_pair("one", 1));
  std::vector<string> words={"one","two"};
  std::map<std::string, int> result;
  result.insert(make_pair("one", 2));
  result.insert(make_pair("two", 1));
 
    REQUIRE(Receiver::InsertWords(M,words)==result);
    
}
TEST_CASE("checking if word contains alphabets or not")
{
 vector<string> words={"one","comment"};

REQUIRE(Receiver::checkforalphabets("79NOSL",words)==words);
}
TEST_CASE("disintergare the line and add each words to the map")
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
 REQUIRE( Receiver::countWords(M,line)=result);
}
