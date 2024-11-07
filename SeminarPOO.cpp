#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m) : anDeschidere(m.anDeschidere) { // : -> lista de initializari a constructorului
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		//de ce nu dezalocam - pentru ca facem un obiect nou si nu avem ce dezaloca
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	//string oras;
	//int nrAngajati;
	//float* salarii;
	//float suprafata;
	//const int anDeschidere;
	//static int impozitM2;

	Magazin operator=(const Magazin& mag) {//pentru a evita apelarea constructorului de copiere
		//dezalocam pentru ca modificam obiectul si trebuie sa eliberam memoria

		if (&mag != this) {//verificare de autoasignare(autoatribuire)

			if (this->salarii != NULL) {
				delete[]this->salarii;
			}

			this->oras = mag.oras;
			this->nrAngajati = mag.nrAngajati;

			this->salarii = new float[mag.nrAngajati];
			for (int i = 0; i < mag.nrAngajati; i++) {
				this->salarii[i] = mag.salarii[i];
			}
			this->suprafata = mag.suprafata;
		}
		return *this; //obiectul de la adresa lui this;

	}

	Magazin operator+(const Magazin& m)const {//sa adune suprafata

		Magazin sup = *this;
		sup.suprafata = this->suprafata + m.suprafata;

		return sup;
	}

	Magazin operator+=(const Magazin& m) {

		this->suprafata = this->suprafata + m.suprafata;
		//this->suprafata+=m.suprafata;
		return*this;
	}

	Magazin operator+(float adaugare)const {
		Magazin temp = *this;
		temp.suprafata = this->suprafata + adaugare;
		return temp;
	}


	~Magazin() { //nu are parametri
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Numar angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}
	//GETTERI - nu are parametru
	int getNrAngajati() {
		return this->nrAngajati;
	}

	float getSuparafata() {
		return this->suprafata;
	}

	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) { //exceptie
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	//SETTERI - primeste parametru pentru noua valoare
	void setNrAngajati(int nrAngajatiNou, float* salarii) {
		if (nrAngajatiNou > 0) {
			this->nrAngajati = nrAngajatiNou;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajatiNou];//this->nrAngajati
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}

		}
	}

	void setSuprafata(float suprafataNou) {
		if (suprafataNou > 0) {
			this->suprafata = suprafataNou;
		}
	}

	friend Magazin operator+(float valoare, const Magazin& m);

};
int Magazin::impozitM2 = 2;

Magazin operator+(float valoare, const Magazin& m) {//este sub forma de functie
	Magazin magazin = m;
	magazin.suprafata = valoare + m.suprafata;
	return magazin;
}


int main() {

	Magazin m1;
	cout << m1.getNrAngajati() << endl;
	m1.setNrAngajati(6, new float[6] {2, 5, 4, 8, 6, 3});//initializare in-line
	cout << m1.getNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1] << endl;//indexam cu valoarea la care vrem sa ne deplasam
	cout << m2.getSalariu(1) << endl;
	m2.setNrAngajati(5, new float[5] {5, 8, 3, 9, 4});

	cout << m2.getSalariu(3) << endl;

	Magazin m3(m2);
	Magazin m4 = m2;



	return 0;
}