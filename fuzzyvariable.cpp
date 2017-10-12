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

#include "fuzzyvariable.hpp"

FuzzyVariable::FuzzyVariable(double _value)
{
	setValue(_value);
}

FuzzyVariable::FuzzyVariable(void)
: variable(0.0) {}

double FuzzyVariable::getValue(void) const
{
	return variable;
}

void FuzzyVariable::setValue(double value)
{
	if (value >= 1.0) variable = 1.0;
	else if (value <= 0.0) variable = 0.0;
	else variable = value;
}

FuzzyVariable FuzzyVariable::operator&& (const FuzzyVariable& other) const
{
	return FuzzyVariable(qMin(variable, other.variable));
}

FuzzyVariable FuzzyVariable::operator|| (const FuzzyVariable& other) const
{
	return FuzzyVariable(qMax(variable, other.variable));
}

bool FuzzyVariable::operator== (const FuzzyVariable& other) const
{
	return variable == other.variable;
}

bool FuzzyVariable::operator!= (const FuzzyVariable& other) const
{
	return variable != other.variable;
}

bool FuzzyVariable::operator> (const FuzzyVariable& other) const
{
	return variable > other.variable;
}

bool FuzzyVariable::operator< (const FuzzyVariable& other) const
{
	return variable < other.variable;
}

bool FuzzyVariable::operator>= (const FuzzyVariable& other) const
{
	return variable >= other.variable;
}

bool FuzzyVariable::operator<= (const FuzzyVariable& other) const
{
	return variable <= other.variable;
}

FuzzyVariable::operator double(void) const
{
	return variable;
}
