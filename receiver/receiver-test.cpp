#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <map>
#include <vector>
#include "catch.hpp"
#include "../receiver/receiver.h"
using namespace std;
TEST_CASE("printing the word and word count") {
 map<std::string, int> M;
   M.insert(make_pair("one", 1));
  std::vector<string> words={"one","two"};
  map<std::string, int> result,res2;
   result.insert(make_pair("one", 2));
  result.insert(make_pair("two", 1));
  res2=InsertWords(M,words);
  
    REQUIRE(res2==result);
  
   
    
}
