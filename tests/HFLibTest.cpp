#include <iostream>

#include "HFLib/Field.h"
#include "HFLib/Filter.h"

using namespace HFLib;

void main()
	{

	Filter a{ 2, 4, 5, 7, 9, 11, 12 };
	//HarmonicField b( { 2, 3 } );
	//HarmonicField c = HarmonicField::Ionian( b );

	for( int i = 0; i <= 7; ++i )
		std::cout << a.rotate( 1 )( i ) << ", ";
	}