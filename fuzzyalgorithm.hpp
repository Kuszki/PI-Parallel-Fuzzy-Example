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

#ifndef FUZZYALGORITHM_HPP
#define FUZZYALGORITHM_HPP

#include "sigmoidfunction.hpp"
#include "gaussfunction.hpp"

#include <boost/bind.hpp>

#include <QtConcurrent>

#include <QThreadPool>
#include <QObject>

class FuzzyAlgorithm : public QObject
{

		Q_OBJECT

	public: using FuzzyVariables = QVector<FuzzyVariable>;
	public: using OutputFunction = FuzzyVariable (*) (const FuzzyVariables&);

	private:

		QVector<MembershipFunction*> inputMembersA;
		QVector<MembershipFunction*> inputMembersB;

		QVector<OutputFunction> outputMembers;
		QVector<double> singletonValues;

		mutable QMutex threadSynchronizer;

	public:

		explicit FuzzyAlgorithm(QObject* parent = nullptr);
		virtual ~FuzzyAlgorithm(void) override;

		double runAsyncOpenmp(double A, double B) const;
		double runAsyncMapped(double A, double B) const;
		double runAsyncRun(double A, double B) const;
		double runSync(double A, double B) const;

	public slots:

		void computeRequest(double A, double B);

	signals:

		void computeFinished(double);

};

#endif // FUZZYALGORITHM_HPP
