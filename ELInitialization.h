/** \file ELInitialization.h
\brief C++ header file initializing physical variables.
Copyright 2016 by Tomas Kojar

Redistribution and use in source and binary forms, with or without modification, are permitted provided
that the following conditions are met:

-# Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

-# Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

-# The name of the copyright holder may not be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef ELINITIALIZATION_H
#define ELINITIALIZATION_H

#include <cmath>
#include <vector>

class ELInitialization {
	friend class ELTensors;

private:


	

public:
	int nuframesx;
	int nuframesy;
	int nuframesz;
	int Graddirections;
	int bval;
	std::vector< std::vector<std::vector<std::vector<double>>> > Aatten;

	std::vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>> DiffGradDir;

	double alpha;
	double Awater;
	double lmin;
	double lmax;
	std::vector<int> WM;
	std::vector<int> WTR;
	/// Constructor.
	ELInitialization(
		int xnframesx,
		int xnframesy,
		int xnframesz,
		int xGraddirections,
		int xbval,
		std::vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>> xDiffGradDir,
		double xalpha,
		double xAwater,
		double xlmin,
		double xlmax,
		std::vector<int> xWM,
		std::vector<int> xWTR
		) : nuframesx(xnframesx), nuframesy(xnframesy), nuframesz(xnframesz), Graddirections(xGraddirections), bval(xbval), DiffGradDir(xDiffGradDir), alpha(xalpha), Awater(xAwater), lmin(xlmin), lmax(xlmax), WM(xWM), WTR(xWTR) {};

	/// Copy constructor.

	double operator()(int k, int coor) { return DiffGradDir[k][coor]; }


};

//std::vector<double> ELInitialization::operator()(int k) { return this->DiffGradDir)[k]; }

#endif
