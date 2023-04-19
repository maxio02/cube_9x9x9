void SimpleTest(int times)
{
  for (times; times > 0;) {

    for (int leds = 0; leds <= 81;)
    {
        digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(2, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
      Tlc.set(leds,100);
      Tlc.update();
      delay(200);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  delay(200);
    }
      Tlc.clear();
      

        

      times--;
    }
  }
