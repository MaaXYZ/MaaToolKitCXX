#pragma once

#include "MaaToolKitDef.h"
#include "MaaToolKitPort.h"

#ifdef __cplusplus
extern "C"
{
#endif

    MaaString MAA_TOOLKIT_API MaaFrameworkVersion();
    MaaString MAA_TOOLKIT_API MaaToolKitVersion();

    MaaBool MAA_TOOLKIT_API MaaToolKitInit();

    MaaSize MAA_TOOLKIT_API MaaToolKitConfigSize();
    MaaString MAA_TOOLKIT_API MaaToolKitGetConfigHandle(MaaSize index);

    MaaBool MAA_TOOLKIT_API MaaToolKitNewConfig(MaaString config_name, MaaString copy_from);
    MaaBool MAA_TOOLKIT_API MaaToolKitDelConfig(MaaString config_name);

#ifdef __cplusplus
}
#endif
