#include <stdio.h>

#include "mods.h"


int main(void){
	topbar_print();
	printf("/-----------------------------------\\\n\n");
	OSprint();
	kernel_print();
	ramfind();
	terminal_print();
	printf("\n\\-----------------------------------/\n");
	return 0;
}


//Logo,
