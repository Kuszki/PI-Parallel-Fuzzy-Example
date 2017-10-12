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

#include "gaussfunction.hpp"

GaussFunction::GaussFunction(double _mean, double _variance)
: mean(_mean), variance(_variance) {}

GaussFunction::~GaussFunction(void) {}

FuzzyVariable GaussFunction::value(double x) const
{
	return qExp(-qPow(x - mean, 2.0) / (2 * variance));
}

double GaussFunction::getMean(void) const
{
	return mean;
}

void GaussFunction::setMean(double value)
{
	mean = value;
}

double GaussFunction::getVariance(void) const
{
	return variance;
}

void GaussFunction::setVariance(double value)
{
	variance = value;
}
