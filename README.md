# FreeRTOS-demo
Basic FreeRTOS demo with the use of the CMSIS wrapper (v2) and configuration guide for use in other projects.

## FreeRTOS Configuration Guide
Good introduction to using FreeRTOS with the CMSIS wrapper:
https://youtu.be/OPrcpbKNSjU

## H7 Demo
Each task prints the time between execution (115200 baud) and has a counter loop that creates a delay between execution for lower priority tasks.
- blink1 (above normal priority)
- blink2 (normal priority)
- blink3 (below normal priority)

blink1: Blinks the green LED (LD1) every 1000ms 
blink2: Blinks the orange LED (LD2) every 1500ms
blink3: Blinks the red LED (LD3) every 2000ms

*Observation*: blink1 always has a delay of 1000ms between execitions while blink2 and blink3 may have longer delays than their expected 1500ms and 2000ms respectively. This demonstrates how blink1 is prioritized higher than the other tasks.

## G431 Demo
Both tasks print the delay between execution (115200 baud) and have a counter loop that creates a delay between execution (only affects lower priority).  
- blink (normal priority)  
- printHello (low priority)  

blink: Blinks the green LED (LD2) every 1000ms  
printHello: Prints "Hello World!" every 1500ms  

*Observation*: blink always has a delay of 1000ms between executions while printHello may have longer delays than its expected 1500ms. This demonstrates how blink is prioritized higher than printHello.