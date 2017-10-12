/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Parallel Fully logic algoritm demo                                     *
 *  Copyright (C) 2017  Łukasz "Kuszki" Dróżdż  l.drozdz@openmailbox.org   *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the  Free Software Foundation, either  version 3 of the  License, or   *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This  program  is  distributed  in the hope  that it will be useful,   *
 *  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have  received a copy  of the  GNU General Public License   *
 *  along with this program. If not, see http://www.gnu.org/licenses/.     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FUZZYVARIABLE_HPP
#define FUZZYVARIABLE_HPP

#include <QtMath>

class FuzzyVariable
{

	private:

		double variable;

	public:

		FuzzyVariable(const FuzzyVariable& other) = default;
		FuzzyVariable(FuzzyVariable&& other) = default;

		FuzzyVariable(double _value);
		FuzzyVariable(void);

		double getValue(void) const;
		void setValue(double value);

		FuzzyVariable& operator= (const FuzzyVariable& other) = default;
		FuzzyVariable& operator= (FuzzyVariable&& other) = default;

		FuzzyVariable operator&& (const FuzzyVariable& other) const;
		FuzzyVariable operator|| (const FuzzyVariable& other) const;

		bool operator== (const FuzzyVariable& other) const;
		bool operator!= (const FuzzyVariable& other) const;

		bool operator> (const FuzzyVariable& other) const;
		bool operator< (const FuzzyVariable& other) const;

		bool operator>= (const FuzzyVariable& other) const;
		bool operator<= (const FuzzyVariable& other) const;

		operator double() const;

};

#endif // FUZZYVARIABLE_HPP
