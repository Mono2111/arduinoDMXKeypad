#include <Keypad.h>
#include <DmxSimple.h>

const byte ROWS = 4;
const byte COLS = 4;
int durchgelaufenEins = 0;
int farbeEins = 0;
int farbeZwei = 0;
int maximaleChannel = 112;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[COLS] = {7, 6, 5, 4};
byte rowPins[ROWS] = {11, 10, 9, 8};

int aTaste = 0;
int bTaste = 0;
int cTaste = 0;
int dTaste = 0;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  DmxSimple.usePin(3);
  DmxSimple.maxChannel(maximaleChannel); //Maximale Kanale
  Serial.begin(9600);
}

void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey == '*') //Blackout
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0); //nur Licht kein Blinken
    }
    aTaste = 0;
  }

  if (customKey == '#') //FullOn
  {
    for (int i = 33; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 255);
    }
    DmxSimple.write(6, 49); //nur Licht kein Blinken
    DmxSimple.write(1, 200); //Kaltweis
    DmxSimple.write(2, 200); //Warmweis
    DmxSimple.write(3, 200); //Bernstein

    DmxSimple.write(22, 49); //nur Licht kein Blinken
    DmxSimple.write(17, 200); //Kaltweis
    DmxSimple.write(18, 200); //Warmweis
    DmxSimple.write(19, 200); //Bernstein
  }
  if (customKey == '0') //Theaterscheinwerfer An
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    DmxSimple.write(6, 49); //nur Licht kein Blinken
    DmxSimple.write(1, 0); //Kaltweis
    DmxSimple.write(2, 40); //Warmweis
    DmxSimple.write(3, 15); //Bernstein

    DmxSimple.write(22, 49); //nur Licht kein Blinken
    DmxSimple.write(17, 0); //Kaltweis
    DmxSimple.write(18, 40); //Warmweis
    DmxSimple.write(19, 15); //Bernstein
  }

  if (customKey == '1') //Rot
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0); //nur Licht kein Blinken
    }
    for (int o = 33; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 255); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
  }

  if (customKey == '2') //Blau
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 255);//Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
  }

  if (customKey == '3') //Gruen
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 255); //Blau
    }
  }

  if (customKey == '4') //Mix1
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 255); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 255);//Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
  }

  if (customKey == '5') //Mix2
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 255); //Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 255);//Blau
    }
  }
  if (customKey == '6') //Mix3
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 255); //Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 255); //Rot
      DmxSimple.write(o + 2, 255);//Gruen
      DmxSimple.write(o + 3, 0); //Blau
    }
  }

  if (customKey == '7') //Mix4
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 255); //Rot
      DmxSimple.write(o + 2, 0);//Gruen
      DmxSimple.write(o + 3, 255); //Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 255); //Blau
    }
  }

  if (customKey == '8') //Mix5
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 80); //Rot
      DmxSimple.write(o + 2, 0); //Gruen
      DmxSimple.write(o + 3, 255);//Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 75); //Rot
      DmxSimple.write(o + 2, 255);//Gruen
      DmxSimple.write(o + 3, 100); //Blau
    }
  }

  if (customKey == '9') //Mix6
  {
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
    for (int o = 33; o < 66; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 0); //Rot
      DmxSimple.write(o + 2, 150);//Gruen
      DmxSimple.write(o + 3, 255);//Blau
    }
    for (int o = 81; o < maximaleChannel; o += 16)
    {
      DmxSimple.write(o, 255); //nur Licht kein Blinken
      DmxSimple.write(o + 1, 150); //Rot
      DmxSimple.write(o + 2, 255);//Gruen
      DmxSimple.write(o + 3, 50); //Blau
    }
  }

  if (customKey == 'A') //Chaser1
  {
    aTaste = 1;
    bTaste = 0;
    cTaste = 0;
    dTaste = 0;
    farbeEins = 255;
    farbeZwei = 0;
    durchgelaufenEins = 0;
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
  }

  if (customKey == 'B') //Chaser1
  {
    aTaste = 0;
    bTaste = 1;
    cTaste = 0;
    dTaste = 0;
    farbeEins = 255;
    farbeZwei = 0;
    durchgelaufenEins = 0;
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
  }

  if (customKey == 'C') //Chaser1
  {
    aTaste = 0;
    bTaste = 0;
    cTaste = 1;
    dTaste = 0;
    farbeEins = 255;
    farbeZwei = 0;
    durchgelaufenEins = 0;
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
  }

  if (customKey == 'D') //Chaser1
  {
    aTaste = 0;
    bTaste = 0;
    cTaste = 0;
    dTaste = 1;
    farbeEins = 255;
    farbeZwei = 0;
    durchgelaufenEins = 0;
    for (int i = 0; i < maximaleChannel; i++)
    {
      DmxSimple.write(i, 0);
    }
  }

  while (aTaste == 1)
  {
    if (durchgelaufenEins == 0)
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, farbeZwei); //Gruen
          DmxSimple.write(o + 3, 0);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, 0);//Gruen
          DmxSimple.write(o + 3, farbeEins); //Blau
        }
        farbeEins--;
        farbeZwei++;
        delay(30);
        if (farbeEins == 0)
        {
          durchgelaufenEins = 1;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          aTaste = 0;
          break;
        }
      }
    }
    else
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, farbeZwei); //Gruen
          DmxSimple.write(o + 3, 0);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, 0);//Gruen
          DmxSimple.write(o + 3, farbeEins); //Blau
        }
        farbeEins++;
        farbeZwei--;
        delay(30);
        if (farbeEins == 255)
        {
          durchgelaufenEins = 0;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          aTaste = 0;
          break;
        }
      }
    }
  }

  while (bTaste == 1)
  {
    if (durchgelaufenEins == 0)
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, farbeEins); //Gruen
          DmxSimple.write(o + 3, 100);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, 30);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins--;
        farbeZwei++;
        delay(30);
        if (farbeEins == 0)
        {
          durchgelaufenEins = 1;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          bTaste = 0;
          break;
        }
      }
    }
    else
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, farbeEins); //Gruen
          DmxSimple.write(o + 3, 100);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, 30);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins++;
        farbeZwei--;
        delay(30);
        if (farbeEins == 255)
        {
          durchgelaufenEins = 0;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          bTaste = 0;
          break;
        }
      }
    }
  }

  while (cTaste == 1)
  {
    if (durchgelaufenEins == 0)
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, 0); //Rot
          DmxSimple.write(o + 2, farbeEins); //Gruen
          DmxSimple.write(o + 3, farbeZwei);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, 120); //Rot
          DmxSimple.write(o + 2, farbeEins);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins--;
        farbeZwei++;
        delay(25);
        if (farbeEins == 0)
        {
          durchgelaufenEins = 1;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          cTaste = 0;
          break;
        }
      }
    }
    else
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, 0); //Rot
          DmxSimple.write(o + 2, farbeEins); //Gruen
          DmxSimple.write(o + 3, farbeZwei);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, 120); //Rot
          DmxSimple.write(o + 2, farbeEins);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins++;
        farbeZwei--;
        delay(25);
        if (farbeEins == 255)
        {
          durchgelaufenEins = 0;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          cTaste = 0;
          break;
        }
      }
    }
  }

  while (dTaste == 1)
  {
    if (durchgelaufenEins == 0)
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, 120); //Gruen
          DmxSimple.write(o + 3, farbeEins);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, 180);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins--;
        farbeZwei++;
        delay(15);
        if (farbeEins == 0)
        {
          durchgelaufenEins = 1;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          dTaste = 0;
          break;
        }
      }
    }
    else
    {
      for (int i = 0; i < 255; i++)
      {
        for (int o = 33; o < 66; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeZwei); //Rot
          DmxSimple.write(o + 2, 120); //Gruen
          DmxSimple.write(o + 3, farbeEins);//Blau
        }
        for (int o = 81; o < maximaleChannel; o += 16)
        {
          DmxSimple.write(o, 255); //nur Licht kein Blinken
          DmxSimple.write(o + 1, farbeEins); //Rot
          DmxSimple.write(o + 2, 180);//Gruen
          DmxSimple.write(o + 3, farbeZwei); //Blau
        }
        farbeEins++;
        farbeZwei--;
        delay(15);
        if (farbeEins == 255)
        {
          durchgelaufenEins = 0;
        }
        customKey = customKeypad.getKey();
        if (customKey)
        {
          dTaste = 0;
          break;
        }
      }
    }
  }

}
