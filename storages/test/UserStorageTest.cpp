#include "UserStorage.h"

#include <gtest/gtest.h>

TEST(UserStorageTest, SimpleAddAndGet) {
    auto userId = Storage::Users::getInstance().add({"John", "Smith", "J.Smith@ya.ru"});
    auto user = Storage::Users::getInstance().get(userId);

    EXPECT_EQ(userId, user.id);
    EXPECT_EQ("John", user.name);
    EXPECT_EQ("Smith", user.lastname);
    EXPECT_EQ("J.Smith@ya.ru", user.email);
}
