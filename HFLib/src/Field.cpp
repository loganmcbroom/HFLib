#include "HFLib/Field.h"

#include <cmath>

using namespace HFLib;

int mod( int a, int b )
	{
	return ( ( a % b ) + b ) % b;
	}

Field::Field( std::vector<double> _multipliers, double _fundamental )
	: multipliers( std::move( _multipliers ) )
	, fundamental( _fundamental )
	{
	}

double Field::operator()( int i ) const
	{
	return multiplier( i ) * fundamental;
	}

double Field::multiplier( int i ) const
	{
	const int note = mod( i, modulus() );
	const int octave = ( i - note ) / modulus();
	return std::pow( 2, octave ) * multipliers[note];
	}

size_t Field::modulus() const
	{
	return multipliers.size();
	}

static const double tet12 = pow( 2, 1.0 / 12.0 );
const Field Field::Chromatic(
	{ 
	std::pow( tet12, 0.0 ),
	std::pow( tet12, 1.0 ),
	std::pow( tet12, 2.0 ),
	std::pow( tet12, 3.0 ),
	std::pow( tet12, 4.0 ),
	std::pow( tet12, 5.0 ),
	std::pow( tet12, 6.0 ),
	std::pow( tet12, 7.0 ),
	std::pow( tet12, 8.0 ),
	std::pow( tet12, 9.0 ),
	std::pow( tet12, 10.0 ),
	std::pow( tet12, 11.0 ),
	});
//const Field Field::Lydian	 ( { 2, 4, 6, 7, 9, 11, 12 } );
//const Field Field::Ionian	 ( { 2, 4, 5, 7, 9, 11, 12 } );
//const Field Field::Myxolydian( { 2, 4, 5, 7, 9, 10, 12 } );
//const Field Field::Dorian	 ( { 2, 3, 5, 7, 9, 10, 12 } );
//const Field Field::Aeolian	 ( { 2, 3, 5, 7, 8, 10, 12 } );
//const Field Field::Phrygian	 ( { 1, 3, 5, 7, 8, 10, 12 } );
//const Field Field::Locrian	 ( { 1, 3, 5, 6, 8, 10, 12 } );