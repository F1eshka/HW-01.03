#include <iostream>
#include <algorithm>
using namespace std;

const int max_size = 25; 

class ExclusionPriorityQueue {

    string data[max_size];
    int priorities[max_size];
    int real_count = 0;

public:
    void Clear() {
        real_count = 0;
    }

    bool IsEmpty() const {
        return real_count == 0;
    }

    bool IsFull() const {
        return real_count == max_size;
    }

    int GetCount() const {
        return real_count;
    }

    void Enqueue(string value, int priority) {

        if (!IsFull()) {
            data[real_count] = value;
            priorities[real_count] = priority;
            real_count++;
        }
        else {
            throw "Queue is full!";
        }
    }

    string Dequeue() {
        if (!IsEmpty()) {
            int max_priority_position = max_element(priorities, priorities + real_count) - priorities;
            string result = data[max_priority_position];
            for (int i = max_priority_position; i < real_count - 1; i++) {
                data[i] = data[i + 1];
                priorities[i] = priorities[i + 1];
            }
            real_count--;
            return result;
        }
        else {
            throw "Queue is empty!";
        }
    }

    void Print() {
        cout << "-----------------------------------------------------\n";
        for (int i = 0; i < real_count; i++)
            cout << i + 1 << ") " << data[i] << "\n";
        cout << "-----------------------------------------------------\n";
    }
};

int main() {

    setlocale(LC_ALL, "RU");

    ExclusionPriorityQueue q;

    q.Enqueue("преподаватель, Александр", 1);
    q.Enqueue("директор филиала, Диана", 4);
    q.Enqueue("менеджер учебного процесса, Екатерина", 2);
    q.Enqueue("заведующая кафедрой, Кристина", 3);
    q.Enqueue("генеральный директор, Дмитрий", 5);
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    return 0;
}
