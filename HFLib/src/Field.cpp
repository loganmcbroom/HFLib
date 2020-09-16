#include "HFLib/Field.h"

#include <cmath>
#include <cassert>

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

Field Field::filter( const Filter & f ) const
	{
	assert( f.modulus() == modulus() );

	std::vector<double> newMultipliers( f.period() );
	for( int i = 0; i < newMultipliers.size(); ++i )
		newMultipliers[i] = multiplier( f( i ) );

	return Field( newMultipliers, fundamental );
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

static Field nTet( size_t n, double fundamental )
	{
	const double r = pow( 2, 1.0 / double( n ) );
	std::vector<double> multipliers( n );
	for( int i = 0; i < n; ++i )
		multipliers[i] = std::pow( r, double( i ) );
	return Field( multipliers, fundamental );
	}

const Field Field::Chromatic = nTet( 12 );
const Field Field::Lydian	  = Field::Chromatic.filter( { 2, 4, 6, 7, 9, 11, 12 } );
const Field Field::Ionian	  = Field::Chromatic.filter( { 2, 4, 5, 7, 9, 11, 12 } );
const Field Field::Myxolydian = Field::Chromatic.filter( { 2, 4, 5, 7, 9, 10, 12 } );
const Field Field::Dorian	  = Field::Chromatic.filter( { 2, 3, 5, 7, 9, 10, 12 } );
const Field Field::Aeolian	  = Field::Chromatic.filter( { 2, 3, 5, 7, 8, 10, 12 } );
const Field Field::Phrygian	  = Field::Chromatic.filter( { 1, 3, 5, 7, 8, 10, 12 } );
const Field Field::Locrian	  = Field::Chromatic.filter( { 1, 3, 5, 6, 8, 10, 12 } );