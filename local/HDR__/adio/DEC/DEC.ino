#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ad_buf;
void setup(){
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  ad_buf = analogRead(A0);
  Serial.println(ad_buf, DEC);
  delay(100);
}
