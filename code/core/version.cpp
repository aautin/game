// Copyright (c) 2026 Autin Alexandre
// SPDX-License-Identifier: MIT

// STL headers
#include <string_view>

// Core headers
#include <core/version.h>

namespace game::core
{
	std::string_view getVersion()
	{
		//
		// Injected by CMake so that project() in CMakeLists.txt stays the single source of the
		// version.
		//
		return GAME_VERSION;
	}
}
