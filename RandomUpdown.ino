void RandomUpDown( int timesf, int speedl, int mode)
{
  int bright, which = 0, offset = 0, dir = 1, prevwhich;
  bool did[81],  done = 1;
  for (int j = 0; j < 81; j++)
  {
    did[j] =0;
  }
  for (int j = 0; j < 729; j++) //filling one layer with turned on leds
  {
    if (j < 81) led[j] = 1;
    else led[j] = 0;
  }
  for ( int howmany = 0; howmany <= timesf; howmany++) //how many times leds go up or down
  {

    
    if (mode)
    {
      prevwhich = which;
      which = random(81);
      while (which == prevwhich)
      {
        which = random(81); // choosing a random column to move
      }
    }



    
    else
    {
      done = 1;
      for (int i = 0; i < 81; i++) {
        if (did[i] == 0) done = 0;
      }
       //Serial.print(" ");
      // Serial.print(done);
      if (done == 1)
      {
        for (int j = 0; j < 81; j++) //filling one layer with turned on leds
        {
          did[j] = 0;
        }
      }
      while (did[which] == 1)
      {
        which = random(81); // choosing a random column to move
        //Serial.println(which);
      }
    }




    if (led[which] == 1) dir = 1; //checking if its at the bottom layer or top and setting direction
    else dir = 0;

    for (int h = 1; h < 9; h++) // depending on the direction setting current and previous led on or off
    {
      //Serial.println(h);
      if (dir)
      {
        led[which + (h * 81)] = 1;
        led[which + ((h - 1) * 81)] = 0;
      }
      else
      {
        led[which + 648 - (h * 81)] = 1;
        led[which + 648 - ((h - 1) * 81)] = 0;
      }
      
      //speedl = analogRead(A6)/64;
      LedShow();
    }
    did[which] = 1;
  }
}
