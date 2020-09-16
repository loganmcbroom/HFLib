#include <iostream>

#include "HFLib/Field.h"
#include "HFLib/Filter.h"

using namespace HFLib;

void main()
	{

	Filter a( { 4, 7 } );
	//HarmonicField b( { 2, 3 } );
	//HarmonicField c = HarmonicField::Ionian( b );

	for( int i = 0; i <= 7; ++i )
		std::cout << Field::Ionian( i ) << ", ";
	}