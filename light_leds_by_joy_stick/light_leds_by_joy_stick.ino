#define ARRAY_SIZE 5 // Change this to the number of elements you want

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5}; // Replace with your numbers

  unsigned long start = micros();
  float mean = calculateMean(numbers, ARRAY_SIZE);
  unsigned long meanTime = micros() - start;

  start = micros();
  float median = calculateMedian(numbers, ARRAY_SIZE);
  unsigned long medianTime = micros() - start;

  Serial.print("Mean: ");
  Serial.print(mean);
  Serial.print(", Time taken: ");
  Serial.print(meanTime);
  Serial.println(" microseconds");

  Serial.print("Median: ");
  Serial.print(median);
  Serial.print(", Time taken: ");
  Serial.print(medianTime);
  Serial.println(" microseconds");

  delay(1000); // Wait for a second before next iteration
}

float calculateMean(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return (float)sum / size;
}

float calculateMedian(int arr[], int size) {
  sort(arr, size);
  if (size % 2 != 0)
    return (float)arr[size / 2];
  
  return (float)(arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
}

void sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
