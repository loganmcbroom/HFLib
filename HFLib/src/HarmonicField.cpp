#include "HFLib/HarmonicField.h"

#include <algorithm>

std::vector<int> harmonicsSetup( std::vector<int> v )
	{
	v.pop_back();
	v.insert( v.begin(), 0 );
	return v;
	}

HarmonicField::HarmonicField( std::vector<int> _harmonics )
	: modulus( _harmonics.back() )
	, harmonics( harmonicsSetup( std::move( _harmonics ) ) )
	{
	}

int HarmonicField::operator()( int i ) const
	{
	const int r = i % harmonics.size();
	const int q = ( i - r ) / harmonics.size();
	return q * modulus + harmonics[r];
	}

HarmonicField HarmonicField::operator()( const HarmonicField & h ) const
	{
	std::vector<int> newHarmonics( h.getNumHarmonics() * getNumHarmonics() );
	for( int i = 0; i < newHarmonics.size(); ++i )
		newHarmonics[i] = (*this)( h( i + 1 ) );
	return HarmonicField( newHarmonics );
	}

const HarmonicField HarmonicField::Lydian	 ( { 2, 4, 6, 7, 9, 11, 12 } );
const HarmonicField HarmonicField::Ionian	 ( { 2, 4, 5, 7, 9, 11, 12 } );
const HarmonicField HarmonicField::Myxolydian( { 2, 4, 5, 7, 9, 10, 12 } );
const HarmonicField HarmonicField::Dorian	 ( { 2, 3, 5, 7, 9, 10, 12 } );
const HarmonicField HarmonicField::Aeolian	 ( { 2, 3, 5, 7, 8, 10, 12 } );
const HarmonicField HarmonicField::Phrygian	 ( { 1, 3, 5, 7, 8, 10, 12 } );
const HarmonicField HarmonicField::Locrian	 ( { 1, 3, 5, 6, 8, 10, 12 } );