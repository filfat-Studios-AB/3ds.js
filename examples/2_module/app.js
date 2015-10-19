/*
* 3ds.js
* Example 2 "Modules"
* This example showcases how to use modules
*/

print("\x1b[0;0H"); //Clear the screen
print("Hello World from app.js");

var lib = require('library');
lib.hello(lib.world);