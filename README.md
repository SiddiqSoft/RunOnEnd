RunOnEnd : Run a lambda in destructor
-------------------------------------------

[![CodeQL](https://github.com/SiddiqSoft/RunOnEnd/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/SiddiqSoft/RunOnEnd/actions/workflows/codeql-analysis.yml)
[![Build Status](https://dev.azure.com/siddiqsoft/siddiqsoft/_apis/build/status/SiddiqSoft.RunOnEnd?branchName=main)](https://dev.azure.com/siddiqsoft/siddiqsoft/_build/latest?definitionId=8&branchName=main)
![](https://img.shields.io/nuget/v/SiddiqSoft.RunOnEnd)
![](https://img.shields.io/github/v/tag/SiddiqSoft/RunOnEnd)
![](https://img.shields.io/azure-devops/tests/siddiqsoft/siddiqsoft/8)
![](https://img.shields.io/azure-devops/coverage/siddiqsoft/siddiqsoft/8)


# Usage

- Use the nuget [SiddiqSoft.RunOnEnd](https://www.nuget.org/packages/SiddiqSoft.RunOnEnd/)
- Copy paste..whatever works.


```cpp
#include "gtest/gtest.h"
#include "siddiqsoft/RunOnEnd.hpp"


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
```


<small align="right">

&copy; 2021 Siddiq Software LLC. All rights reserved.

</small>
