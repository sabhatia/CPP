#include <gtest/gtest.h>

TEST(GT_Bank_Account, Test_Macro_TRUE)
{
    EXPECT_TRUE(true);
}

TEST(GT_Bank_Account, Test_Macro_EQ1)
{
    EXPECT_EQ(true, false);
}

TEST(GT_Bank_Account, Test_Macro_EQ2)
{
    EXPECT_EQ(true, true);
}