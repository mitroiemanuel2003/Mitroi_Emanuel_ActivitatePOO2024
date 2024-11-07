#pragma warning(disable:4996)
#include<iostream>
#include<string>

using namespace std;

//Voi alege domeniul MECANICA AUTO
//Ca si obiecte sugestive voi folosi: clasa Motor, clasa CutieViteze, clasa SistemFranare

class CutieViteze {
private:
	const int nrRapoarte;//luam constant 7 viteze, 6 + marsarier
	string producator;
	int numarModele;//variabila pentru string* si float*, cate modele de cutie are producatorul X si ce capacitati de fluid au fiecare
	float* capacitateUlei;
	string* modelCutie;//unii producatori au mai multe denumiri la cutiile de viteze, ex: Audi - tipTronic, STronic, MultiTronic
	bool esteManuala;//0-nu;1-da
	static string tipAmbreiaj;
public:
	
	//CONSTRUCTORUL FARA PARAMETRI
	CutieViteze() : nrRapoarte(7) {
		this->producator = "Renault";
		this->numarModele = 0;
		this->capacitateUlei = NULL;
		this->modelCutie = NULL;
		this->esteManuala = 1;
	}

	//CONSTRUCTORUL CU 2 PARAMETRI
	CutieViteze(string producator, bool esteManuala) :nrRapoarte(7) {
		this->producator = producator;
		this->numarModele = 0;
		this->capacitateUlei = NULL;
		this->modelCutie = NULL;
		this->esteManuala = esteManuala;
	}

	//CONSTRUCTORUL CU TOTI PARAMETRII
	CutieViteze(string producator, int numarModele, float* capacitateUlei, string* modelCutie, bool esteManuala) :nrRapoarte(7) {
		this->producator = producator;
		this->numarModele = numarModele;
		this->capacitateUlei = new float[numarModele];
		this->modelCutie = new string[numarModele];
		for (int i = 0; i < numarModele; i++) {
			this->capacitateUlei[i] = capacitateUlei[i];
			this->modelCutie[i] = modelCutie[i];
		}
		this->esteManuala = esteManuala;
	}

	//CONSTRUCTORUL DE COPIERE
	CutieViteze(CutieViteze& c) :nrRapoarte(c.nrRapoarte) {
		this->producator = c.producator;
		this->numarModele = c.numarModele;
		this->capacitateUlei = new float[c.numarModele];
		this->modelCutie = new string[c.numarModele];
		for (int i = 0; i < c.numarModele; i++) {
			this->capacitateUlei[i] = c.capacitateUlei[i];
			this->modelCutie[i] = c.modelCutie[i];
		}
		this->esteManuala = c.esteManuala;
	}

	//DESTRUCTOR
	~CutieViteze() {
		if (this->capacitateUlei != NULL) {
			delete[]this->capacitateUlei;
		}
		if (this->modelCutie != NULL) {
			delete[]this->modelCutie;
		}
	}

	//GETTERI
	
	int getNrRapoarte() {
		return this->nrRapoarte;
	}

	string getProducator() {
		return this->producator;
	}

	int getNumarModele() {
		return this->numarModele;
	}

	float* getCapacitateUlei() {
		return this->capacitateUlei;
	}

	string* getModelCutie() {
		return this->modelCutie;
	}

	bool getEsteManuala() {
		return this->esteManuala;
	}

	static string getTipAmbreiaj() {
		return CutieViteze::tipAmbreiaj;
	}

	//SETTERI - pentru parametrul constant nu vom avea setteri, deoarece nu isi modifica valoarea
	
	void setProducator(string producatorNou) {
		if (producatorNou.length() > 0) {
			this->producator = producatorNou;
		}
	}

