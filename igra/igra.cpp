#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class IgroK {
	int id = 0;
	int factory = 0;
	int automated_factory = 0;
	int esm = 0;
	int egp = 0;//units of finished products
	long money = 0;
public:
	int get_id()const { return this->id; }
	int get_factory()const { return this->factory; }
	int get_automated_factory()const { return this->automated_factory; }
	int get_esm()const { return this->esm; }
	int get_egp()const { return this->egp; }
	int get_money()const { return this->money; }

	void set_id(int id) {  this->id = id;  }
	void set_factory(int factory) {  this->factory = factory;  }
	void set_automated_factory(int automated_factory) {  this->automated_factory = automated_factory;  }
	void set_esm(int esm) {  this->esm = esm;  }
	void set_egp(int egp) {  this->egp = egp;  }
	void set_money(int money) {  this->money = money;  }

	IgroK() {cout << "constructor igrok" << this << endl;}
	IgroK(int id,int factory,int automated_factory,int esm,int egp,long money){
		this->id = id;
		this->factory = factory;
		this->automated_factory = automated_factory;
		this->esm = esm;
		this->egp = egp;
		this->money = money;
	}
	IgroK(int id) { set_id(id); }
	~IgroK(){/*деструктор класса*/cout << "destructor igrok"<< this<< endl;}
	void print() {
		cout << "factory :           " << get_factory() << endl;
		cout << "automated_factory : " << get_automated_factory() << endl;
		cout << "esm :               " << get_esm() << endl;
		cout << "egp :               " << get_egp() << endl;
		cout << "money :             " << get_money() << endl;
		cout << endl;
	}

	IgroK& operator= (const IgroK& other) {// оператор присвоени¤
		this->id = other.id;
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
	long money = 100000;
};

class BanK {
private:/// IgroK igrok; // переменная для хранения экземпляра
public:
	
	~BanK() { cout << "destructor bank" << this << endl; }
	BanK() { /*конструктор для инициализации(можно опустить)*/cout << "constructor bank" << this << endl;}

	bool nalog(IgroK& obj) {
		long add = (obj.get_factory() * 1000) + (obj.get_automated_factory() * 1500) + (obj.get_esm() * 300) + (obj.get_egp() * 500);
		long old = obj.get_money();
		if ((old - add) < 0)return true;
		obj.set_money(old - add);
		//obj.print();
		return false;
	}
	void Init_igrok(IgroK& obj) {
		Start_paraM param;
		obj.set_factory(param.factory);
		obj.set_automated_factory(param.automated_factory);
		obj.set_esm(param.esm);
		obj.set_egp(param.egp);
		obj.set_money(param.money);
		//print_igrok(obj);
	}
	void print_igrok(IgroK& obj) { obj.print(); }
	bool buy_a_factory(IgroK& obj) { 
		if (obj.get_factory() > 6 || obj.get_money() < 5000) { return false; }
		else{
		 obj.set_money(obj.get_money() - 5000);
		 obj.set_factory(obj.get_factory() + 1);
		}
		return true;
	}
	bool buy_an_automated_factory(IgroK& obj) {
		if (obj.get_automated_factory() > 6 || obj.get_money() < 10000) { return false; }
		else{
		 obj.set_money(obj.get_money() - 10000);
		 obj.set_automated_factory(obj.get_automated_factory() + 1);
		}
		return true;
	}
	bool buy_a_ESM(IgroK& obj,int kollvo,long cena) {
		if ( obj.get_money() < (kollvo*cena)) { return false; }
		else {
			obj.set_money(obj.get_money() - (kollvo * cena));
			obj.set_esm(obj.get_esm() + kollvo);
		}
		return true;
	}
	
	void purchase_order_ESM(IgroK& obj,int kollvo,long cena){}
};

