    # Coral
    ### A Water Body Health Monitoring System

    ## Contents

    ### TemperatureSensor
    It contains the code for the working of the Water Temperature sensor. 
    
    *Sensor Specs*
    Name : Underwater Temperature Sensor
    Code : DS18B20
    Range : -55 deg C to 125 deg C
    
    For reference you can use this [link](https://create.arduino.cc/projecthub/iotboys/how-to-use-ds18b20-water-proof-temperature-sensor-2adecc).
    
    This guide, however, does not have all the information so the set up will not work and you will end up seeing the output *0C 32F*

    After a little bit of poking around and hit and trial, we realised it also requires a pull-up resistor of 4.7k ohm.

    *Hardware Connection*
    The DS18B20 consists of 3 wires :-
    * The Vcc Wire
    * The GND Wire
    * The Data Wire

    Connect the Vcc Wire to 5V or 3.3V
    Connect the GND Wire to GND
    Connect the Data Wire to an Analog or PWM type pin
    There must be a 4.7k Ohm resistor between the Vcc and Data pin

    _Sometimes this may also not work. Then try the following :_
    * If you are getting negative value output, try inverting the Vcc and GND wires because some manufacturers make it in the opposite manner.
    * If you are getting "0C 32F" then remove the 4.7k ohm resistor and place it between the GND and Data wires.

    If it's still not working, you're doomed.

    
