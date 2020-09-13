#pragma once

#include <vector>

class HarmonicField 
	{
	public:
		//input absolute harmonics, not intervals
		HarmonicField( std::vector<int> _harmonics );

		int operator()( int i ) const;
		HarmonicField operator()( const HarmonicField & h ) const;

		int getModulus() const { return modulus; }
		size_t getNumHarmonics() const { return harmonics.size(); }

	private:
		const int modulus;
		const std::vector<int> harmonics;	
	};