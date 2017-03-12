#include<iostream>
#include<math.h>
using namespace std;
class sequence {
public: 
	int num;
	int idx_last;
	int idx;
	
};
class arifm:public sequence {
	int d;
public:
	arifm(int x, int y, int z,int j) {
		num = x;
		d = y;
		idx_last = z;
		idx = z;
	}
	int sum();
	int index();
};
class constant_seq :public sequence {

};
class geom :public sequence {
	int q;
public:
	geom(int x, int y,int z,int j) {
		num = x;
		q = y;
		idx_last = z;
		idx = j;
	}
	int sum();
	int index();
};
void geom_seq();
void algeb_seq();
int main() {
	int choise;
	cout << "Chouse type of the sequnce: " << endl << "1.Geometric." << endl << "2.Algebraic." << endl << "3.Constant." << endl;
	cin >> choise;
	system("cls");
	switch(choise) {
	case 1: geom_seq();
	case 2: algeb_seq();
	}
	system("pause");
	return 0;
}


int geom::sum()
{

	int s;
	s = (((num*(pow(q,idx_last) - 1))) / (q - 1));
		return s;
}

int geom::index()
{
	int i;
	i = num*pow(q, (idx - 1));
		return i;
}
int arifm::sum()
{

	int s;
	s = ((2 * num + d*(idx - 1)) / 2)*idx;
	return s;
}

int arifm::index()
{
	int i;
	i = num + d*(idx - 1);
	return i;
}
void geom_seq()
{
	cout << "Geometric sequence." << endl;
	int n, q, sum, n_last, idx;
	cout << "Enter the first element: ";
	cin >> n;
	cout << "Enter q: ";
	cin >> q;
	cout << "Enter index of the last element: ";
	cin >> n_last;
	cout << "Enter index of the element, that you want to find: ";
	cin >> idx;

	geom a = geom(n, q,n_last,idx);
	sum = a.sum();

	cout << "The amount of the first "<<n_last<<" elements is " << a.sum() << endl;
	cout << "Your element with index "<<idx<<" is " << a.index() << endl;
}

void algeb_seq()
{
	cout << "Algebraic sequence." << endl;
	int n, d, sum, n_last, idx;
	cout << "Enter the first element: ";
	cin >> n;
	cout << "Enter d: ";
	cin >> d;
	cout << "Enter index of the last element: ";
	cin >> n_last;
	cout << "Enter index of the element, that you want to find: ";
	cin >> idx;
	arifm a(n, d, n_last, idx);
	cout << "The amount of the first " << n_last << " elements is " << a.sum() << endl;
	cout << "Your element with index " << idx << " is " << a.index() << endl;
}
