#pragma once
#ifndef CSVPROJECT_CSVSTREAM_H
#define CSVPROJECT_CSVSTREAM_H

#include<istream>
#include<vector>
#include<fstream>
#include "CTokenStream.h"
#include "DS.h"
using namespace NM_DS;
namespace NM_CSVProject {
	class CSVStream {
	private:
		//default separator
		constexpr static char def_sep{ CTokenStream::def_sep };
		//stream to parse character input into token objects
		CTokenStream *ts;
		//Constructor
		CSVStream(CTokenStream *ts) :ts{ ts } {
			ts->get();			
		}

		int count = 0;
		//Load a token after skipping separator
		void nextSkipToken(CTokenStream *ts) {
			if (ts->get().type == TokenType::separator)
				ts->get();
		}
		int n_col = -1;
		int n_rows = -1;

	public:		
		CSVStream(std::string fileName, char sep = def_sep) :CSVStream(new CTokenStream{fileName, sep }) {};
	
		
		CSVStream(std::istream &in, char sep = def_sep) :CSVStream(new CTokenStream{ in,sep }) {};

		CSVStream(const CSVStream &) = delete;
		CSVStream & operator=(const CSVStream &) = delete;

		CSVStream(CSVStream&&) = default;
		CSVStream & operator=(CSVStream &&) = default;

		~CSVStream() { delete ts; }

		//reads and returns the next record
		row_obj get();
		//checks if file is fully read
		bool empty() const { return ts->empty(); };
		//count the number of elements in a record
		int getcount();
		mat_obj read();
		void writeMat(std::string fileOut, mat_obj matObj);
	};
}

#endif