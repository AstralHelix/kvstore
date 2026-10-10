#include <gtest/gtest.h>
#include "kvstore/store.hpp"
using namespace kvstore;
TEST(KVStoreTest, SetThenGetReturnsValue) {
    KVStore test_store;

    // Act: set a key, then get it into a variable
    test_store.set("A", "1");
    auto get_test = test_store.get("A");
    // Assert: check it exists, then check its value
    ASSERT_TRUE(get_test.has_value());
    EXPECT_EQ(*get_test, "1");

}