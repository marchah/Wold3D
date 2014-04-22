#ifndef	ACASE_HH_
#define ACASE_HH_

#include "ICase.hh"

class	ACase : public ICase
{
protected:
	eTypeCase	typeCase_;
public:
	ACase(eTypeCase typeCase) : typeCase_(typeCase)	{}
	virtual ~ACase()	{}
	virtual ACase & operator=(const ACase & c) { this->typeCase_ = c.getTypeCase(); return *this; }
	virtual eTypeCase	getTypeCase() const { return this->typeCase_; }
	virtual bool		isPlayer() const = 0;
};

#endif // ACASE_HH_