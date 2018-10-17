/*
SCL - A5
SDA - A4
VCC - 5V
GND - GND
*/

#include <DS3231.h>
DS3231  rtc(SDA, SCL);

void setup(){
  Serial.begin(9600);
  rtc.begin();
  rtc.setDOW(PAZARTESI);     //  BU günü pazartesi olarak ayarladık
  rtc.setTime(12, 0, 0);     //  saati 12:00:00 şeklinde ayarladık
  rtc.setDate(1, 1, 2014);   // Tarihi 1/1/2014 olarak ayarladık
}

void loop(){
  //Haftanın hangi günü  serialporta yazdırdık
  Serial.print(" Haftanin gunu: ");
  Serial.println(rtc.getDOWStr()); 

  //Tarih bilgisini serialporta yazdırdık
  Serial.print(" Tarih:");
  Serial.println(rtc.getDateStr()); 

  // saat bilgisini serialporta yazdırdık
  Serial.print(" Saat: ");
  Serial.println(rtc.getTimeStr()); 

  // sıcaklık bilgisini serialporta yazdırdık
  Serial.print(" Sicaklik: ");
  Serial.print(rtc.getTemp());

  Serial.println(" derece");

  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
  delay (1000);
}

