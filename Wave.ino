void Wave( int times, int speedl)
{
  int bright, column;
  float n = -3.14159265 / 2, steps = 3.14159265/18, offset = 0;

  for (int i = 0; i <= 2 * times; i++)
  {
    bright = analogRead(A7); bright = map(bright, 0, 1023, 0, 1400);
    speedl = analogRead(A6)/64;
    if (speedl ==0) speedl=1;
    if (n >= 2 * 3.14159265) n = 0; n += steps /speedl; // bouncing n between -pi/2 and pi/2
    for (int l = 0; l <= 8; l++)
    {
      delayMicroseconds(400);
      digitalWrite(pins[l], LOW);
      delayMicroseconds(400);
      for (column = 0; column < 81; column++)
      {
        Tlc.set(column, (bright * sin(1 * (n - offset))) + (bright));
      }
      Tlc.update();
      digitalWrite(pins[l], HIGH);
      offset += 3.14159265/ 4.5;

    }
    offset = 0;
  }
}
