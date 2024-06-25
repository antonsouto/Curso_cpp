#include "functions.h"
#include "types.h" 
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace std;

// Test para la función includes(const vector<shared_ptr<Person>> &a, shared_ptr<Person> const &obj)
TEST(IncludesTest, SingleElementPresent) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    vector<shared_ptr<Person>> a = {person1};

    EXPECT_TRUE(includes(a, person1));
}

TEST(IncludesTest, SingleElementAbsent) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    vector<shared_ptr<Person>> a = {person1};

    EXPECT_FALSE(includes(a, person2));
}

// Test para la función includes(const vector<shared_ptr<Person>> &a, const vector<shared_ptr<Person>> &b)
TEST(IncludesTest, AllElementsPresent) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    vector<shared_ptr<Person>> a = {person1, person2, person3};
    vector<shared_ptr<Person>> b = {person1, person3};

    EXPECT_TRUE(includes(a, b));
}

TEST(IncludesTest, SomeElementsMissing) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    auto person4 = make_shared<Person>(Person{"Charlie", 35, false});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person1, person3};

    EXPECT_FALSE(includes(a, b));
}

// Test para la función interseccion
TEST(InterseccionTest, CommonElements) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person2, person3};

    vector<shared_ptr<Person>> result = interseccion(a, b);
    EXPECT_EQ(result.size(), 1);
    EXPECT_NE(find(result.begin(), result.end(), person2), result.end());
}

TEST(InterseccionTest, NoCommonElements) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    auto person4 = make_shared<Person>(Person{"Charlie", 35, false});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person3, person4};

    vector<shared_ptr<Person>> result = interseccion(a, b);
    EXPECT_EQ(result.size(), 0);
}

// Test para la función diferencia
TEST(DiferenciaTest, DifferentElements) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person2, person3};

    vector<shared_ptr<Person>> result = diferencia(a, b);
    EXPECT_EQ(result.size(), 1);
    EXPECT_NE(find(result.begin(), result.end(), person1), result.end());
}

TEST(DiferenciaTest, NoDifferentElements) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person1, person2};

    vector<shared_ptr<Person>> result = diferencia(a, b);
    EXPECT_EQ(result.size(), 0);
}

// Test para la función unionv
TEST(UnionvTest, NoDuplicates) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    vector<shared_ptr<Person>> a = {person1, person2};
    vector<shared_ptr<Person>> b = {person3};

    vector<shared_ptr<Person>> result = unionv(a, b);
    EXPECT_EQ(result.size(), 3);
    EXPECT_NE(find(result.begin(), result.end(), person1), result.end());
    EXPECT_NE(find(result.begin(), result.end(), person2), result.end());
    EXPECT_NE(find(result.begin(), result.end(), person3), result.end());
}

TEST(UnionvTest, WithDuplicates) {
    auto person1 = make_shared<Person>(Person{"John", 30, false});
    auto person2 = make_shared<Person>(Person{"Alice", 25, false});
    auto person3 = make_shared<Person>(Person{"Bob", 20, true});
    auto person4 = make_shared<Person>(Person{"Charlie", 35, false});
    vector<shared_ptr<Person>> a = {person1, person2, person3};
    vector<shared_ptr<Person>> b = {person2, person3, person4};

    vector<shared_ptr<Person>> result = unionv(a, b);
    EXPECT_EQ(result.size(), 4);
    EXPECT_NE(find(result.begin(), result.end(), person1), result.end());
    EXPECT_NE(find(result.begin(), result.end(), person2), result.end());
    EXPECT_NE(find(result.begin(), result.end(), person3), result.end());
    EXPECT_NE(find(result.begin(), result.end(), person4), result.end());
}

