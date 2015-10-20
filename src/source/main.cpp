//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!

#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "duktape/duktape.h"
#include "3dsjs.h"
#include "input.h"
#include "fileIO.h"

using namespace std;


duk_context *ctx = NULL;

int main(int argc, const char** argv) {
	srvInit();
	aptInit();
	hidInit();
	fsInit();
	sdmcInit();
	gfxInitDefault();
	//uiInit();
	
	consoleInit(GFX_TOP, NULL);
	printf("\x1b[0;0H"); //Reset position
	
	//Hacky way to improve n3ds performance
	aptOpenSession();
	Result ret = APT_SetAppCpuTimeLimit(NULL, 80);
	aptCloseSession();
	
	
	//Create HEAP
	ctx = duk_create_heap_default();
	if(!ctx) {
        printf("Failed to create a Duktape HEAP!");
        while (1) { }
    }
	
	//Register Helpers
	dsJSInit(ctx);
	inputInit(ctx);
	fileIOInit(ctx);
	
	//Handle module loading
	//TODO: Load 'em from the same directory as the 3dsx file
	duk_eval_string(ctx, "Duktape.modSearch=function(id){return FileIO.read('/' + id + '.js').toString();}");
	
	//Load "app.js"
	//TODO: Load it from the same directory as the 3dsx file
	if (duk_peval_file(ctx, "/app.js") != 0) {
        printf(duk_safe_to_string(ctx, -1));
		while (1) { }
    }
	
	printf("\n\n\nPress \"A\" to exit...");
	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A) break;
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	
	//Destory the HEAP
	duk_destroy_heap(ctx);
	
	//uiExit();
	gfxExit();
	fsExit();
	sdmcExit();
	hidExit();
	aptExit();
	srvExit();
	exit(1);
}
