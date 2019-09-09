/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#include "xgame/xruntime.h"
#include "xgame/xruntime-private.h"

#include <shellapi.h>

USING_NS_CC;

static char *StringWideCharToUtf8(LPWSTR wstr)
{
	if (wstr) 
	{
		int nNum = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, FALSE);
		if (nNum) {
			char* utf8String = new char[nNum + 1];
			utf8String[0] = 0;
			nNum = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8String, nNum + 1, nullptr, FALSE);
			return utf8String;
		}
		else 
		{
			CCLOG("Wrong convert to Utf8 code:0x%x", GetLastError());
		}
	}

	return NULL;
}

int WINAPI _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	// set packageName
	__runtime_setPackageName("org.cocos2dx.hellolua");

    // create the application instance
    AppDelegate app;

	// launch args
	LPWSTR *wargv;
	int argc;
	wargv = CommandLineToArgvW(GetCommandLineW(), &argc);
	char **argv = (char **)malloc(sizeof(char *) * argc);
	for (int i = 0; i < argc; i++) {
		argv[i] = StringWideCharToUtf8(wargv[i]);
	}
	xgame::runtime::parseLaunchArgs(argc, argv);
	for (int i = 0; i < argc; i++) {
		free(argv[i]);
	}
	free(argv);

    return Application::getInstance()->run();
}
