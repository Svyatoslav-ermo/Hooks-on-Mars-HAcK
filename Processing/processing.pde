import processing.serial.*;  //imports library used for wireless comm with the HC-05
Serial myPort;               // declares Serial Port object from library
String Text = "";

void setup()
{
 size(600,700);                         // create window of this size
 myPort=new Serial(this, "COM11", 115200);  //COM port will likely be different, try different ones until it works (usually one of COM3-COM7)
 myPort.bufferUntil('\n');               //delays calling serialEvent unitl reaching '\n'
}

void serialEvent(Serial myPort){        //serialEvent is called whenever data is available
  Text = myPort.readStringUntil('\n');   //reads Serial.println() from Arduino
}

int state = 0;
int x = 0;
void draw()
{

  background(237,240,241);        // sets background to a color, parameters correspond to an RGB code
  fill(20,160,133);               // sets color we will use to fill shapes
  stroke(33);                     // sets color used for border around shapes
  strokeWeight(1);                // sets width of stroke when drawing shapes
  
  rect(x,500,50,50,10);           //creates a rectangle at x,y with size width,height
  x+=1;
  if (x == 600)
    x=0;
  
  fill(0);
  textSize(32);
  text(Text, 400, 600);           //draws text at x,y
    
  if (state == 1) {
    myPort.write('w');            //writes to the Bluetooth Serial port
    state = 0;
  } else if (state == 2) {
    myPort.write('s');
    state = 0;
  } else if (state == 3) {
    myPort.write('a');
    state = 0;
  } else if (state == 4) {
    myPort.write('d');
    state = 0;
  } else if (state == 5) {
    myPort.write('z');
    state = 0;
  } else if (state == 6) {
    myPort.write('x');
    state = 0;
  } else if (state == 7) {
    myPort.write('o');
    state = 0;
  } else if (state == 8) {
    myPort.write('p');
    state = 0;
  } else if (state == 9) {
    myPort.write('m');
    state = 0;
  } else if (state == 10) {
    myPort.write('k');
    state = 0;
  } else if (state == 11) {
    myPort.write('l');
    state = 0;
  } 
  
  delay(20);

}

void keyPressed() 
{               
  //called whenever a key is pressed, key is automatically set to the key that is pressed
  if(key == 'w')
    state = 1;
  else if (key == 's')
    state = 2;
  else if (key == 'a')
    state = 3;
  else if (key == 'd')
    state = 4;
  else if (key == 'z')
    state = 5;
  else if (key == 'x')
    state = 6;
  else if (key == 'o')
    state = 7;
  else if (key == 'p')
    state = 8;
  else if (key == 'm')
    state = 9;
  else if (key == 'k')
    state = 10;
  else if (key == 'l')
    state = 11;
  
}
