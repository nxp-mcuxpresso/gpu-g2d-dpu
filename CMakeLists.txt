# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.g2d.cm7)
    mcux_component_version(2.4.0)
    mcux_add_library(
        LIBS cm7/libg2d.a
        TOOLCHAINS armgcc mcux iar
        BASE_PATH ${SdkRootDirPath}/middleware/g2d_dpu/
    )
    mcux_add_include(
        INCLUDES .
        BASE_PATH ${SdkRootDirPath}/middleware/g2d_dpu/
    )
endif()