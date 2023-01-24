#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Car
{
private:
	int Position;
	std::vector<class Observer*> ObserverList;
public:
	int getPosition()
	{
		return Position;
	}
	void SetPosition(int newPosition) {
		Position = newPosition;
		notify();
	}
	void attach(Observer *obs)
	{
		ObserverList.push_back(obs);
	}
	void detach(Observer* obs)
	{
		ObserverList.erase(std::remove(ObserverList.begin(), ObserverList.end(), obs), ObserverList.end());
	}
	void notify();

};
class Observer {
	Car* _car;

public:
	Observer(Car* car) {
		_car = car;
		_car->attach(this);
	}
	virtual void update() = 0;
protected:
	Car* getCar()
	{
		return _car;
	}
};
void Car::notify() {
	for (int i = 0; i < ObserverList.size(); ++i) {
		ObserverList[i]->update();
	}
}
class LeftObserver:public Observer
{
public:
	LeftObserver(Car *car):Observer(car){}
	void update() {
		int pos = getCar()->getPosition();
		if (pos < 0)
		{
			cout << "left side" << endl;
		}
	}
};
class RightObserver :public Observer {
public:
	RightObserver(Car* car) :Observer(car){}
	void update() {
		int pos = getCar()->getPosition();
		if (pos > 0) {
			cout << "right side" << endl;
		}
	}
};
class MiddleObserver :public Observer {
public:
	MiddleObserver(Car *car): Observer(car){}
	void update() {
		int pos = getCar()->getPosition();
		if (pos == 0) {
			cout << "running in middle" << endl;
		}
	}
};

int main()
{
	Car* car = new Car();

	LeftObserver leftObserver(car);
	RightObserver rightObserver(car);
	MiddleObserver middleObserver(car);

	cout << "hit left right button to  drive a car in your city!!! and press Esc to close" << endl;
	char pressedbutton;
	bool breakLoop = false;
	while (breakLoop == false) {
		cin >> pressedbutton;
		switch (pressedbutton)
		{
		case 108:// 108 is the value of L
			car->SetPosition(-1);
			break;

		case 99:// 99 is th evalue o c for center
			car->SetPosition(0);
			break;

		case 114:
			car->SetPosition(1);
			break;

		case 98://98 for B for Break
			breakLoop = true;
		default:
			cout << "please drive carefully!!";
			break;
		}
	}
	cout << "have good day...";
	return 0;
}