//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"
#include "duktape/duktape.h"

using namespace std;


duk_function_list_entry fileIO_funcs[] = {
	{ "write", fileIO_write, 2 },
	{ "read", fileIO_read, 1 },
	{ NULL, NULL, 0 }
};

/*
    taken from http://stackoverflow.com/a/3464656/3142553 because I'm lazy
*/
char* _readFile(char* filename) {
   char *buffer = NULL;
   int string_size,read_size;
   FILE *handler = fopen(filename,"r");

   if (handler) {
       fseek(handler,0,SEEK_END);
       string_size = ftell (handler);
       rewind(handler);

       buffer = (char*) malloc (sizeof(char) * (string_size + 1) );
       read_size = fread(buffer,sizeof(char),string_size,handler);
       buffer[string_size] = '\0';

       if (string_size != read_size) {
           free(buffer);
           buffer = NULL;
        }
    }
    return buffer;
}

int fileIO_getExecPath(duk_context *ctx) {
	duk_push_string(ctx, (char*)execPath.c_str());
	return 1;
}

int fileIO_read(duk_context *ctx) {
	char *fn = (char*)duk_to_string(ctx, 0);
	duk_push_string(ctx, _readFile(fn));
	return 1;
}

//FileIO.write placeholder
int fileIO_write(duk_context *ctx) {
    char *fn = (char*)duk_to_string(ctx, 0);
    char *out = (char*)duk_to_string(ctx, 1);
    
    if (fn[0] != '/') sprintf(fn, "%s/%s", (char*)execPath.c_str(), fn);
    printf(fn);
    //TODO: Write to file
    
    return 1;
}

void fileIOInit(duk_context *ctx) {
	duk_push_global_object(ctx);
	duk_push_object(ctx);
	duk_put_function_list(ctx, -1, fileIO_funcs);
	duk_put_prop_string(ctx, -2, "FileIO");
	duk_pop(ctx);
}
