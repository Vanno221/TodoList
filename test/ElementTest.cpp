#include <gtest/gtest.h>
#include "../Task.h"

TEST(ElementTest, ConstuctorTest){
    Task e("Testing");
    EXPECT_EQ(e.getName(), "Testing");
    EXPECT_FALSE(e.isChecked());
}

TEST(ElementTest, NameTest){
    Task e;
    e.setName("TestingName");
    EXPECT_EQ(e.getName(), "TestingName");
}

TEST(ElementTest, CheckedTest){
    Task e;
    e.setChecked(true);
    EXPECT_TRUE(e.isChecked());
}

TEST(ElementTest, ToggleTest){
    Task e("Testing");
    e.toggle();
    EXPECT_TRUE(e.isChecked());
    e.toggle();
    EXPECT_FALSE(e.isChecked());
}

TEST(ElementTest, OperatorEqualTest){
    Task e1("Luca");
    Task e2("Luca");
    EXPECT_TRUE(e1 == e2);
    e2.toggle();
    EXPECT_TRUE(e1 == e2);
    e2.setName("Matteo");
    EXPECT_FALSE(e1 == e2);
}
