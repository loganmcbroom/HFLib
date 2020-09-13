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

	public:
		static const HarmonicField Lydian;
		static const HarmonicField Ionian;
		static const HarmonicField Myxolydian;
		static const HarmonicField Dorian;
		static const HarmonicField Aeolian;
		static const HarmonicField Phrygian;
		static const HarmonicField Locrian;
	};