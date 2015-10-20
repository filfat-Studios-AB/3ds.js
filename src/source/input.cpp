//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!
#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "duktape/duktape.h"

using namespace std;

int input_getTouch(duk_context *ctx){
	hidScanInput();
	u32 kDown = hidKeysDown();
	touchPosition tp;
	hidTouchRead(&tp);
	
	bool isDown = false;
	int x = tp.px, y = tp.py;
	
	if(kDown & KEY_TOUCH){
		isDown = true;
	}
	
	duk_idx_t obj = duk_push_object(ctx);
	duk_push_boolean(ctx, isDown);
	duk_put_prop_string(ctx, obj, "isDown");
	
	duk_push_number(ctx, x);
	duk_put_prop_string(ctx, obj, "x");
	
	duk_push_number(ctx, y);
	duk_put_prop_string(ctx, obj, "y");
	return 1;
}

int input_getKeyDown(duk_context *ctx) {
	hidScanInput();
	u32 kDown = hidKeysDown();
	
	duk_push_number(ctx, (int)kDown);
	return 1;
}

void inputInit(duk_context *ctx) {
	duk_push_global_object(ctx);
	duk_push_object(ctx);
	duk_put_function_list(ctx, -1, input_funcs);
	duk_put_prop_string(ctx, -2, "Input");
	duk_pop(ctx);
}