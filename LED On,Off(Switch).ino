int Switch = 3;
int LED = 13;

void setup()
{
    pinMode(Switch, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(115200);
}

int Rising_cnt = 0;
int Falling_cnt = 0;
int Read = 0;
bool check_cnt = true;
int control_cnt = 0;

void loop()
{
    Read = digitalRead(Switch);

    while (Read != HIGH)
    {
        digitalWrite(LED, HIGH);

        Rising_cnt = Rising_cnt;
        Serial.println("Rising_cnt");
        Serial.println(Rising_cnt);

        Read = digitalRead(Switch);

        Rising_cnt++;
    }

    if (Rising_cnt >= 100)
    {
        control_cnt++;
        control_cnt = control_cnt % 5;
        Rising_cnt = 0;
    }

    if (control_cnt == 1)
    {
        digitalWrite(LED, HIGH);
        Serial.println("c_c : 1");
        Serial.println(control_cnt);
    }
    else if (control_cnt == 2)
    {
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        Serial.println("c_c : 2");
        Serial.println(control_cnt);
    }
    else if (control_cnt == 3)
    {
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(500);
        Serial.println("c_c : 1");
        Serial.println(control_cnt);
    }
    else if (control_cnt == 4)
    {
        digitalWrite(LED, LOW);
     
        Serial.println("c_c : 4");
        Serial.println(control_cnt);
    }

    // check_cnt = true;

    // digitalWrite(LED, HIGH);

    // digitalWrite(LED, LOW);

    // Serial.println("Read");
    // Serial.println(Read);

    // if (click_cnt - cnt >= 500)
    // {

    //     click_cnt = cnt;
    //     check_cnt++;
    //     Serial.println(check_cnt);

    // //}
    // Serial.println(cnt);

    // if (click_cnt != Read)
    // {

    //     if (cnt != 1)
    //     {
    //         cnt++;
    //         Serial.println("cnt, in");
    //         Serial.println(cnt);
    //     }
    // }

    // Serial.println("Switch");
    // Serial.println(Switch);
}
