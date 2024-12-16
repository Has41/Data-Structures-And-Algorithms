#include <iostream>

using namespace std;
void initArray(int arr[], int size);
void displayArray(int arr[], int size);
void minimumArray(int arr[], int size);
int maximumArrayIndex(int arr[], int size);
void linearSearch(int arr[], int size, int element);
void binarySearch(int arr[], int size, int element);
void recursiveBinarySearch(int arr[], int element, int beg, int end);
void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main(int argc, char** argv) {
	// int arr[7];
	int arr[10];
	int opt;
	do {
		cout << endl;
		cout << "Press 1 for intialization\n";
		cout << "Press 2 for display\n";
		cout << "Press 3 for Minimum Value\n";
		cout << "press 4 for Maximum Value index \n";
		cout << "press 5 for Selection sort \n";
		cout << "press 6 for Bubble sort \n";
		cout << "press 7 for Insertion sort \n";
		cout << "press 8 for Linear search \n";
		cout << "press 9 for Binary search \n";
		cout << "press 10 for Recursive Binary search \n";
		cout << "Press 0 for exit\n";
		cout << endl;
		cin >> opt;

		switch (opt) {
			case 1:
				initArray(arr, 10);
				break;
			case 2:
				displayArray(arr, 7);
				break;
			case 3:
				minimumArray(arr, 7);
				break;
			case 4: {
				int maxIndex = maximumArrayIndex(arr, 7);
				cout << "Your maximum value is in index: " << maxIndex << endl;
				break;
			}
			case 5:
				selectionSort(arr, 7);
				break;
			case 6:
				bubbleSort(arr, 7);
				break;
			case 7:
				insertionSort(arr, 7);
				break;
			case 8: {
				int element;
				cout << "Enter your element to search in array: ";
				cin >> element;
				linearSearch(arr, 7, element);
				break;
			}
			case 9: {
				int element;
				cout << "Enter your element to search in array: ";
				cin >> element;
				binarySearch(arr, 7, element);
				break;
			}
			case 10: {
				int element;
				cout << "Enter your element to search in array: ";
				cin >> element;
				recursiveBinarySearch(arr, element, 0, 9);
				break;
			}
			case 0: {
				string opt;
				cout << "Are you sure you want to exit? (Y/N): ";
				cin >> opt;
				if (opt == "y" || opt == "Y") {
					exit(0);
				} else {
					cout << "Continuing the program...\n";
				}
			}
		}
	}
	while (true);

	return 0;
}

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value for index " << i << ":" << endl;
		cin >> arr[i];
	}
}

void displayArray(int arr[], int size) {
	cout << "Values in array are: \n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}

void minimumArray(int arr[], int size) {
	cout << "Minimum values in array are: \n";
	int min = arr[0];

	for (int i = 1; i < size; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	cout << "Minimum value is \n" << min << endl;
}

int maximumArrayIndex(int arr[], int size) {
	int max = arr[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void linearSearch(int arr[], int size, int element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
			cout << "Element found at index: " << i << endl;
			return;
		}
	}

	cout << "Element not found!";
}

void binarySearch(int arr[], int size, int element) {
	int beg = 0;
	int end = size - 1;
	int mid = (beg + end) / 2;

	while (beg <= end && arr[mid] != element) {
		if (element > arr[mid]) {
			beg = mid + 1;
		} else if (element < arr[mid]) {
			end = mid - 1;
		}
		mid = (beg + end) / 2;
	}

	if (element == arr[mid]) {
		cout << "Element found in given array at Index " << mid << endl;
	} else {
		cout << "Element doesn't exist in given array!";
	}
}

void recursiveBinarySearch(int arr[], int element, int beg, int end) {
	int mid = (beg + end) / 2;

	if (beg > end) {
		cerr << "Element doesn't exist in given array!";
	} else if (element == arr[mid]) {
		cout << "Element found in given array at Index " << mid << endl;
	} else if (element < arr[mid]) {
		recursiveBinarySearch(arr, element, beg, mid - 1);
	} else {
		recursiveBinarySearch(arr, element, mid + 1, end);
	}
}

void selectionSort(int arr[], int size) {
	cout << "Array before selection sort: ";
	displayArray(arr, size);
	for (int end = size - 1; end > 0; end--) {
		int maxIndex = maximumArrayIndex(arr, end + 1);
		int temp = arr[end];
		arr[end] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
	cout << endl;
	cout << "Array after selection sort: " << endl;
	displayArray(arr, size);
}

void bubbleSort(int arr[], int size) {
	cout << "Array before bubble sort: ";
	displayArray(arr, size);

	for (int end = size - 1; end > 0; end--) {
		bool isSwapped = false;
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			cout << "Array is already sorted!" << endl;
			return;
		}
	}
	cout << endl;
	cout << "Array after bubble sort: ";
	displayArray(arr, size);
}

void insertionSort(int arr[], int size) {
	cout << "Array before insertion sort: ";
	displayArray(arr, size);

	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	cout << endl;
	cout << "Array after insertion sort: ";
	displayArray(arr, size);
}