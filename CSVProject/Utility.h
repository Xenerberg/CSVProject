#ifndef CSVPROJECT_UTILITY_H
#define CSVPROJECT_UTILITY_H

#include "DS.h"
using namespace NM_DS;
namespace NM_Utility {
	class Funct_MeanInterp {
	public:
		Funct_MeanInterp(mat_obj matObj) :_matObj(matObj) {}
		//Define bilinear interpolation after detecting "bad" values
		mat_obj operator() ();
	private:
		mat_obj _matObj; //state of the functor
	};
}
#endif

