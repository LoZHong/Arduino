class pin
{
public:

  int Num;
  bool State;

  pin(int PinNum)
  {
    Num = PinNum;
    State = false;
      //pinMode(Num, OUTPUT);
      //digitalWrite(Num, LOW);
  }

  Toggle()
  {
    if(State == false)
    {
      digitalWrite(Num, HIGH);
      State = true;
    }
    else if(State == true)
    {
      digitalWrite(Num, LOW);
      State = false;
    }
  }

  On()
  {
    State = true;
    digitalWrite(Num,HIGH);
    delay(10);
    digitalWrite(Num,LOW);
    State = false;
  }
};

  pin Pin13(13);
  pin Pin12(12);
  pin Pin11(11);
  pin Pin10(10);
  pin Pin9(9);
  pin Pin8(8);


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(13, LOW);

  Serial.begin(9600);
}

void UserInput()
{
  if (Serial.available() > 0)
  {
    String letter = Serial.readString();

    int intValue = letter.toInt();

    switch (intValue)
    {
      case 13:
        Pin13.Toggle();
        break;
      case 12:
        Pin12.Toggle();
        break;
      case 11:
        Pin11.Toggle();
        break;
      case 10:
        Pin10.Toggle();
        break;
      case 9:
        Pin9.Toggle();
        break;
      case 8:
        Pin8.Toggle();
        break;
      case 0:
        Pin13.Toggle();
        Pin12.Toggle();
        Pin11.Toggle();
        Pin10.Toggle();
        Pin9.Toggle();
        Pin8.Toggle();
        break;
    }
  }
}

void DistanceSensor()
{
    int sensorValue = analogRead(A0);
    int printValue = 0;

    if(sensorValue >= 1000)
    {
      Pin8.On();
    }
    else if(sensorValue >= 600 && sensorValue < 1000)
    {
      Pin9.On();
    }
    else if(sensorValue >= 300&& sensorValue < 600)
    {
      Pin10.On();
    }
    else if(sensorValue >= 200&& sensorValue < 300)
    {
      Pin11.On();
    }
    else if(sensorValue >= 100&& sensorValue < 200)
    {
      Pin12.On();
    }
    else if(sensorValue >= 0 && sensorValue < 100)
    {
      Pin13.On();
    }
  Serial.println(printValue);
  delay(1);
}

void loop()
{
    DistanceSensor();
    UserInput();
}