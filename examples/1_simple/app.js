/*
* 3ds.js
* Example 1 "Simple"
* This example showcases a benchmarking
*/

print("\x1b[0;0H"); //Clear the screen
print("3ds.js version: " + platform.version);
print("duktape version: " + Duktape.version);

//Based on http://duktape.org/guide.html#gettingstarted
function banchmark1() {
	print("\n\n\n(1/3) Benchmarking an algorithm...\n");
	function fib(n) {
		if (n == 0) { return 0; }
		if (n == 1) { return 1; }
		return fib(n-1) + fib(n-2);
	}
	function test() {
		var res = [];
		for (i = 0; i < 20; i++) {
			res.push(fib(i));
		}
	}
	var t0 = new Date().getTime();
	test();
	var t1 = new Date().getTime();
	print("Took " + (t1 - t0).toString() + " millisecond(s).");
}

//Based on http://blog.scottlogic.com/2010/10/15/javascript-array-performance.html
function banchmark2() {
	print("\n\n\n(2/3) Benchmarking arrays...\n");
	var result = 0;
    var a = [];

    for (var i = 0; i < 1; i++) {
      a = [];
      var start = new Date().getTime();

      for (var j = 0; j < 100000; j++) {
        a.push(i);
      }

      var end = new Date().getTime();
      result += end - start;
    }

    print("Took " + result.toString() + " millisecond(s).");
}

//Based on http://www.sitepoint.com/measuring-javascript-functions-performance/
function banchmark3() {
	print("\n\n\n(3/3) Benchmarking hash generation...\n");
	function makeHash(source) {
	  var hash = 0;
	  if (source.length === 0) return hash;
	  for (var i = 0; i < source.length; i++) {
		var char = source.charCodeAt(i);
		hash = ((hash<<5)-hash)+char;
		hash = hash & hash;
	  }
	  return hash;
	}
	var result = 0;
	
	var start = new Date().getTime();
	for (var i = 0; i < 10000; i++) {
		makeHash("3ds.js by filfat Studios AB");
	}
	var end = new Date().getTime();
    result += end - start;

    print("Took " + result.toString() + " millisecond(s).");
}

banchmark1();
banchmark2();
banchmark3();
