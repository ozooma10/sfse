cmake_minimum_required(VERSION 3.18...4.0.2)

# ---- Project ----

project(
	umbrella
	LANGUAGES CXX
)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
	message(
		FATAL_ERROR
			"In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
)
endif()

# ---- Add sub projects ----

if (NOT TARGET sfse)
	add_subdirectory(sfse)
endif()

if (NOT TARGET sfse_common)
	add_subdirectory(sfse_common)
endif()

if (NOT TARGET sfse_loader)
	add_subdirectory(sfse_loader)
endif()

option(SFSE_BUILD_CONTRACT_TESTS "Build lightweight SFSE public API contract tests" OFF)

if(SFSE_BUILD_CONTRACT_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
