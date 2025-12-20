#ifndef _ORG_GJS_CC_CPP_BASE_OBJETO_H
#define _ORG_GJS_CC_CPP_BASE_OBJETO_H

#include <string>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

class Objeto
{
public:
	Objeto ();
	virtual ~Objeto ();

private:
	string tipo;

public:
	string getTipo () const;
	virtual int hash() const;
	virtual bool esValido () const ;

	Objeto * clonar();

	virtual bool equals ( Objeto & objeto ) const;
	virtual bool equals ( Objeto * objeto ) const;

	virtual string toString ();

protected:
	virtual void assignar( Objeto & objeto );

public:
	Objeto & operator=( Objeto & objeto );
	bool operator== ( Objeto & objeto );
	bool operator!= ( Objeto & objeto );

};

 			}
		}
	}
}



#endif
