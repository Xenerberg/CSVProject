#ifndef SORTER_UTILITY_H
#define SORTER_UTILITY_H
#include <vector>
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
	class Funct_Sorter {
	public:
		Funct_Sorter() {};
		void operator()(std::vector<double> con1, std::vector<string> con2);
	private:
		
	};
}
#endif

