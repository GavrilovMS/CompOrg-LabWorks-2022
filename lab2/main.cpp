#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

void Color(int i){
	switch (i)
	{
		case BLACK: cputs("BLACK");
		break;
		case BLUE: cputs("BLUE");
		break;
		case GREEN: cputs("GREEN");
		break;
		case CYAN: cputs("CYAN");
		break;
		case RED: cputs("RED");
		break;
		case MAGENTA: cputs("MAGENTA");
		break;
		case BROWN: cputs("BROWN");
		break;
		case LIGHTGRAY: cputs("LIGHTGRAY");
		break;
		case DARKGRAY: cputs("DARKGRAY");
		break;
		case LIGHTBLUE: cputs("LIGHTBLUE");
		break;
		case LIGHTGREEN: cputs("LIGHTGREEN");
		break;
		case LIGHTCYAN: cputs("LIGHTCYAN");
		break;
		case LIGHTRED: cputs("LIGHTRED");
		break;
		case LIGHTMAGENTA: cputs("LIGHTMAGENTA");
		break;
		case YELLOW: cputs("YELLOW");
		break;
		case WHITE: cputs("WHITE");
		break;
		default:
		break;
	}
}

void scroll()
{
	for (int i=0; i<=1; i++)
		insline();
}

int main()
{
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	window(10, 12, 70, 23);
	gotoxy(1, 1);
	for (int i = 0; i <= 7; i++)
	{
		textbackground(i);
		for (int j = 0; j <= 15; j++)
		{
			textcolor(j);
			cputs(" back:");
			Color(i);
			cputs(" text:");
			Color(j);
			cputs("\n\r");	
			delay(300);
			scroll();
		}
	}
	getche();
	return 0;
}
