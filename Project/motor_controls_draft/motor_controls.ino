// Motor A (front left wheel) connections
int enA = 3;
int in1a = 2;
int in2a = 4;
// Motor B (back left wheel) connections
int enB = 6;
int in3a = 5;
int in4a = 7;

//Motor C (back right wheel) connections
int in1b = 8;
int in2b = 11;
int enC = 9;

//motor D (front right wheel) communications
int in3b = 12;
int in4b = 13;
int enD = 10;


void setup() //Function for intializing the motors to not move.
{
  Serial.begin(9600);
  while(!Serial) 
  {
    ;
  }
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in1a, OUTPUT);
  pinMode(in2a, OUTPUT);
  pinMode(in3a, OUTPUT);
  pinMode(in4a, OUTPUT);
  pinMode(in1b, OUTPUT);
  pinMode(in2b, OUTPUT);
  pinMode(in3b, OUTPUT);
  pinMode(in4b, OUTPUT);
  
  
  // Turn off motors (Gear 0)
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, LOW);
  digitalWrite(in3a, LOW);
  digitalWrite(in4a, LOW);
  digitalWrite(in1b, LOW);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, LOW);
  digitalWrite(in4b, LOW);

  // Set speed PWM for all motors to 50
  analogWrite(enA, 50);
  analogWrite(enB, 50);
  analogWrite(enC, 50);
  analogWrite(enD, 50);
}

/*
The below code was an idea we had for changing the speed of the motors by increasing
or decreasing the PWM in each motor by increments of 50 based on what key we pressed.
We called them gears and defined them below, but during the testing phase, we did not
see a change in the motor speed. We believe it is due to the lack of voltage that supplies
the PWM to the motors.


int gear;

Setting gear levels for robot to move at different speeds at different gears.
The user can press numbered keys to either move up or down the gears, thus increasing or decreasing the speed.
int gear0 = LOW;
int gear1 = 50;
int gear2 = 100;
int gear3 = 150;
int gear4 = 200;
int gear5 = HIGH;
*/

char uart_receive; //this character is being read by input

void moveForward() //moves all wheels forward
{
  digitalWrite(in1a, HIGH);
  digitalWrite(in2a, LOW);
  digitalWrite(in3a, HIGH);
  digitalWrite(in4a, LOW);

  digitalWrite(in1b, HIGH);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, LOW);
  digitalWrite(in4b, HIGH);
  uart_receive = '\0';
}

void moveBackward() //moves all wheels backward
{
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, HIGH);
  digitalWrite(in3a, LOW);
  digitalWrite(in4a, HIGH);

  digitalWrite(in1b, LOW);
  digitalWrite(in2b, HIGH);
  digitalWrite(in3b, HIGH);
  digitalWrite(in4b, LOW);
  uart_receive = '\0';
}

void turnLeft() //controls certain wheels to move robot to the left
{
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, LOW);
  digitalWrite(in3a, HIGH);
  digitalWrite(in4a, LOW);

  digitalWrite(in1b, HIGH);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, LOW);
  digitalWrite(in4b, HIGH);
  uart_receive = '\0';
}

void turnRight() //controls certain wheels to move robot to the right
{
  digitalWrite(in1a, HIGH);
  digitalWrite(in2a, LOW);
  digitalWrite(in3a, HIGH);
  digitalWrite(in4a, LOW);

  digitalWrite(in1b, LOW);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, LOW);
  digitalWrite(in4b, HIGH);
  uart_receive = '\0';
}

void reverseLeft() //controls certain wheels to reverse robot to the left
{
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, HIGH);
  digitalWrite(in3a, LOW);
  digitalWrite(in4a, LOW);

  digitalWrite(in1b, LOW);
  digitalWrite(in2b, HIGH);
  digitalWrite(in3b, HIGH);
  digitalWrite(in4b, LOW);
  uart_receive = '\0';
}

