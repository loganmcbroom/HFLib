#include <iostream>

#include "HFLib/HarmonicField.h"

void main()
	{
	HarmonicField a( { 4, 7 } );
	HarmonicField b( { 2, 3 } );
	HarmonicField c = HarmonicField::Ionian( b );

	for( int i = 0; i < 20; ++i )
		std::cout << c( i ) << ", ";
	}