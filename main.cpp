#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Produs {

protected:

    string material;
    float pret;
    int stoc;

public:

    //constructori
    Produs(string material = "nimic", float pret = 0.0, int stoc = 0); //un singur constructor si pt fara parametrii si cu parametrii
    Produs(const Produs& p); //copy constructor

    //operatori
    Produs& operator=(const Produs& p);
    friend istream& operator>>(istream& in, Produs& p);
    friend ostream& operator<<(ostream& out, const Produs& p);

    //metode
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
    void esteCumparat(int cant) {this -> stoc -= cant;}

    //setteri si getteri
    void setMaterial(string material) {this -> material = material;}
    void setPret(float pret) {this -> pret = pret;}
    void setStoc(float stoc) {this -> stoc = stoc;}

    float getPret() {return this -> pret;}
    int getStoc() {return this -> stoc;}

    //destructor
    virtual ~Produs() {};

};

//clasa PRODUS
//constructori
Produs::Produs(string material, float pret, int stoc) {
    this -> material = material;
    this -> pret = pret;
    this -> stoc = stoc;
}
Produs::Produs(const Produs& p)
{
    this -> material = p.material;
    this -> pret = p.pret;
    this -> stoc = p.stoc;
}

//operatori
Produs& Produs::operator=(const Produs& p)
{
    if(this != &p)
    {
        this -> material = p.material;
        this -> pret = p.pret;
        this -> stoc = p.stoc;
    }
    return *this;
}
istream& operator>>(istream& in, Produs& p)
{
    return p.citire(in);
}
ostream& operator <<(ostream& out, const Produs& p)
{
    return p.afisare(out);
}
//metode
istream& Produs::citire(istream& in)
{
    cout << "Material: ";
    in >> this -> material;
    cout << "Pret: ";
    in >> this -> pret;
    cout << "Cate avem in stoc? ";
    in >> this -> stoc;

    return in;
}
ostream& Produs::afisare(ostream& out) const
{
    out << "Material: " << this -> material << '\n';
    out << "Pret: " << this -> pret << '\n';
    if(this -> stoc == 0)
        out << "Nu avem produse in stoc!\n";
    else out << "In stoc: " << this -> stoc << '\n';

    return out;
}




class Bobina: virtual public Produs {

protected:

    string culoareB;
    char grosime; //char intre 1 si 7
    float crosetaRecomandata;

public:

    //constructori
    Bobina(); //fara parametrii
    Bobina(string material, string culoareB, char grosime, float crosetaRecomandata, float pret, int stoc);//toti parametrii
    Bobina(const Bobina& Obj); //copy constructor

    //operatori
    Bobina &operator =(const Bobina& Obj);
    //folosim operatorii de citire si afisare mosteniti din produs, dar suprascriem functiile citire si afisare

    //metode
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    //setteri si getteri
    void setCuloareB(string culoare) {this -> culoareB = culoare;}
    void setGrosime(char grosime) {this -> grosime = grosime;}
    void setCrosetaRecomandata(float crosetaRecomandata) {this -> crosetaRecomandata = crosetaRecomandata;}

    //destructor
    virtual ~Bobina() {};
};

//clasa BOBINA
//constructori
Bobina::Bobina(): Produs("bumbac"), culoareB("negru"), grosime('0'), crosetaRecomandata(0.0) {};
Bobina::Bobina(string material, string culoareB, char grosime, float crosetaRecomandata, float pret, int stoc): Produs(material, pret, stoc) {
    this -> culoareB = culoareB;
    this -> grosime = grosime;
    this -> crosetaRecomandata = crosetaRecomandata;
}
Bobina::Bobina(const Bobina& Obj): Produs(Obj) {
    this -> culoareB = Obj.culoareB;
    this -> grosime = Obj.grosime;
    this -> crosetaRecomandata = Obj.crosetaRecomandata;
}
//operatori
Bobina& Bobina::operator =(const Bobina& Obj) {
    if(this != &Obj) {
        Produs::operator=(Obj);
        this -> culoareB = Obj.culoareB;
        this -> grosime = Obj.grosime;
        this -> crosetaRecomandata = Obj.crosetaRecomandata;
    }
    return *this;
}
//metode
istream& Bobina::citire(istream& in)
{
    cout << "Culoare: ";
    in >> this -> culoareB;
    cout << "Grosime [1 - 7]: ";
    in >> this -> grosime;
    cout << "Croseta Recomandata: ";
    in >> this -> crosetaRecomandata;
    Produs::citire(in);

    return in;
}
ostream& Bobina::afisare(ostream& out) const
{
    out << "Culoare: " << this -> culoareB << '\n';
    out << "Grosime: " << this -> grosime << '\n';
    out << "Croseta Recomandata: " << this -> crosetaRecomandata << '\n';
    Produs::afisare(out);

    return out;
}




class Nasture: virtual public Produs {

protected:

    string forma;
    string culoareN;

public:

    //constructori
    Nasture(string forma = "rotund", string culoareN = "negru", string material = "plastic", float pret = 0.0, int stoc = 0);
    Nasture(const Nasture& n);

    //operatori
    Nasture& operator=(const Nasture& n);
    //folosim operatorii de citire si afisare mosteniti din produs, dar suprascriem functiile citire si afisare

    //metode
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    //setteri si getteri
    void setForma(string forma) {this -> forma = forma;}
    void setCuloareN(string culoare) {this -> culoareN = culoare;}

    //destructor
    virtual ~Nasture() {};

};

//clasa NASTURE
//constructori
Nasture::Nasture(string forma, string culoareN, string material, float pret, int stoc): Produs(material, pret, stoc) {
    this -> forma = forma;
    this -> culoareN = culoareN;
}
Nasture::Nasture(const Nasture& n): Produs(n)
{
    this -> forma = n.forma;
    this -> culoareN = n.culoareN;
}
//operatori
Nasture& Nasture::operator=(const Nasture& n)
{
    if(this != &n)
    {
        Produs::operator=(n);
        this -> forma = n.forma;
        this -> culoareN = n.culoareN;
    }
    return *this;
}
//metode
istream& Nasture::citire(istream& in)
{
    cout << "Forma: ";
    in >> this -> forma;
    cout << "Culoarea: ";
    in >> this -> culoareN;
    Produs::citire(in);

    return in;
}
ostream& Nasture::afisare(ostream& out) const
{
    out << "Forma: " << this -> forma << '\n';
    out << "Culoarea: " << this -> culoareN << '\n';
    Produs::afisare(out);

    return out;
}





class Amigurumi: public Bobina, public Nasture
{
private:
    string nume;
    string marime; //XS-XL

public:
    //constructori
    Amigurumi(string material = "nimic", string culoareB = "negru", char grosime = '0', float crosetaRecomandata = 0.0, float pret = 0.0,
              int stoc = 0, string forma = "patrat", string culoareN = "negru", string nume = "anonim", string marime = "nimic");
    Amigurumi(const Amigurumi& obj);

    //operatori
    Amigurumi& operator=(const Amigurumi& obj);
    //folosim operatorii de citire si afisare mosteniti din produs, dar suprascriem functiile citire si afisare

    //metode
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    //setteri si getteri
    void setNume(string nume) {this -> nume = nume;}
    void setMarime(string marime) {this -> marime = marime;}

    //destructor
    ~Amigurumi() {};
};
//clasa AMIGURUMI
//constructori
Amigurumi::Amigurumi(string material, string culoareB, char grosime, float crosetaRecomandata, float pret, int stoc, string forma,
                     string culoareN, string nume, string marime): Produs(material, pret, stoc), Bobina(material, culoareB, grosime,
                     crosetaRecomandata, pret, stoc), Nasture(forma, culoareN, material, pret, stoc)
{
    this -> nume = nume;
    this -> marime = marime;
}
Amigurumi::Amigurumi(const Amigurumi& obj): Produs(obj), Bobina(obj), Nasture(obj)
{
    this -> nume = obj.nume;
    this -> marime = obj.marime;
}
//operatori
Amigurumi& Amigurumi::operator=(const Amigurumi& obj)
{
    if(this != &obj)
    {
        Bobina::operator=(obj);
        Nasture::operator=(obj);
        this -> nume = obj.nume;
        this -> marime = obj.marime;
    }
    return *this;
}
//metode
istream& Amigurumi::citire(istream& in)
{
    //chemam citire pt produs si pe cele din bobina si nasture le copiem, altfel cream amiguitati
    //chestii amigurumi
    cout << "Nume Amigurumi: ";
    in >> this -> nume;
    cout << "Marime [XS - XL]: ";
    in >> this -> marime;

    //chestii bobina
    cout << "Culoare Bobine: ";
    in >> this -> culoareB;
    cout << "Grosime [1 - 7]: ";
    in >> this -> grosime;
    cout << "Croseta Recomandata: ";
    in >> this -> crosetaRecomandata;

    //chestii nasture
    cout << "Forma Nasturi: ";
    in >> this -> forma;
    cout << "Culoare Nasturi: ";
    in >> this -> culoareN;

    //chestii produs
    Produs::citire(in);

    return in;
}
ostream& Amigurumi::afisare(ostream& out) const
{
    //date amigurumi
    out << "Nume Amigurumi: " << this -> nume << '\n';
    out << "Marime: " << this -> marime << '\n';

    //date bobina
    out << "Culoare Bobina: " << this -> culoareB << '\n';
    out << "Grosime: " << this -> grosime << '\n';
    out << "Croseta Recomandata: " << this -> crosetaRecomandata << '\n';

    //date nasture
    out << "Forma Nasturi: " << this -> forma << '\n';
    out << "Culoare Nasturi: " << this -> culoareN << '\n';

    //date produs
    Produs::afisare(out);

    return out;
}



class Croseta: public Produs {

private:

    float marime;
    bool manerErgonomic;

public:

    //constructori
    Croseta();// fara parametrii
    Croseta(float marime, bool manerErgonomic); //toti parametrii
    Croseta(const Croseta& Obj);

    //operatori
    Croseta &operator =(const Croseta &Obj);
    //folosim operatorii de citire si afisare mosteniti din produs, dar suprascriem functiile citire si afisare

    //metode
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    //setteri si getteri
    void setMarime(float marime) {this -> marime = marime;}
    void setManerErgonomic(bool manerErgonomic) {this -> manerErgonomic = manerErgonomic;}

    bool getManerErgonomic() {return this -> manerErgonomic;}

     //destructor
    ~Croseta() {};
};

//clasa CROSETA
Croseta::Croseta(): Produs("nimic"), marime(0.0), manerErgonomic(false) {};
Croseta::Croseta(float marime, bool manerErgonomic): Produs(material, pret, stoc) {
    this -> marime = marime;
    this -> manerErgonomic = manerErgonomic;
}
Croseta::Croseta(const Croseta& Obj): Produs(Obj) {
    this -> marime = Obj.marime;
    this -> manerErgonomic = Obj.manerErgonomic;
}
//operatori
Croseta& Croseta::operator =(const Croseta &Obj) {
    if(this != &Obj) {
        Produs::operator=(Obj);
        this -> marime = Obj.marime;
        this -> manerErgonomic = Obj.manerErgonomic;
    }
    return *this;
}
//metode
istream& Croseta::citire(istream &in) {
    cout << "Marimea: ";
    in >> this -> marime;
    Produs::citire(in);
    cout << "Maner ergonomic? [0/1]: ";
    in >> this -> manerErgonomic;

    return in;
}
ostream& Croseta::afisare(ostream &out) const
{
    out << "Marimea: " << this -> marime << '\n';
    Produs::afisare(out);
    if(!this -> manerErgonomic)
        out << "NU ";
    out << "ARE maner ergonomic" << '\n';

    return out;
}






class Proiect {

private:

    string nume;
    float timpNecesar;
    int nrBobine;
    int nrCrosete;
    vector <float> croseteNecesare;

public:

    //constructori
    Proiect(); //fara parametrii
    Proiect(string nume, float timpNecesar, int nrBobine, vector <float> croseteNecesare, int nrCrosete); //toti parametrii
    Proiect(const Proiect& Obj); //copy constructor

    //operatori
    Proiect &operator =(const Proiect &Obj);
    friend istream& operator >>(istream &in, Proiect& p);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Proiect& p);

    //setteri si getteri
    void setNume(string nume) {this -> nume = nume;}
    void setTimpNecesar(float timpNecesar) {this -> timpNecesar = timpNecesar;}
    void setNrBobine(float nrBobine) {this -> nrBobine = nrBobine;}
    void setCroseteNecesare(vector <float> croseteNecesare)
    {
        this -> nrCrosete = croseteNecesare.size();
        this -> croseteNecesare = croseteNecesare;
    }

    float getTimpNecesar() const {return this -> timpNecesar;}

    //destructor
    ~Proiect() {};
};

