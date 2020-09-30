/*Code by Swayamshee */
#include <LiquidCrystal.h>
#include <IRremote.h>
LiquidCrystal lcd(6,5,12,11,10,7);
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
String ctr;
int lcdled = 13;
int lcd1 = HIGH;

byte heart[8] =
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smile[8] =
{
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

void setup()
{

  Serial.begin(9600);
  delay(2000);
  lcd.createChar(1, heart);
  lcd.createChar(2, smile);
  lcd.begin(16, 2);
  irrecv.enableIRIn();
  lcd.print("IR  DECODER  BY");
  delay(2000);
  lcd.clear();
  lcd.print("OM SHREE MOHANTY");
  lcd.setCursor(0, 1);
  lcd.write(1); lcd.write(2); lcd.write(1); lcd.write(2);
  lcd.write(1); lcd.write(2); lcd.write(1); lcd.write(2);
  lcd.write(1); lcd.write(2); lcd.write(1); lcd.write(2);
  lcd.write(1); lcd.write(2); lcd.write(1); lcd.write(2);
  delay(3000);
  lcd.clear();
  lcd.print("PRESS A BUTTON ");
  lcd.setCursor(0, 1);
  lcd.print("TO DECODE VALUE");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DECODED VALUE: ");
  
}

void dump(decode_results *results)
{
  lcd.setCursor(0, 1);
  lcd.print(results->value, HEX);
}


void loop()
{

  if (irrecv.decode(&results))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DECODED VALUE: ");
    Serial.println(results.value, HEX);
    dump(&results);
    delay(800);
    irrecv.resume();
  }
}
