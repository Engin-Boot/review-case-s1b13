#define CATCH_CONFIG_MAIN  
#include "../catch.hpp"
#include "../sender/Sender.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
Sender s;

TEST_CASE("This is the First CASE")
{
    
    string third = "10/23/45 23:45,No additional comments";
    
    
    char data1 = s.PrintSelectedColumn(1,2,third,15);
    cout<<data1<<endl;
    char data = 'N';
    REQUIRE(data1==data);
}

