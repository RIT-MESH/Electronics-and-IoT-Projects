<h1 align="center">Implementing IoT with Azure -(Sending Data to Azure Iot Hub using ESP32)
</h1>

### First we have to create IoT hub and then in that Hub we have to create device to see output
For more detail on how to create IoT Hub and Device in it, go through the official document. [Click here](https://learn.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal) 


<h1 align="center">Step 1
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%201.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 2
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%202.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 3
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%203.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 4
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%204.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 5
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%205.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 6
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%206.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 7
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%208.png?raw=true"alt="Sublime's custom image"/>
</p>

<h1 align="center">Step 9
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%209.png?raw=true"alt="Sublime's custom image"/>
</p>


<h1 align="center">Step 10
</h1>

Now open the cloud shell and paste the following commands to connect Azure platform to ESP32

##### az iot hub monitor-event --hub-name ESP32DEMO --device-id ESP32THING

<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/12Implementing%20IoT%20with%20Azure%20-(Sending%20Data%20to%20Azure%20Iot%20Hub%20using%20ESP32)/Azure%20step%2010.png?raw=true"alt="Sublime's custom image"/>
</p>
