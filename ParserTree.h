#ifndef PARSER_TREE
#define PARSER_TREE

#include <list>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

class Parser_Tree
{
	public:
		typedef Parser_Tree* Node_Ptr;
		
		Parser_Tree() { };
		virtual ~Parser_Tree() 
		{
			if(!_children.empty()) {
				for(std::list< Node_Ptr >::iterator it = _children.begin(); it != _children.end(); it++) {
					delete *it;
				}
			}
		}
		
		void addChild(const Node_Ptr child) 
		{
			_children.push_back(child);
		}

		Node_Ptr getChild(const std::string header)
		{
			if(!_children.empty()) {
				for(std::list< Node_Ptr >::iterator it = _children.begin(); it != _children.end(); it++) {
					if((*it)->_header == header) {
						return *it;
					}
				}
					
				std::cerr << "No child of this node has an header tag which the name : " << header << std::endl;
			} else {
				std::cerr << "This node has no child" << std::endl;
			}

			return NULL;
		}

		Node_Ptr getNextChild()
		{
			if(_parent != NULL) {
				std::list< Node_Ptr >::iterator it = std::find(_parent->_children.begin(), _parent->_children.end(), this);
				
				if(it != _parent->_children.end()) {			
					for(it++; it != _parent->_children.end(); it++) {
						if((*it)->_header == this->_header) {
							return *it;
						}
					}
				} else {
					std::cerr << "This is the last node which the header is " << this->_header << std::endl;
				}

				std::cerr << "There is just one node which the header is " << this->_header << std::endl;
			} else {
				std::cerr << "The node is the root so it has only one child." << std::endl;
			}

			return NULL;
		}

		void setData(const std::string data)
		{
			_data = data;
		}

		const std::string getData() 
		{
			return _data;
		}

		void addAttribut(const std::pair< std::string, std::string > attribut)
		{
			_attributs.insert(attribut);
		}

	protected:
		std::string _header;
		std::string _data;

		std::map< std::string, std::string > _attributs;
		
		Node_Ptr _parent;
		std::list< Node_Ptr > _children;
};

#endif
