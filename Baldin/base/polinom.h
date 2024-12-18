#pragma once

#include <iostream>
#include "list.h"
#include <string>
#include <vector>

class Polinom {
private:
	struct Polinom::Monom {
		double coef;
		size_t degree;
		Monom(double c = 0, size_t d = 0) : coef(c), degree(d) {}
	};

	List<Monom> monoms;

	void AddMonom(const Monom& m);

	Monom ParseMonom(const string& monomStr);
	
	void ParseFromString(const string& p);
	
public: 
	Polinom();
	
	Polinom(const string& polStr);
	
	double calculate(double x, double y, double z) const;

	friend ostream& operator<<(ostream& os, const Polinom& polinom);

	Polinom operator+(const Polinom& other) const;

	Polinom operator-(const Polinom& other) const;

	Polinom operator*(double c) const;

	friend Polinom operator* (double c, const Polinom& p);

	Polinom operator*(const Polinom& other);

	Polinom derivative(char var) const;
};

