#include <iostream>
#include <vector>
using namespace std;

class IgroK {
	int id = 0;
	string name;
	int factory = 0;
	int automated_factory = 0;
	int esm = 0;
	int egp = 0;//units of finished products
	long money = 0;
public:
	int get_id()const { return this->id; }
	string get_name()const { return this->name; }
	int get_factory()const { return this->factory; }
	int get_automated_factory()const { return this->automated_factory; }
	int get_esm()const { return this->esm; }
	int get_egp()const { return this->egp; }
	int get_money()const { return this->money; }

	void set_id(int id) {  this->id = id;  }
	void set_name(string name) {  this->name = name;  }
	void set_factory(int factory) {  this->factory = factory;  }
	void set_automated_factory(int automated_factory) {  this->automated_factory = automated_factory;  }
	void set_esm(int esm) {  this->esm = esm;  }
	void set_egp(int egp) {  this->egp = egp;  }
	void set_money(int money) {  this->money = money;  }

	IgroK() {cout << "constructor igrok" << this << endl;}
	IgroK(int id,string name,int factory,int automated_factory,int esm,int egp,long money){
		this->id = id;
		this->name = name;
		this->factory = factory;
		this->automated_factory = automated_factory;
		this->esm = esm;
		this->egp = egp;
		this->money = money;
	}
	IgroK(string name) { set_name(name); }
	~IgroK(){//деструктор класса
	cout << "destructor igrok"<< this<< endl;}
	void print() {
		cout << "factory :           " << get_factory() << endl;
		cout << "automated_factory : " << get_automated_factory() << endl;
		cout << "esm :               " << get_esm() << endl;
		cout << "egp :               " << get_egp() << endl;
		cout << "money :             " << get_money() << endl;
		cout << endl;
	}

	//void buy_a_factory(BanK obj){
	//	//get_
	//}
	IgroK& operator= (const IgroK& other) {// оператор присвоени¤
		this->id = other.id;
		this->name = other.name;
		this->factory = other.factory;
		this->automated_factory = other.automated_factory;
		this->esm = other.esm;
		this->egp = other.egp;
		this->money = other.money;
		//cout << "copyAssigment  " << this << endl;
		return *this;
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
	void get_factory() {}
	~BanK() { cout << "destructor bank" << this << endl; }
	BanK() { // конструктор для инициализации (можно опустить)
		cout << "constructor bank" << this << endl;
		//igrok = new igrok1();
	}

	bool nalog(IgroK& obj) {
		long add = (obj.get_factory() * 1000) + (obj.get_automated_factory() * 1500) + (obj.get_esm() * 300) + (obj.get_egp() * 500);
		long old = obj.get_money();
		if ((old - add) < 0)return true;
		obj.set_money(old - add);
		//obj.print();
		return false;
	}
	void start_igrok(IgroK& obj) {
		Start_paraM param;
		obj.set_factory(param.factory);
		obj.set_automated_factory(param.automated_factory);
		obj.set_esm(param.esm);
		obj.set_egp(param.egp);
		obj.set_money(param.money);
		//print_igrok(obj);
	}
	void print_igrok(IgroK& obj) { obj.print(); }
};


	void main(){
		setlocale(LC_ALL, "Russian");
		int l = 1;
		int xz;
		BanK bank;
		cout << "введите число игроков :"; cin >> xz;
		vector <IgroK> igroki_vector(xz+1);
		IgroK player =  IgroK(0,"федя",2,1,10,12,100500);
		player.print();
		for (int i = 1;i<size(igroki_vector);i++){bank.start_igrok(igroki_vector[i]); /*cout << "igrok "<<i << endl; igroki_vector[i].print();*/}
	metka:	
		while (l != 0) {
			for (int i = 1; i < size(igroki_vector); i++) { 
				if (bank.nalog(igroki_vector[i])) {
					cout << "game over igrok " << i << "  " << endl; l = 0; goto metka;;
				}
			}
			for (int i = 1; i < size(igroki_vector); i++){ cout << "igrok " << i << endl; igroki_vector[i].print(); }
			cin >> l;
				/*int xz[] = { 1,2,3,4,5,6,7,8,100500,0,0,0,1 };
				for (int i = 0; i < size(xz); i++) {
					if ((size(xz) - 1) !=i) { cout << xz[i] << ","; }
					else { cout << xz[i] << endl; }
				}*/
		}
		//delete[]igroki_vector;
	system("pause");
}
/*
	купить фабрику buy_a_factory
	купить автоматизированную фабрику buy_an_automated_factory
	модернизировать modernize
	продать sell
*/