#include <gtest/gtest.h>
#include "Time.hpp"

TEST(TimeConstructorTest, DefaultConstructor)
{
    Time t;
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeConstructorTest, ParameterizedConstructor)
{
    Time t(10, 30, 45);
    EXPECT_EQ(t.GetHours(), 10);
    EXPECT_EQ(t.GetMinutes(), 30);
    EXPECT_EQ(t.GetSeconds(), 45);
}

TEST(TimeConstructorTest, ParameterizedConstructorFailure)
{
    Time t(25, 61, 70);
    EXPECT_EQ(t.GetHours(), 25);
}

TEST(TimeOperatorTest, AdditionOperator)
{
    Time t1(1, 30, 30);
    Time t2(0, 45, 50);
    Time result = t1 + t2;
    EXPECT_EQ(result.GetHours(), 2);
    EXPECT_EQ(result.GetMinutes(), 16);
    EXPECT_EQ(result.GetSeconds(), 20);
}

TEST(TimeOperatorTest, SubtractionOperator)
{
    Time t1(2, 30, 30);
    Time t2(1, 15, 15);
    Time result = t1 - t2;
    EXPECT_EQ(result.GetHours(), 1);
    EXPECT_EQ(result.GetMinutes(), 15);
    EXPECT_EQ(result.GetSeconds(), 15);
}

TEST(TimeOperatorTest, AdditionOperatorFailure)
{
    Time t1(1, 30, 30);
    Time t2(0, 45, 50);
    Time result = t1 + t2;
    EXPECT_EQ(result.GetHours(), 2);
    EXPECT_EQ(result.GetMinutes(), 15);
}

TEST(TimeFunctionTest, NormalizeTest)
{
    Time t(25, 61, 70);
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 2);
    EXPECT_EQ(t.GetMinutes(), 2);
    EXPECT_EQ(t.GetSeconds(), 10);
}

TEST(TimeFunctionTest, SettersAndGetters)
{
    Time t;
    t.SetHours(5);
    t.SetMinutes(45);
    t.SetSeconds(30);
    EXPECT_EQ(t.GetHours(), 5);
    EXPECT_EQ(t.GetMinutes(), 45);
    EXPECT_EQ(t.GetSeconds(), 30);
}

TEST(TimeFunctionTest, SettersAndGettersFailure)
{
    Time t;
    t.SetHours(5);
    t.SetMinutes(45);
    t.SetSeconds(30);
    EXPECT_EQ(t.GetMinutes(), 50);
}
