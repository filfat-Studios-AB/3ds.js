/*
* 3ds.js
* Example 3 "Input"
* This example showcases input
*/

print("Press B to exit the loop");
while(1){
    var inp = Input.getKeyDown();
    var toh = Input.getTouch();

    if(inp && inp == 2)
        break;
    else if(inp)
        print("Key: " + inp);
    
    if(toh.isDown)
        print("Touch: " + toh.x + ", " + toh.y);
}
