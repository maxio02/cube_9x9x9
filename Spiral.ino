void Spiral(int times)
{
  float n3 = 0, steps = 3.14159265 / 8;
  for (int i = 0; i < times; i++)
  {
        for (int j = 0; j < 729; j++)
    {
      led[j] = 0;
    }
    //Serial.println(n3);
    if (n3 >= 2 * 3.14159265) n3 = 0; n3 += steps ;
    
    for(int layer=0;layer<9;layer++) led[CubeXYZ(cos(n3+((layer+1)*0.349066)) * 3.7 + 4.5, sin(n3+((layer+1)*0.349066)) * 3.7 + 4.5, layer)] = 1;

    for(int layer=0;layer<9;layer++) led[CubeXYZ(cos(n3+ 3.14159265+((layer+1)*0.349066)) * 3.7 + 4.5, sin(n3+3.14159265+((layer+1)*0.349066)) * 3.7 + 4.5, layer)] = 1;
    LedShow();

  }
}
