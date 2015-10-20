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


int input_getTouch(duk_context *ctx);
int input_getKeyDown(duk_context *ctx);
void inputInit(duk_context *ctx);

static duk_function_list_entry input_funcs[] = {
	{ "getTouch", input_getTouch, 2 },
	{ "getKeyDown", input_getKeyDown, 1 },
	{ NULL, NULL, 0 }
};