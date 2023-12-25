#include "stuff.h"

DWORD random() {
    DWORD xor = __rdtsc();

    xor ^= xor << 13;
    xor ^= xor << 17;
    xor ^= xor << 5;

    return xor;
}

COLORREF WINAPI Hue(int nHue) {
    float X = 1 - abs(fmod(nHue / 60.0, 2) - 1);
    float r, g, b;

    if (nHue >= 0 && nHue < 60) {
        r = 1, g = X, b = 0;
    }
    else if (nHue >= 60 && nHue < 120) {
        r = X, g = 1, b = 0;
    }
    else if (nHue >= 120 && nHue < 180) {
        r = 0, g = 1, b = X;
    }
    else if (nHue >= 180 && nHue < 240) {
        r = 0, g = X, b = 1;
    }
    else if (nHue >= 240 && nHue < 300) {
        r = X, g = 0, b = 1;
    }
    else if (nHue >= 300 && nHue < 360) {
        r = 1, g = 0, b = X;
    }

    int result = RGB(r * 255, g * 255, b * 255);
    return result;
}

RGBTRIPLE WINAPI prgbHue(int nHue) {
    float X = 1 - abs(fmod(nHue / 60.0, 2) - 1);
    float r, g, b;
    RGBTRIPLE rgb;

    if (nHue >= 0 && nHue < 60) {
        r = 1, g = X, b = 0;
    }
    else if (nHue >= 60 && nHue < 120) {
        r = X, g = 1, b = 0;
    }
    else if (nHue >= 120 && nHue < 180) {
        r = 0, g = 1, b = X;
    }
    else if (nHue >= 180 && nHue < 240) {
        r = 0, g = X, b = 1;
    }
    else if (nHue >= 240 && nHue < 300) {
        r = X, g = 0, b = 1;
    }
    else if (nHue >= 300 && nHue < 360) {
        r = 1, g = 0, b = X;
    }

    rgb.rgbtRed = r * 255;
    rgb.rgbtGreen = g * 255;
    rgb.rgbtBlue = b * 255;
    return rgb;
}