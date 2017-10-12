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

#include <QCoreApplication>

#include "fuzzyalgorithm.hpp"

#define N 100000

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	FuzzyAlgorithm fuzzy;

	double A[N], B[N];

	qsrand(QDateTime::currentSecsSinceEpoch());

	for (int i = 0; i < N; ++i)
	{
		A[i] = 3.0 * double(qrand()) / double(RAND_MAX) - 1.5;
		B[i] = 3.0 * double(qrand()) / double(RAND_MAX) - 1.5;
	}

	{
		const QTime t = QTime::currentTime();

		for (int i = 0; i < N; ++i) fuzzy.runAsyncMapped(A[i], B[i]);

		const unsigned n = t.msecsTo(QTime::currentTime());

		qDebug() << "runAsyncMapped:" << n;
	}

	{
		const QTime t = QTime::currentTime();

		for (int i = 0; i < N; ++i) fuzzy.runAsyncRun(A[i], B[i]);

		const unsigned n = t.msecsTo(QTime::currentTime());

		qDebug() << "runAsyncRun:" << n;
	}

	{
		const QTime t = QTime::currentTime();

		for (int i = 0; i < N; ++i) fuzzy.runAsyncOpenmp(A[i], B[i]);

		const unsigned n = t.msecsTo(QTime::currentTime());

		qDebug() << "runAsyncOpenmp:" << n;
	}

	{
		const QTime t = QTime::currentTime();

		for (int i = 0; i < N; ++i) fuzzy.runSync(A[i], B[i]);

		const unsigned n = t.msecsTo(QTime::currentTime());

		qDebug() << "runSync:" << n;
	}

	return 0;
}
