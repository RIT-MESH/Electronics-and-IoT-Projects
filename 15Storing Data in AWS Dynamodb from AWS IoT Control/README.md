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
   - In **Partition key value**, enter **${DeviceID()}**
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
