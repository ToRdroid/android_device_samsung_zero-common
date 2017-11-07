/*
 * Copyright (C) 2017 TeamNexus
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libOMX.Exynos"
#define LOG_NDEBUG 0

#include <cutils/log.h>
 
#include <exynos_format.h>
#include <exynos/Exynos_OMX_Def.h>
#include <Exynos_OSAL_Log.h>
#include <media/openmax/OMX_IVCommon.h>
#include <system/graphics.h>

extern "C" {

    int Exynos_OSAL_HAL2OMXColorFormat(
        int nHALFormat)
    {
        OMX_COLOR_FORMATTYPE eOMXFormat = OMX_COLOR_FormatUnused;

        switch (nHALFormat) {
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M:
            eOMXFormat = OMX_COLOR_FormatYUV420SemiPlanar;
            break;
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_TILED:
            eOMXFormat = (OMX_COLOR_FORMATTYPE)OMX_SEC_COLOR_FormatNV12Tiled;
            break;
        case HAL_PIXEL_FORMAT_YCrCb_420_SP:
        case HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M:
            eOMXFormat = (OMX_COLOR_FORMATTYPE)OMX_SEC_COLOR_FormatNV21Linear;
            break;
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P:
        case HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P_M:
            eOMXFormat = OMX_COLOR_FormatYUV420Planar;
            break;
        case HAL_PIXEL_FORMAT_YV12:
        case HAL_PIXEL_FORMAT_EXYNOS_YV12_M:
            eOMXFormat = (OMX_COLOR_FORMATTYPE)OMX_SEC_COLOR_FormatYVU420Planar;
            break;
        case HAL_PIXEL_FORMAT_YCbCr_422_I:
            eOMXFormat = OMX_COLOR_FormatYCbYCr;
            break;
        case HAL_PIXEL_FORMAT_BGRA_8888:
            eOMXFormat = OMX_COLOR_Format32bitARGB8888;
            break;
        case HAL_PIXEL_FORMAT_EXYNOS_ARGB_8888:
            eOMXFormat = OMX_COLOR_Format32bitBGRA8888;
            break;
        case HAL_PIXEL_FORMAT_RGBA_8888:
            eOMXFormat = (OMX_COLOR_FORMATTYPE)OMX_SEC_COLOR_Format32bitABGR8888;
            break;
        default:
            ALOGE("[SHIMMED] %s: HAL format is unsupported(0x%x)", __func__, nHALFormat);
            eOMXFormat = OMX_COLOR_Format32bitBGRA8888;
            break;
        }

        return eOMXFormat;
    }
    
}
