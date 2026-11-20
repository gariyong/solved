#include <iostream>
#include <vector>

using namespace std;

class Maxheap {
private:
    vector<int> heap;

    void heapifyup(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = (int) heap.size();
        while (index * 2 + 1 < size) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;

            if (!heap.empty()) {
                if (left < size && heap[left] > heap[largest]) {
                    largest = left;
                }
                if (right < size && heap[right] > heap[largest]) {
                    largest = right;
                }
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }
public:
    void push(int value) {
        heap.push_back(value);
        heapifyup((int) heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() const {
        if (heap.empty()) {
            return 0;
        }
        return heap[0];
    }

    bool empty()const {
        return heap.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    Maxheap h;

    cin >> n;

    while (n > 0) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << h.top() << '\n';
            h.pop();
        }
        else {
            h.push(x);
        }
        n--;
    }

    return 0;
}