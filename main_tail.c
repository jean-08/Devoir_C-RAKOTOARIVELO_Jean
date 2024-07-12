#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"


int main (int argc,char *argv[]){
    if (argc < 2) {
       
        traiter_options(2, argv);
    } else {
        traiter_options(argc, argv);
    }
	
	return 0;
}
