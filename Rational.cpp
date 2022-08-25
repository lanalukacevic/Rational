#include <iostream>
using namespace std;

class Rational
{
    private:
    
        int p, q;
    
    public:
        
        Rational()
        {
            p = q = 1;
        }

        Rational(int p, int q) : p(p), q(q)
        {}


        Rational(const Rational& r)
        {
            cout << "copied" <<endl;
            p = r.p;
            q = r.q;
        }

        int getP() const
        {
            return p;
        }
        
        int getQ() const
        {
            return q;
        }

        void setP(const int& p)
        {
            this -> p = p;
        }

        void setQ(const int& q)
        {
            this -> q = q;
        }

        void operator = (const Rational& r)
        {
            cout << "Assigned" << endl;
            q = r.q;
            p = r.p;
        }

        bool operator == (const Rational& r) const
        {
            return 1.0 * p / q == 1.0 * r.p / r.q;
        }
        
        bool operator != (const Rational& r) const
        {
            return !(1.0 * p / q == 1.0 * r.p / r.q);
        }

        Rational operator + (const Rational& r) const
        {
            if (q == r.q)
            {
                return Rational(p + r.p, q);
            }
            else
            {
                int newP = r.q * p + q * r.p;
                int newQ = q * r.q;
                return Rational(newP, newQ);
            }
        }

        Rational operator - (const Rational& r) const
        {
            if (q == r.q)
            {
                return Rational(p - r.p, q);
            }
            else
            {
                int newP = r.q * p - q * r.p;
                int newQ = q * r.q;
                return Rational(newP, newQ);
            }
        }

        Rational operator / (const Rational& r) const
        {
            int newP, newQ;
            newP = p * r.q;
            newQ = q * r.p;
            return Rational(newP, newQ);
        }

        Rational operator * (const Rational& r) const
        {
            int newP, newQ;
            newP = p * r.p;
            newQ = q * r.q;
            return Rational(newP, newQ);
        }

        friend ostream& operator << (ostream& out, const Rational& r);
        friend istream& operator >> (istream& in, Rational& r);
};
        
ostream& operator << (ostream& out, const Rational& r)
{
    if ( r.p == r.q)
    {
        out << r.p/r.q << endl;
    }
    else if (r.p > r.q)
    {
        out << r.p/r.q << " (" << r.p % r.q << "/" << r.q << ")" << endl;
    }
    else
    {
        out << r.p << "/" << r.q << endl;
    }
    return out;
}

istream& operator >> (istream& in, Rational& r)
{
    cout << "Enter p: ";
    in >> r.p;
    cout << "Enter q: ";
    in >> r.q;
}