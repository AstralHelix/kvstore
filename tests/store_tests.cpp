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

TEST(KVStoreTest, GetMissingKeyReturnsEmpty) {
    KVStore test_store;

    // Act: get value of key that does not exist
    auto get_test = test_store.get("A");
    // Assert: check it does not exist
    ASSERT_FALSE(get_test.has_value());
}

TEST(KVStoreTest, SetExistingKeyOverwritesValue) {
    KVStore test_store;

    // Act: set a key, then overwrite then get it into a variable
    test_store.set("A", "1");
    test_store.set("A", "2");
    auto get_test = test_store.get("A");
    // Assert: check it exists, then check its value
    ASSERT_TRUE(get_test.has_value());
    EXPECT_EQ(*get_test, "2");

}
