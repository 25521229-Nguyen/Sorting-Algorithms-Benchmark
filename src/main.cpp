#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void nhapVector(vector<double>& v, int n)
{
    v.reserve(n);
    double a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
}

void inVector(vector<double> v, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Quick Sort
int partition(vector<double> &arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]);

    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<double> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(vector<double>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<double>& arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort
void merge(vector<double>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<double> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<double>& arr, int left, int right){
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> v;

    int n = 1000000;
    nhapVector(v, n);

    auto start_time = chrono::high_resolution_clock::now();
    //quickSort(v, 0, n - 1);
    //heapSort(v);
    //mergeSort(v, 0, n - 1);
    //sort(v.begin(), v.end());
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;
    cout << "Thoi gian thuc thi: " << duration.count() << endl;


    system("pause");
    return 0;
}
