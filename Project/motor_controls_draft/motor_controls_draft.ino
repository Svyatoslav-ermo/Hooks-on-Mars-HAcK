// Motor A connections
int enA = 7;
int in1 = 6;
int in2 = 5;
// Motor B connections
int enB = 2;
int in3 = 4;
int in4 = 3;

//Setting gear levels for robot to move at different speeds at different gears.
//The user can press 2 keys to either move up or down the gears, thus increasing or decreasing the speed.
int gear0 = LOW; //resting state of the robot
int gear1 = 50;
int gear2 = 100;
int gear3 = 150;
int gear4 = 200;
int gear5 = HIGH;

void setup() //rename later as "initialState" to avoid the other setup function
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors (Gear 0)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() //calls two defined functions at an interval of one second
{
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl() 
{
  // Set motors to resting state
  // For PWM maximum possible values are 0 to 255
  
  
  analogWrite(enA, gear1);
  analogWrite(enB, gear1);
  
  //these If statements control the direction of the robot by controlling the direction
  //of the motors (clockwise or counterclockwise) when you press the w,a,s,d keys. 
  
  if (uart_receive == 'w')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);
  }
  else if (uart_receive == 's')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
  }
  else if (uart_receive == 'a')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
  }
  else if uart_receive == 'd')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);
  }
  /*
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  
  // Now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
*/
  
  
//This function lets you control speed of the motors
void speedControl() 
{
   // We will use 2 keys to switch the gears for the robot so it moves at different speeds at different gears.
  
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  /* Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) 
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  */

  
  if (
  
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) 
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
