// Singleton Pattern
#if 0
#include <bits/stdc++.h>

using namespace std;

class Singleton {

private:
	Singleton() {}
	Singleton(const Singleton& ref) {}
	Singleton& operator=(const Singleton& ref) {}
	~Singleton() {}

	//static Singleton* instance_;
public:
	static Singleton& GetInstance() {
		static Singleton* instance = new Singleton();
		return *instance;
	}
	/*
	static Singleton* GetInstance() {
		if (instance_ == nullptr) {
			instance_ = new Singleton();
		}
		return instance_;
	}
	*/
};


//Singleton* Singleton::instance_ = nullptr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	clock_t start, fin;

	start = clock();

	Singleton& a = Singleton::GetInstance();
	Singleton& b = Singleton::GetInstance();
	Singleton& c = Singleton::GetInstance();

	cout << "Singleton a Address: " << &a << '\n';
	cout << "Singleton b Address: " << &b << '\n';
	cout << "Singleton c Address: " << &c << '\n';

	fin = clock();

	double timeLen = (double)(fin - start) / CLOCKS_PER_SEC;
	cout << fixed;
	cout.precision(15);
	cout << timeLen;

	return 0;
}


#endif