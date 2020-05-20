/* Connect 5v of PH to 5v of Arduino , Gnd toGns , Tx of PH to Rx of Arduino
 *  while uploading code always remove connection at Rx of Arduino
 *  After uploading connect back
 *  PH Sensor gives data at its TX pin every second
 *  PH value,W - Depth immersed , L -light vale ( 0 for full dark)
 *  & T tempearture
 *  In this code we parse the PH value alone as Float value *  
 *  
 */


void setup() {
    Serial.begin(9600);
}

void loop() {
    for(int i=1; i<=10; i++) {
        String phdata = Serial.readStringUntil(':');
        Serial.println(phdata);
        if(phdata != ""){
            String ph = Serial.readStringUntil('$');
           
            Serial.println(ph);
            float phvalue=ph.toFloat();
             Serial.println();
            Serial.println("PH Value");
            Serial.println(phvalue);
        }
    }
}
