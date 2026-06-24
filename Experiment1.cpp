#include <iostream>

using namespace std;

void numCheck(string text) {
    int n = text.length();
    bool numeric = true;
    
    if (n == 0) {
        numeric = false;
    }

    for (int i = 0; i < n; i++) {
        char ch = text[i];
        if (ch < '0' || ch > '9') {
            numeric = false;
            break;
        }
    }
    
    if (numeric) {
        cout << "Numeric Constant." << endl;
    } else {
        cout << "Not Numeric." << endl;
    }
}

int isOperator(string text) {
    int c = 0;
    int n = text.length();
    
    for (int i = 0; i < n; i++) {
        char ch = text[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
            ch == '%' || ch == '=' || ch == '<' || ch == '>' || ch == '!') {
            c++;
            cout << "Operator " << c << ": " << ch << endl;
        }
    }
    
    if (c == 0) {
        cout << "No Operator(s) detected!" << endl;
    }
    return c;
}

void isComment(string text) {
    int n = text.length();

    if (n >= 2 && text[0] == '/' && text[1] == '/') {
        cout << "Single line comment." << endl;
    } 
    else if (n >= 4 && text[0] == '/' && text[1] == '*' && text[n - 2] == '*' && text[n - 1] == '/') {
        cout << "Multi line comment." << endl;
    } 
    else {
        cout << "No comment detected!" << endl;
    }
}

bool isValidIdentifier(string text) {
    int n = text.length();
    
    if (n == 0) {
        return false;
    }

    char first = text[0];
    if (!((first >= 'a' && first <= 'z') || (first >= 'A' && first <= 'Z') || first == '_')) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        char ch = text[i];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')) {
            return false;
        }
    }

    return true;
}

double getAverage(int arr[], int n) {
    if (n == 0) {
        return 0.0;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;
}

void findMinMax(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;
}

string getFullName(string firstName, string lastName) {
    return firstName + " " + lastName;
}

int main() {
    string text;
    
    // 1. Numeric Check
    cout << "Enter text to numeric check: ";
    cin >> text;
    numCheck(text);

    // 2. Operator Check
    cout << "\nEnter text to operator check: ";
    cin >> text;
    isOperator(text);

    // 3. Comment Check
    cout << "\nEnter text to comment check (Type 'STOP' on a new line to finish): \n";
    // Clear the input buffer before reading multiline input
    while (cin.get() != '\n') {
        continue;
    }
    
    string commentText = "";
    string line;
    while (getline(cin, line)) {
        if (line == "STOP") {
            break;
        }
        commentText += line;
    }
    isComment(commentText);

    // 4. Identifier Check
    cout << "\nEnter text to identifier check: ";
    cin >> text;
    if (isValidIdentifier(text)) {
        cout << "Given input is Identifier." << endl;
    } else {
        cout << "Given input is Not Identifier." << endl;
    }

    // 5. Average Array
    int n;
    cout << "\nEnter the size of the array for average: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Average: " << getAverage(arr, n) << endl;
    delete[] arr; // Free memory

    // 6. Min-Max Array
    cout << "\nEnter the size of the array for min-max: ";
    cin >> n;
    int* arr2 = new int[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    findMinMax(arr2, n);
    delete[] arr2; // Free memory

    // 7. Concatenate Name
    string firstName, lastName;
    cout << "\nEnter First Name: ";
    cin >> firstName;
    cout << "Enter Second Name: ";
    cin >> lastName;
    cout << "Full Name: " << getFullName(firstName, lastName) << endl;
    
    return 0;
}