/*
 * Process Hacker Plugins - 
 *   CommonUtil Plugin
 *
 * Copyright (C) 2016 dmex
 *
 * This file is part of Process Hacker.
 *
 * Process Hacker is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Process Hacker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process Hacker.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _WCT_H_
#define _WCT_H_

#define CINTERFACE
#define COBJMACROS
#include <phdk.h>
#include <phappresource.h>
#include <mxml.h>
#include <verify.h>
#include <workqueue.h>
#include <shlobj.h>
#include <Shellapi.h>
#include <psapi.h>
#include <winhttp.h>
#include <windowsx.h>
#include <uxtheme.h>
#include "resource.h"
#include "CommonUtil.h"

#define PLUGIN_NAME L"ProcessHacker.CommonUtil"

extern PPH_PLUGIN PluginInstance;

typedef struct _EDIT_CONTEXT
{
    UINT CommandID;

    union
    {
        ULONG Flags;
        struct
        {
            ULONG Hot : 1;
            ULONG Pushed : 1;
            ULONG Spare : 30;
        };
    };
   
    LONG CXWidth;
    INT CXBorder;
    INT ImageWidth;
    INT ImageHeight;
    HWND WindowHandle;
    HFONT WindowFont;
    HICON BitmapActive;
    HICON BitmapInactive;
    HBRUSH BrushNormal;
    HBRUSH BrushPushed;
    HBRUSH BrushHot;
} EDIT_CONTEXT, *PEDIT_CONTEXT;

VOID CreateSearchControl(
    _In_ HWND Parent,
    _In_ HWND WindowHandle,
    _In_ UINT CommandID
    );

HBITMAP LoadImageFromResources(
    _In_ UINT Width,
    _In_ UINT Height,
    _In_ PCWSTR Name,
    _In_ BOOLEAN RGBAImage
    );

HICON BitmapToIcon(
    _In_ HBITMAP BitmapHandle,
    _In_ INT Width,
    _In_ INT Height
    );

#endif