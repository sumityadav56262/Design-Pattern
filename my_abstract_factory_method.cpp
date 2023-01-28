#include<iostream>
using namespace std;
class iCar
{
public:
	virtual void getCar() = 0;
};
class HyundaiCar : public iCar
{
public:
	void getCar()
	{
		cout << "geting hyundai car." << endl;
	}
};
class ToyotaCar : public iCar
{
public:
	void getCar()
	{
		cout << "geting Toyota Car." << endl;
	}
};
class iBike
{
public:
	virtual void getBike() = 0;
};
class HyundaiBike :public iBike
{
	void getBike()
	{
		cout << "getting hyudai bike." << endl;
	}
};
class ToyotaBike : public iBike
{
	void getBike()
	{
		cout << "getting Toyota Bike." << endl;
	}
};
class iCompany
{
public:
	virtual iCar* creatCar() = 0;
	virtual iBike* creatBike() = 0;
};
class HyudaiCompany : public iCompany
{
	iCar* creatCar()
	{
		return new HyundaiCar;
	}
	iBike* creatBike()
	{
		return new HyundaiBike;
	}
};
class ToyotaCompany : public iCompany
{
	iCar* creatCar()
	{
		return new ToyotaCar;
	}
	iBike* creatBike()
	{
		return new ToyotaBike;
	}
};

class vehicleCompany
{
public:
	static iCompany* creatVehicle(string company)
	{
		if (company == "hyundai")
			return new HyudaiCompany;
		else if (company == "tayota")
			return new ToyotaCompany;

		cout << "invailid inpute!!";
		return 0;
	}

};
int main()
{
	string company;
	cout << "Enter vehicle company name: ";
	cin >> company;
	iCompany* com = vehicleCompany::creatVehicle(company);

	iCar* car = com->creatCar();
	car->getCar();

	iBike* Bike = com->creatBike();
	Bike->getBike();

	return 0;
}