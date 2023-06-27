#include <catch2/catch_test_macros.hpp>
#include "../MyStack.h"

using namespace std::literals;
TEST_CASE("Create empty stack")
{
    CMyStack<std::string> strStack;
    REQUIRE(strStack.IsEmpty());
    CMyStack<int> intStack;
    REQUIRE(intStack.IsEmpty());
}

// Int stack

TEST_CASE("Push in int stack")
{
    CMyStack<int> intSt;
    REQUIRE(intSt.IsEmpty());
    intSt.Push(5);
    REQUIRE_FALSE(intSt.IsEmpty());
}

TEST_CASE("Top in int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    REQUIRE(intSt.Top() == 5);
}

TEST_CASE("Pop in int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    intSt.Push(10);
    REQUIRE(intSt.Top() == 10);
    intSt.Pop();
    REQUIRE(intSt.Top() == 5);
}

TEST_CASE("Clear int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    intSt.Push(10);
    REQUIRE_FALSE(intSt.IsEmpty());
    intSt.Clear();
    REQUIRE(intSt.IsEmpty());
}

TEST_CASE("Copy constructor int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    intSt.Push(10);
    CMyStack<int> intStCopy(intSt);
    REQUIRE(intSt.Top() == 10);
    REQUIRE(intSt.Top() == intStCopy.Top());
    intSt.Pop();
    REQUIRE_FALSE(intSt.Top() == intStCopy.Top());
}

TEST_CASE("Move constructor int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    intSt.Push(10);
    REQUIRE_FALSE(intSt.IsEmpty());
    CMyStack<int> movedSt(std::move(intSt));
    REQUIRE(intSt.IsEmpty());
    REQUIRE_FALSE(movedSt.IsEmpty());
    REQUIRE(movedSt.Top() == 10);
}

TEST_CASE("Move operator int stack")
{
    CMyStack<int> intSt;
    intSt.Push(5);
    intSt.Push(10);
    CMyStack<int> movedSt;
    movedSt.Push(50);
    movedSt.Push(100);
    movedSt = std::move(intSt);
    REQUIRE(movedSt.Top() == 10);
    REQUIRE(intSt.IsEmpty());
}

// String stack

TEST_CASE("Push in string stack")
{
    CMyStack<std::string> intSt;
    REQUIRE(intSt.IsEmpty());
    intSt.Push("5"s);
    REQUIRE_FALSE(intSt.IsEmpty());
}

TEST_CASE("Top in string stack")
{
    CMyStack<std::string> intSt;
    intSt.Push("5"s);
    REQUIRE(intSt.Top() == "5"s);
}

TEST_CASE("Pop in string stack")
{
    CMyStack<std::string> intSt;
    intSt.Push("5"s);
    intSt.Push("10"s);
    REQUIRE(intSt.Top() == "10"s);
    intSt.Pop();
    REQUIRE(intSt.Top() == "5"s);
}

TEST_CASE("Clear string stack")
{
    CMyStack<std::string> intSt;
    intSt.Push("5"s);
    intSt.Push("10"s);
    REQUIRE_FALSE(intSt.IsEmpty());
    intSt.Clear();
    REQUIRE(intSt.IsEmpty());
}

TEST_CASE("Copy constructor string stack")
{
    CMyStack<std::string> intSt;
    intSt.Push("5"s);
    intSt.Push("10"s);
    CMyStack<std::string> intStCopy(intSt);
    REQUIRE(intSt.Top() == "10"s);
    REQUIRE(intSt.Top() == intStCopy.Top());
    intSt.Pop();
    REQUIRE_FALSE(intSt.Top() == intStCopy.Top());
}

TEST_CASE("Move constructor string stack")
{
    CMyStack<std::string> stringSt;
    stringSt.Push("5"s);
    stringSt.Push("10"s);
    REQUIRE_FALSE(stringSt.IsEmpty());
    CMyStack<std::string> movedSt(std::move(stringSt));
    REQUIRE(stringSt.IsEmpty());
    REQUIRE_FALSE(movedSt.IsEmpty());
    REQUIRE(movedSt.Top() == "10"s);
}