#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class priorityqueue
{
private:

	vector<int> a;
	int n = 0;

	void siftDown(int i) // Max
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int largest = i;
		if ((l < n) && (a[i] > a[l]))
			largest = l;
		if ((r < n) && (a[largest] > a[r]))
			largest = r;
		if (largest != i)
		{
			swap(a[i], a[largest]);
			siftDown(largest);
		}
	}
	void siftUp(int i) // Min,
	{
		if ((i > 0) && (a[i] < a[(i - 1) / 2]))
		{
			swap(a[i], a[(i - 1) / 2]);
			siftUp((i - 1) / 2);
		}
	}
	int findKey(int mas) //
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == mas)
				return i;
		}
		return -1;
	}

public:
	priorityqueue() {
		a.resize(1000000);
	}

	void push(int mas) {
		a[n] = mas;
		siftUp(n++);
	}

	int extractMin() {
		if (n > 0) {
			int value = a[0];
			a[0] = a[--n];
			siftDown(0);
			return value;
		}
		else
			return -1000000001;
	}

	void decreaseKey(int mas, int newNumber) {
		int index = findKey(mas);
		a[index] = newNumber;
		siftUp(index);
	}

};

int main() {
	ifstream fin("priorityqueue.in");
	ofstream fout("priorityqueue.out");
	priorityqueue priorq;
	vector<int> arr(1000000);
	string command;
	int x, y;
	int k = 0;
	while (!fin.eof())
	{
		command = "";
		fin >> command;
		if (command == "push")
		{
			fin >> x;
			priorq.push(x);
			arr[k] = x;
		}
		else if (command == "extract-min")
		{
			int min = priorq.extractMin();
			if (min > -1000000001)
				fout << min << endl;
			else
				fout << '*' << endl;
		}
		else if (command == "decrease-key")
		{
			fin >> x >> y;
			priorq.decreaseKey(arr[x - 1], y);
			arr[x - 1] = y;
		}
		k++;
	}
	fin.close();
	fout.close();
	return 0;
}