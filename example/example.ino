//Wiring
 
//Connect SDA to SDA 
//Connect SCL to SCL
//Connect GND to GND
//Connect VCC to VCC

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>  // F Malpartida's NewLiquidCrystal library
// download the repository from here and put it in your documents/arduino/libraries folder and restart your ide 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads

#define I2C_ADDR    0x27  // Define I2C Address for controller
#define BACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

#define  LED_OFF  0
#define  LED_ON  1
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() 
{
  lcd.begin (20,4);  // initialize the lcd
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(LED_ON);
}

void loop()  
{

// Reset the display 
  lcd.clear();
  lcd.home();
 
// Print on the LCD
  lcd.backlight();  
  lcd.setCursor(0,0); 
  lcd.print("I2C interface");
  
  lcd.setCursor(0,1);
  lcd.print("20 Character 4 Lines");

  lcd.setCursor(0,2);
  lcd.print("Example on GitHub");

  
  lcd.setCursor(0,3); 
  lcd.print("www.iotmodules.co.uk");
  delay(8000);
}
