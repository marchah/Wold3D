#ifndef	ICASE_HH_
#define ICASE_HH_

class	ICase
{
public:
	enum eTypeCase
	{
		EMPTY,
		WALL,
		PLAYER_BASIC
	};
	virtual ~ICase() {}
	virtual eTypeCase	getTypeCase() const = 0;
	virtual bool		isPlayer() const = 0;
};

#endif // ICASE_HH_