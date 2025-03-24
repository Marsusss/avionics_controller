int waitTime = 1500;
int serialBaudRate = 9600;
String str = "Hello, world!";
float f = 3.14;
int arr[] = {1, 2, 3, 4, 5};
int startTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaudRate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  startTime = millis();
}

void loop() {
  

  // Send string
  if (millis() > startTime + waitTime)
  {
    Serial.println(str);
    startTime = millis();
  }
    
  // Send float
  /*Serial.println(f, 2);  // The second argument specifies the number of decimal places
  
  // Send float as binary
  Serial.println(f, BIN);

  // Send array
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    Serial.print(arr[i]);
    if (i < sizeof(arr)/sizeof(arr[0]) - 1) {
      Serial.print(",");  // Add a comma between numbers
    }
  }
  Serial.println();  // Add a newline at the end*/

}
