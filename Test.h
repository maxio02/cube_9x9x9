/*int layer = 1;
int prevleds = 2;
int prevleds2 = 2;
int offset = 0, prevmills = 0,current=0;
void Test(int times)
{
 for (times; times > 0;) {
Serial.println("here");
 for (int leds = 0; leds <= 729;)
 {
 if (times % 10 == 0)
 {
 led[leds]=1;
 if(leds !=0) led[leds-1]=0;
 leds++;
 }
 // Tlc.set(prevleds, 1000);
 // Tlc.set(prevleds2, 0);
 // prevleds2=prevleds;
 // prevleds=leds;
 //delay(250);
 Serial.println(leds);
 //current=millis();
  //Serial.println(1000/(current-prevmills));
  //prevmills=millis();
  for (int l = 0; l <= 8; l++)
  {
  for (int column = 0; column < 81; column++)
  {
  Tlc.set(column, led[column + offset] * 1000);
  }
  Tlc.update();
  delayMicroseconds(1000);
  //Serial.println(pins[l]);
  digitalWrite(pins[l], LOW);
  delayMicroseconds(1000);

  digitalWrite(pins[l], HIGH);
  offset += 81;
  }
  offset = 0;

  times--;
  }
  }
}*/
