#include <oslib/oslib.h>

PSP_MODULE_INFO("OSlib Menu Example",0,1,1);

OSL_COLOR black = RGB(0,0,0),red = RGB(255,0,0), white = RGB(255,255,255);

int select,foo;

void oslPrintText(int x, int y, char * text, OSL_COLOR color) {
	oslSetTextColor(color);
	oslSetBkColor(RGBA(0,0,0,0));
	oslPrintf_xy(x,y,text);
}

char menuItems[10][25] = {
	{"Item 0"},
	{"Start"},
	{"Options"},
	{"Item 2"},
	{"Controls"},
	{"Online Play"},
	{"Item 6"},
	{"Item 7"},
	{"Credits"},
	{"Exit"},
};

int main(){
        oslInit(0);
	oslInitGfx(OSL_PF_8888,1);
	oslInitConsole();

	while(!osl_quit) {
		oslStartDrawing();
        	oslReadKeys();
        	oslClearScreen(white);

		for(foo=0;foo<10;foo++) {
			oslPrintText(200,foo*10+70,menuItems[foo],black);
		}
		oslPrintText(200,select*10+70,menuItems[select],red);
		if ((osl_keys->pressed.up) && (select > 0))
			select--;
		if ((osl_keys->pressed.down) && (select < 9))
			select++;
		oslEndDrawing();
		oslSyncFrame();
	}
	oslQuit();
	return 0;
}
