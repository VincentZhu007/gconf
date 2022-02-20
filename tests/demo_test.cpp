#include <iostream>
#include "gtest/gtest.h"

using namespace std;

int Add(int a, int b)
{
    return a + b;
}

class DemoTest: public ::testing::Test
{
protected:
    void SetUp()
    {
        cout << "setup TestAdd" << endl;
    }
    void TearDown()
    {
        cout << "tear down TestAdd" << endl;
    }
};

TEST_F(DemoTest, AddPositive)
{
    ASSERT_EQ(Add(1, 2), 3);
}

TEST_F(DemoTest, AddNegative)
{
    ASSERT_EQ(Add(-1, -2), -3);
}

TEST_F(DemoTest, AddPositiveAndNegative)
{
    ASSERT_EQ(Add(-1, 1), 0);
}
