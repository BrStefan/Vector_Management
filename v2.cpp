#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

//////////////////////////////////-------------COMPLEX-------------------------------////////////////////////


class Complex
{
	private:
		float re,im;
	public:
		Complex(float , float);
		Complex(Complex &);
		~Complex();
		Complex operator = (Complex&);
		friend istream& operator >> (istream&, Complex&);
		friend ostream& operator << (ostream&, const Complex&);
		int getReal();
		int getImaginar();
};

Complex::Complex(float i=0.0,float j=0.0)
{
	re=i;
	im=j;
}

Complex::Complex(Complex &o)
{
	re=o.re;
	im=o.im;
}

Complex::~Complex()
{
	re=0;
	im=0;
}

Complex Complex::operator=(Complex &o)
{
	re = o.re;
	im = o.im;
	return *this;	
}

istream& operator>> (istream &fin, Complex &nr)
{
	fin>>nr.re>>nr.im;
	return fin;
}

ostream& operator<< (ostream& fout,const Complex& nr)
{
	fout<<nr.re<<" "<<nr.im<<"\n";
	return fout;
}

int Complex::getReal()
{
	return (*this).re;
}

int Complex::getImaginar()
{
	return (*this).im;
}

//////////////////////////////////-------------COMPLEX-------------------------------////////////////////////


//////////////////////////////////--------------VECTOR-------------------------------////////////////////////

class Vector
{
	protected:
		int dim;
		Complex *v;
		static int cnt_v;
	public:
		Vector(int);
		Vector(Vector&);
		~Vector();
		Vector& operator = (const Vector&);
		friend istream& operator >> (istream&, Vector&);
		friend ostream& operator << (ostream&, const Vector&);
		virtual void afisare(ostream&) const;
		virtual void citire(istream&);
		virtual void verificare();
		static int get_cate();
};

int Vector::cnt_v=0;

Vector::Vector(int n=0)
{
	dim=n;
	v = new Complex[dim+1];
}

Vector::Vector(Vector &a)
{
	dim=a.dim;
	for(int i=0;i<dim;i++)
	{
		v[i]=a.v[i];
	}
}
Vector::~Vector()
{
	delete []v;
}

Vector& Vector::operator=(const Vector &o)
{
	if(this == &o) return *this;
	dim=o.dim; 
	for(int i=0;i<dim;i++)
	{
		v[i]=o.v[i];
	}
	return *this;
}

istream& operator>> (istream &fin, Vector &nr)
{
	nr.citire(fin);
	return fin;
}

ostream& operator<< (ostream& fout,const Vector& nr)
{
	nr.afisare(fout);
	return fout;
}

void Vector::citire(istream& fin)
{
	for(int i=0;i<(*this).dim;i++)fin>>(*this).v[i];
	cnt_v++;
}

void Vector::afisare(ostream& fout) const
{
	for(int i=0;i<(*this).dim;i++)fout<<(*this).v[i];
}

void Vector::verificare()
{
	fout<<"Aceast obiect este un vector\n";
}
int Vector::get_cate()
{
	return cnt_v;
}



//////////////////////////////////--------------VECTOR-------------------------------////////////////////////

//////////////////////////////////--------------STIVA-------------------------------////////////////////////

class Stiva:public Vector
{
	protected:
		int vf;
		static int cnt_s;
	public:
		Stiva(int);
		Stiva(Stiva&);
		~Stiva();
		Stiva& operator = (const Stiva&);
		friend istream& operator >> (istream&, Stiva&);
		friend ostream& operator << (ostream&, const Stiva&);
		void afisare(ostream&) const;
		void citire(istream&);
		virtual void verificare();
		static int get_cate();
};

int Stiva::cnt_s=0;

Stiva::Stiva(int n=0):Vector(n)
{
	vf=0;
}

Stiva::Stiva(Stiva &a)
{
	dim=a.dim;
	for(int i=0;i<dim;i++)
	{
		v[i]=a.v[i];
	}
}
Stiva::~Stiva()
{
	delete []v;
}

Stiva& Stiva::operator=(const Stiva &o)
{
	if(this == &o) return *this;
	dim=o.dim; 
	for(int i=0;i<dim;i++)
	{
		v[i]=o.v[i];
	}
	return *this;
}

istream& operator>> (istream &fin, Stiva &nr)
{
	nr.citire(fin);
	return fin;
}

ostream& operator<< (ostream& fout,const Stiva& nr)
{
	nr.afisare(fout);
	return fout;
}

