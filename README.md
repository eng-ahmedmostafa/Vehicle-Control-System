# Vehicle-Control-System
Developed a Vehicle Control System in C, featuring interactive engine control, sensor-based speed, room, and engine temperature adjustments. Utilized menus for traffic light, AC, and temperature settings, displaying the vehicle's state. Included a preprocessor directive to conditionally compile engine temperature controller code.
The system is user-interactive and includes the following functionalities:

User Interaction:

Prompt the user to choose from the following options:
Turn on the vehicle engine
Turn off the vehicle engine
Quit the system
Display the current state of the system based on user choices.
Vehicle Engine Control:

When the engine is turned on, a "Sensors Set Menu" is displayed, allowing the user to:
Turn off the engine
Set the traffic light color
Set the room temperature via the Temperature Sensor
Set the engine temperature via the Engine Temperature Sensor
Sensor-Based Adjustments:

Traffic Light Sensor:
Set vehicle speed based on traffic light color:
'G' (Green): 100 km/hr
'O' (Orange): 30 km/hr
'R' (Red): 0 km/hr
Room Temperature Sensor:
Adjust AC and room temperature:
If < 10°C or > 30°C: Turn AC ON, set temperature to 20°C
Otherwise: Turn AC OFF
Engine Temperature Sensor:
Manage engine temperature:
If < 100°C or > 150°C: Turn "Engine Temperature Controller" ON, set temperature to 125°C
Otherwise: Turn "Engine Temperature Controller" OFF
Conditional Operations:

If vehicle speed is 30 km/hr:
Turn ON AC and adjust room temperature to (current temperature * 5/4) + 1
Turn ON "Engine Temperature Controller" and set engine temperature to (current temperature * 5/4) + 1
Display the current state of the vehicle, including:
Engine state (ON/OFF)
AC state (ON/OFF)
Vehicle speed
Room temperature
Engine Temperature Controller state
Engine temperature
