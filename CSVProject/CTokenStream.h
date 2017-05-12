#ifndef CSVPROJECT_CTOKENSTREAM_H
#define CSVPROJECT_CTOKENSTREAM_H
#include "stdafx.h"
#include <iostream>
#include <istream>
#include <sstream>
#include "SToken.h"
#include <fstream>

namespace NM_CSVProject {
	class CTokenStream {
	public:
		
		//Default separator and newline
		constexpr static char def_sep{ ',' }, def_nl{ '\n' };
		//Constructors (parameterzied)
		CTokenStream(std::istream &in, char sep = def_sep, char nl = def_nl) :CTokenStream(&in, sep, nl) {};		
		CTokenStream(std::string fileName, char sep = def_sep, char nl = def_nl) :CTokenStream(new std::ifstream{ fileName }, sep, nl) {};
		//Prevent Copy constructor and equals operator
		CTokenStream(const CTokenStream &) = delete;
		CTokenStream& operator=(const CTokenStream &) = delete;
		//Destructor to free internal streams
		~CTokenStream() { fn_Release(); };
		//Reads and returns next token
		SToken get();
		//Returns current token
		const SToken &current() {
			return curr;
		}
		void CTokenStream::put(SToken tokObj);
		void setInput(std::istream &in);
		void setInput(std::istream * in);
		void setOutput(std::ostream &in);
		void setOutput(std::ostream *in);
		//returns true if there are no more tokens to be streamed
		bool empty() { return curr.type == TokenType::end; }
		//returns true if there are no more tokens to be parsed
		bool EndOfRecords() { return curr.type == TokenType::nl || empty(); }
	protected:
		CTokenStream(CTokenStream &&) = default;
		CTokenStream& operator=(CTokenStream &&) = default;

	private:
		//input stream
		std::istream *in;
		std::ostream *out;
		const char sep, nl;

		SToken curr{ TokenType::end };

		CTokenStream(std::istream *in, char sep, char nl) :in{ in }, sep{ sep }, nl{ nl } {};
		
		void fn_Release() {
			delete in;
		}


	};

}

#endif