//clasa PROIECT
//constructori
Proiect::Proiect(): nume("Necunoscut"), timpNecesar(0.0), nrBobine(0), nrCrosete(0) {
    this -> croseteNecesare = {};
}
Proiect::Proiect(string nume, float timpNecesar, int nrBobine, vector <float> croseteNecesare, int nrCrosete) {
    this -> nume = nume;
    this -> timpNecesar = timpNecesar;
    this -> nrBobine = nrBobine;
    this -> nrCrosete = nrCrosete;
    this -> croseteNecesare = croseteNecesare;
}
Proiect::Proiect(const Proiect& Obj) {
    this -> nume = Obj.nume;
    this -> timpNecesar = Obj.timpNecesar;
    this -> nrBobine = Obj.nrBobine;
    this -> nrCrosete = Obj.nrCrosete;
    this -> croseteNecesare = Obj.croseteNecesare;
}
//operatori
Proiect& Proiect::operator =(const Proiect &Obj) {
    if(this != &Obj) {
        this -> nume = Obj.nume;
        this -> timpNecesar = Obj.timpNecesar;
        this -> nrBobine = Obj.nrBobine;
        this -> nrCrosete = Obj.nrCrosete;
        this -> croseteNecesare = Obj.croseteNecesare;
    }
    return *this;
}
istream& operator >>(istream &in, Proiect &p) {
    cout << "Numele Proiectului: ";
    cin.ignore();
    getline(in, p.nume);
    cout << "Timpul necesar realizarii proiectului (in zile): ";
    in >> p.timpNecesar;
    cout << "Numarul de bobine necesare: ";
    in >> p.nrBobine;
    cout << "Numarul de crosete necesare: ";
    in >> p.nrCrosete;

    if(p.nrCrosete)
        cout << "Marimile crosetelor necesare: \n";

    if(!p.croseteNecesare.empty())
        p.croseteNecesare.clear(); //eliberam vectorul
    for(int i = 0; i < p.nrCrosete; i++)
    {
        cout << " - croseta " << i + 1 << ": ";
        float marime;
        in >> marime;
        p.croseteNecesare.push_back(marime);
    }
    return in;
}
ostream& operator <<(ostream &out, const Proiect &p)
{
    out << "Nume Proiect: " << p.nume << '\n';
    out << "Timp necesar realizarii proiectului: " << p.timpNecesar << " zile\n";
    out << "Numarul de bobine necesare: " << p.nrBobine << '\n';
    if(p.nrCrosete > 0)
    {
        out << p.nrCrosete << " crosete necesare: \n";
        for(int i = 0; i < p.nrCrosete; i++)
            out << " - croseta " << i + 1 << ": " << p.croseteNecesare[i] << '\n';
    }
    else out << "Nu necesita nicio croseta\n";

    return out;
}




class Cos {
private:
    map <Produs*, vector <int>> produse;
    //cosul meu o sa aiba un produs, caruia ii va fi atribuit un vector,
    //in care prima componenta reprezenta tipul de produs, iar a doua cantitatea

public:
    //constructor
    Cos() {this -> produse = {};}
    Cos(map <Produs*, vector<int>> produse) {this -> produse = produse;}
    Cos(const Cos& c) {this -> produse = c.produse;}

    //operatori
    Cos& operator=(const Cos& c);
    friend istream& operator >>(istream& in, Cos& c);
    friend ostream& operator <<(ostream& out, const Cos& c);

    //metode
    void adaugaProdus(int optiune, Produs* p, int cantitate); //adauga un produs in cos
    float calcTotal() const; //calculeaza pretul total al produselor din cos
    void cumparam(); //scade stocul tuturor produselor din cos corespunzator il sterge din lista

    //setteri si getteri
    void setProduse(map <Produs*, vector <int>> produse) {this -> produse = produse;}
    map <Produs*, vector <int>> getProduse() {return this -> produse;} //nu e nevoie de const fiindca returneaza o copie

    //destructor
    ~Cos() {};

};
//clasa COS
//operatori
Cos& Cos::operator=(const Cos& c)
{
    if(this != &c)
    {
        this -> produse = c.produse;
    }
    return *this;
}
istream& operator>>(istream& in, Cos& c)
{
    //daca avem ceva in cos il golim
    c.setProduse({});
    bool vremSaAdaugam = true;
    while(vremSaAdaugam)
    {
        cout << "Adaugati produse in cos: \n";
        cout << " 1 - o bobina \n 2 - o croseta \n 3 - un nasture \n 4 - un amigurumi \n";
        int optiune, cantitate;
        cin >> optiune;
        cout << "\nCate produse de acest fel vreti sa adaugati in cos? ";
        cin >> cantitate;
        switch(optiune)
        {
        case 1:
            {
                Produs* produsNou = new Bobina();
                in >> *produsNou;
                c.produse[produsNou].push_back(optiune);
                c.produse[produsNou].push_back(cantitate);
                break;
            }
        case 2:
            {
                Produs* produsNou = new Croseta();
                in >> *produsNou;
                c.produse[produsNou].push_back(optiune);
                c.produse[produsNou].push_back(cantitate);
                break;
            }
        case 3:
            {
                Produs* produsNou = new Nasture();
                in >> *produsNou;
                c.produse[produsNou].push_back(optiune);
                c.produse[produsNou].push_back(cantitate);
                break;
            }
        case 4:
            {
                Produs* produsNou = new Amigurumi();
                in >> *produsNou;
                c.produse[produsNou].push_back(optiune);
                c.produse[produsNou].push_back(cantitate);
                break;
            }
        default:
            throw runtime_error("Tip invalid!");
        }
        cout << "Doriti sa mai adaugati? [0/1]: ";
        cin >> vremSaAdaugam;
        cout << endl;
    }

}
ostream& operator<<(ostream& out, const Cos& c)
{
    out << "Produsele din cosul dumneavoastra: \n\n";
    for(auto i = c.produse.begin(); i != c.produse.end(); i++)
    {
        //afisam tipul de produs corespunzator
        switch((i -> second)[0])
        {
        case 1:
            {
                out << " Bobina:\n";
                break;
            }
        case 2:
            {
                out << " Croseta:\n";
                break;
            }
        case 3:
            {
                out << " Nasture:\n";
                break;
            }
        case 4:
            {
                out << " Amigurumi:\n";
                break;
            }
        default:
            throw runtime_error("Tip produs invalid!");
        }
        //afisam produsul
        out << *(i -> first);
        //afisam cantitatea
        out << " Cantitate: " << (i -> second)[1] << "\n\n";

    }
    //afisam totalul
    out << "TOTAL: " << c.calcTotal() << "\n\n";

    return out;
}
//metode
void Cos::adaugaProdus(int optiune, Produs* p, int cantitate)
{
    if((this -> produse).count(p) == 0) //daca produsul nu e in cos il adaugam
    {
        this -> produse[p].push_back(optiune);
        this -> produse[p].push_back(cantitate);
    }
    else {
        //altfel ii crestem cantitatea
        if(cantitate + (this -> produse[p])[1] > (*p).getStoc())
        //daca vr sa punem mai mult decat cate avem in stoc, punem doar cate avem in stoc =)
            cantitate = (*p).getStoc() - (this -> produse[p])[1];
        (this -> produse[p])[1] += cantitate;
    }
}
float Cos::calcTotal() const
{
    float total = 0.0;
    for(auto i = (this -> produse).begin(); i != (this -> produse).end(); ++i)
        total += (*(i -> first)).getPret() * (i -> second)[1]; //adaugam pretul obiectului * cantitatea din cos
    return total;
}
void Cos::cumparam()
{
    //scadem stocul fiecarui obiect din cos cu atatea unitati cate cumparam
    for(auto i = (this -> produse).begin(); i != (this -> produse).end(); ++i)
        (*(i -> first)).esteCumparat((i -> second)[1]);
}




class Client {

private:

    string nume;
    string email;
    string parola;
    bool trimiteAnunturi;
    float bani;
    float timpLiber; //in zile
    vector <Proiect> proiecte;

public:

    //constructori
    Client(); //constructor fara parametrii
    // toti parametrii
    Client(string nume, string email, string parola, bool trimiteAnunturi, float bani, float timpLiber, vector <Proiect> proiecte);
    Client(const Client& Obj); //copy constructor

    //operatori
    Client &operator =(const Client &Obj);
    friend istream& operator >>(istream& in, Client& C);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Client& C);

    //metode
    void iaVacanta(float zile);
    void cumpara(int cant);
    void adaugaProiect(const Proiect& p);

    //setteri si getteri
    void setNume(string nume) {this -> nume = nume;}
    void setEmail(string email) {this -> email = email;}
    void setParola(string parola) {this -> parola = parola;}
    void setTrimiteAnunturi(bool trimiteAnunturi) {this -> trimiteAnunturi = trimiteAnunturi;}
    void setBani(float bani) {this -> bani = bani;}
    void setTimpLiber(float timpLiber) {this -> timpLiber = timpLiber;}
    void setProiecte(vector <Proiect> proiecte) {this -> proiecte = proiecte;}

    string getNume() {return this -> nume;}
    string getEmail() {return this -> email;}
    string getParola() {return this -> parola;}
    bool getTrimiteAnunturi() {return this -> trimiteAnunturi;}
    float getBani() {return this -> bani;}
    float getTimpLiber() {return this -> timpLiber;}

    //destructor
    ~Client() {};
};

//clasa CLIENT
Client::Client():nume("Anonim"), email(""), parola(""), trimiteAnunturi(false), bani(0.0), timpLiber(0.0) {
    this -> proiecte = {};
}
Client::Client(string nume, string email, string parola, bool trimiteAnunturi, float bani, float timpLiber, vector <Proiect> proiecte) {
    this -> nume = nume;
    this -> email = email;
    this -> parola = parola;
    this -> trimiteAnunturi = trimiteAnunturi;
    this -> bani = bani;
    this -> timpLiber = timpLiber;
    this -> proiecte = proiecte;
}
Client::Client(const Client& Obj) {
    this -> nume = Obj.nume;
    this -> email = Obj.email;
    this -> parola = Obj.parola;
    this -> trimiteAnunturi = Obj.trimiteAnunturi;
    this -> bani = Obj.bani;
    this -> timpLiber = Obj.timpLiber;
    this -> proiecte = Obj.proiecte;
}
//operatori
Client& Client::operator =(const Client &Obj) {
    if(this != &Obj) {
        this -> nume = Obj.nume;
        this -> email = Obj.email;
        this -> parola = Obj.parola;
        this -> trimiteAnunturi = Obj.trimiteAnunturi;
        this -> bani = Obj.bani;
        this -> timpLiber = Obj.timpLiber;
        this -> proiecte = Obj.proiecte;
    }
    return *this;
}
istream& operator >>(istream& in, Client& C) {
    cout << "Numele clientului: ";
    cin.ignore(); //il folosesti cand treci de la cin >> la getline/get
    getline(in, C.nume);
    cout << "Email: ";
    getline(in, C.email);
    bool parolaInvalida = true;
    while(parolaInvalida)
    {
        cout << "Parola: ";
        string aux;
        getline(in, aux);
        cout << "Confirmare parola: ";
        string aux2;
        getline(in, aux2);
        if(aux == aux2)
        {
            C.parola = aux;
            parolaInvalida = false;
        }
        else
            cout << "\x1B[31mParola si confirmarea parolei nu conicid!\x1B[97m\n";
    }
    cout << "Suma de bani de care dispune: ";
    in >> C.bani;
    cout << "Timpul liber (in zile): ";
    in >> C.timpLiber;
    cout << "Ati realizat proiecte? [0/1]: ";
    bool areProiecte;
    in >> areProiecte;

    if(!areProiecte && !C.proiecte.empty()) //daca nu are proiecte, dar vectorul proiecte nu e gol, il eliberam
        C.proiecte.clear();
    else if(areProiecte)
    {
        cout << "\nAdaugati proiecte \n\n";
        while(areProiecte)
        {
            Proiect aux;
            in >> aux;
            C.proiecte.push_back(aux);
            cout << "Mai adaugati proiecte? [0/1]: ";
            in >> areProiecte;
        }
    }
    cout << "Doriti sa primiti oferte si anunturi pe adresa de mail? [0/1]: ";
    in >> C.trimiteAnunturi;

    return in;
}
ostream& operator <<(ostream &out, const Client& C) {
    out << "Numele clientului: " << C.nume << '\n';
    out << "Emailul: " << C.email << '\n';
    //nu afisam parola
    if(C.trimiteAnunturi == false)
        out << "NU ";
    out << "Doreste sa primeasca anunturi \n";
    out << "Suma de bani de care dispune: " << C.bani << '\n';
    out << "Timpul liber: " << C.timpLiber << " zile\n";
    if(!C.proiecte.empty())
    {
        out << C.proiecte.size() << " proiecte realizate: \n";
        for(int i = 0; i < C.proiecte.size(); i++)
            out << " - proiectul " << i + 1 << ": \n" << C.proiecte[i] << '\n';
    }
    else out << "Nu a realizat niciun proiect\n";

    return out;
}
//metode
void Client::iaVacanta(float zile)
{
    this -> timpLiber += zile;
    this -> bani -= 100 * zile; //fiindca am stabilit eu ca o zi de vacanta te costa 100 =)
}
void Client::cumpara(int cant)
{
    this -> bani -= cant;
}
void Client::adaugaProiect(const Proiect& p)
{
    this -> proiecte.push_back(p);
    //scadem timpul de care avem nevoie pt realizarea proiectului
    this -> timpLiber -= p.getTimpNecesar();
}




