#include <dos.h>
#include <stdio.h>
#include <conio.h>

unsigned long far* N = (unsigned long far*) MK_FP(0x0040, 0x006c);

void interrupt Custom()
{
	if (*N % 36L == 0)
	{
		cputs("WOW");
	}
}

int main()
{
	void interrupt(*base)();
	base = getvect(0xc1);
	setvect(0x1c, Custom);
	getch();
	setvect(0x1c, base);
	return 0;
}
