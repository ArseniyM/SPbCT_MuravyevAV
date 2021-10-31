#include "pch.h"
#pragma comment(lib, "netapi32.lib")
#ifndef UNICODE
#define UNICODE
#endif
#include <stdio.h>
#include <windows.h>
#include <lm.h>
#include <lmaccess.h>
#include <iostream>
BOOL DelUser(PWSTR pszName) {
	NET_API_STATUS nStatus;
	nStatus = NetUserDel(NULL, pszName);
	return (nStatus == NERR_Success);
}
int main() {
	if (!DelUser(L"ExpUser"))
		printf("A system error has occurred");
	return 0;
}