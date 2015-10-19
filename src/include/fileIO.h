//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!
#pragma once
#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "duktape/duktape.h"

using namespace std;


char* _readFile(char* filename);
int fileIO_read(duk_context *ctx);
void fileIOInit(duk_context *ctx);

static duk_function_list_entry fileIO_funcs[] = {
	{ "read", fileIO_read, 1 },
	{ NULL, NULL, 0 }
};