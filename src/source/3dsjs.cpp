//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3dsjs.h"
#include "duktape/duktape.h"

using namespace std;


void dsJSInit(duk_context *ctx) {
	duk_push_global_object(ctx);
	duk_push_object(ctx);
	duk_idx_t obj_idx = duk_push_object(ctx);
	
	duk_push_string(ctx, __FRAMEWORK_VERSION__);
	duk_put_prop_string(ctx, obj_idx, "version");
	
	duk_put_global_string(ctx, "platform");
	duk_pop(ctx);
}