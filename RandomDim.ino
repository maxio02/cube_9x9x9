void RandomDim( int times, int speedl)
{
  int  offset = 0;
  int bright=0; 

  
  for (int j = 0; j < 729; j++) //filling array with 0's
  {
    led[j] = 0;
  }

  
  for (int j = 0; j <= times; j++)
  { 
  
    speedl = analogRead(A6)/32;
    if (speedl ==0) speedl=1;

    
    bright =  analogRead(A7) / 32;

    
    //Serial.println(bright);
    for (int i = 0; i <= 728; i++) 
    {
      led[i]--;
      led[i] = constrain(led[i], 0, 127); //dimming all leds by 1 and constraining them to a miminmum brightness, gives the effect of slowly dumming all leds
    }

    
    //current = millis();
   // Serial.println( (current - prevmills));
   // prevmills = millis();
   // delayw = ((delayw * 7 ) + analogRead(A6)) / 8;
   
    for (int l = 0; l <= 8; l++)
    {
      for (int column = 0; column < 81; column++)
      {
        Tlc.set(column, led[column + offset]*bright);
      }
      //Serial.println(bright);
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
    
    if ((j) % speedl == 0) led[random(729)] = 127; //choosing a new led to light up depending on the speed
  }
}
