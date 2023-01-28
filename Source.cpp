#include<iostream>
# define MAX 7
using namespace std;

class queue
{
	int front, rear;
	int l[MAX];

public:
	queue() :front(-1), rear(-1) {}

	void enqueue();
	int  dequeue();
	int  search(int ss);
	void display();
};

void queue::enqueue()
{
	if (front == 0 && rear == MAX - 1 || front == rear + 1)
		cout << " QUEUE IS FULL....!" << endl;
		
	else
	{
		int data;
		cout << " Enter Data: ";
		cin >> data;

		if (front == -1)
			front = rear = 0;
		else if (rear == MAX - 1 && front != 0)
			rear = 0;
		else
			rear++;

		l[rear] = data;
	}


}

int queue::dequeue()
{
	if (front == -1)
		cout << " QUEUE IS EMPTY ... !!" << endl;

	else
	{
		int data;
		data = l[front];

		if (front == rear)
			front = rear = -1;
		else if (front == MAX - 1)
			front = 0;
		else
			front++;

		return data;
	}
}

void queue::display()
{
	int i, j;
	if (front == -1)
		cout << " QUEUE IS EMPTY ....!!" << endl;
	else
	{
		if (front > rear)
		{
			cout << " Data From Front to Last: ";
			for (i = front; i <= MAX - 1; i++)
				 cout << l[i] << " ";

			cout << "Data From Rear to Front: ";
			for (j = 0; j <= rear; j++)
				 cout << l[j] << " ";
		}
		else
		{
			cout << " Data From Front to Rear : " ;
			for (i = front; i <= rear; i++)
				cout << l[i] << " ";
		}
	}
	cout << endl << endl;

}

int queue::search(int ss)
{
	if (front > rear)
	{
		int size = MAX - front;
		int pos = ss - size;
		if (pos <= 0)
		{
			pos = front + ss;

			return l[pos];
		}
		else if (pos <= rear)
			return l[pos];
		else
		{
			cout << " Position Out Of Range..." << endl;
			cout << " Total Employees : " << size + rear << endl;
			return -1;
		}

	}
	else if (front > -1)
	{
		int check = front;
		check += ss;
		if (check < MAX)
			return l[ss];
		else
		{
			cout << "Position Out Of Range..." << endl;
			return -1;
		}
	}
	else
	{
		cout << "Queue is Empty ....\n\n";
		return -1;
	}
}

int main()
{
	queue q;
	int pos, data;
	char ch;

	do
	{
		system("CLS");
		cout << "---------(MAIN MENU)---------" << endl;
		cout << " 1) INSERTION" << endl;
		cout << " 2) DELETION " << endl;
		cout << " 3) SEARCHING " << endl;
		cout << " 4) DISPLAY " << endl;
		cout << " 5) EXIT " << endl<<endl;
		cout << "Enter Your Choice: " ;
		cin >> ch;
		switch (ch)
		{
		case '1':
			q.enqueue();
			break;
		case '2':
			q.dequeue();
			break;
		case '3':
			cout << "Enter The Position: ";
			cin >> pos;
			data = q.search(pos);
			if (data != -1)
				cout << "Data At Your position : " << data << endl;
			system("pause");
			break;

		case '4':
			q.display();
			system("pause");
			break;
		case '5':
			exit(-1);
		}
	} while (true);

	system("pause");
}
