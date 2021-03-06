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


int input_getInputDown(duk_context *ctx);
int input_getInputUp(duk_context *ctx);
int input_getInput(duk_context *ctx);
void inputInit(duk_context *ctx);

extern duk_function_list_entry input_funcs[];