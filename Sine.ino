void Sine(int speeds, int mode) {
   int  z;
  float n = 0, steps = 3.14159265 / 8, n2 = 0, yrot, xrot, n3 = 0, n4 = 0,divid=0;
  for (int i = 0; i < speeds; i++)
  {
    for (int j = 0; j < 729; j++) //filling all empty
    {
      led[j] = 0;
    }

    
    divid=analogRead(A6)*2;
    divid = constrain(divid, 256, 1638);
    if (mode == 1) if (n >= 2.5 * 3.14159265) n = 0; n += steps / 1;
    if (mode == 0) if (n2 >= 3.3333333 * 3.14159265) n2 = 0; n2 += steps / 1;
    
    if (mode == 2)
    {
    if (n3 >= 2 * 3.14159265) n3 = 0; n3 += steps / 8;
    if (n4 >= 2 * 3.14159265) n4 = 0; n4 += steps / 1;
    yrot = sin(n3) * 4 + 4;
    xrot = cos(n3) * 4 + 4;
    }
   // Serial.print("  ");
   // Serial.println(n2);

    for (int x = 0; x < 9; x++)
    {
      for ( int y = 0; y < 9; y++)
      {
            
            if (mode == 1) z = (sin(0.8 * (sqrt(x * x + y * y) + n))) * 3.8 + 4.20;
            else if (mode == 0) z = (sin(0.6 * (sqrt((4 - x) * (4 - x) + (4 - y) * (4 - y)) + n2))) * 3.8 + 4.40;
            else z = (sin(0.5 * (sqrt((xrot - x) * (xrot - x) + (yrot - y) * (yrot - y))) + n4 )) * 3.8 + 4.40;
            //if ((y)%9==1)Serial.println(z);
        led[CubeXYZ(x, y, z)] = 1;
      }
    }

      LedShow();

  }
}
