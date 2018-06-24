#ifndef TYPES__H
#define TYPES__H

#include <stdio.h>

typedef enum{
	OK = 0,
	ERR_INVALID_OUTPUT_FILE,
	ERR_WRITING_TO_FILE,
	ERR_CLOSING_FILE
}status_t;

#endif