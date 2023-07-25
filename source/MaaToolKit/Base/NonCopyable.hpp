#pragma once

#include "Common/MaaConf.h"

MAA_TOOLKIT_NS_BEGIN

class NonCopyable
{
public:
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable(NonCopyable&&) = delete;

    NonCopyable operator=(const NonCopyable&) = delete;
    NonCopyable operator=(NonCopyable&&) = delete;

protected:
    NonCopyable() = default;
};

MAA_TOOLKIT_NS_END