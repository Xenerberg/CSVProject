#ifndef SORTER_UTILITY_H
#define SORTER_UTILITY_H

#include "DS.h"
using namespace NM_DS;
namespace NM_Utility {	
	template<class T, class S>
	class Funct_Sorter {
	public:
		Funct_Sorter() {};		
		void Funct_Sorter::operator()(std::vector<T> &con1, std::vector<S> con2)
		{
			std::vector<pair<S, T>> vecPairObj;
			for (auto iCount = 0; iCount < con2.size(); iCount++)
			{
				vecPairObj.push_back(std::make_pair(con2[iCount], con1[iCount]));
			}
			//sort in ascending order - the comparison lambda function can be changed for other sorting criteria
			std::sort(vecPairObj.begin(), vecPairObj.end(), [=](std::pair<S, T>& a, std::pair<S, T> &b) {return a.first < b.first; });
			con1.clear();
			for (auto &it = vecPairObj.begin(); it != vecPairObj.end(); ++it)
			{
				con1.push_back(it->second);
			}
		}
	private:
		
	};
}
#endif

