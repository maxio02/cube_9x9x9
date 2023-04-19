void CubicSpiral(int times)
{
  int8_t outer[288];
  uint8_t speedl = 0;
  int next = 0,offset=0,bright;
  for (int i = 0; i < 288; i++)
  {
    outer[i] = 0;
  }
    outer[0] = 127;
  Tlc.clear();
  for (int j = 0; j < times; j++)
  {

    for (int i = 0; i < 288; i++)
    {
      outer[i] -= 2;
      outer[i] = constrain(outer[i], 0, 127); //dimming all leds by 1 and constraining them to a miminmum brightness, gives the effect of slowly dumming all leds
      if (outer[i] == 123 && i + 1 < 288) outer[i + 1] = 127;
    }
     if(j%288==0) outer[0] = 127;
    speedl = analogRead(A6) / 16;
  
  
  bright = analogRead(A7) / 32;
  for (int l = 0; l <= 8; l++)
    {
      for (int column = 0; column < 32; column++)
      {
        Tlc.set(outerborder[column], outer[column + offset]*bright);
      }
      //Serial.println(bright);
      Tlc.update(); 
      delayMicroseconds(980);
      //Serial.println(pins[l]);
      digitalWrite(pins[l], LOW);
      delayMicroseconds(980);
      //Serial.println(delayw);
      digitalWrite(pins[l], HIGH);
      offset += 32;
    }
    offset = 0;
  }
}
