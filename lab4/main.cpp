#include <iostream.h>
#include <GRAPHICS.H>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <bios.h>

void ActiveWindow(int x1, int y1, int x2, int y2, int textback, int textcol)
{
    window (x1-1, y1-1, x2+1, y2+2);
    textbackground(textback);
    clrscr();
    textcolor(textcol);

    for (int i = 0; i < x2 - x1 + 3; i++)
        cprintf("#");

	for(int j = 0; j < (y2 - y1 + 1); j++)
	{
		cprintf("#");

	    for(int k = 0; k < (x2 - x1 + 1); k++)
			cprintf(" ");

		cprintf("#");
	};

	for (int p = 0; p < x2 - x1 + 3; p++)
        cprintf("#");

    window(x1,y1,x2,y2);
    textbackground(textback);
	clrscr();
	textcolor(textcol);
}

int BiosF(int &work, int &mode)
{
    int ch;

    if (bioskey(1))
    {
        ch = bioskey(0);
        switch (ch)
		{
		case 20480:
			mode = 1;
			break;
		case 18432:
			mode = 2;
			break;
		case 283:
			work = 0;
			break;
        default:
            break;
		}

		return 1;
    }

    return 0;
}

void Move(int &y, int mode)
{
	switch (mode)
	{
		case 1:
			y++;
			break;
		case 2:
			y--;
			break;
		default:
            break;	
	}
}

int main()

{
    clrscr();
    textbackground(BLACK);

	int x1 = 10, y1 = 12, x2 = 70, y2 = 23, textcol, textback, work = 1, ch, mode;
	int x = (x2 - x1) / 2, y = (y2 - y1) / 2;

    ActiveWindow(x1, y1, x2, y2, BLACK, WHITE);
    _setcursortype (_NOCURSOR);

    gotoxy(x,y);
    cprintf("*");

    while (work)
    {
        if (BiosF(work, mode))
        {
			do
			{
				Move(y, mode);
				clrscr();
				gotoxy(x,y);
				cprintf("*");
				if (x == 0)
					x = x2 - x1 + 1;
				if (x == x2 - x1 + 2)
					x = 1;
				if (y == 0)
				{
					y = y2 - y1 + 1;
					x--;
				}
				if (y == y2 - y1 + 2)
				{
					y = 1;
					x++;
				}
				delay(100);
			}while(!bioskey(1));
        }

    }
	return 0;
}
 
#include <iostream.h>
#include <GRAPHICS.H>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <bios.h>

void ActiveWindow(int x1, int y1, int x2, int y2, int textback, int textcol)
{
    window (x1-1, y1-1, x2+1, y2+2);
    textbackground(textback);
    clrscr();
    textcolor(textcol);

    for (int i = 0; i < x2 - x1 + 3; i++)
        cprintf("#");

	for(int j = 0; j < (y2 - y1 + 1); j++)
	{
		cprintf("#");

	    for(int k = 0; k < (x2 - x1 + 1); k++)
			cprintf(" ");

		cprintf("#");
	};

	for (int p = 0; p < x2 - x1 + 3; p++)
        cprintf("#");

    window(x1,y1,x2,y2);
    textbackground(textback);
	clrscr();
	textcolor(textcol);
}

int StandartF(int &work, int &mode)
{
    char ch;

    if (kbhit())
    {
        ch = getch();
        switch (ch)
		{
		case 89:
			mode = 1;
			break;
		case 91:
			mode = 2;
			break;
		case 27:
			work = 0;
			break;
        default:
            break;
		}

		return 1;
    }

    return 0;
}

void Move(int &y, int mode)
{
	switch (mode)
	{
		case 1:
			y++;
			break;
		case 2:
			y--;
			break;
		default:
            break;	
	}
}

int main()

{
    clrscr();
    textbackground(BLACK);

	int x1 = 10, y1 = 12, x2 = 70, y2 = 23, textcol, textback, work = 1, ch, mode;
	int x = (x2 - x1) / 2, y = (y2 - y1) / 2;
