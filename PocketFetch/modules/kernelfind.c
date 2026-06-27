#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mods.h"

char *kernel_type(void){
	static char kernel_name[20];

	FILE *fp= fopen("/proc/sys/kernel/ostype","r");
	if (fgets(kernel_name,sizeof(kernel_name),fp) == NULL) {
	return NULL;}
	kernel_name[strlen(kernel_name)-1] = '\0';

	return kernel_name;
}


char *kernel_ver(void){
	static char ver[25];

	FILE *fp= fopen("/proc/sys/kernel/osrelease","r");
	
	if (fgets(ver, sizeof(ver),fp) == NULL) {
	return NULL; };
	ver[strlen(ver)-1] = '\0';
	return ver;
}

void kernel_print(void){
	char *name= kernel_type();
	char *version= kernel_ver();

	printf(" Kernel: %s (%s)\n",name,version);

}
