#include "HFLib/Filter.h"

using namespace HFLib;

std::vector<size_t> mapSetup( std::vector<size_t> v )
	{
	v.pop_back();
	v.insert( v.begin(), 0 );
	return v;
	}

Filter::Filter( std::vector<size_t> _harmonics )
	: _modulus( _harmonics.back() )
	, map( mapSetup( std::move( _harmonics ) ) )
	{
	}

size_t Filter::operator()( size_t i ) const
	{
	const int r = i % period();
	const int q = ( i - r ) / period();
	return q * modulus() + map[r];
	}

Filter Filter::operator()( const Filter & h ) const
	{
	std::vector<size_t> newHarmonics( h.period() * period() );
	for( int i = 0; i < newHarmonics.size(); ++i )
		newHarmonics[i] = (*this)( h( i + 1 ) );
	return Filter( newHarmonics );
	}