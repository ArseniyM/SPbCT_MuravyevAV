#define _WIN32_WINNT 0x0500
#define UNICODE
#ifdef UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
void main(void) {
	wchar_t UserName[256];
	DWORD MaxUserNameLength = 256;
	SID Sid[1024];
	PSID pSid;
	LPTSTR StringSid;
	DWORD SidSize = 1024;
	SID_NAME_USE SidType;
	LPTSTR DomainName = NULL;
	DWORD DomainNameSize = 16;
	HANDLE hHeap;
	hHeap = GetProcessHeap();
	pSid = &Sid[0];
	DomainName = (LPTSTR)HeapAlloc(hHeap, 0, DomainNameSize * sizeof(TCHAR));
	if (!ConvertStringSidToSidA("S-1-5-21-2001705613-1155405010-617497212-1001", &pSid))
		printf("Convert SID to string SID failed.");
	LookupAccountSid(
		NULL, // локальный компьютер
		pSid, UserName, &MaxUserNameLength, DomainName, &DomainNameSize, &SidType);
	wprintf(L"UserName %s\n", UserName);
	HeapFree(hHeap, 0, DomainName);
}