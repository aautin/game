// Copyright (c) 2026 Autin Alexandre
// SPDX-License-Identifier: MIT

// External headers
#include <gtest/gtest.h>

// Project headers
#include <core/version.h>

TEST(Version, ReturnsProjectVersion)
{
	EXPECT_EQ(game::core::getVersion(), GAME_VERSION);
}
