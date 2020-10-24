#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

using namespace ApprovalTests;

extern "C" {
}

TEST(GameTest, itsLockedDown) {
    Approvals::verify("Hello");
//    ASSERT_EQ(1, 1);
}