//
// Created by aslan on 02.12.18.
//

#include "../src/Math.cpp"
#include <gtest/gtest.h>

TEST(MathTest, testAddition){
    Math math;

    int expected=200;
    int actual = math.add(40, 60);

    EXPECT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
