void RotateCubeBy( int axis, int deg)
{
  float RotMat[3][3] = {
    1, 0, 0,
    0, cos(3.14159265359), (-1 * sin(3.14159265359)),
    0, sin(3.14159265359), cos(3.14159265359)
  };
  bool temp[729];
  for (int j = 0; j < 729; j++) //filling one layer with turned on leds
  {
    temp[j]=led[j];
  }
  //delay(1000);
  for (int z = 0; z < 9; z++)
  {
    for (int y = 0; y < 9; y++)
    {
      for (int x = 0; x < 9; x++)
      {
        
        //Serial.print(led[x + (9 * y) + (81 * z)]);
        int o=(x + (9 * y) + (81 * z));
        led[int((((RotMat[0][0] * (x - 4)) + (RotMat[1][0] * (y - 4)) + (RotMat[2][0] * (z - 4))) + 4) +           ((((RotMat[0][1] * (x - 4)) + (RotMat[1][1] * (y - 4)) + (RotMat[2][1] * (z - 4))) + 4) *9)    +       ((((RotMat[0][2] * (x - 4)) + (RotMat[1][2] * (y - 4)) + (RotMat[2][2] * (z - 4))) + 4)*81))] = temp[o];
        //Serial.print (int((((RotMat[0][0] * (x - 4)) + (RotMat[1][0] * (y - 4)) + (RotMat[2][0] * (z - 4))) + 4) +           ((((RotMat[0][1] * (x - 4)) + (RotMat[1][1] * (y - 4)) + (RotMat[2][1] * (z - 4))) + 4) *9)    +       ((((RotMat[0][2] * (x - 4)) + (RotMat[1][2] * (y - 4)) + (RotMat[2][2] * (z - 4))) + 4)*81))); Serial.print(" ");
       // if ((x + 1) % 9 == 0)Serial.println(" ");
      }
    }
  }

 /* for (int j = 0; j < 729; j++) //filling one layer with turned on leds
  {
    Serial.print(led[j]);
    if((j+1)%9==0) Serial.println();
  }
    delay(1000); */

}
