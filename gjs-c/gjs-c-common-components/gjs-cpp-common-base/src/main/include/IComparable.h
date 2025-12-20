#ifndef _ORG_GJS_C_CC_CPP_ICOMPARABLE_H
#define _ORG_GJS_C_CC_CPP_ICOMPARABLE_H


#include <functional>

#include <IToString.h>


using namespace std;
using namespace org::gjs::cpp::common;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class IComparable : public IToString
			{

			public:
				IComparable();
				virtual ~IComparable();

			private:
				virtual long getHash() const = 0;

			public:
				virtual string toString() override;

				bool esIgual( IComparable & obj );
				bool esIgual( IComparable * obj );

				bool operator== ( IComparable & obj );
				bool operator!= ( IComparable & obj );
				bool operator< ( IComparable & obj );
				bool operator> ( IComparable & obj );
				bool operator<= ( IComparable & obj );
				bool operator>= ( IComparable & obj );

			};

            }
		}
	}
}

#endif