//Уровень	ЕСМ	    Минимальная цена	ЕГП	    Максимальная цена
double arr_urovni[5][4] = { { 1.0, 800, 3.0, 6500 },  //	1		1.0Р	800					З.ОР	6500
							{ 1.5, 650, 2.5, 6000 },  //	2		1.5Р	650					2.5Р	6000
							{ 2.0, 500, 2.0, 5500 },  //	3		2.0Р	500					2.0Р	5500
							{ 2.5, 400, 1.5, 5000 },  //	4		2.5Р	400					1.5Р	5000
							{ 3.0, 300, 1.0, 4500 } };//	5		3.0Р	300					1.0Р	4500

//Старый уровень
// |	    |------------Новый уровень------------|
// |	 	  1		  2		  3		  4		  5			  1 2 3 4 5
int arr_veroyatnosti[5][5] = { { 4, 4, 2, 1, 1 },  // 1		1 / 3	1 / 3	1 / 6	1 / 12	1 / 12     1  4,4,2,1,1
							   { 3, 4, 3, 1, 1 },  // 2		1 / 4	1 / 3	1 / 4	1 / 12	1 / 12	   2  3,4,3,1,1
							   { 1, 3, 4, 3, 1 },  // 3		1 / 12	1 / 4	1 / 3	1 / 4	1 / 12	   3  1,3,4,3,1
							   { 1, 1, 3, 4, 3 },  // 4		1 / 12	1 / 12	1 / 4	1 / 3	1 / 4	   4  1,1,3,4,3
							   { 1, 1, 2, 4, 4 } };// 5		1 / 12	1 / 12	1 / 6	1 / 3	1 / 3	   5  1,1,2,4,4

void main() {
	setlocale(LC_ALL, "Russian");
	int l = 1;
	int xz;
	cout << "введите число игроков :"; cin >> xz;
	vector <IgroK> igroki_vector(xz + 1);
	//vector <double> yrovni_cen();

		BanK bank;
		
		//IgroK player =  IgroK(0,"федя",2,1,10,12,100500);player.print();
		
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 4; j++) {
				if (j == 3) { cout << setw(4) << arr_urovni[i][j] << endl; }
				else {cout << setw(4) << arr_urovni[i][j] << ",  ";}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == 4) { cout << setw(1) << arr_veroyatnosti[i][j] << endl; }
				else { cout << setw(1) << arr_veroyatnosti[i][j] << ", "; }
			}
		}
		for (int i = 1;i<size(igroki_vector);i++){bank.Init_igrok(igroki_vector[i]);}
		for (int i = 1;i<size(igroki_vector);i++){ cout << "igrok " << i << endl; bank.print_igrok(igroki_vector[i]);  /*igroki_vector[i].print();*/}

		system("pause");
		bool brr =true;
		brr = bank.buy_a_factory(igroki_vector[2]);
		if (brr) {for (int i = 1; i < size(igroki_vector); i++) {cout << "igrok " << i << endl; bank.print_igrok(igroki_vector[i]);}}
		else{ cout << "косяк при покупке фабрики"; brr = true;}
		brr = bank.buy_a_ESM(igroki_vector[2],3,300);
		if (brr) { for (int i = 1; i < size(igroki_vector); i++) { cout << "igrok " << i << endl; bank.print_igrok(igroki_vector[i]); } }
		else { cout << "косяк при покупке фабрики"; brr = true; }

	metka:	
		while (l != 0) {
			for (int i = 1; i < size(igroki_vector); i++) { 
				if (bank.nalog(igroki_vector[i])) {cout << "game over igrok " << i << "  " << endl; l = 0; goto metka;
				}
			}
			for (int i = 1; i < size(igroki_vector); i++){ cout << "igrok " << i << endl; igroki_vector[i].print(); }
			cin >> l;
				
		}
	system("pause");
}
/*
	модернизировать modernize
*/
			/*
			int xz[] = { 1,2,3,4,5,6,7,8,100500,0,0,0,1 };
			for (int i = 0; i < size(xz); i++) {
				if ((size(xz) - 1) !=i) { cout << xz[i] << ","; }	
				else { cout << xz[i] << endl; }	
			}
			*/