void Stiva::citire(istream& fin)
{
	for(int i=0;i<(*this).dim;i++)
	{
		fin>>(*this).v[vf];
		(*this).vf++;
	}
	cnt_s++;
}

void Stiva::afisare(ostream& fout) const
{
	for(int i=0;i<(*this).dim;i++)fout<<(*this).v[i];
}

void Stiva::verificare()
{
	bool e=0;
	for(int i=0;i<(*this).vf;i++)
		if((*this).v[i].getReal()==0 && (*this).v[i].getImaginar())
			{
				fout<<"Aceasta stiva are cel putin un element care are doar partea imaginara nenula!\n";
				e=1;
				break;
			}
	if(e==0)fout<<"Aceasta stiva nu are cel putin un element care are doar partea imaginara nenula!\n";
}

int Stiva::get_cate()
{
	return cnt_s;
}

//////////////////////////////////--------------STIVA-------------------------------////////////////////////

//////////////////////////////////--------------COADA-------------------------------////////////////////////

class Coada:public Vector
{
	protected:
		int prim,ultim;
		static int cnt_c;
	public:
		Coada(int);
		Coada(Coada&);
		~Coada();
		Coada& operator = (const Coada&);
		friend istream& operator >> (istream&, Coada&);
		friend ostream& operator << (ostream&, const Coada&);
		void afisare(ostream&) const;
		void citire(istream&);
		void verificare();
		static int get_cate();
};

int Coada::cnt_c=0;

Coada::Coada(int n=0):Vector(n)
{
	prim=0;
	ultim=0;
}

Coada::Coada(Coada &a)
{
	dim=a.dim;
	for(int i=0;i<dim;i++)
	{
		v[i]=a.v[i];
	}
}
Coada::~Coada()
{
	delete []v;
}

Coada& Coada::operator=(const Coada &o)
{
	if(this == &o) return *this;
	dim=o.dim; 
	for(int i=0;i<dim;i++)
	{
		v[i]=o.v[i];
	}
	return *this;
}

istream& operator>> (istream &fin, Coada &nr)
{
	nr.citire(fin);
	return fin;
}

ostream& operator<< (ostream& fout,const Coada& nr)
{
	nr.afisare(fout);
	return fout;
}

void Coada::citire(istream& fin)
{
	for(int i=0;i<(*this).dim;i++)
	{
		fin>>(*this).v[ultim];
		(*this).ultim++;
	}
	cnt_c++;
}

void Coada::afisare(ostream& fout) const
{
	for(int i=0;i<(*this).dim;i++)fout<<(*this).v[i];
}

void Coada::verificare()
{
	bool e=0;
	for(int i=0;i<(*this).ultim;i++)
		if((*this).v[i].getReal()==0 && (*this).v[i].getImaginar())
			{
				fout<<"Aceasta stiva are cel putin un element care are doar partea imaginara nenula!\n";
				e=1;
				break;
			}
	if(e==0)fout<<"Aceasta stiva nu are cel putin un element care are doar partea imaginara nenula!\n";
}

int Coada::get_cate()
{
	return cnt_c;
}

//////////////////////////////////--------------COADA-------------------------------////////////////////////


int main()
{
	int op,n,dim;
	Vector** f;
	fin>>n;
	f = new Vector* [n+1];
	for(int i=0;i<n;i++)
	{
		fin>>op;
		switch(op)
		{
			case 1: // citiere vector
			{
				fin>>dim;
				f[i] = new Vector(dim);
				fin>>*f[i];
				break;
			}
			case 2: // citiere coada
			{
				fin>>dim;
				f[i] = new Coada(dim);
				fin>>*f[i];
				break;
			}
			case 3: // citiere stiva
			{
				fin>>dim;
				f[i] = new Stiva(dim);
				fin>>*f[i];
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		fout<<*f[i];
		fout<<"\n";
		(*f[i]).verificare();
	}
	fout<<"\nNumarul de vectori: "<<Vector::get_cate();
	fout<<"\nNumarul de stive: "<<Stiva::get_cate();
	fout<<"\nNumarul de cozi: "<<Coada::get_cate();

	// exemplu doar pt evidentierea down-cast-ului
	Vector* baza = new Stiva(1);
	Stiva* derivata = dynamic_cast<Stiva*>(baza);
	if(derivata)
	{
		fin>>*derivata;
		fout<<"\n"<<*derivata;
	}
	else fout<<"\nDown-cast nereusit";

	return 1;
}