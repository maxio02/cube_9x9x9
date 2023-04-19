void RandomFill( int times, int speedl)
{
  int  which = 0; 
 bool  done=0,dir=0;
  for (int j = 0; j < 125; j++) //filling array with 0's
  {
    led[j] = 0;
  }
  for (int j = 0; j <= times; j++)
  {


    done = 1;
    for (int i = 0; i < 729; i++) {
      if (led[i] == dir) done = 0;
    }


    if (done == 1)  dir = !dir;
 
    while (led[which] != dir)
    {
      which = random(729);
      //Serial.print(which);
    }
    //Serial.println();
    if (led[which] == 1) led[which] = 0;
    else led[which] = 1;

    LedShow();
  }
}
