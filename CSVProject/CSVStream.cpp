#include "CSVStream.h"
#include <string>
#include <iostream>
#include "DS.h"
using namespace NM_DS;
using namespace NM_CSVProject;
namespace NM_CSVProject{
	NM_DS::row_obj CSVStream::get() {
		if (empty()) {
			//throw exceptions
		}
		//int nCol = CSVStream::getcount();
		row_obj row{};
		while (!ts->EndOfRecords())		
		{
			
			switch (ts->current().type) 
			{
			
			case TokenType::str:
				row.push_back(stof(ts->current().str));
				nextSkipToken(ts);				
				break;
			case TokenType::separator:
				ts->get();
				break;
			case TokenType::nl:
				ts->get();
				break;
			case TokenType::end:
				break;
			default:;

			}
				
		}
		if (ts->EndOfRecords()) {
			nextSkipToken(ts);
		}
		return row;
			
	}	
	int CSVStream::getcount() {
		int count = 1;
		while (!ts->EndOfRecords()) {
			SToken tokObj = ts->current();
			if (tokObj.type == TokenType::str)
				count++;
		}
		if (!ts->empty())
			ts->get();
		return count;
	}

	NM_DS::mat_obj CSVStream::read() {
		mat_obj matObj {};
		while (!this->empty()) {
			auto record = this->get();
			if (n_col < 0)
			{
				n_col = record.size();
			}
			matObj.push_back(record);							
		}
		if (n_rows < 0)
			n_rows = matObj.size();
		
		return matObj;

	}
	void CSVStream::writeMat(std::string fileOut, NM_DS::mat_obj matObj)
	{
		ts->setOutput(new std::ofstream{ fileOut });
		
		for (auto iCount1 = 0; iCount1 < n_rows; iCount1++)
		{
			for (auto iCount2 = 0; iCount2 < n_col; iCount2++)
			{
				ts->put(SToken{ TokenType::str, std::to_string(matObj[iCount1][iCount2]) });
				ts->put(SToken{ TokenType::separator, "" });
			}
			ts->put(SToken{ TokenType::nl, "" });
		}
	}


	
}