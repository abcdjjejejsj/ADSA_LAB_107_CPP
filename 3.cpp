#include <iostream>
using namespace std;

// Function to count trailing zeros in factorial of num
int countTrailingZeros(int num) {
    int count = 0;
    int power = 5;
    while (num / power > 0) {
        count += num / power;
        power *= 5;
    }
    return count;
}

int findSmallestNumber(int n) {
    int low = n;
    int high = n * 5; // Worst case, each 5 contributes 1 zero

    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros < n) {
            low = mid + 1; // Need more zeros → go right
        } else {
            if (zeros == n) {
                ans = mid; // Possible answer
            }
            high = mid - 1; // Try to find smaller one
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of trailing zeros: ";
    cin >> n;

    int result = findSmallestNumber(n);

    if (result == -1) {
        cout << "Invalid input. No number found whose factorial has exactly " << n << " trailing zeros.\n";
    } else {
        cout << "Smallest number whose factorial has exactly " << n << " trailing zeros is: " << result << endl;
    }

    return 0;
}
