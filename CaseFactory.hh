#ifndef	CASE_FACTORY_HH_
#define CASE_FACTORY_HH_

#include "ICase.hh"

class CaseFactory
{
public:
	static ICase *createCase(const char c);
	static ICase *createCase(ICase::eTypeCase type);
	static ICase *createBlockEmpty();
	static ICase *createBlockWall();
	static ICase *createPlayerBasic();
};

class CaseFactoryException : public std::exception
{
	std::string   _message;
public:
	CaseFactoryException(std::string const &msg) : _message(msg) {}
	~CaseFactoryException() throw() {}
	std::string const &   What() const throw() { return (this->_message); }
	std::string const &   getMessage() const throw() { return (this->_message); }
};

struct	ptr_func
{
	ICase::eTypeCase type;
	char c;
	ICase* (*ptr)();
};

#endif // CASE_FACTORY_HH_
