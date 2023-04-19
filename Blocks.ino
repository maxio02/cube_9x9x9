void Blocks( int times, int speedl)
{
  int bright, column, indvbright[10], offset = 0, prevmills = 0, current = 0, delayw = 0  ;
  bool smallcube[27];
  uint8_t cubecor[9][3];
  int  dir = 0, cube = 0, steps = 0;
  for (int j = 0; j < 729; j++) //filling array with 0's
  {
    led[j] = 0;

  }


  for (int j = 0; j < 9; j++) //filling array with 0's
  {
    for (int i = 0; i < 3; i++) //filling array with 0's
    {
      cubecor[j][i] = random(3);
    }
  }

  for (int j = 0; j < 9; j++) //filling array with 0's
  {
    for (int i = 0; i < 3; i++) //filling array with 0's
    {
      Serial.print(cubecor[j][i]) ;
      if ((i + 1) % 3 == 0) Serial.println (" ");
    }
  }
Serial.println (" ");
  for (int j = 0; j < 27; j++) //filling array with 0's
  {

    smallcube[j] = 0;

  }


  for (int j = 0; j <= times; j++)
  {
    speedl = analogRead(A6) / 32;
    if (speedl == 0) speedl = 1;
    bright = ((bright * 7 * 32) + analogRead(A7)) / 8;
    bright /= 32;
    //Serial.println(bright);

    //dir = random(6);
    //cube = random(9);
    // steps = random(3);

    switch (dir)
    {
      case 0:
        for (int move = 0; move < steps; move++)
        {
       //   if (cubecor[cube][0] < 3)cubecor[cube][0]++;
        //  else steps = 0;
        }
        break;

      case 1:
        for (int move = 0; move < steps; move++)
        {
          if (cubecor[cube][1] < 3)cubecor[cube][1]++;
          else steps = 0;
        }
        break;

      case 2:
        for (int move = 0; move < steps; move++)
        {
          if (cubecor[cube][2] < 3)cubecor[cube][2]++;
          else steps = 0;
        }
        break;

      case 3:
        cubecor[cube][0]--;
        break;

      case 4:
        cubecor[cube][1]--;
        break;

      case 5:
        cubecor[cube][2]--;
        break;
    }
    for (int numberofcube = 0; numberofcube < 9; numberofcube++)
    {
      smallcube[cubecor[numberofcube][0] + (3 * cubecor[numberofcube][1]) + (9 * cubecor[numberofcube][2])] = 1;
    }


    for (int debug = 0; debug < 27; debug++)
    {
      Serial.print (smallcube[debug]);
      if ((debug + 1) % 3 == 0) Serial.println (" ");
    }



    ////mapping
    for (int offz = 0; offz < 3; offz++)
    {
      for (int offy = 0; offy < 3; offy++)
      {
        for (int offx = 0; offx < 3; offx++)
        {
          for (int offcz = 0; offcz < 3; offcz++)
          {
            for (int offcy = 0; offcy < 3; offcy++)
            {
              for (int offcx = 0; offcx < 3; offcx++)
              {
                Serial.print (smallcube[offx + (offy * 3) + (offz * 9)]);
                if ((offx + (offy * 3) + (offz * 9)+1) % 9 == 0) Serial.println (" ");
                if (smallcube[offx + (offy * 3) + (offz * 9)] == 1)
                {
                  led[((offx * 3) + offcx) + 9*((offy * 3) + offcy)+ 81*((offz * 3) + offcz)] = 1;
               // }
               // else bigcube[(offx * 3) + offcx][(offy * 3) + offcy][(offz * 3) + offcz] = 0; 
                
              }
            }
          }
        }
      }
    }
    for (int x = 0; x < 729; x++) //filling array with 0's
    {
      Serial.print(led[x]);
      if((x+1)%9==0) Serial.println();
    }



    delay(100000);

    //current = millis();
    // Serial.println( (current - prevmills));
    // prevmills = millis();
    // delayw = ((delayw * 7 ) + analogRead(A6)) / 8;
    for (int l = 0; l <= 8; l++)
    {
      for (int column = 0; column < 81; column++)
      {
       // Tlc.set(column, led[column + offset]*bright);
      }
      Tlc.update();
      delay(1);
      //Serial.println(pins[l]);
      digitalWrite(pins[l], LOW);
      delay(1);
      //Serial.println(delayw);
      digitalWrite(pins[l], HIGH);
      offset += 81;
    }
    offset = 0;

    if ((j - 4) % speedl == 0) led[random(729)] = 127; //choosing a new led to light up depending on the speed
  }
}
