#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mods.h"

void ramfind(void){
	char buffer[500];
	char fullram[25];
	char freeram[25];
	double usedram=0;
	double usedpercent;

	FILE *fp= fopen("/proc/meminfo","r");
	
	size_t ram= fread(buffer, 1, 100, fp);

	buffer[ram] = '\0';
	
	char *start = strstr(buffer, "l");

	char *end = strstr(buffer, "kB");

	int len= end -start;

	strncpy(fullram, start+2, len-3);
	strncpy(freeram, end+12, len-3);


	fullram[len+2] = '\0';
	freeram[len+4] = '\0';

	double fullram_int= atoi(fullram);
	double freeram_int= atoi(freeram);

	freeram_int = (((freeram_int + 500)/1000)/1024);
	fullram_int = (((fullram_int + 500)/1000)/1024);
	
	usedram = fullram_int - freeram_int;

	usedpercent = (usedram *100.00/fullram_int);


	//printf("Total RAM = %.2f Gib\n",fullram_int);
	//printf("Free RAM = %.2f Gib\n",freeram_int);
	//printf("Used RAM = %.2f Gib\n",usedram);
	printf(" Memory: %.2f Gib/ %.2f Gib (%.2f%%)\n", usedram, fullram_int, usedpercent);

}

