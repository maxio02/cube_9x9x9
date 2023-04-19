int offset = 0, column = 0, bright = 0,speedl=0;
void LedShow()
{
   /* for (int u = 0; u < 729; u++) //filling one layer with turned on leds
        {
        Serial.print (led[u]);
        Serial.print ("  ");
        if ((u+1)%9==0)Serial.println(" ");
        }*/
        
  speedl = analogRead(A6) / 64;
  for (int i = 0; i <= speedl; i++) //times to multiplex for a delay but smooth playback
  {
    bright =  analogRead(A7) * 4 ;

    for (int l = 0; l <= 8; l++)
    {
      for (int column = 0; column < 81; column++)
      {
        Tlc.set(column, led[column + offset]*bright);
      }
      Tlc.update();
      delayMicroseconds(980);
      //Serial.println(pins[l]);
      digitalWrite(pins[l], LOW);
      delayMicroseconds(980);
      //Serial.println(delayw);
      digitalWrite(pins[l], HIGH);
      offset += 81;
    }
    offset = 0;
  }
}
