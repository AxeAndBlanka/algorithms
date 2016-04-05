#ifndef TEST_CUT_HPP_
#define TEST_CUT_HPP_

#include <sstream>

#include "/home/maryna/Work/Test/src/LibCut.h"

using namespace std;

struct CoutRedirect
{
    CoutRedirect(streambuf* newBuffer)
        : old(cout.rdbuf(newBuffer))
    { }


    ~CoutRedirect( )
    {
        std::cout.rdbuf(old);
    }

private:
    streambuf* old;
};

class TestCut
{
public:
    void testParseList(const string& list, const map<int, int>& ranges, const string& stdOutput, const string& testName)
    {
        map<int, int> output;
        stringstream buffer;
        auto c = new CoutRedirect(buffer.rdbuf());
        MyLib::parseList(list, output);
        std::string text = buffer.str();
        delete c;
        //testEqual(output, ranges, testName);
        testEqual(text, stdOutput, testName);
    }

private:
    bool isTestsSucceed = true;

    template <typename T>
    void testEqual(const T& value, const T& expectedValue, const std::string& testName)
    {
        if(value != expectedValue)
        {
           cout << testName << ": FAILED" << endl;
           cout << "expected: " << expectedValue << endl;
           cout << "got: " << value << endl;
           isTestsSucceed = false;
        }
    }
};

#endif
