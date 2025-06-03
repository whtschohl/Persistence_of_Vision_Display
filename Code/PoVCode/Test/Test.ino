/* Code by 
 *  Hans W. Tschohl
 * 
 * This Code is used to display words to a Persistence of Vission Display
 * designed by Hans W. Tschohl. 
 * 
 * function distLetter will flash LEDs from both sides of the rotating 'fan'.
 */

// Numbers

int num9[] = { 48, 145, 145, 146, 124};
int num8[] = {110, 145, 145, 145, 110};
int num7[] = { 96, 128, 135, 152, 224};
int num6[] = { 62,  73, 137, 137,   6};
int num5[] = {250, 145, 145, 145, 142};
int num4[] = { 12,  52,  68, 255,   4};
int num3[] = { 70, 129, 145, 145, 110};
int num2[] = { 49, 131, 133, 137, 113};
int num1[] = {  0,  65, 255,   1,   0};
int num0[] = {126, 135, 153, 225, 126};

// Letters

int A[] = { 63,  72, 136,  72,  63};
int B[] = {255, 145, 145, 145, 110};
int C[] = {126, 129, 129, 129,  70};
int D[] = {225, 129, 129, 129, 126};
int E[] = {255, 145, 145, 145, 129};
int F[] = {255, 144, 144, 144, 128};
int G[] = {126, 129, 129, 137,  79};
int H[] = {255,  16,  16,  16, 255};
int I[] = {  0, 129, 255, 129,   0};
int J[] = {  2, 129, 255, 128,   0};
int K[] = {255,  16,  40,  68, 131};
int L[] = {255,   1,   1,   1,   1};
int M[] = {255,  96,  16,  96, 255};
int N[] = {255,  96,  24,   6, 255};
int O[] = {126, 129, 129, 129, 126};
int P[] = {255, 144, 144, 144,  96};
int Q[] = {124, 130, 138, 134, 125};
int R[] = {255, 144, 152, 148,  99};
int S[] = { 98, 145, 145, 145,  78};
int T[] = {128, 128, 255, 128, 128};
int U[] = {254,   1,   1,   1, 254};
int V[] = {254,  28,   3,  28, 254};
int W[] = {252,   7,  24,   7, 252};
int X[] = {195,  36,  24,  36, 195};
int Y[] = {192,  32,  31,  32, 192};
int Z[] = {199, 135, 145, 161, 195};
int Ao[]= { 15,  20, 164,  20,  15};
int Ae[]= { 15, 148,  36, 148,  15};
int Oe[]= { 30, 161,  33, 161,  30};
int Ue[]= { 62, 129,   1, 129,  62};
int Ss[]= {127, 132, 164,  88,   0};

int Test[]= {255,255,255,255,255};

//Symbols

int _[] = {  0,   0,   0,   0,   0};
int Exclaim[] ={  0,  0, 253, 0, 0};

// Pins

      // Shift Registers
int srSD1   = 11;   //srSD - Shifr Register Serial Data
int shiftC1 = 12;   //shift clock CP
int latchC1 = 10;   //latch clock CE

int srSD2   = 8;
int shiftC2 = 9;
int latchC2 = 7;

int srSD3   = 5;
int shiftC3 = 6;
int latchC3 = 4;

int srSD4   = 2;
int shiftC4 = 3;
int latchC4 = 0;

        //Hall effect sensor (positional sensor)
int HES_pin = 13;

// Variables

int letterDist;       // time delay between letters in ms
int nextArray;        // time delay between arrays in ms (5 arrays = 1 letter)
int revTime;           // time it takes for 1 revolution in ms

void setup() 
{
  pinMode(HES_pin, INPUT);
  
  pinMode(srSD1, OUTPUT);
  pinMode(shiftC1, OUTPUT);
  pinMode(latchC1, OUTPUT);
  pinMode(srSD2, OUTPUT);
  pinMode(shiftC2, OUTPUT);
  pinMode(latchC2, OUTPUT);
  pinMode(srSD3, OUTPUT);
  pinMode(shiftC3, OUTPUT);
  pinMode(latchC3, OUTPUT);
  pinMode(srSD4, OUTPUT);
  pinMode(shiftC4, OUTPUT);
  pinMode(latchC4, OUTPUT);
  
//  pinMode(hbS1, OUTPUT);
//  pinMode(hbS2, OUTPUT);
//  pinMode(hbS3, OUTPUT);
//  pinMode(hbS4, OUTPUT);
  
  letterDist = 5; 
  nextArray = 1;
  revTime = 2;
}

void dispLetter1(int letter[])
{
  int i; //i is the letter placement number 

  for (int iCount = 0; iCount < 5; iCount++)
  {
    digitalWrite(latchC1, LOW);
    
    shiftOut(srSD1, shiftC1, MSBFIRST, letter[iCount]);
    digitalWrite(latchC1, HIGH);
    delay(nextArray);
  }
  digitalWrite(srSD1, 0);
  digitalWrite(latchC1, HIGH);
  delay(letterDist);
  digitalWrite(latchC1, LOW);
}

void dispLetter4(int letter[])
{
  int i; //i is the letter placement number 

  for (int iCount = 0; iCount < 5; iCount++)
  {
    digitalWrite(latchC4, LOW);
    
    shiftOut(srSD4, shiftC4, MSBFIRST, letter[iCount]);
    digitalWrite(latchC4, HIGH);
    delay(nextArray);
  }
  digitalWrite(srSD4, 0);
  digitalWrite(latchC4, HIGH);
  delay(letterDist);
  digitalWrite(latchC4, LOW);
}

void loop() 
{
  int numOfLetters;
  
    dispLetter1(Test);

}
