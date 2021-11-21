/* Rudimentaerer Loesungsentwurf Aufgabe 1
   Programmieren II fuer (Wirtschafts-)Mathematiker WS 21/22 */

#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

using namespace std;

class Complex {
  private:
    double r,phi;

  public:
    Complex(double Re=0, double Im=0): 
      r(sqrt(Re*Re+Im*Im)), phi(atan2(Im,Re)) {}

    double real() const { 
      return r*cos(phi);
    }

    double imag() const { 
      return r*sin(phi);
    }

    friend Complex operator+(Complex z1, Complex z2) {
      Complex z;
      z.r = (z1.r*z1.r + z2.r*z2.r+2*z1.r*z2.r*cos(z1.phi-z2.phi));// z.r und z.phi berechnen
      z.phi = atan2(z1.r*sin(z1.phi)+z2.r*sin(z2.phi),z1.r*cos(z1.phi)+z2.r*cos(z2.phi));
      return z;
    }

    friend istream& operator>>(istream& stream, Complex& z) {
      char c1,c2,c3;
      double x,y;
      stream >> c1 >> x >> c2 >> y >> c3;
      if (c1!='(' || c2!=',' || c3!=')') {
        stream.setstate(ios::failbit);
      }
      else {
        z = Complex(x,y);
      }
      return stream;
    }
    friend ostream& operator<<(ostream& stream, Complex z) {
      // Ausgabe auf stream vornehmen
      stream << "(" <<z.real()<<","<<z.imag()<<")";
      return stream;
    }
};


int main()
{
  complex<double> w1,w2;

  cout << "z1 z2: ";
  cin >> w1 >> w2;   
  Complex z1(w1.real(),w1.imag()),z2(w2.real(),w2.imag());

  cout << fixed << setprecision(15);
  cout << "z1+z2:  " << z1+z2 << endl;
  cout << "w1+w2:  " << w1+w2 << endl;
  return 0;
}
