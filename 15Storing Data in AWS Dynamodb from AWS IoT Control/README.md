Steps
1) Go to IoT Core in AWS platform
2) click Act>Rule>Create a rule --- >add a rule name and iot topics
3) Click **add action** > select **Insert a message into a DynamoDB table** >Click **configure action**
4) Click **create a new resourse**, this will open DynamoDB page
5) - Click **Tables** > **create table**
   - In **Table name**, choose the name of the DynamoDB table
   - In **Partition key**, enter name **DeviceID**
   - In **Sort key**, enter name **Timestamp**
   - Click **Creat Table**
6) Again goto **Rule** and select the table just created
   - In **Partition key value**, enter **${DeviceID}**
   - In **Sort key value**, enter **${timestamp()}**
   - In the **Create role** dialog box, for Role name, enter role name
   - Click **Add action**
   - Click **Create rule**
7) In **IAM role**, choose the role name just created.
8) Open DynamoDB page
   - Click **Items**
   - Select the table just created. In that we will see the Attributes such as DeviceID, 
     Timestamp, and payloads, in our case its Tempurature and Humidity.
     So in our case we have used ESP32 to send data and we have used three atribute DeviceID, 
    Tempurature and Humidity.

<h1 align="center">Step 1
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2020.png? alt="drawing" width="600"/>
</p>

<h1 align="center">Step 2
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2021.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 3
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2022.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 4
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2023.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 5
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2024.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 6
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2025.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 7
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2026.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 8
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2027.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 9
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2028.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 10
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2029.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 11
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2030.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 12
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2031.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 13
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2032.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 14
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2033.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 15
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2034.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 16
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2035.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 17
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2036.png? alt="drawing" width="600"/>
</p>

<h1 align="center">Step 18
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2038.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 19
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2039.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 20
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2040.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 21
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2041.png? alt="drawing" width="600"/>
</p>
<h1 align="center">Step 22
</h1>


<p align="center"><img src="https://github.com/RIT-MESH/Electronics-and-IoT-Projects/blob/main/15Storing%20Data%20in%20AWS%20Dynamodb%20from%20AWS%20IoT%20Control/AWS%2042.png? alt="drawing" width="600"/>
</p>

