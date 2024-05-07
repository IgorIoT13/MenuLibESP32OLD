#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#include <Menulib.h>


#define COLUMS              20  
#define ROWS                4    
#define LCD_SPACE_SYMBOL    0x20 
#define SCL_PIN             22
#define SDA_PIN             21
#define SPEED_I2C           400000
#define TIME_I2C            250



Menu* menu ;
Screen* testScreen;

Line* Fan;
Line* Ten;
Line* Cool;


void setup(){
  
    
Serial.begin(9600);

    menu = initMenu();
    testScreen = menu->newScreen(menu, "Setting", "Test");

    Fan = menu->addLine(menu, "FAN 60%", "FAN");
    Ten = menu->addLine(menu, "TEN 42%", "TEN");
    Cool = menu->addLine(menu, "COOL 100%", "COOL");


}

void loop(){
    delay(3000);

    menu->nextLine(menu);
    Serial.printf("%s", menu->getName(menu));
}