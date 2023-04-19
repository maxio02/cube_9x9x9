void CubeOutline(uint8_t origin_x, uint8_t origin_y, uint8_t origin_z, uint8_t size,bool clear, bool invert)
{
  
  //Serial.print ("here");
  uint8_t origin [3] = {origin_x, origin_y, origin_z};
  
  int bright = 0, offset = 0 ;

    if (clear) for (int j = 0; j < 729; j++) led[j] = 0;


    for (int i = 0; i < size; i++)
    {
      led[CubeXYZ(origin[0] + i, origin[1], origin[2])] = invert;
      led[CubeXYZ(origin[0], origin[1] + i, origin[2])] = invert;
      led[CubeXYZ(origin[0], origin[1], origin[2] + i)] = invert;
      
      led[CubeXYZ(origin[0] + size, origin[1] + i, origin[2])] = invert;
      led[CubeXYZ(origin[0] + size, origin[1], origin[2] + i)] = invert;
      led[CubeXYZ(origin[0] + i, origin[1] + size, origin[2])] = invert;
      led[CubeXYZ(origin[0], origin[1] + size, origin[2] + i)] = invert;
      led[CubeXYZ(origin[0] + i, origin[1], origin[2] + size)] = invert;
      led[CubeXYZ(origin[0], origin[1] + i, origin[2] + size)] = invert;

      led[CubeXYZ(origin[0] + size, origin[1] + size, origin[2] + i)] = invert;
      led[CubeXYZ(origin[0] + size, origin[1] + i, origin[2] + size)] = invert;
      led[CubeXYZ(origin[0] + i, origin[1] + size, origin[2] + size)] = invert; 
    }
    led[CubeXYZ(origin[0]+size,origin[1]+size,origin[2]+size)]=invert;

    //Serial.println(bright);
   
}
