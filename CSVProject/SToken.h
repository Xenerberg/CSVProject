#ifndef CSVProject_TOKEN_H
#define CSVProject_TOKEN_H

#include<string>
namespace NM_CSVProject {
	enum class TokenType { separator, str, nl, end };

	struct SToken {
		TokenType type;
		std::string str;
	};
}
#endif

