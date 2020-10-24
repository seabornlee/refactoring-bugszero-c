#define APPROVALS_GOOGLETEST_EXISTING_MAIN
#include "ApprovalTests.hpp"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ApprovalTests::initializeApprovalTestsForGoogleTests();
    return RUN_ALL_TESTS();
}