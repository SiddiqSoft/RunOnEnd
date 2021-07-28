RunOnEnd : Run a lambda in destructor
-------------------------------------------

[![CodeQL](https://github.com/SiddiqSoft/RunOnEnd/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/SiddiqSoft/RunOnEnd/actions/workflows/codeql-analysis.yml)
[![Build Status](https://dev.azure.com/siddiqsoft/siddiqsoft/_apis/build/status/SiddiqSoft.RunOnEnd?branchName=main)](https://dev.azure.com/siddiqsoft/siddiqsoft/_build/latest?definitionId=10&branchName=main)
![](https://img.shields.io/nuget/v/SiddiqSoft.RunOnEnd)
![](https://img.shields.io/github/v/tag/SiddiqSoft/RunOnEnd)
![](https://img.shields.io/azure-devops/tests/siddiqsoft/siddiqsoft/10)
![](https://img.shields.io/azure-devops/coverage/siddiqsoft/siddiqsoft/10)


# Objective
- A simpler "run on end" vs. the custom deletor available via `std::unique_ptr<>`. It is important to note that we do not provide an "owning" helper as this is better accomplished via the destructor code for `std::unique_ptr<>`.
- Use the nuget [SiddiqSoft.RunOnEnd](https://www.nuget.org/packages/SiddiqSoft.RunOnEnd/)
- Copy paste..whatever works.

# Usage

The utility can be used to ensure you cleanup within a scope, update some global variable or use the definition to build your own auto-cleanup.

Consider the following [example](tests/test.cpp) where the utility `UseWinsock` builds on `RunOnEnd` for its functionality.

```cpp
struct UseWinsock : private siddiqsoft::RunOnEnd
{
    UseWinsock() noexcept
        : m_rc(E_FAIL)
        , siddiqsoft::RunOnEnd([&]() {
            if (m_rc == S_OK) WSACleanup();
        })
    {
        ZeroMemory(&m_wsaData, sizeof(m_wsaData));
        m_rc = WSAStartup(MAKEWORD(2, 2), &m_wsaData);
        m_rc = (m_rc == 0) ? S_OK : WSAGetLastError();
    }

    operator bool() { return (m_rc == S_OK); }

private:
    int     m_rc;
    WSADATA m_wsaData;
};
```



<small align="right">

&copy; 2021 Siddiq Software LLC. All rights reserved.

</small>
