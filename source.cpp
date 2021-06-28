// StretchBlt WinAPI
// Very annoying effects, also flashing images

// Do not ran this if you are sensitive to flashing lights!

// Coded by Manh Khoi / 10G Tech

#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	std::cout << "Fuck you\n";
	std::cout << "Now we are fucking ur computer up ...\n";
	std::cout << "Enjoy your death HAHA\n";

	srand(static_cast<unsigned int>(time(0)));

	HDC desk;
	int l, t, sw, sh;

	while (true)
	{
		desk = GetDC(0);
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);

		l = rand() % sw;
		t = rand() % sh;
		StretchBlt(desk, 0, 0, sw, sh, desk, l, t, 1, 1, SRCINVERT);

		StretchBlt(desk, 20, 20, sw - 40, sh - 40, desk, 0, 0, sw, sh, NOTSRCCOPY);

		l = rand() % sw;
		t = rand() % sh;
		StretchBlt(desk, l, t, sw + (l * 2), t, desk, 0, t, sw, t, SRCERASE);

		l = rand() % sw;
		t = rand() % sh;
		StretchBlt(desk, 0, t, sw, t, desk, l, t, sw * (l * 2), t, SRCPAINT);
	};
	return 0;
}