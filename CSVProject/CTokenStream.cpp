#include "CTokenStream.h"

namespace NM_CSVProject {
	SToken CTokenStream::get() {
		//Read and return the next token
		if (in->eof()) {
			curr.type = TokenType::end;
			return curr;
		}

		char c = in->get();

		if (in->eof()) curr.type = TokenType::end;
		else if (c == sep) curr.type = TokenType::separator;
		else if (c == nl) curr.type = TokenType::nl;
		else {
			curr.type = TokenType::str;
			std::stringstream s{};
			s << c;
			for (;;) {
				if ((c = in->get()) == nl || c == sep) {
					in->putback(c);
					break;
				}
				if (in->eof()) break;
				//Error
				if (in->fail()) break;

				s << c;
			}
			curr.str = s.str();
		}
		return curr;
	}
	void CTokenStream::put(SToken tokObj) {
		switch (tokObj.type) {
		case TokenType::str:
			*(this->out) << tokObj.str;
			break;
		case TokenType::nl:
			*(this->out) << nl;
			break;
		case TokenType::separator:
			*(this->out) << sep;
			break;
		}
		
	}
	void CTokenStream::setInput(std::istream &in)
	{
		fn_Release();
		this->in = &in;
		curr.type = TokenType::end;
	}
	void CTokenStream::setInput(std::istream *in)
	{
		fn_Release();
		this->in = in;
		curr.type = TokenType::end;
	}
	void CTokenStream::setOutput(std::ostream *out)
	{
		this->out = out;
	}
	void CTokenStream::setOutput(std::ostream &out)
	{
		this->out = &out;
	}
}