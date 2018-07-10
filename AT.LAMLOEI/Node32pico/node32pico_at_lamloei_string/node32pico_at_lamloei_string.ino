#include <Wire.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  if ( Serial.available() ) {
    String s = Serial.readString();
    s.trim();
    if (s.equalsIgnoreCase("AT"))         { Serial.println(s);Serial.println("OK"); }
    else if (s.equalsIgnoreCase("AT."))   { Serial.println(s);Serial.println("OK.LAMLOEI"); }
    else                                  { Serial.println(s);Serial.println("ERROR"); }
  }
}

