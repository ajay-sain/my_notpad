#include <iostream>
#include "../include/_error.h"

void error_calbsck(int error_code, const char* error_description){
    fprintf(stderr, "Error Code: %d \n Description:: %s\n", error_code, error_description);
}