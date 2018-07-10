#include <Wire.h>
#define _CC_C10 (c[i]==char(10))
#define _CC_C13 (c[i-1]==char(13))

#define _CC0 (c[0]=='a'||c[0]=='A')
#define _CC1 (c[1]=='t'||c[1]=='T')
#define _CC2 (c[2]=='.')

int i=0;
char c[8192];
char d;

void clearChar() {
  memset(c, (char)0, sizeof c);
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  if ( Serial.available() ) {
    c[i] = Serial.read();
    if( c[i] == '\n') {
      if (i==3 && _CC0 && _CC1 & _CC_C13 & _CC_C10 ) {
        Serial.println();
        Serial.println("OK");
      } else if (i==4 && _CC0 && _CC1 && _CC2 & _CC_C13 & _CC_C10 ) {
        Serial.println();
        Serial.println("OK.LAMLOEI");
      } else {
        Serial.println();
        Serial.println("ERROR");
      }
      clearChar();
      i=0;
    } else {
      Serial.print(c[i]);
      i++;
    }
  }
}

