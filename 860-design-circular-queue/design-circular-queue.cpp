class MyCircularQueue {
public:
    vector<int> array;
    int rear;
    int front;
    int size;
    int capacity;
    MyCircularQueue(int k)
        : array(k), rear(-1), front(0), size(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull())
            return false;
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (!isEmpty())
            return array[front];
        else
            return -1;
    }

    int Rear() {
        if (!isEmpty())
            return array[rear];
        return -1;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};