int main()
{
    //schimbam culoarea consolei, primul simbol e pentru fundal, al doilea pt font
    system("color 3f");
    //"stocul"
    vector <Client> listaClienti;
    vector <Bobina> listaBobine;
    vector <Nasture> listaNasturi;
    vector <Croseta> listaCrosete;
    vector <Amigurumi> listaAmigurumi;
    vector <Proiect> listaProiecte;
    bool stop = true; //controleaza cand iesim din program
    while(stop)
    {
    //stergem ce s-a afisat pana la momentul respectiv in consola
    system("cls");
    int identitate; //tine minte daca suntem client sau administrator
    cout << " Hello! Bine ati venit la Granny Mary \n Sunteti: \n 1 - Client \n 2 - Administrator \n";
    cin >> identitate;
    switch(identitate)
    {
    case 1:
    {
        bool profil = true; //controleaza cand iesim din profilul ales
        while(profil)
        {
            int comanda;
            system("cls");
            cout << " Hello, Mister Costumer! \n Va rugam realizati una dintre urmatoarele actiuni: \n 1 - Inregistrati-va";
            cout << "\n 2 - Daca aveti deja un cont, autentificati-va \n 3 - Mergeti inapoi \n 4 - Iesiti \n";
            int cont;
            cin >> cont;
            //inregistrare client nou
            if(cont == 1)
            {
                system("cls");
                cout << " Deveniti parte din comunitatea noastra!\n\n";
                //facem un client auxiliar pe care il punem in lista de clienti doar in momentul in care confirma ca datele sunt corecte
                Client ClientCurent;
                cin >> ClientCurent;
                bool confirmare;
                cout << "\n Urmatoarele date sunt corecte?\n\n";
                //nu o sa-i afisez parola dar oricum trebuie sa fi trecut de confirmarea ei
                cout << ClientCurent;
                cout << "\n Da\/Nu? [1/0]: ";
                cin >> confirmare;
                //daca confirma il bagam in lista si ii oferim sansa sa iasa din program
                //indiferent de confirmare, se intoarce inapoi la meniu anterior
                if(confirmare)
                {
                    listaClienti.push_back(ClientCurent);
                    bool iesire;
                    cout << "\n Cont creat cu succes! Doriti sa iesiti? [0/1]: ";
                    cin >> iesire;
                    if(iesire)
                    {
                        system("cls");
                        cout << "O zi frumoasa! Va mai asteptam!";
                        stop = false;
                        profil = false;
                    }
                }
            }
            else {
                    //autentificare
                    if(cont == 2)
                    {
                        bool neAutentificam = true;
                        while(neAutentificam)
                        {
                            system("cls");
                            cout << "Autentificati-va!\n\n";
                            //se introduce un email si o parola care sunt dupa cautate in lista de clienti inregistrati
                            string email, parola;
                            cout << "Email: ";
                            cin.ignore();
                            getline(cin, email);
                            cout << "Parola: "; //nu stiu sa o ascund...
                            getline(cin, parola);
                            int indiceCurent = -1;//daca gasim clientul in lista ii pastram indicele pt a putea sa manipulam usor obiectul respectiv
                            for(int i = 0; i < listaClienti.size(); i++)
                                if(listaClienti[i].getEmail() == email && listaClienti[i].getParola() == parola)
                                    indiceCurent = i;
                            //daca indicele curent e 0, avand in vedere ca lista de clienti e indexata de la 1, inseamna ca nu am gasit clientul in lista
                            if(indiceCurent == -1)
                            {
                                //ii oferim sansa sa mai incerce, sa revina la meniul anterior sau sa iasa cu totul din program
                                cout << "\nAutentificare esuata! Email sau parola incorecta.";
                                cout << "\nDoriti sa: \n1- Incercati din nou \n2 - Reveniti la meniul anterior \n3 - Iesiti\n";
                                int iesire;
                                cin >> iesire;
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "O zi frumoasa! Va mai asteptam!";
                                    stop = true;
                                    profil = true;
                                    neAutentificam = false;
                                }
                                else {
                                    if(iesire == 2)
                                        neAutentificam = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda invalida!!");
                                    }
                                }
                            }
                            //autentificare reusita
                            else {
                                    bool autentificati = true; //controleaza cat suntem autentificati, astfel incat sa putem iesi doar din cont daca vrem
                                    while(autentificati)
                                    {
                                        system("cls");
                                        cout << "Bine ati revenit, " << listaClienti[indiceCurent].getNume() << '\n';
                                        cout << "Ce doriti sa faceti?\n 1 - Vizualizati-ne stocul \n 2 - Alegeti-va urmatorul proiect";
                                        cout << "\n 3 - Contul meu \n 4 - Iesiti din cont \n 5 - Iesiti din aplicatie \n";
                                        cin >> comanda;
                                        Cos cos; //cosul clientului de cumparaturi
                                        system("cls");
                                        switch(comanda)
                                        {
                                        //daca vrem sa vizualizam un stoc / sa cumparam ceva
                                        case 1:
                                            {
                                                bool vremSaCumparam = true;
                                                //luam un pointer pe care il trimitem spre functia adaugaProdus daca vrem sa punem ceva in cos
                                                Produs* p;
                                                while(vremSaCumparam)
                                                {
                                                    system("cls");
                                                    int fel_produs; //daca vrem sa vedem/cumparam bobine sau crosete sau etc
                                                    cout << " Doriti sa vizualizati oferta noastra de: \n 1 - Bobine \n 2 - Crosete\n 3 - Nasturi \n 4 - Amigurumi \n";
                                                    //sa apara asta doar daca am ceva in cos
                                                    if(!cos.getProduse().empty())
                                                        cout << " Sau: \n 5 - Doriti sa va vizualizati cosul?\n";
                                                    cin >> fel_produs;
                                                    system("cls");
                                                    switch(fel_produs)
                                                    {
                                                    //daca vrem sa vedem/cumparam bobine
                                                    case 1:
                                                        {
                                                            //daca nu avem bobine in stoc
                                                            if(listaBobine.empty())
                                                            {
                                                                cout << "Din pacate, momentan nu avem bobine in stoc. \nVa rugam reveniti mai tarziu!";
                                                                //iese din if si ofera ocazia utilizatorului sa iasa din program
                                                            }
                                                            //daca avem bobine in stoc
                                                            else {
                                                                //afisam stocul cu tot cu indicele bobinelor in lista lor
                                                                cout << "Stocul nostru de bobine: \n\n";
                                                                for(int i = 0; i < listaBobine.size(); i++)
                                                                    cout << "Tipul " << i + 1 << " de bobine:\n" << listaBobine[i] << endl << endl;

                                                                //intrebam utilizatorul daca vrea sa cumpere ceva
                                                                bool cumparam;
                                                                cout << "\nDoriti sa adaugati bobine in cos? [0/1]: ";
                                                                cin >> cumparam;
                                                                //daca vrea sa adauge in cos
                                                                if(cumparam)
                                                                {
                                                                    //face selectia bobinei dupa indicele ei in lista
                                                                    int indiceBobina, cantitate;
                                                                    cout << "\nCe tip de bobina doriti sa cumparati? ";
                                                                    cin >> indiceBobina;
                                                                    indiceBobina--;
                                                                    //verificam ca indicele sa fie valid
                                                                    if(indiceBobina < 0 || indiceBobina >= listaBobine.size())
                                                                        throw runtime_error("Indice invalid!");
                                                                    cout << "\nCate bobine de acest tip doriti sa adaugati in cos? ";
                                                                    cin >> cantitate;
                                                                    //verificam daca avem destule bobine in stoc
                                                                    if(cantitate > listaBobine[indiceBobina].getStoc())
                                                                        cout << "\nNu sunt destule bobine de acest tip in stoc\n";
                                                                    else
                                                                    {
                                                                        //le adaugam in cos
                                                                        p = &(listaBobine[indiceBobina]); //p pointeaza spre o bobina
                                                                        cos.adaugaProdus(1, p, cantitate);
                                                                    }

                                                                }
                                                            }
                                                            break;
                                                        }
                                                    //daca vrem sa vedem/cumparam crosete
                                                    case 2:
                                                        {
                                                            //daca nu avem crosete in stoc
                                                            if(listaCrosete.empty())
                                                            {
                                                                cout << "Din pacate, momentan nu avem crosete in stoc. \nVa rugam reveniti mai tarziu!";
                                                            }
                                                            //daca avem crosete in stoc
                                                            else {
                                                                //afisam stocul de crosete cu tot cu indicele din lista lor
                                                                cout << "Stocul nostru de crosete: \n\n";
                                                                for(int i = 0; i < listaCrosete.size(); i++)
                                                                    cout << "Tipul " << i + 1 << " de crosete:\n" << listaCrosete[i] << endl;
                                                                //verificam daca utilizatorul vrea sa cumpere ceva
                                                                bool cumparam;
                                                                cout << "\nDoriti sa adaugati crosete in cos? [0/1]: ";
                                                                cin >> cumparam;
                                                                //daca vrem sa adaugam in cos
                                                                if(cumparam)
                                                                {
                                                                    //selectam croseta prin indicele din lista crosetelor, pe care l-am afisat odata cu stocul
                                                                    int indiceCroseta, cantitate;
                                                                    cout << "\nCe tip de croseta doriti sa cumparati? ";
                                                                    cin >> indiceCroseta;
                                                                    indiceCroseta--;
                                                                    //verificam validitatea stocului
                                                                    if(indiceCroseta < 0 || indiceCroseta >= listaCrosete.size())
                                                                        throw runtime_error("Indice invalid!");
                                                                    cout << "\nCate crosete de acest tip doriti sa adaugati in cos? ";
                                                                    cin >> cantitate;
                                                                    //verificam daca avem destule crosete in stoc
                                                                    if(cantitate > listaCrosete[indiceCroseta].getStoc())
                                                                        cout << "\nNu sunt destule crosete de acest tip in stoc\n";
                                                                    else
                                                                    {
                                                                        p = &(listaCrosete[indiceCroseta]); //p pointeaza spre o croseta
                                                                        cos.adaugaProdus(2, p, cantitate);
                                                                    }
                                                                }
                                                            }
                                                            break;
                                                        }
                                                    //daca vrem sa vedem/cumparam nasturi
                                                    case 3:
                                                        {
                                                            //daca nu avem nasturi in stoc
                                                            if(listaNasturi.empty())
                                                            {
                                                                cout << "Din pacate, momentan nu avem nasturi in stoc. \nVa rugam reveniti mai tarziu!";
                                                            }
                                                            //daca avem nasturi in stoc
                                                            else {
                                                                //afisam stocul de nasturi cu tot cu indicele din lista lor
                                                                cout << "Stocul nostru de nasturi: \n\n";
                                                                for(int i = 0; i < listaNasturi.size(); i++)
                                                                    cout << "Tipul " << i + 1 << " de nasturi:\n" << listaNasturi[i] << endl;
                                                                //verificam daca utilizatorul vrea sa cumpere ceva
                                                                bool cumparam;
                                                                cout << "\nDoriti sa adaugati nasturi in cos? [0/1]: ";
                                                                cin >> cumparam;
                                                                //daca vrem sa adaugam in cos
                                                                if(cumparam)
                                                                {
                                                                    //selectam nasturele prin indicele din lista nasturilor, pe care l-am afisat odata cu stocul
                                                                    int indiceNasture, cantitate;
                                                                    cout << "\nCe tip de nasture doriti sa cumparati? ";
                                                                    cin >> indiceNasture;
                                                                    indiceNasture--;
                                                                    //verificam validitatea stocului
                                                                    if(indiceNasture < 0 || indiceNasture >= listaNasturi.size())
                                                                        throw runtime_error("Indice invalid!");
                                                                    cout << "\nCati nasturi de acest tip doriti sa adaugati in cos? ";
                                                                    cin >> cantitate;
                                                                    //verificam daca avem destui nasturi in stoc
                                                                    if(cantitate > listaNasturi[indiceNasture].getStoc())
                                                                        cout << "\nNu sunt destui nasturi de acest tip in stoc\n";
                                                                    else
                                                                    {
                                                                        p = &(listaNasturi[indiceNasture]); //p pointeaza spre un nasture
                                                                        cos.adaugaProdus(3, p, cantitate);
                                                                    }
                                                                }
                                                            }
                                                            break;
                                                        }
                                                    //daca vrem sa vedem/cumparam amigurumi
                                                    case 4:
                                                        {
                                                            //daca nu avem amigurumi in stoc
                                                            if(listaAmigurumi.empty())
                                                            {
                                                                cout << "Din pacate, momentan nu avem amigurumi in stoc. \nVa rugam reveniti mai tarziu!";
                                                            }
                                                            //daca avem amigurumi in stoc
                                                            else {
                                                                //afisam stocul de amigurumi cu tot cu indicele din lista lor
                                                                cout << "Stocul nostru de amigurumi: \n\n";
                                                                for(int i = 0; i < listaAmigurumi.size(); i++)
                                                                    cout << "Tipul " << i + 1 << " de amigurumi:\n" << listaAmigurumi[i] << endl;
                                                                //verificam daca utilizatorul vrea sa cumpere ceva
                                                                bool cumparam;
                                                                cout << "\nDoriti sa adaugati amigurumi in cos? [0/1]: ";
                                                                cin >> cumparam;
                                                                //daca vrem sa adaugam in cos
                                                                if(cumparam)
                                                                {
                                                                    //selectam amigurumi prin indicele din lista amigurumilor, pe care l-am afisat odata cu stocul
                                                                    int indiceAmigurumi, cantitate;
                                                                    cout << "\nCe tip de amigurumi doriti sa cumparati? ";
                                                                    cin >> indiceAmigurumi;
                                                                    indiceAmigurumi--;
                                                                    //verificam validitatea stocului
                                                                    if(indiceAmigurumi < 0 || indiceAmigurumi >= listaAmigurumi.size())
                                                                        throw runtime_error("Indice invalid!");
                                                                    cout << "\nCati amigurumi de acest tip doriti sa adaugati in cos? ";
                                                                    cin >> cantitate;
                                                                    //verificam daca avem destui amigurumi in stoc
                                                                    if(cantitate > listaAmigurumi[indiceAmigurumi].getStoc())
                                                                        cout << "\nNu sunt destui amigurumi de acest tip in stoc\n";
                                                                    else
                                                                    {
                                                                        p = &(listaAmigurumi[indiceAmigurumi]); //p pointeaza spre un amigurumi
                                                                        cos.adaugaProdus(4, p, cantitate);
                                                                    }
                                                                }
                                                            }
                                                            break;
                                                        }
                                                    //daca dorim sa vizualizam cosul
                                                    case 5:
                                                        {
                                                            cout << cos;
                                                            int comandam; //tine minte daca dam comanda sau nu
                                                            cout << "Doriti sa: \n 1 - Goliti cosul";
                                                            cout << " \n 2 - Finalizati comanda \n 3 - Vedeti optiunile de iesire \n";
                                                            cin >> comandam;
                                                            switch(comandam)
                                                            {
                                                            //daca vrem sa golim cosul
                                                            case 1:
                                                                {
                                                                    cos.setProduse({}); //setam dictionarul la unul gol
                                                                    cout << "\nCosul dumneavoastra a fost golit!\n";
                                                                    break;
                                                                }
                                                            //daca vrem sa dam comanda
                                                            case 2:
                                                                {
                                                                    //verificam daca clientul are destui bani cat sa finalizeze comanda
                                                                    if(listaClienti[indiceCurent].getBani() >= cos.calcTotal())
                                                                    {
                                                                        //realizam tranzactia <=> clientului ii scad banii,
                                                                        //cumparam fiecare obiect din cos (ii scade stocul)
                                                                        cos.cumparam();
                                                                        listaClienti[indiceCurent].cumpara(cos.calcTotal());
                                                                        //golim cosul
                                                                        cos.setProduse({});
                                                                        cout << "\nTranzactie realizata cu succes!\n";

                                                                    }
                                                                    else cout << "Nu aveti un buget suficient de mare pentru a realiza tranzactia dorita!\n";
                                                                    break;
                                                                }
                                                            case 3:
                                                                {
                                                                    //vrem sa iesim asa ca nu facem nimic
                                                                    break;
                                                                }
                                                            default:
                                                                throw runtime_error("Comanda invalida!");
                                                            }
                                                            break;
                                                        }
                                                    default:
                                                        throw runtime_error("Comanda invalida!!");
                                                    }
                                                    //la final, indiferent de ce am ales sa facem, oferim posibilitatea iesirii din program
                                                    //sau de intoarcere la meniul principal
                                                    int iesire;
                                                    cout << "\n Ati dori sa:";
                                                    cout << " \n1 - Mergeti inapoi \n2 - Intorceti-va la meniul principal \n3 - Iesiti\n";
                                                    cin >> iesire;
                                                    if(iesire == 3)
                                                    {
                                                        system("cls");
                                                        cout << "O zi frumoasa! Va mai asteptam!\n";
                                                        stop = false;
                                                        profil = false;
                                                        neAutentificam = false;
                                                        autentificati = false;
                                                        vremSaCumparam = false;
                                                    }
                                                    else {
                                                        if(iesire == 2)
                                                            vremSaCumparam = false;
                                                    }

                                                }
                                                break;
                                            }
                                        //daca vrem sa vizualizam/sa ne alegem un proiect
                                        case 2:
                                            {
                                                //daca nu avem niciun proiect
                                                if(listaProiecte.empty())
                                                {
                                                    cout << "Din pacate, momentan nu avem proiecte postate. \nVa rugam reveniti mai tarziu!";
                                                    //dupa iese din if si ii dam ocazia sa iasa din program sau sa se intoarca la meniul principal
                                                }
                                                //daca avem proiecte
                                                else {
                                                    //afisam lista de proiecte cu indicele lor in lista de proiecte
                                                    cout << "Vizualizati pattern-urile noastre si alegeti-va viitorul proiect!\n\n";
                                                    for(int i = 0; i < listaProiecte.size(); i++)
                                                        cout << "Proiectul " << i + 1 << ": \n" << listaProiecte[i] << endl;
                                                    //selectam un nou proiect cu ajutorul indicelui din lista proiectelor
                                                    int indiceProiect;
                                                    cout << "\nAlegeti-va viitorul proiect: ";
                                                    cin >> indiceProiect;
                                                    indiceProiect--;
                                                    //verificam validitatea indicelui
                                                    if(indiceProiect < 0 || indiceProiect >= listaProiecte.size()) //vectorul listaProiecte e indexat de la 1
                                                        throw runtime_error("Indice invalid!");
                                                    //daca vrem sa alegem un proiect valid
                                                    else {
                                                        system("cls");
                                                        //afisam proiectul
                                                        cout << "Ati ales proiectul " << indiceProiect << endl;
                                                        cout << listaProiecte[indiceProiect] << endl;
                                                        //verificam daca nu avem timp
                                                        if(listaClienti[indiceCurent].getTimpLiber() < listaProiecte[indiceProiect].getTimpNecesar())
                                                        {
                                                            //ii sugeram sa-si ia o vacanta
                                                            cout << "\nDin pacate, nu aveti timp liber suficient pentru a termina proiectul =(";
                                                            cout << "\nVa sugeram calduros sa va luati o vacanta!";
                                                            cout << "\n1 - Imi iau concediu \n2 - Renunt la proiect =( \n";
                                                            int concendiu;
                                                            cin >> concendiu;
                                                            //daca isi ia vacanta
                                                            if(concendiu)
                                                            {
                                                                //ii spunem ca vacanta costa si de cate zile are nevoie macar pentru a realiza proiectul dorit
                                                                float diferenta = listaProiecte[indiceProiect].getTimpNecesar();
                                                                diferenta -= listaClienti[indiceCurent].getTimpLiber();
                                                                cout << "\nAveti nevoie de macar ";
                                                                cout << diferenta; //numarul de zile necesar pt a realiza proiectul
                                                                cout << " zile de vacanta \n";
                                                                cout << "Luati in considerare faptul ca fiecare zi de concediu costa 100 de lei :P\n";
                                                                cout << "Cate zile de concediu doriti sa va luati? ";
                                                                int zile;
                                                                cin >> zile; //cate zile de vacanta vrea clientul sa isi ia
                                                                //daca nu are bani de atatea zile de vacanta
                                                                if(zile * 100 > listaClienti[indiceCurent].getBani())
                                                                        cout << "\nNu aveti destui bani sa va luati " << zile << " zile de concediu...";
                                                                else {
                                                                    //daca are bani, dar si-a luat prea putine zile de concediu
                                                                    if(zile < diferenta)
                                                                    {
                                                                        cout << "\nNu v-ati luat destule zile de vacanta...";
                                                                        listaClienti[indiceCurent].iaVacanta(zile); //i le adaugam totusi (ii scadem si banii)
                                                                    }
                                                                    //daca are bani si si-a luat destule
                                                                    else
                                                                    {
                                                                        //ii adaugam zilele luate si ii scadem banii
                                                                        listaClienti[indiceCurent].iaVacanta(zile);
                                                                        //ii adaugam proiectul la lista si ii scadem zilele necesare
                                                                        listaClienti[indiceCurent].adaugaProiect(listaProiecte[indiceProiect]);
                                                                        cout << "\nAti realizat proiectul cu succes! Felicitari!!";
                                                                    }

                                                                }
                                                            }
                                                        }
                                                        //daca avem timp il adaugam la lista noastra de proiecte
                                                        else {
                                                            listaClienti[indiceCurent].adaugaProiect(listaProiecte[indiceProiect]);
                                                            cout << "\nAti realizat proiectul cu succes! Felicitari!!";
                                                        }
                                                    }
                                                }
                                                //ii oferim posibilitatea sa iasa din program/sa se intoarca la meniul principal
                                                int iesire;
                                                cout << " \n1 - Iesiti \n2 - Intorceti-va la meniul principal\n";
                                                cin >> iesire;
                                                if(iesire == 1)
                                                {
                                                    system("cls");
                                                    cout << "O zi frumoasa! Va mai asteptam!\n";
                                                    stop = false;
                                                    profil = false;
                                                    neAutentificam = false;
                                                    autentificati = false;
                                                }
                                                break;
                                            }
                                        //modificam sau stergem contul curent
                                        case 3:
                                            {
                                                //ii afisam datele contului
                                                system("cls");
                                                cout << "Contul Dumneavoastra: \n\n";
                                                cout << listaClienti[indiceCurent];
                                                //poate sa-si stearga sau sa-si modifice contul
                                                cout << "\n 1 - Modificati-va contul \n 2 - Stergeti-va contul \n 3 - Inapoi \n 4 - Iesiti \n";
                                                int modificare;
                                                cin >> modificare;
                                                //modificam contul
                                                switch(modificare)
                                                {
                                                case 1:
                                                    {
                                                        bool vremSaModificam = true; //ne mentine in meniul de schimbare a contului pana zicem ca vrem sa iesim
                                                        while(vremSaModificam)
                                                        {
                                                            system("cls");
                                                            //afisam din nou datele contului
                                                            cout << "Contul Dumneavoastra: \n\n";
                                                            cout << listaClienti[indiceCurent];
                                                            //ii dam posibilitatea sa-si modifice orice detaliu din cont
                                                            cout << "\n Ce doriti sa modificati? \n 1 - Numele \n 2 - Emailul \n 3 - Parola";
                                                            cout << "\n 4 - Decizia de a primi anunturi \n 5 - Banii \n 6 - Timpul liber ";
                                                            cout << "\n 7 - Proiectele \n";
                                                            int schimbare;
                                                            cin >> schimbare;
                                                            switch(schimbare)
                                                            {
                                                            //schimbam numele
                                                            case 1:
                                                                {
                                                                    string numeNou;
                                                                    cout << "\n Dati noul nume: ";
                                                                    cin.ignore();
                                                                    getline(cin, numeNou);
                                                                    listaClienti[indiceCurent].setNume(numeNou);
                                                                    break;
                                                                }
                                                            //schimbam email-ul
                                                            case 2:
                                                                {
                                                                    string emailNou;
                                                                    cout << "\n Dati noul email: ";
                                                                    cin.ignore();
                                                                    getline(cin, emailNou);
                                                                    listaClienti[indiceCurent].setEmail(emailNou);
                                                                    break;
                                                                }
                                                            //schimbam parola
                                                            case 3:
                                                                {
                                                                    string aux, aux2; //citim doua auxiliare pt parola si confirmarea ei
                                                                    bool parolaInvalida = true;
                                                                    cin.ignore();
                                                                    //tot citim pana cele doua auxiliare sunt egale
                                                                    while(parolaInvalida)
                                                                    {
                                                                        cout << "\n Dati noua parola: ";
                                                                        getline(cin, aux);
                                                                        cout << "\n Confirmati parola: ";
                                                                        getline(cin, aux2);
                                                                        //iesim din while cand sunt egale, moment in care setam si parola
                                                                        if(aux == aux2)
                                                                        {
                                                                            listaClienti[indiceCurent].setParola(aux);
                                                                            parolaInvalida = false;
                                                                        }
                                                                        // \x1B inseamna ca fundalul ramane la fel, [31m - font rosu, [97m - font alb
                                                                        else cout << "\n \x1B[31mParola si confirmarea parolei nu conicid!\x1B[97m";
                                                                    }
                                                                    break;
                                                                }
                                                            //schimbam daca vrem sau nu anunturi
                                                            case 4:
                                                                {
                                                                    if(listaClienti[indiceCurent].getTrimiteAnunturi())
                                                                        listaClienti[indiceCurent].setTrimiteAnunturi(false);
                                                                    else listaClienti[indiceCurent].setTrimiteAnunturi(true);
                                                                    break;
                                                                }
                                                            //schimbam bugetul
                                                            case 5:
                                                                {
                                                                    float baniNoi;
                                                                    cout << "\n Cat sunteti dispus sa investiti in produsele noastre? ";
                                                                    cin >> baniNoi;
                                                                    listaClienti[indiceCurent].setBani(baniNoi);
                                                                    break;
                                                                }
                                                            //schimbam timpul liber pe care il avem
                                                            case 6:
                                                                {
                                                                    float timpNou;
                                                                    cout << "\n Cat timp liber aveti la dispozitie? ";
                                                                    cin >> timpNou;
                                                                    listaClienti[indiceCurent].setTimpLiber(timpNou);
                                                                    break;
                                                                }
                                                            //schimbam proiectele pe care le-am realizat
                                                            case 7:
                                                                {
                                                                    int nrProiecteNou;
                                                                    vector <Proiect> proiecteNoi;
                                                                    cout << "Dati numarul nou de proiecte: ";
                                                                    cin >> nrProiecteNou;
                                                                    cout << "Dati noile proiecte: ";
                                                                    for(int i = 0; i < nrProiecteNou; i++)
                                                                    {
                                                                        Proiect aux;
                                                                        cin >> aux;
                                                                        proiecteNoi.push_back(aux);
                                                                    }
                                                                    listaClienti[indiceCurent].setProiecte(proiecteNoi);
                                                                    break;
                                                                }
                                                            default:
                                                                throw runtime_error("Comanda invalida!!");
                                                            }
                                                            system("cls");
                                                            //afisam contul modificat si vedem daca vrea sa mai modifice ceva sau nu
                                                            cout << " Modificare realizata cu succes! \n Contul dumneavoastra: \n\n";
                                                            cout << listaClienti[indiceCurent] << endl;
                                                            cout << " Doriti sa:\n 1 - Continuati modificarile\n 2 - Intorceti-va la meniu\n 3 - Iesiti\n";
                                                            int iesire;
                                                            cin >> iesire;
                                                            if(iesire == 3)
                                                            {
                                                                system("cls");
                                                                cout << "O zi frumoasa! Va mai asteptam!\n";
                                                                vremSaModificam = false;
                                                                neAutentificam = false;
                                                                autentificati = false;
                                                                profil = false;
                                                                stop = false;
                                                            }
                                                            else {
                                                                if(iesire == 2)
                                                                    vremSaModificam = false;
                                                                else {
                                                                    if(iesire != 1)
                                                                        throw runtime_error("Comanda invalida!!");
                                                                }
                                                            }
                                                        }
                                                        break;
                                                    }
                                                //stergem contul
                                                case 2:
                                                    {
                                                        //ne asiguram ca vr sa-si stearga permanent contul
                                                        bool stergere;
                                                        cout << "\n Sunteti sigur ca vreti sa va stergeti permanent contul? [0/1]: ";
                                                        cin >> stergere;
                                                        //stergem contul curent din lista
                                                        if(stergere)
                                                        {
                                                            listaClienti.erase(listaClienti.begin() + indiceCurent);
                                                            cout << "\n Contul a fost sters cu succes!";
                                                        }
                                                        int iesire;
                                                        cout << "\n Doriti sa: \n 1 - Ramaneti in aplicatie \n 2 - Iesiti \n";
                                                        cin >> iesire;
                                                        //daca vrem sa iesim
                                                        if(iesire == 2)
                                                        {
                                                            system("cls");
                                                            cout << "O zi frumoasa! Va mai asteptam!\n";
                                                            stop = false;
                                                            profil = false;
                                                            neAutentificam = false;
                                                            autentificati = false;
                                                        }
                                                        else {
                                                            //daca vrem sa ramanem in aplicatie
                                                            if(iesire == 1)
                                                            {
                                                                //o sa trebuiasca sa ne autentificam din nou
                                                                autentificati = false;
                                                                neAutentificam = false;
                                                            }
                                                            else throw runtime_error("Comanda invalida!");
                                                        }
                                                        break;
                                                    }
                                                //daca vrem sa mergem inapoi
                                                case 3:
                                                    {
                                                        break;
                                                    }
                                                //daca vrem sa iesim de tot
                                                case 4:
                                                    {
                                                        system("cls");
                                                        cout << "O zi frumoasa! Va mai asteptam!\n";
                                                        stop = false;
                                                        profil = false;
                                                        neAutentificam = false;
                                                        autentificati = false;
                                                        break;
                                                    }
                                                default:
                                                    throw runtime_error("Comanda Invalida!!");
                                                }
                                                break;
                                            }
                                        //daca vrem sa iesim din cont
                                        case 4:
                                            {
                                                neAutentificam = false;
                                                autentificati = false;
                                                break;
                                            }
                                        //daca vrem sa iesim din aplicatie
                                        case 5:
                                            {
                                                system("cls");
                                                cout << "O zi frumoasa! Va mai asteptam!\n";
                                                stop = false;
                                                profil = false;
                                                neAutentificam = false;
                                                autentificati = false;
                                                break;
                                            }
                                        default:
                                            {
                                                throw runtime_error("Comanda necunoscuta! =(");
                                                break;
                                            }
                                        }
                                    }

                            }
                        }

                    }

                    else {
                        //vrem sa ne intoarcem
                        if(cont == 3)
                        {
                            profil = false;
                        }
                        //vrem sa iesim
                        else {
                                if(cont == 4)
                                {
                                    system("cls");
                                    cout << "O zi frumoasa! Va mai asteptam!";
                                    stop = false;
                                    profil = false;
                                }
                                else throw runtime_error("Comanda necunoscuta!!");
                        }
                    }
            }

        }
    break;
    }
    //daca suntem administrator
    case 2:
         {
        int profil = true; //controleaza cand iesim din profilul ales
        while(profil)
        {
            int comanda;
            system("cls");
            cout << " Hello, Boss! \n Cu ce va pot ajuta astazi? \n 1 - Vreau sa reactualizez un stoc\n";
            cout << " 2 - Vreau sa reactualizez lista de proiecte \n 3 - Vreau sa vizualizez lista de clienti \n";
            cout << " 4 - Inapoi \n 5 - Iesiti \n";
            cin >> comanda;
            system("cls");
            switch(comanda)
            {
            //daca vrem sa reactualizam un stoc
            case 1:
                {
                    cout << "Doriti sa reactualizati stocul de: \n";
                    cout << " 1 - Bobine\n 2 - Crosete\n 3 - Nasturi \n 4 - Amigurumi \n";
                    int felStoc; //tine minte cu ce fel de stoc alegem sa lucram
                    cin >> felStoc;
                    system("cls");
                    switch(felStoc)
                    {
                    //daca vrem sa reactualizam stocul de bobine
                    case 1:
                        {
                            // putem sa adaugam, stergem sau modificam bobine
                            cout << " Reactualizarea stocului de bobine! \n";
                            cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                            int adauga;
                            cin >> adauga;
                            switch(adauga)
                            {
                            //daca alegem sa adaugam o bobina
                            case 1:
                                {
                                    bool vremSaAdaugam = true; //ne tine in meniul de adaugare pana vrem sa iesim
                                    while(vremSaAdaugam)
                                    {
                                        system("cls");
                                        //introducem o bobina auxiliara pe care o adauga la lista doar in momentul in care confirmam faptul ca datele sunt corecte
                                        cout << " Adaugati noi bobine\n\n";
                                        Bobina BobinaCurenta;
                                        cin >> BobinaCurenta;
                                        bool confirmare;
                                        cout << "\n Urmatoarele date sunt corecte?\n\n";
                                        cout << BobinaCurenta;
                                        cout << "\n Da\/Nu? [1/0]: ";
                                        cin >> confirmare;
                                        //daca avem confirmarea
                                        if(confirmare)
                                        {
                                            //adaugam bobina la lista
                                            listaBobine.push_back(BobinaCurenta);
                                            int iesire;
                                            cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                            cout << "\n 3 - Iesiti\n";
                                            cin >> iesire;
                                            //daca vrem sa ramanem in meniul de adaugat nu schimbam nimic
                                            //daca vrem sa iesim
                                            if(iesire == 3)
                                            {
                                                system("cls");
                                                cout << "Bye, Boss! <3\n";
                                                profil = false;
                                                stop = false;
                                                vremSaAdaugam = false;
                                            }
                                            else {
                                                //daca vr ne intoarcem inapoi iesim din while
                                                if(iesire == 2)
                                                    vremSaAdaugam = false;
                                                else {
                                                    if(iesire != 1)
                                                        throw runtime_error("Comanda Invalida!");
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                            //daca alegem sa stergem o bobina
                            case 2:
                                {
                                    bool vremSaStergem = true; //ne tine in meniul de stergere pana decidem sa iesim
                                    while(vremSaStergem)
                                    {
                                        system("cls");
                                        cout << "Stergeti bobine \n\n";
                                        //verificam daca avem bobine in stoc
                                        if(listaBobine.empty())
                                        {
                                            cout << "Nu avem inca bobine in stoc! =(\n";
                                            //iesim din if si afisam optiunile de iesire
                                        }
                                        else {
                                            //afisam stocul curent cu indicii bobinelor din lista de bobine
                                            cout << "Stocul curent: \n";
                                            for(int i = 0; i < listaBobine.size(); i++)
                                                cout << "Tipul de bobine " << i + 1 << ": \n" << listaBobine[i] << endl;
                                            //selectam bobina cu ajutorul indicelui din lista de bobine
                                            cout << "Doriti sa stergeti bobine de tipul: ";
                                            int indice, cantitate;
                                            cin >> indice;
                                            indice--;
                                            //verificam validitatea indicelui
                                            if(indice < 0 || indice >= listaBobine.size())
                                                throw runtime_error("Index invalid!");
                                            cout << "Cate bobine de acest fel doriti sa stergeti? ";
                                            cin >> cantitate;
                                            //daca vrem sa stergem mai putine decat sunt in stoc
                                            if(cantitate < listaBobine[indice].getStoc())
                                                //modificam stocul (e ca si cum sunt cumparate)
                                                listaBobine[indice].esteCumparat(cantitate);
                                            //daca vrei sa stergi cate bobine sunt in stoc sau mai multe pur si simplu iti sterge obiectul
                                            else listaBobine.erase(listaBobine.begin() + indice);
                                            //afisam stocul actualizat
                                            system("cls");
                                            cout << "Stocul actual: \n\n";
                                            for(int i = 0; i < listaBobine.size(); i++)
                                                cout << listaBobine[i] << endl;
                                        }
                                        //afisam optiunile de iesire
                                        cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                        cout << "\n 3 - Iesiti \n";
                                        int iesire;
                                        cin >> iesire;
                                        //daca vrem sa mai stergem nu facem nimic
                                        //daca vrem sa iesim de tot
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaStergem = false;
                                        }
                                        else {
                                            //daca vr ne intoarcem inapoi iesim din while
                                            if(iesire == 2)
                                                vremSaStergem = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                    break;
                                }
                            //daca vrem sa modificam o bobina
                            case 3:
                                {
                                    bool vremSaModificam = true; //ne tine in meniul de modificare pana vrem sa iesim
                                    while(vremSaModificam)
                                    {
                                        system("cls");
                                        cout << "Modificati un tip de bobina! \n";
                                        //verificam daca avem bobine in stoc
                                        if(listaBobine.empty())
                                        {
                                            cout << "Nu avem inca bobine in stoc";
                                        }
                                        //daca avem bobine in stoc
                                        else {
                                            //afisam stocul curent cu tot cu indicele bobinelor din lista de bobine
                                            cout << "Stocul curent de bobine: \n";
                                            for(int i = 0; i < listaBobine.size(); i++)
                                                cout << "Bobinele de tipul " << i + 1 << ": \n" << listaBobine[i] << endl;
                                            //selectam bobina ce urmeaza sa fie modificata prin intermediul indicelui din lista de bobine
                                            cout << "Doriti sa modificati bobinele de tipul numarul: ";
                                            int indice;
                                            cin >> indice;
                                            indice--;
                                            //verificam validitatea indicelui
                                            if(indice < 0 || indice >= listaBobine.size())
                                                throw runtime_error("Indice invalid!");
                                            system("cls");
                                            //afisam bobina ce urmeaza sa fie modificata
                                            cout << "Modificam bobinele: \n\n";
                                            cout << listaBobine[indice];
                                            //alegem sa vrem sa modificam la ea
                                            int modificare;
                                            cout << "\nModificati: \n 1 - Materialul \n 2 - Culoarea \n 3 - Grosimea \n 4 - Croseta Recomandata";
                                            cout << "\n 5 - Pretul \n";
                                            cin >> modificare;
                                            switch(modificare)
                                            {
                                            //modificam materialul
                                            case 1:
                                                {
                                                    string materialNou;
                                                    cout << "\n Dati noul material: ";
                                                    cin.get();
                                                    getline(cin, materialNou);
                                                    listaBobine[indice].setMaterial(materialNou);
                                                    break;
                                                }
                                            //modificam culoarea
                                            case 2:
                                                {
                                                    string culoareNoua;
                                                    cout << "\n Dati noua culoare: ";
                                                    cin >> culoareNoua;
                                                    listaBobine[indice].setCuloareB(culoareNoua);
                                                    break;
                                                }
                                            //modificam grosimea
                                            case 3:
                                                {
                                                    char grosimeNoua;
                                                    cout << "\n Dati noua grosime [0-7]: ";
                                                    cin >> grosimeNoua;
                                                    listaBobine[indice].setGrosime(grosimeNoua);
                                                    break;
                                                }
                                            //modificam marimea crosetei recomandate
                                            case 4:
                                                {
                                                    float crosetaNoua;
                                                    cout << "\n Dati marimea noii crosete: ";
                                                    cin >> crosetaNoua;
                                                    listaBobine[indice].setCrosetaRecomandata(crosetaNoua);
                                                    break;
                                                }
                                            //modficam pretul
                                            case 5:
                                                {
                                                    float pretNou;
                                                    cout << "\n Dati noul pret: ";
                                                    cin >> pretNou;
                                                    listaBobine[indice].setPret(pretNou);
                                                    break;
                                                }
                                            default:
                                                throw runtime_error("Comanda invalida!");
                                            }
                                            //afisam bobina modificata
                                            system("cls");
                                            cout << " Modificare realizata cu succes! Bobina actualizata: \n";
                                            cout << listaBobine[indice];
                                        }
                                        //afisam optiunile de iesire
                                        cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                        cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                        int iesire;
                                        cin >> iesire;
                                        //daca vrem sa iesim din program
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaModificam = false;
                                        }
                                        else {
                                            //daca vrem sa ne intoarcem la meniul principal
                                            if(iesire == 2)
                                                vremSaModificam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                    break;
                                }
                                default:
                                    throw runtime_error("Comanda invalida!");
                            }
                            break;
                        }
                    //reactualizam stocul de crosete
                    case 2:
                        {
                            cout << " Reactualizarea stocului de crosete! \n";
                            cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                            int adauga;
                            cin >> adauga;
                            //daca alegem sa adaugam o croseta
                            if(adauga == 1)
                            {
                                bool vremSaAdaugam = true; //ne tine in meniul de adaugat pana vrem sa iesim
                                while(vremSaAdaugam)
                                {
                                    system("cls");
                                    //citim o croseta auxiliara care va fi adaugata in lista de crosete doar dupa confirmarea corectitudinii datelor
                                    cout << " Adaugati o noua croseta\n\n";
                                    Croseta CrosetaCurenta;
                                    cin >> CrosetaCurenta;
                                    bool confirmare;
                                    cout << "\n Urmatoarele date sunt corecte?\n\n";
                                    cout << CrosetaCurenta;
                                    cout << "\n Da\/Nu? [1/0]: ";
                                    cin >> confirmare;
                                    //daca avem confirmarea
                                    if(confirmare)
                                    {
                                        //adaugam croseta in lista
                                        listaCrosete.push_back(CrosetaCurenta);
                                        int iesire;
                                        //afisam optiunile de iesire
                                        cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                        cout << "\n 3 - Iesiti\n";
                                        cin >> iesire;
                                        //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                                        //daca vrem sa iesim
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaAdaugam = false;
                                        }
                                        else {
                                            //daca vr ne intoarcem inapoi iesim din while
                                            if(iesire == 2)
                                                vremSaAdaugam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                }

                            }
                            //daca alegem sa stergem o croseta
                            else {
                                    if(adauga == 2)
                                    {
                                        bool vremSaStergem = true; //ne tine in meniul de stergere pana vrem sa iesim
                                        while(vremSaStergem)
                                        {
                                            system("cls");
                                            cout << "Stergeti crosete \n\n";
                                            //verificam daca avem crosete in stoc
                                            if(listaCrosete.empty())
                                            {
                                                cout << "Nu avem inca crosete in stoc!";
                                            }
                                            //daca avem crosete in stoc
                                            else {
                                                //afisam stocul curent cu tot cu indicii din lista de crosete
                                                cout << "Stocul curent: \n";
                                                for(int i = 0; i < listaCrosete.size(); i++)
                                                    cout << "Tipul de crosete " << i + 1 << ": \n" << listaCrosete[i] << endl;
                                                //selectia crosetei se realizeaza pe baza indicelui din lista de crosete
                                                cout << "Doriti sa stergeti crosete de tipul: ";
                                                int indice, cantitate;
                                                cin >> indice;
                                                indice--;
                                                //verificam validitatea indicelui
                                                if(indice < 0 || indice >= listaCrosete.size())
                                                    throw runtime_error("Indice invalid!");
                                                cout << "Cate crosete de acest fel doriti sa stergeti? ";
                                                cin >> cantitate;
                                                //daca stergem mai putine crosete decat cate avem in stoc
                                                if(cantitate < listaCrosete[indice].getStoc())
                                                    //modificam stocul (e ca si cum sunt cumparate)
                                                    listaCrosete[indice].esteCumparat(cantitate);
                                                //daca stregem cate avem in stoc sau mai multe pur si simplu stergem obiectul
                                                else listaCrosete.erase(listaCrosete.begin() + indice);
                                                //afisam stocul actualizat
                                                system("cls");
                                                cout << "Stocul actual: \n\n";
                                                for(int i = 0; i < listaCrosete.size(); i++)
                                                    cout << listaCrosete[i] << endl;
                                            }
                                            //afisam optiunile de iesire
                                            cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                            cout << "\n 3 - Iesiti \n";
                                            int iesire;
                                            cin >> iesire;
                                            //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                            //daca vrem sa iesim
                                            if(iesire == 3)
                                            {
                                                system("cls");
                                                cout << "Bye, Boss! <3\n";
                                                profil = false;
                                                stop = false;
                                                vremSaStergem = false;
                                            }
                                            else {
                                                //daca vr ne intoarcem inapoi iesim din while
                                                if(iesire == 2)
                                                    vremSaStergem = false;
                                                else {
                                                    if(iesire != 1)
                                                        throw runtime_error("Comanda invalida!");
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        //modificam crosete
                                        if(adauga == 3)
                                        {
                                            bool vremSaModificam = true; //ne mentine in meniul de modificare pana vrem sa iesim
                                            while(vremSaModificam)
                                            {
                                                system("cls");
                                                cout << "Modificati un tip de croseta! \n";
                                                //verificam daca avem crosete in stoc
                                                if(listaCrosete.empty())
                                                    cout << "Nu avem inca crosete in stoc!";
                                                //daca avem crosete in stoc
                                                else {
                                                    //afisam stocul curent cu indicii din lista de crosete
                                                    cout << "Stocul curent de crosete: \n";
                                                    for(int i = 0; i < listaCrosete.size(); i++)
                                                        cout << "Crosetele de tipul " << i + 1 << ": \n" << listaCrosete[i] << endl;
                                                    //selectam croseta ce va fi modificata prin intermediul indicelui sau din lista de crosete
                                                    cout << "Doriti sa modificati crosetele de tipul numarul: ";
                                                    int indice;
                                                    cin >> indice;
                                                    indice--;
                                                    //verificam validitatea indicelui
                                                    if(indice < 0 || indice >= listaCrosete.size())
                                                        throw runtime_error("Index invalid!");
                                                    system("cls");
                                                    //afisam crosetele pe care vrem sa le modificam
                                                    cout << "Modificam crosetele: \n\n";
                                                    cout << listaCrosete[indice];
                                                    int modificare;
                                                    //alegem ce vrem sa modificam
                                                    cout << "\nModificati: \n 1 - Marimea \n 2 - Materialul \n 3 - Manerul ergonomic \n 4 - Pretul \n";
                                                    cin >> modificare;
                                                    switch(modificare)
                                                    {
                                                    //modificam marimea
                                                    case 1:
                                                        {
                                                            float marimeNoua;
                                                            cout << "\n Dati noua marime: ";
                                                            cin >> marimeNoua;
                                                            listaCrosete[indice].setMarime(marimeNoua);
                                                            break;
                                                        }
                                                    //modificam materialul
                                                    case 2:
                                                        {
                                                            char materialNou[20];
                                                            cout << "\n Dati noul material: ";
                                                            cin >> materialNou;
                                                            listaCrosete[indice].setMaterial(materialNou);
                                                            break;
                                                        }
                                                    //modificam manerul ergonomic
                                                    case 3:
                                                        {
                                                            if(listaCrosete[indice].getManerErgonomic())
                                                                listaCrosete[indice].setManerErgonomic(false);
                                                            else listaCrosete[indice].setManerErgonomic(true);
                                                            break;
                                                        }
                                                    //modificam pretul
                                                    case 4:
                                                        {
                                                            float pretNou;
                                                            cout << "\n Dati noul pret: ";
                                                            cin >> pretNou;
                                                            listaCrosete[indice].setPret(pretNou);
                                                            break;
                                                        }
                                                    default:
                                                        throw runtime_error("Comanda invalida!");
                                                    }
                                                    //afisam croseta modificata
                                                    system("cls");
                                                    cout << " Modificare realizata cu succes! Croseta actualizata: \n";
                                                    cout << listaCrosete[indice];
                                                }
                                                //afisam optiunile de iesire
                                                cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                                cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                                int iesire;
                                                cin >> iesire;
                                                //daca vrem sa mai modificam nu facem nimic
                                                //daca vrem sa iesim din program
                                                if(iesire == 3)
                                                {
                                                    system("cls");
                                                    cout << "Bye, Boss! <3\n";
                                                    profil = false;
                                                    stop = false;
                                                    vremSaModificam = false;
                                                }
                                                else {
                                                    //daca vrem sa ne intoarcem la meniul principal
                                                    if(iesire == 2)
                                                        vremSaModificam = false;
                                                    else {
                                                        if(iesire != 1)
                                                            throw runtime_error("Comanda invalida!");
                                                    }
                                                }
                                            }
                                        }
                                        else throw runtime_error("Comanda invalida!");
                                    }
                            }
                            break;
                        }
                    //reactualizam stocul de nasturi
                    case 3:
                        {
                            cout << " Reactualizarea stocului de nasturi! \n";
                            cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                            int adauga;
                            cin >> adauga;
                            //daca alegem sa adaugam un tip de nasturi
                            if(adauga == 1)
                            {
                                bool vremSaAdaugam = true; //ne tine in meniul de adaugat pana vrem sa iesim
                                while(vremSaAdaugam)
                                {
                                    system("cls");
                                    //citim un nasture auxiliar care va fi adaugat in lista de nasturi doar dupa confirmarea corectitudinii datelor
                                    cout << " Adaugati un nou nasture\n\n";
                                    Nasture NastureCurent;
                                    cin >> NastureCurent;
                                    bool confirmare;
                                    cout << "\n Urmatoarele date sunt corecte?\n\n";
                                    cout << NastureCurent;
                                    cout << "\n Da\/Nu? [1/0]: ";
                                    cin >> confirmare;
                                    //daca avem confirmarea
                                    if(confirmare)
                                    {
                                        //adaugam croseta in lista
                                        listaNasturi.push_back(NastureCurent);
                                        int iesire;
                                        //afisam optiunile de iesire
                                        cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                        cout << "\n 3 - Iesiti\n";
                                        cin >> iesire;
                                        //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                                        //daca vrem sa iesim
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaAdaugam = false;
                                        }
                                        else {
                                            //daca vr ne intoarcem inapoi iesim din while
                                            if(iesire == 2)
                                                vremSaAdaugam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                }

                            }
                            //daca alegem sa stergem un nasture
                            else {
                                    if(adauga == 2)
                                    {
                                        bool vremSaStergem = true; //ne tine in meniul de stergere pana vrem sa iesim
                                        while(vremSaStergem)
                                        {
                                            system("cls");
                                            cout << "Stergeti nasturi \n\n";
                                            //verificam daca avem nasturi in stoc
                                            if(listaNasturi.empty())
                                            {
                                                cout << "Nu avem inca nasturi in stoc!";
                                            }
                                            //daca avem nasturi in stoc
                                            else {
                                                //afisam stocul curent cu tot cu indicii din lista de nasturi
                                                cout << "Stocul curent: \n";
                                                for(int i = 0; i < listaNasturi.size(); i++)
                                                    cout << "Tipul de nasturi " << i + 1 << ": \n" << listaNasturi[i] << endl;
                                                //selectia nasturilor se realizeaza pe baza indicelui din lista de nasturi
                                                cout << "Doriti sa stergeti nasturi de tipul: ";
                                                int indice, cantitate;
                                                cin >> indice;
                                                indice--;
                                                //verificam validitatea indicelui
                                                if(indice < 0 || indice >= listaNasturi.size())
                                                    throw runtime_error("Indice invalid!");
                                                cout << "Cati nasturi de acest fel doriti sa stergeti? ";
                                                cin >> cantitate;
                                                //daca stergem mai putine crosete decat cate avem in stoc
                                                if(cantitate < listaNasturi[indice].getStoc())
                                                    //modificam stocul (e ca si cum sunt cumparate)
                                                    listaNasturi[indice].esteCumparat(cantitate);
                                                //daca stregem cati avem in stoc sau mai multi pur si simplu stergem obiectul
                                                else listaNasturi.erase(listaNasturi.begin() + indice);
                                                //afisam stocul actualizat
                                                system("cls");
                                                cout << "Stocul actual: \n\n";
                                                for(int i = 0; i < listaNasturi.size(); i++)
                                                    cout << listaNasturi[i] << endl;
                                            }
                                            //afisam optiunile de iesire
                                            cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                            cout << "\n 3 - Iesiti \n";
                                            int iesire;
                                            cin >> iesire;
                                            //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                            //daca vrem sa iesim
                                            if(iesire == 3)
                                            {
                                                system("cls");
                                                cout << "Bye, Boss! <3\n";
                                                profil = false;
                                                stop = false;
                                                vremSaStergem = false;
                                            }
                                            else {
                                                //daca vr ne intoarcem inapoi iesim din while
                                                if(iesire == 2)
                                                    vremSaStergem = false;
                                                else {
                                                    if(iesire != 1)
                                                        throw runtime_error("Comanda invalida!");
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        //modificam nasturi
                                        if(adauga == 3)
                                        {
                                            bool vremSaModificam = true; //ne mentine in meniul de modificare pana vrem sa iesim
                                            while(vremSaModificam)
                                            {
                                                system("cls");
                                                cout << "Modificati un tip de nasturi! \n";
                                                //verificam daca avem nasturi in stoc
                                                if(listaNasturi.empty())
                                                    cout << "Nu avem inca nasturi in stoc!";
                                                //daca avem nasturi in stoc
                                                else {
                                                    //afisam stocul curent cu indicii din lista de nasturi
                                                    cout << "Stocul curent de nasturi: \n";
                                                    for(int i = 0; i < listaNasturi.size(); i++)
                                                        cout << "Nasturii de tipul " << i + 1 << ": \n" << listaNasturi[i] << endl;
                                                    //selectam nasturii ce vor fi modificati prin intermediul indicelui lor din lista de nasturi
                                                    cout << "Doriti sa modificati nasturii de tipul numarul: ";
                                                    int indice;
                                                    cin >> indice;
                                                    indice--;
                                                    //verificam validitatea indicelui
                                                    if(indice < 0 || indice >= listaNasturi.size())
                                                        throw runtime_error("Index invalid!");
                                                    system("cls");
                                                    //afisam nasturii pe care vrem sa-i modificam
                                                    cout << "Modificam nasturii: \n\n";
                                                    cout << listaNasturi[indice];
                                                    int modificare;
                                                    Nasture n;
                                                    //alegem ce vrem sa modificam
                                                    cout << "\nModificati: \n 1 - Forma \n 2 - Culoarea \n 3 - Materialul \n 4 - Pretul \n";
                                                    cin >> modificare;
                                                    switch(modificare)
                                                    {
                                                    //modificam forma
                                                    case 1:
                                                        {
                                                            string formaNoua;
                                                            cout << "\n Dati noua forma: ";
                                                            cin >> formaNoua;
                                                            listaNasturi[indice].setForma(formaNoua);
                                                            break;
                                                        }
                                                    //modificam culoarea
                                                    case 2:
                                                        {
                                                            string culoareNoua;
                                                            cout << "\n Dati noua culoare: ";
                                                            cin >> culoareNoua;
                                                            listaNasturi[indice].setCuloareN(culoareNoua);
                                                            break;
                                                        }
                                                    //modificam materialul
                                                    case 3:
                                                        {
                                                            char materialNou[20];
                                                            cout << "\n Dati noul material: ";
                                                            cin >> materialNou;
                                                            listaNasturi[indice].setMaterial(materialNou);
                                                            break;
                                                        }

                                                    //modificam pretul
                                                    case 4:
                                                        {
                                                            float pretNou;
                                                            cout << "\n Dati noul pret: ";
                                                            cin >> pretNou;
                                                            listaNasturi[indice].setPret(pretNou);
                                                            break;
                                                        }
                                                    default:
                                                        throw runtime_error("Comanda invalida!");
                                                    }
                                                    //afisam nasturii modificati
                                                    system("cls");
                                                    cout << " Modificare realizata cu succes! Nasturi actualizati: \n";
                                                    cout << listaNasturi[indice];
                                                }
                                                //afisam optiunile de iesire
                                                cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                                cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                                int iesire;
                                                cin >> iesire;
                                                //daca vrem sa mai modificam nu facem nimic
                                                //daca vrem sa iesim din program
                                                if(iesire == 3)
                                                {
                                                    system("cls");
                                                    cout << "Bye, Boss! <3\n";
                                                    profil = false;
                                                    stop = false;
                                                    vremSaModificam = false;
                                                }
                                                else {
                                                    //daca vrem sa ne intoarcem la meniul principal
                                                    if(iesire == 2)
                                                        vremSaModificam = false;
                                                    else {
                                                        if(iesire != 1)
                                                            throw runtime_error("Comanda invalida!");
                                                    }
                                                }
                                            }
                                        }
                                        else throw runtime_error("Comanda invalida!");
                                    }
                            }
                            break;
                    }
                    //reactualizam stocul de amigurumi
                    case 4:
                        {
                            cout << " Reactualizarea stocului de amigurumi! \n";
                            cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                            int adauga;
                            cin >> adauga;
                            //daca alegem sa adaugam un amigurumi
                            if(adauga == 1)
                            {
                                bool vremSaAdaugam = true; //ne tine in meniul de adaugat pana vrem sa iesim
                                while(vremSaAdaugam)
                                {
                                    system("cls");
                                    //citim un amigurumi auxiliar care va fi adaugat in lista de amigurumi doar dupa confirmarea corectitudinii datelor
                                    cout << " Adaugati un nou amigurumi\n\n";
                                    Amigurumi AmigurumiCurent;
                                    cin >> AmigurumiCurent;
                                    bool confirmare;
                                    cout << "\n Urmatoarele date sunt corecte?\n\n";
                                    cout << AmigurumiCurent;
                                    cout << "\n Da\/Nu? [1/0]: ";
                                    cin >> confirmare;
                                    //daca avem confirmarea
                                    if(confirmare)
                                    {
                                        //adaugam amigurumi in lista
                                        listaAmigurumi.push_back(AmigurumiCurent);
                                        int iesire;
                                        //afisam optiunile de iesire
                                        cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                        cout << "\n 3 - Iesiti\n";
                                        cin >> iesire;
                                        //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                                        //daca vrem sa iesim
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaAdaugam = false;
                                        }
                                        else {
                                            //daca vr ne intoarcem inapoi iesim din while
                                            if(iesire == 2)
                                                vremSaAdaugam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                }

                            }
                            //daca alegem sa stergem un amigurumi
                            else {
                                    if(adauga == 2)
                                    {
                                        bool vremSaStergem = true; //ne tine in meniul de stergere pana vrem sa iesim
                                        while(vremSaStergem)
                                        {
                                            system("cls");
                                            cout << "Stergeti amigurumi \n\n";
                                            //verificam daca avem amigurumi in stoc
                                            if(listaAmigurumi.empty())
                                                cout << "Nu avem inca amigurumi in stoc!";
                                            //daca avem amigurumi in stoc
                                            else {
                                                //afisam stocul curent cu tot cu indicii din lista de amigurumi
                                                cout << "Stocul curent: \n";
                                                for(int i = 0; i < listaAmigurumi.size(); i++)
                                                    cout << "Tipul de amigurumi " << i + 1 << ": \n" << listaAmigurumi[i] << endl;
                                                //selectia amigurumilor se realizeaza pe baza indicelui din lista de amigurumi
                                                cout << "Doriti sa stergeti amigurumi de tipul: ";
                                                int indice, cantitate;
                                                cin >> indice;
                                                indice--;
                                                //verificam validitatea indicelui
                                                if(indice < 0 || indice >= listaAmigurumi.size())
                                                    throw runtime_error("Indice invalid!");
                                                cout << "Cati amigurumi de acest fel doriti sa stergeti? ";
                                                cin >> cantitate;
                                                //daca stergem mai putini amigurumi decat cati avem in stoc
                                                if(cantitate < listaAmigurumi[indice].getStoc())
                                                    //modificam stocul (e ca si cum sunt cumparate)
                                                    listaAmigurumi[indice].esteCumparat(cantitate);
                                                //daca stergem cati avem in stoc sau mai multi pur si simplu stergem obiectul
                                                else listaAmigurumi.erase(listaAmigurumi.begin() + indice);
                                                //afisam stocul actualizat
                                                system("cls");
                                                cout << "Stocul actual: \n\n";
                                                for(int i = 0; i < listaAmigurumi.size(); i++)
                                                    cout << listaAmigurumi[i] << endl;
                                            }
                                            //afisam optiunile de iesire
                                            cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                            cout << "\n 3 - Iesiti \n";
                                            int iesire;
                                            cin >> iesire;
                                            //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                            //daca vrem sa iesim
                                            if(iesire == 3)
                                            {
                                                system("cls");
                                                cout << "Bye, Boss! <3\n";
                                                profil = false;
                                                stop = false;
                                                vremSaStergem = false;
                                            }
                                            else {
                                                //daca vr ne intoarcem inapoi iesim din while
                                                if(iesire == 2)
                                                    vremSaStergem = false;
                                                else {
                                                    if(iesire != 1)
                                                        throw runtime_error("Comanda invalida!");
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        //modificam amigurumi
                                        if(adauga == 3)
                                        {
                                            bool vremSaModificam = true; //ne mentine in meniul de modificare pana vrem sa iesim
                                            while(vremSaModificam)
                                            {
                                                system("cls");
                                                cout << "Modificati un amigurumi! \n";
                                                //verificam daca avem amigurumi in stoc
                                                if(listaAmigurumi.empty())
                                                    cout << "Nu avem inca amigurumi in stoc!";
                                                //daca avem amigurumi in stoc
                                                else {
                                                    //afisam stocul curent cu indicii din lista de amigurumi
                                                    cout << "Stocul curent de amigurumi: \n";
                                                    for(int i = 0; i < listaAmigurumi.size(); i++)
                                                        cout << "Amigurumi de tipul " << i + 1 << ": \n" << listaAmigurumi[i] << endl;
                                                    //selectam amigurumi ce va fi modificat prin intermediul indicelui sau din lista de amigurumi
                                                    cout << "Doriti sa modificati amigurumi de tipul numarul: ";
                                                    int indice;
                                                    cin >> indice;
                                                    indice--;
                                                    //verificam validitatea indicelui
                                                    if(indice < 0 || indice >= listaAmigurumi.size())
                                                        throw runtime_error("Index invalid!");
                                                    system("cls");
                                                    //afisam amigurumi pe care vrem sa ii modificam
                                                    cout << "Modificam amigurumi: \n\n";
                                                    cout << listaAmigurumi[indice];
                                                    int modificare;
                                                    //alegem ce vrem sa modificam
                                                    cout << "\nModificati: \n 1 - Numele \n 2 - Marimea \n 3 - Culoarea Bobinei \n 4 - Grosimea \n";
                                                    cout << " 5 - Croseta Recomandata \n 6 - Culoarea Nasturilor \n 7 - Forma Nasturilor \n";
                                                    cout << " 8 - Materialul \n 9 - Pretul \n";
                                                    cin >> modificare;
                                                    switch(modificare)
                                                    {
                                                    //modificam numele
                                                    case 1:
                                                        {
                                                            string numeNou;
                                                            cout << "\n Dati noul nume: ";
                                                            cin.ignore();
                                                            getline(cin, numeNou);
                                                            listaAmigurumi[indice].setNume(numeNou);
                                                            break;
                                                        }
                                                    //modificam marimea
                                                    case 2:
                                                        {
                                                            string marimeNoua;
                                                            cout << "\n Dati noua marime: ";
                                                            cin >> marimeNoua;
                                                            listaAmigurumi[indice].setMarime(marimeNoua);
                                                            break;
                                                        }
                                                    //modificam culoarea bobinei
                                                    case 3:
                                                        {
                                                            string nouaCuloareB;
                                                            cout << "\n Dati noua culoare a bobinei: ";
                                                            cin >> nouaCuloareB;
                                                            listaAmigurumi[indice].setCuloareB(nouaCuloareB);
                                                            break;
                                                        }
                                                    //modificam grosimea
                                                    case 4:
                                                        {
                                                            char grosimeNoua;
                                                            cout << "\n Dati noua grosime [1-7]: ";
                                                            cin >> grosimeNoua;
                                                            listaAmigurumi[indice].setGrosime(grosimeNoua);
                                                        }
                                                    //modificam croseta recomandata
                                                    case 5:
                                                        {
                                                            float crosetaRecomandataNoua;
                                                            cout << "\n Dati marimea noii crosete recomandate: ";
                                                            cin >> crosetaRecomandataNoua;
                                                            listaAmigurumi[indice].setCrosetaRecomandata(crosetaRecomandataNoua);
                                                            break;
                                                        }
                                                    //modificam culoarea nasturilor
                                                    case 6:
                                                        {
                                                            string nouaCuloareN;
                                                            cout << "\n Dati noua culoare a nasturilor: ";
                                                            cin >> nouaCuloareN;
                                                            listaAmigurumi[indice].setCuloareN(nouaCuloareN);
                                                            break;
                                                        }
                                                    //modificam forma nasturilor
                                                    case 7:
                                                        {
                                                            string formaNoua;
                                                            cout << "\n Dati noua forma a nasturilor: ";
                                                            cin >> formaNoua;
                                                            listaAmigurumi[indice].setForma(formaNoua);
                                                            break;
                                                        }
                                                    //modificam materialul
                                                    case 8:
                                                        {
                                                            string materialNou;
                                                            cout << "\n Dati noul material: ";
                                                            cin >> materialNou;
                                                            listaAmigurumi[indice].setMaterial(materialNou);
                                                            break;
                                                        }
                                                    //modificam pretul
                                                    case 9:
                                                        {
                                                            float pretNou;
                                                            cout << "\n Dati noul pret: ";
                                                            cin >> pretNou;
                                                            listaAmigurumi[indice].setPret(pretNou);
                                                            break;
                                                        }
                                                    default:
                                                        throw runtime_error("Comanda invalida!");
                                                    }
                                                    //afisam croseta modificata
                                                    system("cls");
                                                    cout << " Modificare realizata cu succes! Croseta actualizata: \n";
                                                    cout << listaAmigurumi[indice];
                                                }
                                                //afisam optiunile de iesire
                                                cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                                cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                                int iesire;
                                                cin >> iesire;
                                                //daca vrem sa mai modificam nu facem nimic
                                                //daca vrem sa iesim din program
                                                if(iesire == 3)
                                                {
                                                    system("cls");
                                                    cout << "Bye, Boss! <3\n";
                                                    profil = false;
                                                    stop = false;
                                                    vremSaModificam = false;
                                                }
                                                else {
                                                    //daca vrem sa ne intoarcem la meniul principal
                                                    if(iesire == 2)
                                                        vremSaModificam = false;
                                                    else {
                                                        if(iesire != 1)
                                                            throw runtime_error("Comanda invalida!");
                                                    }
                                                }
                                            }
                                        }
                                        else throw runtime_error("Comanda invalida!");
                                    }
                            }
                            break;
                        }
                    default:
                        throw runtime_error("Comanda invalida!");
                    }
                    break;
                }
            //daca vrem sa reactualizam proiectele
            case 2:
                {
                    cout << " Reactualizarea proiectelor! \n";
                    cout << "Doriti sa: \n 1 - Adaugati un nou proiect \n 2 - Stergeti un proiect (neindicat)";
                    cout << "\n 3 - Modificati un proiect existent\n";
                    int adaugam;
                    cin >> adaugam;
                    //daca vrem sa adaugam un proiect
                    if(adaugam == 1)
                    {
                        bool vremSaAdaugam = true; //ne mentine in meniul de adaugat pana vrem sa iesim
                        while(vremSaAdaugam)
                        {
                            system("cls");
                            //citim un proiect auxiliar ce va fi adaugat la lista de proiecte doar dupa confirmarea corectitudinii datelor
                            cout << " Adaugati un nou proiect\n\n";
                            Proiect ProiectCurent;
                            cin >> ProiectCurent;
                            bool confirmare;
                            cout << "\n Urmatoarele date sunt corecte?\n\n";
                            cout << ProiectCurent;
                            cout << "\n Da\/Nu? [1/0]: ";
                            cin >> confirmare;
                            //daca primim confirmarea
                            if(confirmare)
                            {
                                //adaugam proiectul in lista
                                listaProiecte.push_back(ProiectCurent);
                                cout << "\nLista actualizata!";

                            }
                            //afisam optiunile de iesire
                            int iesire;
                            cout << "Doriti sa: \n 1 - Mai adaugati proiecte \n 2 - Va intoarceti la meniul principal";
                            cout << "\n 3 - Iesiti \n";
                            cin >> iesire;
                            //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                            //daca vrem sa iesim din program
                            if(iesire == 3)
                            {
                                system("cls");
                                cout << "Bye, Boss! <3\n";
                                profil = false;
                                stop = false;
                                vremSaAdaugam = false;
                            }
                            else {
                                //daca vrem sa ne intoarcem la meniul principal
                                if(iesire == 2)
                                    vremSaAdaugam = false;
                                else {
                                    if(iesire != 1)
                                        throw runtime_error("Comanda invalida!");
                                   }
                            }
                        }
                    }
                    else {
                        //daca vrem sa stergem un proiect
                        if(adaugam == 2)
                        {
                            bool vremSaStergem = true; //ne mentine in meniul de stergere pana vrem sa iesim
                            while(vremSaStergem)
                            {
                                system("cls");
                                cout << " Stregeti un proiect \n\n";
                                //verificam daca avem proiecte postate
                                if(listaProiecte.empty())
                                    cout << "Nu avem inca proiecte postate!";
                                //daca avem proiecte in stoc
                                else {
                                    //afisam lista curenta cu tot cu indicii proiectelor in lista de proiecte
                                    cout << " Lista curenta de pattern-uri disponibile: \n";
                                    for(int i = 0; i < listaProiecte.size(); i++)
                                        cout << "Proiectul " << i << ": \n" << listaProiecte[i] << endl;
                                    //selectam proiectul prin intermediul indicelui sau din lista de proiecte
                                    cout << "Doriti sa stergeti proiectul numarul: ";
                                    int indice;
                                    cin >> indice;
                                    indice--;
                                    //verificam validitatea indicelui
                                    if(indice < 0 || indice >= listaProiecte.size())
                                        throw runtime_error("Comanda invalida");
                                    //stregem proiectul cu indicele "indice" din lista de proiecte
                                    listaProiecte.erase(listaProiecte.begin() + indice);
                                    //afisam stocul actualizat
                                    system("cls");
                                    cout << "Lista actualizata de proiecte din revista: \n\n";
                                    for(int i = 0; i < listaProiecte.size(); i++)
                                        cout << listaProiecte[i] << endl;
                                }
                                //afisam optiunile de iesire
                                cout << "Mai departe doriti sa: \n 1 - Continuati sa stergeti proiecte \n 2 - Reveniti la meniul principal";
                                cout << "\n 3 - Iesiti \n";
                                int iesire;
                                cin >> iesire;
                                //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                //daca vrem sa iesim din program
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "Bye, Boss! <3\n";
                                    profil = false;
                                    stop = false;
                                    vremSaStergem = false;
                                }
                                else {
                                    //daca vrem sa ne intoarcem la meniul principal
                                    if(iesire == 2)
                                        vremSaStergem = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda invalida!");
                                    }
                                }
                            }
                        }
                        else {
                            //daca vrem sa modificam un proiect
                            if(adaugam == 3)
                            {
                                bool vremSaModificam = true;//ne mentine in meniul de modificat
                                while(vremSaModificam)
                                {
                                    system("cls");
                                    cout << "Modificati un proiect! \n";
                                    //verificam daca avem proiecte postate
                                    if(listaProiecte.empty())
                                        cout << "Nu avem proiecte posatate!";
                                    //daca avem proiecte postate
                                    else {
                                        //afisam lista proiectelor curente cu tot cu indicii proiectelor in ea
                                        cout << "Lista curenta de pattern-uri disponibile: \n";
                                        for(int i = 0; i < listaProiecte.size(); i++)
                                            cout << "Proiectul " << i + 1 << ": \n" << listaProiecte[i] << endl;
                                        //selectam proiectul prin intermediul indicelui din lista
                                        cout << "Doriti sa modificati proiectul numarul: ";
                                        int indice;
                                        cin >> indice;
                                        indice--;
                                        //verificam validitatea indicelui
                                        if(indice < 0 || indice >= listaProiecte.size())
                                            throw runtime_error("Comanda invalida!");
                                        system("cls");
                                        //afisam proiectul selectat
                                        cout << "Modificam proiectul: \n";
                                        cout << listaProiecte[indice];
                                        int modificare;
                                        //selectam ce vrem sa modificam
                                        cout << "\nModificati: \n 1 - Numele proiectului \n 2 - Timpul necesar realizarii sale \n 3 - Numarul de bobine";
                                        cout << "\n 4 - Crosetele Necesare\n";
                                        cin >> modificare;
                                        switch(modificare)
                                        {
                                        //modificam numele
                                        case 1:
                                            {
                                                string numeNou;
                                                cout << "\n Dati noul nume: ";
                                                cin.get();
                                                getline(cin, numeNou);
                                                listaProiecte[indice].setNume(numeNou);
                                                break;
                                            }
                                        //modificam timpul necesar realizarii lui
                                        case 2:
                                            {
                                                float timpNou;
                                                cout << "\n Dati noul timp necesar realizarii proiectului (in ore): ";
                                                cin >> timpNou;
                                                listaProiecte[indice].setTimpNecesar(timpNou);
                                                break;
                                            }
                                        //modificam numarul de bobine necesare realizarii lui
                                        case 3:
                                            {
                                                int nrBobineNou;
                                                cout << "\n Dati noul numar de bobine necesare realizarii proiectului: ";
                                                cin >> nrBobineNou;
                                                listaProiecte[indice].setNrBobine(nrBobineNou);
                                                break;
                                            }
                                        //modificam crosetele necesare realizarii lui
                                        case 4:
                                            {
                                                int nrCroseteNou;
                                                vector <float> croseteNoi;
                                                cout << "\n Dati numarul crosetelor noi: ";
                                                cin >> nrCroseteNou;
                                                cout << "\n Dati marimile noilor crosete: ";
                                                for(int i = 0; i < nrCroseteNou; i++)
                                                {
                                                    float aux;
                                                    cin >> aux;
                                                    croseteNoi.push_back(aux);
                                                }
                                                listaProiecte[indice].setCroseteNecesare(croseteNoi);
                                                break;
                                            }
                                        default:
                                            throw runtime_error("Comanda invalida!");
                                        }
                                        //afisam proiectul modificat
                                        system("cls");
                                        cout << " Modificare realizata cu succes! Proiectul actualizat: \n";
                                        cout << listaProiecte[indice];
                                    }
                                    //afisam optiunile de iesire
                                    cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati proiecte";
                                    cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                    int iesire;
                                    cin >> iesire;
                                    //daca vrem sa ramanem in meniul de modificat nu facem nimic
                                    //daca vrem sa iesim din program
                                    if(iesire == 3)
                                    {
                                        system("cls");
                                        cout << "Bye, Boss! <3\n";
                                        profil = false;
                                        stop = false;
                                        vremSaModificam = false;
                                    }
                                    else {
                                        //daca vrem sa ne intoarcem la meniul principal
                                        if(iesire == 2)
                                            vremSaModificam = false;
                                        else {
                                            if(iesire != 1)
                                                throw runtime_error("Comanda invalida!");
                                        }
                                    }
                                }

                            }
                            else throw runtime_error("Comanda invalida!");
                        }
                    }
                    break;
                }
            //daca vrem sa afisam lista de clienti inregistrati
            case 3:
                {
                    //verificam daca avem clienti inregistrati
                    if(!listaClienti.empty())
                    {
                        //afisam lista clientilor
                        cout << " Lista clientilor inregistrati: \n\n";
                        for(int i = 0; i < listaClienti.size(); i++)
                            cout << listaClienti[i] << endl;
                        //afisam cati clienti inregistrati avem
                        if(listaClienti.size() == 1)
                            cout << "\n Avem un singur client inregistrat! Se putea si mai bine... \n";
                        else cout << "\n Avem un total de " << listaClienti.size() << " clienti inregistrati! \n Bravo noua!! =) \n";
                    }
                    //daca nu avem clienti
                    else cout << "Nu avem clienti inregistrati =(( \n";
                    //afisam optiunile de iesire
                    bool iesire;
                    cout << "Doriti sa iesiti? [0/1]: ";
                    cin >> iesire;
                    //daca vrm sa iesim
                    if(iesire)
                    {
                        system("cls");
                        cout << "Bye, Boss! <3\n";
                        profil = false;
                        stop = false;
                    }
                    break;
                }
            //daca vrem sa iesim din meniul de administrator
            case 4:
                {
                    profil = false;
                    break;
                }
            //daca vrem sa iesim din program
            case 5:
                {
                    system("cls");
                    cout << "Bye, Boss! <3\n";
                    profil = false;
                    stop = false;
                    break;
                }
            default:
                {
                    throw runtime_error("Comanda necunoscuta! =(");
                    break;
                }
            }
        }
    break;
    }
    default: {
        throw runtime_error("Identitate necunoscuta! =( ");
        break;
    }
    }
    }
    return 0;
}
