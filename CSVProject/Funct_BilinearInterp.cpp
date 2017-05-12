#include "Utility.h"

namespace NM_Utility {
	mat_obj Funct_MeanInterp::operator()() {
		
		for (int iCount1 = 0; iCount1 < _matObj.size();iCount1++) {
			row_obj rowObj = _matObj[iCount1];
			int l_r, l_l, h_r, h_l;
			for (int iCount2 = 0; iCount2 < rowObj.size();iCount2++ ) {
				double &item = _matObj[iCount1][iCount2];
				//bad value
				if (item == 0) {
					if (iCount1 == 0)						
						l_l = iCount1;											
					else					
						l_l = iCount1 - 1;						
					
					
					if (iCount1 == _matObj.size()-1)
						h_l = iCount1;
					else
						h_l = iCount1 + 1;



					if (iCount2 == 0) 
						l_r = iCount2;											
					else 
						l_r = iCount2 - 1;
					if (iCount2 == rowObj.size()-1)
						h_r = iCount2;
					else
						h_r = iCount2 + 1;

					
					int counter = 0;
					double temp = 0;
					for (auto i = l_l; i <= h_l; i++) {						
						for (auto j = l_r; j <= h_r; j++) {
							temp = temp + _matObj[i][j];
							counter++;
						}
					}
					item = temp / (counter-1);

				}
				
			}
		}
		return _matObj;
	}

}