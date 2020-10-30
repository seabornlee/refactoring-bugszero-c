#include <gtest/gtest.h>
#include <ApprovalTests.hpp>


using namespace ApprovalTests;

extern "C" {
#include "game_runner.h"
}

TEST(GameTest, itsLockedDown) {
    testing::internal::CaptureStdout();
    playGame();
    const std::string &out = testing::internal::GetCapturedStdout();
    ApprovalTests::Approvals::verify(out);
}