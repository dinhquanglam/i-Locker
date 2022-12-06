//BY ARDUICREATE
//INCLUDE THESE LIBRARYS
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(2, 3);
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define Password_Lenght 5 // Give enough room for six chars + NULL char
char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
 char codeLocker1[Password_Lenght]= "1111";
char codeLocker2[Password_Lenght]= "2222";
char codeLocker3[Password_Lenght]= "3333";
char codeLocker4[Password_Lenght]= "4444" ;

char C[3];
void I2C(int);

byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3',},
  {'4', '5', '6',},
  {'7', '8', '9',},
  {'*', '0', '#',}
};

byte rowPins [ROWS] = {8, 10, 6, 5}; //pins of the keypad
byte colPins [COLS] = {4, 9, 2};
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int lightLocker1 = 0;
int lightLocker2 = 3;
int lightLocker3 = 1;
int lightLocker4 = 7;


void setup()
{

Serial.begin(115200);
Wire.begin(19,18);
lcd.init();
lcd.backlight();

  Serial.println("Sent via phone number & gmail");
  Serial.println("Code for costumer 1: 1111");
  Serial.println("---------------------------------");
  
  Serial.println("Sent via phone number & gmail");
  Serial.println("Code for costumer 2: 2222");
  Serial.println("---------------------------------");

  Serial.println("Sent via phone number & gmail");
  Serial.println("Code for costumer 3: 3333");
  Serial.println("---------------------------------");

  Serial.println("Sent via phone number & gmail");
  Serial.println("Code for costumer 4: 4444");
  Serial.println("---------------------------------");
  
  pinMode(lightLocker1, OUTPUT);
  pinMode(lightLocker2, OUTPUT);
  pinMode(lightLocker3, OUTPUT);
  pinMode(lightLocker4, OUTPUT);

}

void loop(){


  lcd.setCursor(0, 0);
  lcd.print("Enter Password");

  customKey = myKeypad.getKey();
  if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }

  if (data_count == Password_Lenght - 1) // if the array index is equal to the number of expected chars, compare data to master
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Pass is");

    if (!strcmp(Data, codeLocker1)) // equal to (strcmp(Data, Master) == 0)
    {
      lcd.setCursor(0, 1);
      lcd.print("CORRECT-Locker1");
      openLocker1();
    }
    else if (!strcmp(Data, codeLocker2)){
      lcd.setCursor(0, 1);
      lcd.print("CORRECT-Locker2");
      openLocker2();
    }
    else if (!strcmp(Data, codeLocker3)){
      lcd.setCursor(0, 1);
      lcd.print("CORRECT-Locker3");
      openLocker3();
    }
    else if (!strcmp(Data, codeLocker4)){
      lcd.setCursor(0, 1);
      lcd.print("CORRECT-Locker4");
      openLocker4();
    }

    else {
      lcd.setCursor(0, 1);
      lcd.print("INCORRECT");
      wrongCode();
    }
    delay(1000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.
    lcd.clear();
    clearData();
  }
}

void clearData()
{
  while (data_count != 0)
  { // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}
void wrongCode()
{
  Serial.println("Wrong Code");
  Serial.println("Try again!!!");
  Serial.println("---------------------------------");

  delay(2000);
}
void openLocker1()
{
  Serial.println("locker1 open");
  digitalWrite(lightLocker1,HIGH);
  assign(codeLocker1);
  delay(500);
  Serial.println("a new code is generating...");
  delay(1000);
  Serial.println("Sent code via phone number & gmail");
  delay(1000);
  Serial.print("Code for costumer of L1: ");
  Serial.println(codeLocker1);
  Serial.println("---------------------------------");
  delay(2000);
  digitalWrite(lightLocker1,LOW);

}
void openLocker2()
{
  Serial.println("locker2 open");
  digitalWrite(lightLocker2,HIGH);
  assign(codeLocker2);
  delay(500);
  Serial.println("a new code is generating...");
  delay(1000); 
  Serial.println("Sent code via phone number & gmail");
  Serial.print("Code for costumer of L2: ");
  Serial.println(codeLocker2);
  Serial.println("---------------------------------");
  delay(2000);
  digitalWrite(lightLocker2,LOW);


}
void openLocker3()
{
  Serial.println("locker3 open");
  digitalWrite(lightLocker3,HIGH);
  assign(codeLocker3);
  delay(500);
  Serial.println("a new code is generating...");
  delay(1000);
  Serial.println("Sent code via phone number & gmail");
  Serial.print("Code for costumer L3: ");
  Serial.println(codeLocker3);
  Serial.println("---------------------------------");
  delay(2000);
  digitalWrite(lightLocker3,LOW);

}
void openLocker4()
{
  Serial.println("locker4 open");
  digitalWrite(lightLocker4,HIGH);
  assign(codeLocker4);
  delay(500);
  Serial.println("a new code is generating...");
  delay(1000);
  Serial.println("Sent code via phone number & gmail");
  Serial.print("Code for costumer L4: ");
  Serial.println(codeLocker4);
  Serial.println("---------------------------------");
  delay(2000);
  digitalWrite(lightLocker4,LOW);

}


void assign(char *pw){
  int randNumber;
  char changeCode[5];
  randNumber = random(1000);
  I2C(randNumber);
  changeCode[1] = C[0];
  changeCode[2] = C[1];
  changeCode[3] = C[2];
  for ( int i =1; i<4; i++){
    pw[i] = changeCode[i];
  }
}

void I2C(int Number){
  int Num0 = Number%10;
  int Num1 = (Number/10)%10;
  int Num2 = Number/100;
  C[2] = Num0+48;
  C[1] = Num1+48;
  C[0] = Num2+48;
}