	void setNumarModele(int numarModeleNou, float* capacitateUleiNoua,string* modelCutieNou) {
		if (numarModeleNou > 0) {
			this->numarModele = numarModeleNou;
			if (this->capacitateUlei !=NULL) {
				delete[]this->capacitateUlei;
			}
			if (this->modelCutie != NULL) {
				delete[]this->modelCutie;
			}
			this->capacitateUlei = new float[numarModeleNou];
			this->modelCutie = new string[numarModeleNou];
			for (int i = 0; i < numarModeleNou; i++) {
				this->capacitateUlei[i] = capacitateUleiNoua[i];
				this->modelCutie[i] = modelCutieNou[i];
			}
		}
	}

	void setEsteManuala(bool esteManualaNou) {
		this->esteManuala = esteManualaNou;
	}
	
	static void setTipAmbreiaj(string tipAmbreiajNou) {
		if (tipAmbreiajNou.length() > 0) {
			CutieViteze::tipAmbreiaj = tipAmbreiajNou;
		}
	}

	//o functie de implementat

};
string CutieViteze::tipAmbreiaj = "hidraulic";

class Motor {
private:
	const int anulProductiei;
	int numarPistoane;
	int putereCP;
	static bool esteHybrid;
	float capacitate;
	char* producator;
	string combustibil;
public:
	//CONSTRUCTORUL FARA PARAMETRI
	Motor() :anulProductiei(2010) {
		this->numarPistoane = 4;
		this->putereCP = 100;
		this->capacitate = 1.4;
		this->producator = new char[strlen("Renault") + 1];
		strcpy(this->producator,"Renault");
		this->combustibil = "benzina";
	}

	//CONSTRUCTORUL CU 3 PARAMETRI
	Motor(int numarPistoane,float capacitate,string combustibil) :anulProductiei(2021) {
		this->numarPistoane = numarPistoane;
		this->putereCP = 140;
		this->capacitate = capacitate;
		this->producator = new char[strlen("VW") + 1];
		strcpy(this->producator, "VW");
		this->combustibil = combustibil;
	}

	//CONSTRUCTORUL CU TOTI PARAMETRII
	Motor(int numarPistoane, int putereCP, float capacitate, const char* producator,string combustibil) :anulProductiei(2023) {
		this->numarPistoane = numarPistoane;
		this->putereCP = putereCP;
		this->capacitate = capacitate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->combustibil = combustibil;
	}

	//CONSTRUCTORUL DE COPIERE
	Motor(Motor& m) :anulProductiei(m.anulProductiei) {
		this->numarPistoane = m.numarPistoane;
		this->putereCP = m.putereCP;
		this->capacitate = m.capacitate;
		this->producator = new char[strlen(m.producator) + 1];
		strcpy(this->producator, m.producator);
		this->combustibil = m.combustibil;
	}

	//DESTRUCTOR
	~Motor() {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}
	
	//GETTERI
	int getNumarPistoane() {
		return this->numarPistoane;
	}
	int getPutere() {
		return this->putereCP;
	}
	int getAnulProductiei() {
		return this->anulProductiei;
	}
	float getCapacitate() {
		return this->capacitate;
	}
	char* getProducator() {
		return this->producator;
	}
	string getCombustibil() {
		return this->combustibil;
	}
	static bool getEsteHybrid() {
		return Motor::esteHybrid;
	}

	//SETTERI

	void setNumarPistoane(int nrPistoane) {
		if (nrPistoane > 0) {
			this->numarPistoane = nrPistoane;
		}
	}
	void setPutere(int putere) {
		if (putere > 0) {
			this->putereCP = putere;
		}
	}
	void setCapacitate(float capacitate) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
	}
	void setProducator(const char* prod) {
		if (prod != NULL) {
			delete[]producator;
		}
		producator = new char[strlen(prod) + 1];
		strcpy(producator, prod);
	}
	void setCombustibil(string combustibil) {
		if (combustibil.length() > 0) {
			this->combustibil = combustibil;
		}
	}
	static void setEsteHybrid(bool hybrid) {
		Motor::esteHybrid = hybrid;
	}

	//FUNCTII GLOBALE DE TIP FRIEND (IN AFARA CLASEI)
	friend float kilowati(int putereCP); //transforma puterea motorului din cai putere in kilowati
	friend float puterePerPiston(int putereCP, int numarPistoane); //afla puterea motorului per piston

};
bool Motor::esteHybrid = 0;

