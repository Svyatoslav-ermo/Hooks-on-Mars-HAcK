// Motor A connections
int enA = 6;
int in1 = 7;
int in2 = 5;
// Motor B connections
int enB = 3;
int in3 = 4;
int in4 = 2;


void setup() //rename later as "initialState" to avoid the other setup function
{
  Serial.begin(9600);
  while(!Serial) 
  {
    ;
  }
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

char uart_receive;
//int gear = 0;

//Setting gear levels for robot to move at different speeds at different gears.
//The user can press numbered keys to either move up or down the gears, thus increasing or decreasing the speed.
//int gear0 = LOW;
//int gear1 = 50;
//int gear2 = 100;
//int gear3 = 150;
//int gear4 = 200;
//int gear5 = HIGH;

//void speedControl() 
//{
//   // For PWM the range is from 0 to 255
//  //gear = gear1;
//  analogWrite(enA, gear);
//  analogWrite(enB, gear);
//
//  if (uart_receive == '1')
//  {
//    gear = gear1;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//  else if (uart_receive == '2')
//  {
//    gear = gear2;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//  else if (uart_receive == '3')
//  {
//    gear = gear3;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//  else if (uart_receive == '4')
//  {
//    gear = gear4;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//  else if (uart_receive == '5')
//  {
//    gear = gear5;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//  else if (uart_receive == '0') //No PWM so no speed
//  {
//    gear = gear0;
//    analogWrite(enA, gear);
//    analogWrite(enB, gear);
//    uart_receive = '\0';
//    delay(20);
//  }
//}

// This function lets you control spinning direction of motors
void directionControl() 
{
  // Set motors to resting state
 
  
  //these If statements control the direction of the robot by controlling the direction
  //of the motors (clockwise or counterclockwise) when you press the w,a,s,d keys. 
  
  if (uart_receive == 'w')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    uart_receive = '\0';
    //delay(2000);
  }
  else if (uart_receive == 's')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    uart_receive = '\0';
    //delay(2000);
  }
  else if (uart_receive == 'a')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    uart_receive = '\0';
    //delay(2000);
  }
  else if (uart_receive == 'd')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    uart_receive = '\0';
    //delay(2000);
  }
  else if (uart_receive == '\0')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

void loop() //calls two defined functions at an interval of one second
{
  if (Serial.available())
  {
    uart_receive = char(Serial.read());
    Serial.print(uart_receive);
    
  }
  
  directionControl();
  delay(20);
  
  
  //speedControl();
  //delay(20);
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
  
