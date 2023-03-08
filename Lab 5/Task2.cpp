//#include <iostream>
//using namespace std;
//
//class Time {
//private:
//	int hour;
//	int minute;
//	int second;
//public:
//	void setHour(int h) {
//		while (h < 1 && h > 23) {
//			cout << "Invalid Hour Input, enter again " << endl;
//			cin >> h;
//		}
//		hour = h;
//	}
//	void setMinute(int m) {
//		while (m < 1 && m > 59) {
//			cout << "Invalid Minute Input, enter again " << endl;
//			cin >> m;
//		}
//		minute = m;
//	}
//	void setSecond(int s) {
//		while (s < 1 && s > 59) {
//			cout << "Invalid Seconds Input, enter again " << endl;
//			cin >> s;
//		}
//		second = s;
//	}
//	int getHour() {
//		return hour;
//	}
//	int getMinute() {
//		return minute;
//	}
//	int getSecond() {
//		return second;
//	}
//	void print24hour() {
//		cout << hour << " : " << minute << " : " << second;
//	}
//	void print12hour() {
//		cout << hour - 12 << " : " << minute << " : " << second;
//	}
//	void incSec(int x = 1) {
//		second += x;
//	}
//	void incMinute(int x = 1) {
//		minute += x;
//	}
//	void incHour(int x = 1) {
//		hour += x;
//	}
//};