float kilowati(int putereCP) {
	float putereKW = putereCP * 0.7457;//1cp=0.7457kwh
	return putereKW;
}

float puterePerPiston(int putereCP, int numarPistoane) {
	if (numarPistoane > 0) {
		float puterePiston = putereCP / numarPistoane;
		return puterePiston;
	}
}














class SistemFranare {
private:
	int numarProducatori;
	float* dimensiunePlacuta;
	string* producator;
	static bool areTambur;//0-NU / 1-DA
	int temperaturaOptimaFranare;
	const string materialPlacuta;
public:
	//CONSTRUCTORUL FARA PARAMETRI
	SistemFranare() :materialPlacuta("semi-metal"){
		this->numarProducatori = 0;
		this->dimensiunePlacuta = NULL;
		this->producator = NULL;
		this->temperaturaOptimaFranare = 150;
	}
	//CONSTRUCTORUL CU 1 PARAMETRU
	SistemFranare(int temperaturaOptimaFranare) :materialPlacuta("azbest") {
		this->numarProducatori = 0;
		this->dimensiunePlacuta = NULL;
		this->producator = NULL;
		this->temperaturaOptimaFranare = temperaturaOptimaFranare;
	}

	//CONSTRUCTORUL CU TOTI PARAMETRII
	SistemFranare(int numarProducatori, float* dimensiunePlacuta, string* producator, int temperaturaOptimaFranare,const string materialPlacuta) :materialPlacuta(materialPlacuta) {
		this->numarProducatori = numarProducatori;
		this->dimensiunePlacuta = new float[numarProducatori];
		this->producator = new string[numarProducatori];
		for (int i = 0; i < numarProducatori; i++) {
			this->dimensiunePlacuta[i] = dimensiunePlacuta[i];
			this->producator[i] = producator[i];
		}
		this->temperaturaOptimaFranare = temperaturaOptimaFranare;
	}

	//CONSTRUCTORUL DE COPIERE
	SistemFranare(SistemFranare& s):materialPlacuta(s.materialPlacuta) {
		this->numarProducatori = s.numarProducatori;
		this->dimensiunePlacuta = new float[s.numarProducatori];
		this->producator = new string[s.numarProducatori];
		for (int i = 0; i < s.numarProducatori; i++) {
			this->dimensiunePlacuta[i] = s.dimensiunePlacuta[i];
			this->producator[i] = s.producator[i];
		}
		this->temperaturaOptimaFranare = s.temperaturaOptimaFranare;
	}

	//DESTRUCTORUL
	~SistemFranare() {
		if (this->dimensiunePlacuta != NULL) {
			delete[]this->dimensiunePlacuta;
		}
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}

	//GETTERI
	
	int getNumarProducatori() {
		return this->numarProducatori;
	}
	float* getDimensiunePlacuta() {
		return this->dimensiunePlacuta;
	}
	string* getProducator() {
		return this->producator;
	}
	static bool getAreTambur() {
		return SistemFranare::areTambur;
	}
	int getTemperaturaOptimaFranare() {
		return this->temperaturaOptimaFranare;
	}
	const string getMaterialPlacuta() {
		return this->materialPlacuta;
	}

	//SETTERI
	//int numarProducatori;
	//float* dimensiunePlacuta;
	//string* producator;
	//static bool areTambur;//0-NU / 1-DA
	//int temperaturaOptimaFranare;
	//const string materialPlacuta;

