void Display(int times)
{
bool   outer[297] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,
                    0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,1,
                    1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,
                    0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,
                    0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,
                    0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,
                    0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,1,
                    0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0,1,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};
                    int speedl=0, offset=0;
                    Tlc.clear();
for(int i=0;i < times;i++){
  
for(int x=0;x<297;x++)
{
if(x%33 ==0 && x !=0) outer[x]=outer[x-32];
else if(x != 296) outer[x]=outer[x+1];
}
for(int x=0;x<297;x++)
{
//Serial.print(outer[x]);
//if((x+1)%33 ==0)Serial.println();
}
   speedl = analogRead(A6) / 64;
  for (int j = 0; j <= speedl; j++) //times to multiplex for a delay but smooth playback
  {
    bright =  analogRead(A7) * 4 ;

  for (int l = 8; l >= 0; l--)
    {
      for (int column = 16; column < 32; column++)
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
      offset += 33;
    }
    offset = 0;
  }
}
}
