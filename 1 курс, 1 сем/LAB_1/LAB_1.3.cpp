#include <fstream>
#include <vector>

using namespace std;
ifstream in;
ofstream out;

int max(int a, int b) {      //???????, ??????? ?????????? ??????? ?????
	if (a >= b) return a;
	else return b;
}

int main() {
	in.open("turtle.in");
	int h, w;
	in >> h >> w;
	vector < vector <int> > a(h, vector <int>(w));
	for (int i = h - 1; i >= 0; i--) {		//????????? ????????? ??????, ??? ??? ? ??????? ??????? ??????? ???????? ?????????(????????? ????????? ???? ????? ?????),
		for (int j = 0; j < w; j++) {		//? ????????? ?? ???? ??? ??????, ?? ?????????? ???????? ?????? ? h-1 ??????, ?? ???? ?????? ????
			in >> a[i][j];
		}
	}
	in.close();
	for (int i = 1; i < h; i++) {
		a[i][0] += a[i - 1][0];		// ??????? ??? ???????? ??????? ????????, ??? ??? ? ??? ????? ??????? ?????? 1 ????? ??? ????? ?? ??????
	}
	for (int j = 1; j < w; j++) {
		a[0][j] += a[0][j - 1];		//?????????? ??????? ???????? ????????? ? ?????? ????????(??, ??? ?????) ?? ??? ?? ???????
	}
	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			a[i][j] += max(a[i - 1][j], a[i][j - 1]);		//??????? ? ???????? 1 1(????? ??? ? ???? ?????????? ???????????? ??????)
		}                                                   //??????? ?????????? ??????? ????? ??? ?????, ??? ??? ?????? ?? ??? ????? ???? ???????
	}                                                       //????? ??????? ??????? ?????????? ???????? ??? ??????? ???????? ???????
	out.open("turtle.out");
	out << a[h - 1][w - 1];                                //??????? -1, ??? ??? ???????? ? ???????? ????????
	out.close();
	return 0;
}