void reverseRight() //controls certain wheels to reverse robot to the right
{
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, HIGH);
  digitalWrite(in3a, LOW);
  digitalWrite(in4a, HIGH);

  digitalWrite(in1b, LOW);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, HIGH);
  digitalWrite(in4b, LOW);
  uart_receive = '\0';
}
void Dance() //Unfinished code to make robot dance to cupid shuffle
{
  turnRight();
  delay(50);
  turnRight();
  delay(50);
  turnRight();
  delay(50);
  turnRight();
  delay(50);
  turnLeft();
  delay(50);
  turnLeft();
  delay(50);
  turnLeft();
  delay(50);
  turnLeft();
  delay(50);
  
  reverseRight();
  delay(10);
  reverseLeft();
  delay(10);
  reverseRight();
  delay(10);
  reverseLeft();
  delay(10);
}
void Pause() //turns off all motors as a robot's resting phase
{
  digitalWrite(in1a, LOW);
  digitalWrite(in2a, LOW);
  digitalWrite(in3a, LOW);
  digitalWrite(in4a, LOW);
    
  digitalWrite(in1b, LOW);
  digitalWrite(in2b, LOW);
  digitalWrite(in3b, LOW);
  digitalWrite(in4b, LOW);
}

// This function lets you control spinning direction of motors 
void directionControl() 
{
  Pause();
  
  //these If statements control the direction of the robot by controlling the direction
  //of the motors (clockwise or counterclockwise) when you press the w,a,s,d keys. 
  //Z and X are the reverse keys. M is the dance key.
  
  if (uart_receive == 'w')
  {
    moveForward();
  }
  else if (uart_receive == 's')
  {
    moveBackward();
  }
  else if (uart_receive == 'a')
  {
    turnLeft();
  }
  else if (uart_receive == 'd')
  {
    turnRight();
  }
  else if (uart_receive == 'z')
  {
    reverseLeft();
  }
  else if (uart_receive == 'x')
  {
    reverseRight();
  }
  else if (uart_receive == 'm')
  {
    Dance();
  }
  else if (uart_receive == '\0')
  {
    Pause();
  }
  
  /*
  The code below was meant for changing the PWM for the motors based on what key
  was pressed. We defined each key as "gears". The higher the gear, the faster the wheels went.
  Unfortunately we were not able to change the PWM of the motors.
  {
   // For PWM the range is from 0 to 255
    gear = 250;
    analogWrite(enA, 150);
    analogWrite(enB, 150);
    analogWrite(enC, 150);
    analogWrite(enD, 150);

    if (uart_receive == 'c')
    {
      analogWrite(enA, 50);
      analogWrite(enB, 50);
      analogWrite(enC, 50);
      analogWrite(enD, 50);
      uart_receive = '\0';
      delay(20);
    }
    else if (uart_receive == 'v')
    {
      analogWrite(enA, 100);
      analogWrite(enB, 100);
      analogWrite(enC, 100);
      analogWrite(enD, 100);
      uart_receive = '\0';
      delay(20);
    }
    else if (uart_receive == 'b')
    {
      analogWrite(enA, 150);
      analogWrite(enB, 150);
      analogWrite(enC, 150);
      analogWrite(enD, 150);
      uart_receive = '\0';
      delay(20);
    }
    else if (uart_receive == 'n')
    {
      analogWrite(enA, 200);
      analogWrite(enB, 200);
      analogWrite(enC, 200);
      analogWrite(enD, 200);
      uart_receive = '\0';
      delay(20);
    }
    else if (uart_receive == 'm')
    {
      analogWrite(enA, 250);
      analogWrite(enB, 250);
      analogWrite(enC, 250);
      analogWrite(enD, 250);
      uart_receive = '\0';
      delay(20);
    }
    else if (uart_receive == 'l') //No PWM so no speed
    {
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      analogWrite(enC, 0);
      analogWrite(enD, 0);
      uart_receive = '\0';
      delay(20);
    }
  }   
}
*/
  
  

void loop() //calls two defined functions at an interval of one second
{
  if (Serial.available())
  {
    uart_receive = char(Serial.read());
    Serial.print(uart_receive);
  }
  delay(20);
  directionControl();
}
