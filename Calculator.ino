/* BY Suhas Peddinti 
 *  in 9th std at the age of 14yrs
 *  completed on 18-08-2020
 *  My first written-working code for Adruino
 *  *****Calculator*****
*/

//==========================================================================> Global variables
int a = -1;
int b = -1;
int sign = 0;
float result;
//==========================================================================> void setup
void setup() {
  //initialise Serial port
  Serial.begin(9600);
}
//==========================================================================> void loop
void loop() {
  reset();
  Mode();
  Serial.println();
}
//==========================================================================> void Mode
void Mode() {
  int q = 0;
  Serial.println("Press 1 to open Arithmetic calculator");
  Serial.println("Press 2 to open Squares and Cubes calculator");
  Serial.println("Press 3 to open Square and cube roots calculator");
  Serial.print("Entered number: ");
  while (!Serial.available());
  q = readSerial();
  if (q == 0)
  {
    return;
  }
  if (q == 1) {
    Ar_Ca();
  }
  if (q == 2) {
    SqCu_Ca();
  }
  if (q == 3) {
    SqCuRo_Ca();
  }
}
//==========================================================================> Arithmetic calculator
void Ar_Ca() {
  input();
  float Result = findValue();
  //print out the result
  Serial.println();
  Serial.print("Result = ");
  Serial.println(Result);
}
//==========================================================================> SqCu_Calculator
void SqCu_Ca() {
  Serial.println();
  Serial.print("Enter the base value: ");
  while (!Serial.available());
  a = readSerial();
  if (a == -1)
  {
    return;
  }
  Serial.println();
  Serial.println("Enter the power: ");
  while (!Serial.available());
  b = readSerial();
  if (b == -1)
  {
    return;
  }
  float Result;
  Result = pow(a, b);
  //print out the result
  Serial.println();
  Serial.print("Result = ");
  Serial.println(Result);
}
//===========================================================================> SqCuRo_Calculator
void SqCuRo_Ca() {
  Serial.println();
  Serial.print("Enter a value: ");
  while (!Serial.available());
  a = readSerial();
  if (a == -1)
  {
    return;
  }
  Serial.println();
  Serial.println("Enter 1 for squareroot of no.");
  Serial.println("Enter 2 for cuberoot of no.");
  Serial.print("Entered number: ");
  while (!Serial.available());
  int q = readSerial();
  if (q <= 0 || q >= 3)
  {
    return;
  }
  float Result;
  if (q == 1) {
    Result = sqrt(a);
  }
  if (q == 2) {
    int e;
    int w;
    do {
      e = b * b * b;
      if (e == a) {
        w = b;
      }
      b++;
    } while (e != a);
    Result = w ;
  }
  //print out the result
  Serial.println();
  Serial.print("Result = ");
  Serial.println(Result);
}
//===========================================================================> input values
void input() {
  Serial.println();
  //print instructions, and wait until there is something in the serial buffer
  Serial.print("Enter a First value: ");
  while (!Serial.available());
  a = readSerial();
  if (a == -1)
  {
    return;
  }
  Serial.println();
  Serial.println("Enter 1 for Addition");
  Serial.println("Enter 2 for Subtraction");
  Serial.println("Enter 3 for Multiplication");
  Serial.println("Enter 4 for Division");
  Serial.print("Entered number: ");
  while (!Serial.available());
  sign = readSerial();
  if (sign <= 0 || sign >= 5)
  {
    return;
  }
  Serial.println();
  Serial.print("Enter the Second value: ");
  while (!Serial.available());
  b = readSerial();
  if (b == -1)
  {
    return;
  }
}
//==========================================================================> readSerial
//readSerial takes the neat integer in the Serial buffer
//clears the buffer, then returns it
int readSerial() {
  int i = Serial.parseInt();
  Serial.println(i);
  Serial.parseInt();
  return i;
}
//==========================================================================> findValue
int findValue () {
  //work out the maths problem
  if (sign == 1) {
    result = a + b;
  }
  if (sign == 2) {
    result = a - b;
  }
  if (sign == 3) {
    result = a * b;
  }
  if (sign == 4) {
    result = a / b;
  }
  return result ;
}
//===========================================================================> reset
void reset() {
  a = -1;
  b = -1;
  sign = 0;
  result = 0;
}
//***************************************************************************> End
