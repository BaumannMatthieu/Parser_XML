#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "ParserTree.h"
#include "ParserXML.h"

int main(void)
{
	Parser::Parser_XML parser;
	parser.load_file("test.xml");
	
	std::cout << parser.getChild("code")->getNextChild()->getNextChild()->getChild("test")->getAttribut("toto") << std::endl;

	return 0;
}
