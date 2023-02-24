#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#include <unordered_map>
#include <string>

using namespace std;

string findPair(int* arr, int size) {
    string result = "";
    unordered_map<int, pair<int, int>> hash_map;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = arr[i] + arr[j];
            if (hash_map.find(sum) != hash_map.end()) {
                pair<int, int> p = hash_map[sum];
                result += "{" + to_string(p.first) + "," + to_string(p.second) + "}";
                result += "{" + to_string(arr[i]) + "," + to_string(arr[j]) + "}";
                return result;
            }
            else {
                hash_map[sum] = make_pair(arr[i], arr[j]);
            }
        }
    }

    return result;
}

int main() {
    int arr[] = { 3, 4, 7, 1, 12, 9 };
    int size = 6;
    string result = findPair(arr, size);
    cout << result << endl;
}
