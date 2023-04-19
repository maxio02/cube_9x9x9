void Extendo( int times, int speedl)
{
  bool  dir = 1;
  uint8_t height[81], invert[81];
  uint8_t zrem[81];
  int bright = 0, offset = 0;
  for (int j = 0; j < 729; j++) //filling one layer with turned on leds
  {
    if (j < 81)
    {
      led[j] = 1;
      zrem[j] = 0;
    }
    else led[j] = 0;

  }

  for (int j = 0; j <= times; j++)
  {


    for (int column = 0; column < 81; column++)
    {

      height[column] = random(9); //choosing a diffrent height for each column
      invert[column] = (8 - height[column]);
      //Serial.println(height[column]+invert[column]);
    }
    for (int maxheight = 0; maxheight < 40; maxheight++)
    {
      if (maxheight < 20 && maxheight > 0)
      {
        for (int column = 0; column < 81; column++)
        {

          //Serial.print (zrem[column]);
          //if ((column+1)%9==0)Serial.println(" ");
          //z = constrain(z, 0, height[x+(9*y)]); //constraining to the chosen height
          if (dir)
          {
            if (height[column] != 0)
            {
              zrem[column]++;
              height[column]--;
            }

            led[(column + (zrem[column] * 81))] = 1;
            if (zrem[column] != 0) led[(column + (zrem[column] * 81)) - 81] = 0;
          }
          else
          {
            if (height[column] != 0)
            {
              zrem[column]--;
              height[column]--;
            }
            led[(column + (zrem[column] * 81))] = 1;
            if (zrem[column] != 8) led[(column + (zrem[column] * 81)) + 81] = 0;
          }
        }
      }
      else if (maxheight >= 20)
      {
        for (int column = 0; column < 81; column++)
        {

          if (dir)
          {
            if (invert[column] != 0)
            {
              zrem[column]++;
              invert[column]--;
            }

            led[(column + (zrem[column] * 81))] = 1;
            if (zrem[column] != 0) led[(column + (zrem[column] * 81)) - 81] = 0;
          }
          else
          {
            if (invert[column] != 0)
            {
              zrem[column]--;
              invert[column]--;
            }
            led[(column + (zrem[column] * 81))] = 1;
            if (zrem[column] != 8) led[(column + (zrem[column] * 81)) + 81] = 0;
          }

        }
      }
      /* for (int u = 0; u < 729; u++) //filling one layer with turned on leds
        {
        Serial.print (led[u]);
        Serial.print ("  ");
        if ((u+1)%9==0)Serial.println(" ");
        } */

      //Serial.println(" ");
      //Serial.println(" ");


        LedShow();
      
    }
    dir = !dir;
  }
}
