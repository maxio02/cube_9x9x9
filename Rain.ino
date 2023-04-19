void Rain( int times, int speedl)
{
  int bright, column, offset = 0,which=0,prevwhich;
  for (int j = 0; j < 729; j++) //filling array with 0's
  {
    led[j] = 0;
  }
  for (int j = 0; j <= times; j++)
  {    
    if (j % speedl == 0)
    {
     prevwhich = which;
      which = random(81)+648;
      while (which == prevwhich)
      {
        which = random(81)+648; // choosing a random column to move
      }
      led[which]=127;
    }
    for (int i = 0; i <= 728; i++) 
    {
      led[i]-=3;
      led[i] = constrain(led[i], 0, 127); //dimming all leds by 1 and constraining them to a miminmum brightness, gives the effect of slowly dumming all leds
      if(led[i]==97 && i-81>=0) led[i-81]=127;
    }
    speedl = analogRead(A6)/16;
    if (speedl <=0) speedl=8;
    
        bright = analogRead(A7) / 32;
   // Serial.println(bright);
    
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

      digitalWrite(pins[l], HIGH);
      offset += 81;
    }
    offset = 0;
  }
}
