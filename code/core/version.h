// Copyright (c) 2026 Autin Alexandre
// SPDX-License-Identifier: MIT

#pragma once

// STL headers
#include <string_view>

namespace game::core
{
	/*!
	 * \brief          Get the game version as set by the CMake project version.
	 *
	 * \return         The version string, formatted as "major.minor.patch".
	 */
	[[nodiscard]] std::string_view getVersion();
}
