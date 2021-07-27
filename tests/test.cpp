#include "gtest/gtest.h"

#include <chrono>

#include "../src/RunOnEnd.hpp"


TEST(examples, Example1)
{
	bool passTest {false};

	try
	{
		// Use initializer list-style instantiation; we do not allow move/assignment construction.
		// Note that the `()` is not required when the lambda/function takes no argument.
		siddiqsoft::RunOnEnd roe {[&passTest] {
			// Runs when this scope ends
			passTest = true;
		}};
	}
	catch (...)
	{
		EXPECT_TRUE(false); // if we throw then the test fails.
	}

	// Iff the lambda runs, it should be true
	EXPECT_TRUE(passTest);
}


TEST(examples, Example2)
{
	bool     passTest {false};
	uint64_t ttx {0};

	try
	{
		siddiqsoft::RunOnEnd roe {[&passTest, &ttx] {
			// Runs when this scope ends
			passTest = true;
			ttx      = std::chrono::system_clock::now().time_since_epoch().count();
		}};
	}
	catch (...)
	{
		EXPECT_TRUE(false); // if we throw then the test fails.
	}

	// Iff the lambda runs, it should be true
	EXPECT_TRUE(passTest);
	EXPECT_NE(0, ttx);
}
