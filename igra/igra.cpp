#include <iostream>
#include <vector>
using namespace std;

class IgroK {
	int factory = 0;
	int automated_factory = 0;
	int esm = 0; 
	int egp = 0;//units of finished products
	long money = 0;
public:
	int get_factory()const { return this->factory; }
	int get_automated_factory()const { return this->automated_factory; }
	int get_esm()const { return this->esm; }
	int get_egp()const { return this->egp; }
	int get_money()const { return this->money; }

	void set_factory(int factory) {  this->factory = factory;  }
	void set_automated_factory(int automated_factory) {  this->automated_factory = automated_factory;  }
	void set_esm(int esm) {  this->esm = esm;  }
	void set_egp(int egp) {  this->egp = egp;  }
	void set_money(int money) {  this->money = money;  }

	IgroK() {
		cout << "constructor igrok" << this << endl;
}
	~IgroK(){//деструктор класса
	cout << "destructor igrok"<< this<< endl;
	}
	void print() {
		cout << "factory :           " << get_factory() << endl;
		cout << "automated_factory : " << get_automated_factory() << endl;
		cout << "esm :               " << get_esm() << endl;
		cout << "egp :               " << get_egp() << endl;
		cout << "money :             " << get_money() << endl;
		cout << endl;
	}
};
struct Start_paraM {
	int factory = 2;
	int automated_factory = 0;
	int esm = 4;
	int egp = 2;//units of finished products
	long money = 10000;
};

class BanK {
private:/// IgroK igrok; // переменная для хранения экземпляра
public:
	~BanK(){ cout << "destructor bank" << this << endl; }
	BanK() { // конструктор для инициализации (можно опустить)
		cout << "constructor bank" << this << endl;
		//igrok = new igrok1();
	}

	bool nalog(IgroK &obj) {
		long add = (obj.get_factory()*1000)+ (obj.get_automated_factory() * 1500)+ (obj.get_esm() * 300)+ (obj.get_egp() * 500);
		long old = obj.get_money();
		if ((old - add) < 0)return true;
		obj.set_money(old - add);
		//obj.print();
		return false;
	}
	void start_igrok(IgroK &obj) {
		Start_paraM param;
		obj.set_factory(param.factory);
		obj.set_automated_factory(param.automated_factory);
		obj.set_esm(param.esm);
		obj.set_egp(param.egp);
		obj.set_money(param.money);
		//print_igrok(obj);
	}
	void print_igrok(IgroK &obj) {obj.print();}
};


	void main(){
		int i = 1;
		IgroK A,B;
		BanK bank;
		bank.start_igrok(A);cout << "igrok A" << endl;A.print();
		bank.start_igrok(B);cout << "igrok B" << endl;B.print();
	while(i!=0){
		if (bank.nalog(A)) { cout << "game over igrok A  "<<endl; i = 0; break; }
		if (bank.nalog(B)) { cout << "game over igrok B  "<<endl; i = 0; break; }
		cout << "igrok A" << endl;A.print();
		cout << "igrok B" << endl;B.print();
		cin >> i;
		}
	}
	/*
		купить фабрику buy_a_factory
		купить автоматизированную фабрику buy_an_automated_factory
		модернизировать modernize
		продать sell
	*/		