	void setNumarProducatori(int numarProducatori, float* dimensiunePlacuta, string* producator) {
		if (numarProducatori > 0) {
			this->numarProducatori = numarProducatori;
		}
		if (this->dimensiunePlacuta != NULL) {
			delete[]this->dimensiunePlacuta;
		}
		if (this->producator != NULL) {
			delete[]this->producator;
		}
		this->dimensiunePlacuta = new float[numarProducatori];
		this->producator = new string[numarProducatori];
		for (int i = 0; i < numarProducatori; i++) {
			this->dimensiunePlacuta[i] = dimensiunePlacuta[i];
			this->producator[i] = producator[i];
		}
	}

	static void setAreTambur(bool areTambur) {
		SistemFranare::areTambur = areTambur;
	}

	void setTemperaturaOptimaFranare(int temperaturaOptimaFranare) {
		if (temperaturaOptimaFranare > 0) {
			this->temperaturaOptimaFranare = temperaturaOptimaFranare;
		}
	}

	//FUNCTII GLOBALE
	
	friend string numarPlacute(bool areTambur);
	friend string temperaturaOptima(int temperaturaOptimaFranare);//punem o conditite pentru a identifica tipul de placuta in functie de temperatura
};
bool SistemFranare::areTambur = 0;

string numarPlacute(bool areTambur) {
	if (areTambur) {
		return "Numarul de placute este 4.";
	}
	else {
		return "Numarul de placute este 8.";
	}
}

string temperaturaOptima(int temperaturaOptimaFranare) {
	if (temperaturaOptimaFranare > 150) {
		return "Placutele sunt fabricate din ceramica!";
	}
	else {
		return "Placutele sunt fabricate din metal/azbest!";
	}
}












