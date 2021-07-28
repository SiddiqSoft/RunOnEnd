#include "gtest/gtest.h"

#include <chrono>
#include <thread>

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


#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")


TEST(examples, Example3)
{
	bool passTest {false};

	struct UseWinsock : private siddiqsoft::RunOnEnd
	{
		UseWinsock() noexcept
			: m_rc(E_FAIL)
			, siddiqsoft::RunOnEnd([&]() {
				if (m_rc == S_OK) std::cerr << "Invoke WSACleanup():" << WSACleanup() << std::endl;
			})
		{
			ZeroMemory(&m_wsaData, sizeof(m_wsaData));
			m_rc = WSAStartup(MAKEWORD(2, 2), &m_wsaData);
			m_rc = (m_rc == 0) ? S_OK : WSAGetLastError();
			std::cerr << "WSAStartup(): " << m_rc << std::endl;
		}

		operator bool() { return (m_rc == S_OK); }

	private:
		int     m_rc;
		WSADATA m_wsaData;
	};


	try
	{
		UseWinsock ws;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	catch (...)
	{
		EXPECT_TRUE(false); // if we throw then the test fails.
	}

	// Iff the lambda runs we should have called WSACleanup in which case
	// the second invocation should fail.
	EXPECT_EQ(SOCKET_ERROR, WSACleanup());
	EXPECT_EQ(WSANOTINITIALISED, GetLastError());
}

#include <winsock.h>