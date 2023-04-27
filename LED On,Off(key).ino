int LED = 13;
int Hswitch = 3;

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(Hswitch, INPUT_PULLUP);
    Serial.begin(115200);
}
unsigned long cnt = 0;   // key
unsigned long cnt_n = 0; // key
String indata;           // key
bool button = true;
int button_cnt = 0;

void loop()
{
    digitalWrite(Hswitch, LOW);
    cnt = millis();
    cnt_n = cnt - cnt_n;
    if (Serial.available() != 0)
    {
        indata = Serial.readString();
        indata.trim();
    }
    cnt_n = cnt;
    key_con(indata, cnt);

    button_con(button, button_cnt);
}

void key_con(String indata, unsigned long cnt)
{

    if (indata == "one")
    {
        if (cnt - cnt_n <= 1000)
        {
            digitalWrite(LED, HIGH);
            interrupt(cnt_n, cnt);
            digitalWrite(LED, LOW);
            interrupt(cnt_n, cnt);
        }
    }
    else if (indata == "two")
    {
        if (cnt - cnt_n <= 500)
        {
            digitalWrite(LED, HIGH);
            interrupt(cnt_n, cnt);
            digitalWrite(LED, LOW);
            interrupt(cnt_n, cnt);
        }
    }
    else if (indata == "three")
    {
        digitalWrite(LED, HIGH);
    }
    else if (indata == "zero")
    {
        digitalWrite(LED, LOW);
    }
    else if( indata == "clear")
    {
        cnt = 0;
        cnt_n = 0;
    }
    Serial.println(indata);
}

int interrupt(unsigned long cnt_n, unsigned long cnt)
{
    for (int i = 0; i < cnt_n; i++)
    {
        if (Serial.available() != 0)
        {
            break;
        }
    }
    cnt_n = cnt;
}

void button_con(int botton, int botton_cnt)
{
}