void main() {
	cout << "<<<<<<<<<<<<<<<<<<CLASA CUTIE VITEZE>>>>>>>>>>>>>>>>>>>>>" << endl << endl;
	CutieViteze c1;
	cout << "Producator: " << c1.getProducator() << endl;
	cout << "Numar modele cutii de viteze disponibile de la producatorul " << c1.getProducator() << ": " << c1.getNumarModele() << endl;
	cout << "Cutia este (0-manuala,1-automata): " << c1.getEsteManuala() << endl;
	cout << "Numar rapoarte: " << c1.getNrRapoarte() << endl;
	cout << "Model cutie + capacitate ulei:" << endl;
	for (int i = 0; i < c1.getNumarModele(); i++) {
		cout << "Model: " << c1.getModelCutie()[i] << endl;
		cout << "Capacitate ulei: " << c1.getCapacitateUlei()[i] << endl;
	}
	cout << endl << endl;

	CutieViteze c2("BMW", 1);
	cout << "Producator: " << c2.getProducator() << endl;
	cout << "Numar modele cutii de viteze disponibile de la producatorul " << c2.getProducator() << ": " << c2.getNumarModele() << endl;
	cout << "Cutia este (0-manuala,1-automata): " << c2.getEsteManuala() << endl;
	cout << "Numar rapoarte: " << c2.getNrRapoarte() << endl;
	cout << "Model cutie + capacitate ulei:" << endl;
	for (int i = 0; i < c2.getNumarModele(); i++) {
		cout << "Model: " << c2.getModelCutie()[i] << endl;
		cout << "Capacitate ulei: " << c2.getCapacitateUlei()[i] << endl;
	}
	cout << endl << endl;



	float uleiC3[] = { 4.5 , 3.9 ,4.3 };//uleiC3 va tine locul lui float* capacitateUlei, fiind capacitatile pentru fiecare tip de cutie
	string modelC3[] = { "TipTronic","STronic","MultiTronic" };
	CutieViteze c3("Audi", 3, uleiC3, modelC3, 0);
	cout << "Producator: " << c3.getProducator() << endl;
	cout << "Numar modele cutii de viteze disponibile de la producatorul " << c3.getProducator() << ": " << c3.getNumarModele() << endl;
	cout << "Cutia este (0-manuala,1-automata): " << c3.getEsteManuala() << endl;
	cout << "Numar rapoarte: " << c3.getNrRapoarte() << endl;
	cout << "Model cutie + capacitate ulei:" << endl;
	for (int i = 0; i < c3.getNumarModele(); i++) {
		cout << "Model: " << c3.getModelCutie()[i] << endl;
		cout << "Capacitate ulei: " << c3.getCapacitateUlei()[i] << endl;
	}
	cout << endl << endl;

	cout << "CONSTRUCTORUL DE COPIERE: " << endl;

	CutieViteze c4(c3);
	cout << "Constructorul de copiere: " << endl;
	cout << "Producator: " << c4.getProducator() << endl;
	cout << "Numar modele cutii de viteze disponibile de la producatorul " << c4.getProducator() << ": " << c4.getNumarModele() << endl;
	cout << "Cutia este (0-manuala,1-automata): " << c4.getEsteManuala() << endl;
	cout << "Numar rapoarte: " << c4.getNrRapoarte() << endl;
	cout << "Model cutie + capacitate ulei:" << endl;
	for (int i = 0; i < c4.getNumarModele(); i++) {
		cout << "Model: " << c4.getModelCutie()[i] << endl;
		cout << "Capacitate ulei: " << c4.getCapacitateUlei()[i] << endl;
	}
	cout << endl << endl;

	c3.setProducator("ZF");
	c3.setNumarModele(2, new float[2] {3.8, 4.2}, new string[2]{ "6HP","8HP" });
	c3.setEsteManuala(0);

	cout << "Obiectul c3 dupa apelarea setterilor: " << endl << endl;
	cout << "Producator: " << c3.getProducator() << endl;
	cout << "Numar modele cutii de viteze disponibile de la producatorul " << c3.getProducator() << ": " << c3.getNumarModele() << endl;
	cout << "Cutia este (0-manuala,1-automata): " << c3.getEsteManuala() << endl;
	cout << "Numar rapoarte: " << c3.getNrRapoarte() << endl;
	cout << "Model cutie + capacitate ulei:" << endl;
	for (int i = 0; i < c3.getNumarModele(); i++) {
		cout << "Model: " << c3.getModelCutie()[i] << endl;
		cout << "Capacitate ulei: " << c3.getCapacitateUlei()[i] << endl;
	}
	cout << endl << endl;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<CLASA MOTOR>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;
	Motor m1;
	/*const int anulProductiei;
	int numarPistoane;
	int putereCP;
	static bool esteHybrid;
	float capacitate;
	char* producator;
	string combustibil;*/
	cout << "Producatorul: " << m1.getProducator() << endl;
	cout << "Anul productiei motorului: " << m1.getAnulProductiei() << endl;
	cout << "Capacitatea: " << m1.getCapacitate() << endl;
	cout << "Numarul de pistoane: " << m1.getNumarPistoane() << endl;
	cout << "Putere (cp): " << m1.getPutere() << endl;
	cout << "Combustibil: " << m1.getCombustibil() << endl;
	cout << "Hybrid (0-nu,1-da): " << m1.getEsteHybrid() << endl;
	cout << endl << endl;

	Motor m2(4, 1.9, "diesel");
	cout << "Producatorul: " << m2.getProducator() << endl;
	cout << "Anul productiei motorului: " << m2.getAnulProductiei() << endl;
	cout << "Capacitatea: " << m2.getCapacitate() << endl;
	cout << "Numarul de pistoane: " << m2.getNumarPistoane() << endl;
	cout << "Putere (cp): " << m2.getPutere() << endl;
	cout << "Combustibil: " << m2.getCombustibil() << endl;
	cout << "Hybrid (0-nu,1-da): " << m2.getEsteHybrid() << endl;
	cout << endl << endl;

	Motor m3(6, 218, 2.5, "BMW", "diesel");
	cout << "Producatorul: " << m3.getProducator() << endl;
	cout << "Anul productiei motorului: " << m3.getAnulProductiei() << endl;
	cout << "Capacitatea: " << m3.getCapacitate() << endl;
	cout << "Numarul de pistoane: " << m3.getNumarPistoane() << endl;
	cout << "Putere (cp): " << m3.getPutere() << endl;
	cout << "Combustibil: " << m3.getCombustibil() << endl;
	cout << "Hybrid (0-nu,1-da): " << m3.getEsteHybrid() << endl;
	cout << endl << endl;

	Motor m4(m3);
	cout << "Constructorul de copiere: " << endl;
	cout << "Producatorul: " << m4.getProducator() << endl;
	cout << "Anul productiei motorului: " << m4.getAnulProductiei() << endl;
	cout << "Capacitatea: " << m4.getCapacitate() << endl;
	cout << "Numarul de pistoane: " << m4.getNumarPistoane() << endl;
	cout << "Putere (cp): " << m4.getPutere() << endl;
	cout << "Combustibil: " << m4.getCombustibil() << endl;
	cout << "Hybrid (0-nu,1-da): " << m4.getEsteHybrid() << endl;
	cout << endl << endl;

	cout << "========FUNCTII GLOBALE=======" << endl;
	int putere = m3.getPutere();
	float putereKW = kilowati(putere);
	cout << "Putere in kilowati ora: " << putereKW << " kW" << endl;

	int putere2 = m3.getPutere();
	int numarPistoane = m3.getNumarPistoane();
	float puterePiston = puterePerPiston(putere2, numarPistoane);
	cout << "Putere per piston: " << puterePiston << " cp" << endl << endl;
	cout << endl << endl;

	m3.setCapacitate(3.0);
	m3.setCombustibil("benzina");
	m3.setEsteHybrid(0);
	m3.setNumarPistoane(6);
	m3.setPutere(245);
	m3.setProducator("Audi");

	cout << "Obiectul m3 dupa apelarea setterilor: " << endl;
	cout << "Producatorul: " << m3.getProducator() << endl;
	cout << "Anul productiei motorului: " << m3.getAnulProductiei() << endl;
	cout << "Capacitatea: " << m3.getCapacitate() << endl;
	cout << "Numarul de pistoane: " << m3.getNumarPistoane() << endl;
	cout << "Putere (cp): " << m3.getPutere() << endl;
	cout << "Combustibil: " << m3.getCombustibil() << endl;
	cout << "Hybrid (0-nu,1-da): " << m3.getEsteHybrid() << endl;
	cout << endl << endl;


	cout << "<<<<<<<<<<<<<<<<<<<<<<<CLASA SISTEM FRANARE>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;
	//int numarProducatori;
	//float* dimensiunePlacuta;
	//string* producator;
	//static bool areTambur;//0-NU / 1-DA
	//int temperaturaOptimaFranare;
	//const string materialPlacuta;

	SistemFranare s1;
	cout << "Numar modele de placute disponibile in stoc: " << s1.getNumarProducatori() << endl;
	cout << "Producatori si dimensiunile aferenete: " << endl;
	for (int i = 0; i < s1.getNumarProducatori(); i++) {
		cout << "Producator: " << s1.getProducator()[i] << endl;
		cout << "Dimensiune: " << s1.getDimensiunePlacuta()[i] << endl;
	}
	cout << "Au tambur? 0-NU,1-DA: " << s1.getAreTambur() << endl;
	cout << "Temperatura optima de franare pentru placutele fabricate din " << s1.getMaterialPlacuta() << " este: " << s1.getTemperaturaOptimaFranare() <<" grade celsius"<< endl;
	cout << endl << endl;

	SistemFranare s2(100);
	cout << "Numar modele de placute disponibile in stoc: " << s2.getNumarProducatori() << endl;
	cout << "Producatori si dimensiunile aferenete: " << endl;
	for (int i = 0; i < s2.getNumarProducatori(); i++) {
		cout << "Producator: " << s2.getProducator()[i] << endl;
		cout << "Dimensiune: " << s2.getDimensiunePlacuta()[i] << endl;
	}
	cout << "Au tambur? 0-NU,1-DA: " << s2.getAreTambur() << endl;
	cout << "Temperatura optima de franare pentru placutele fabricate din " << s2.getMaterialPlacuta() << " este: " << s2.getTemperaturaOptimaFranare() << " grade celsius" << endl;
	cout << endl << endl;

	float dimensiuni[] = { 13.2,14.5,12.3 };
	string producatori[] = { "ATE","TRW","SKF" };
	SistemFranare s3(3, dimensiuni, producatori, 300, "ceramica");
	cout << "Numar modele de placute disponibile in stoc: " << s3.getNumarProducatori() << endl;
	cout << "Producatori si dimensiunile aferenete: " << endl;
	for (int i = 0; i < s3.getNumarProducatori(); i++) {
		cout << "Producator: " << s3.getProducator()[i] << endl;
		cout << "Dimensiune: " << s3.getDimensiunePlacuta()[i] << endl;
		cout << endl;
	}
	cout << "Au tambur? 0-NU,1-DA: " << s3.getAreTambur() << endl;
	cout << "Temperatura optima de franare pentru placutele fabricate din " << s3.getMaterialPlacuta() << " este: " << s3.getTemperaturaOptimaFranare() << " grade celsius" << endl;
	cout << endl << endl;

	//Functii globale
	cout << "========FUNCTII GLOBALE=======" << endl;
	string nrPlacute = numarPlacute(s3.getAreTambur());
	cout << nrPlacute << endl;

	string temperatura = temperaturaOptima(s3.getTemperaturaOptimaFranare());
	cout << temperatura << endl << endl;

	SistemFranare s4(s3);
	cout << "Constructorul de copiere: " << endl;
	cout << "Numar modele de placute disponibile in stoc: " << s4.getNumarProducatori() << endl;
	cout << "Producatori si dimensiunile aferenete: " << endl;
	for (int i = 0; i < s4.getNumarProducatori(); i++) {
		cout << "Producator: " << s4.getProducator()[i] << endl;
		cout << "Dimensiune: " << s4.getDimensiunePlacuta()[i] << endl;
		cout << endl;
	}
	cout << "Au tambur? 0-NU,1-DA: " << s4.getAreTambur() << endl;
	cout << "Temperatura optima de franare pentru placutele fabricate din " << s4.getMaterialPlacuta() << " este: " << s4.getTemperaturaOptimaFranare() << " grade celsius" << endl;
	cout << endl << endl;

	s3.setAreTambur(1);
	s3.setTemperaturaOptimaFranare(285);
	s3.setNumarProducatori(3, new float[3] {13.9, 14.2, 15.3}, new string[3]{ "Delphi","Ferrodo","Textar" });

	cout << "Obiectul s3 dupa apelarea setterilor: " << endl;
	cout << "Numar modele de placute disponibile in stoc: " << s3.getNumarProducatori() << endl;
	cout << "Producatori si dimensiunile aferenete: " << endl;
	for (int i = 0; i < s3.getNumarProducatori(); i++) {
		cout << "Producator: " << s3.getProducator()[i] << endl;
		cout << "Dimensiune: " << s3.getDimensiunePlacuta()[i] << endl;
		cout << endl;
	}
	cout << "Au tambur? 0-NU,1-DA: " << s3.getAreTambur() << endl;
	cout << "Temperatura optima de franare pentru placutele fabricate din " << s3.getMaterialPlacuta() << " este: " << s3.getTemperaturaOptimaFranare() << " grade celsius" << endl;
	cout << endl << endl;

	
	
}