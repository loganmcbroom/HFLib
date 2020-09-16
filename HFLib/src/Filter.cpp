#include "HFLib/Filter.h"

using namespace HFLib;

static int mod( int a, int b )
	{
	return ( ( a % b ) + b ) % b;
	}

std::vector<size_t> mapSetup( std::vector<size_t> v )
	{
	v.pop_back();
	v.insert( v.begin(), 0 );
	return v;
	}

Filter::Filter( std::vector<size_t> v )
	: _modulus( v.back() )
	, map( mapSetup( std::move( v ) ) )
	{
	}


Filter::Filter( std::initializer_list<size_t> v )
	: Filter( std::vector<size_t>( v ) )
	{}

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

Filter Filter::rotate( int r ) const
	{
	r = mod( r, modulus() );

	if( r == 0 ) return *this;

	const size_t rJump = (*this)( r );
	std::vector<size_t> newMap( map.size() );
	for( int i = 0; i < newMap.size(); ++i )
		newMap[i] = (*this)( i + 1 + r ) - rJump;

	return Filter( newMap );
	}