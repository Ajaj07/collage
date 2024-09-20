Components:
    * NodeMCU
    * LED
    * Resistor (220Ω or 330Ω)
    * Breadboard and jumper wires

Circuit:
    * Connect the LED's anode (long leg) to a digital pin (e.g., D1/GPIO5) on the NodeMCU.
    * Connect the LED's cathode (short leg) to the ground (GND) through a resistor.
Code:
    * given in this folder (wifi-led_blinking.ino)

Explanation:
       *  Wi-Fi Connection: The code connects the NodeMCU to your Wi-Fi network using the SSID and password.
       *  LED Control: The LED is connected to pin D1. You can control it by sending requests to the web server hosted by the NodeMCU.
       *  Web Server: The NodeMCU serves a simple HTML page with buttons to turn the LED on and off.
       *   HTTP Requests: When you click on "Turn On" or "Turn Off," the browser sends a request to the NodeMCU, which then toggles the LED accordingly.
    
if not contain Resistor:

If you don't have a resistor and your NodeMCU is powered via USB from your laptop, you can still proceed with the LED control, but it's important to note that directly connecting an LED without a resistor may potentially damage the LED or the NodeMCU pin over time. However, for short-term testing or low-power LEDs, this can work in practice.

additional info :
    You're correct! The NodeMCU has several GPIO pins available, each corresponding to a different labeled pin (D0 to D8). Here's the proper mapping:

        D1 corresponds to GPIO5
        D2 corresponds to GPIO4
        D3 corresponds to GPIO0
        D4 corresponds to GPIO2
        D5 corresponds to GPIO14
        D6 corresponds to GPIO12
        D7 corresponds to GPIO13
        D8 corresponds to GPIO15
        
        So, if you want to connect the LED to D8, you should update the pin definition in the code accordingly:
