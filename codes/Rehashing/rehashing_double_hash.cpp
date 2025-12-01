#include <iostream>
using namespace std;

class RehashTable
{
private:
    int *keys;
    string *values;
    bool *occupied;

    int currentSize;
    int size;

    int hash1(int key)
    {
        return key % size;
    }
    int hash2(int key)
    {
        return 7 - (key % 7);
    }

    void rehash()
    {
        int oldSize = size;
        int *oldKeys = keys;
        bool *oldOccupied = occupied;
        string *oldValues = values;

        size = size * 2;
        occupied = new bool[size];
        keys = new int[size];
        values = new string[size];

        for (int i = 0; i < size; i++)
        {
            keys[i] = -1;
            values[i] = "";
            occupied[i] = false;
        }

        currentSize = 0;
        for (int i = 0; i < oldSize; i++)
        {
            if (oldOccupied[i])
            {
                insert(oldKeys[i], oldValues[i]);
            }
        }

        delete[] oldKeys;
        delete[] oldValues;
        delete[] oldOccupied;
    }

public:
    RehashTable(int size)
    {
        keys = new int[size];
        values = new string[size];
        occupied = new bool[size];

        for (int i = 0; i < size; i++)
        {
            occupied[i] = false;
            keys[i] = -1;
            values[i] = "";
        }

        currentSize = 0;
        this->size = size;
    };

    void insert(int key, const string value)
    {

        double loadFactor = (double)currentSize / size;

        if (loadFactor > 0.7)
        {
            rehash();
        }

        int h1 = hash1(key);
        int h2 = hash2(key);
        int index = h1;

        int i = 1;
        while (occupied[index])
        {
            // update if key matches
            if (keys[index] == key)
            {
                values[index] = value;
                return;
            }

            index = (h1 + i * h2) % size;

            i++;
            if (i > size)
            {
                cout << "Table is full" << endl;
                return;
            }
        }

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;

        currentSize++;
    }

    void display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << keys[i] << ": '" << values[i] << "'" << endl;
        }
    }

    ~RehashTable()
    {
        delete[] keys;
        delete[] occupied;
        delete[] values;
    };
};

int main()
{
    RehashTable h(10);

    // Insert enough items to exceed 70% load factor
    h.insert(1, "A");
    h.insert(2, "B");
    h.insert(3, "C");
    h.insert(4, "D");
    h.insert(5, "E");
    h.insert(6, "F");
    h.insert(7, "G");

    cout << "\n--- Before Rehashing ---\n";
    h.display();

    // This insert will cause rehash (8th element)
    h.insert(8, "H");

    cout << "\n--- After Rehashing ---\n";
    h.display();

    // Add more entries to show new capacity works
    h.insert(18, "X");
    h.insert(28, "Y");

    cout << "\n--- Final Table ---\n";
    h.display();

    return 0;
}
