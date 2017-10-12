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

#include "sigmoidfunction.hpp"

SigmoidFunction::SigmoidFunction(double _beta, double _offset, bool _rising)
: beta(_beta), offset(_offset), rising(_rising) {}

SigmoidFunction::~SigmoidFunction(void) {}

FuzzyVariable SigmoidFunction::value(double x) const
{
	const double ret = 1.0 / (1.0 + qExp(beta * (x - offset)));

	return rising ? 1 - ret : ret;
}

double SigmoidFunction::getBeta(void) const
{
	return beta;
}

void SigmoidFunction::setBeta(double value)
{
	beta = value;
}

double SigmoidFunction::getOffset(void) const
{
	return offset;
}

void SigmoidFunction::setOffset(double value)
{
	offset = value;
}

bool SigmoidFunction::getRising(void) const
{
	return rising;
}

void SigmoidFunction::setRising(bool value)
{
	rising = value;
}
