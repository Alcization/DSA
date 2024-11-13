#include <string>
#include <iostream>
using namespace std;

class PrinterQueue
{
public:
    string max_heap[100];
    int size = 0;
public:
    PrinterQueue()
    {
        for(int i = 0 ; i < 100; i++) max_heap[i] = "";
    }
    void addNewRequest(int priority, string fileName)
    {
        if (max_heap[priority] == "") max_heap[priority] = fileName;
        else max_heap[priority] += " " + fileName;
    }
    void print()
    {
        for (int i = 100 - 1 ; i >= 0; i--)
        {
            if (max_heap[i] != "")
            {
                int count = max_heap[i].find(" ");
                if (count == -1){
                    cout << max_heap[i] << endl;
                    max_heap[i] = "";
                }
                else
                {
                    cout << max_heap[i].substr(0, count) << endl;
                    max_heap[i] = max_heap[i].substr(count+1);
                }
                return;
            }
        }
        cout << "No file to print" << endl;
    }
};