#include "gtest/gtest.h"
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
