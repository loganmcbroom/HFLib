#pragma once

#include <vector>

#include "HFLib/Filter.h"

namespace HFLib
{

/**
 *	A Field is a mapping from the integers into frequency
 *	 Fields, in this context, must repeat in each octave, and thus must have a set number of notes per octave.
 *	 This number is called the modulus of the Field.
 */

class Field 
	{
	public:
		/** Rather than passing frequencies directly, we pass in multipliers of the fundamental frequency.
		 *	 E.g. passing {1.0, 1.5} gives a field of roots and perfect fifths.
		 */
		Field( std::vector<double> multipliers, double fundamental = 440.0 );

		double operator()( int i ) const;

		Field filter( const Filter & ) const;

		double multiplier( int i ) const;

		size_t modulus() const;

	private:
		const std::vector<double> multipliers;	
		const double fundamental;

	public:
		/** Generates an n-tone equal temperment field */
		static Field nTet( size_t n, double fundamental = 440.0 );

		static const Field Chromatic;

		static const Field Lydian;
		static const Field Ionian;
		static const Field Myxolydian;
		static const Field Dorian;
		static const Field Aeolian;
		static const Field Phrygian;
		static const Field Locrian;
	};

};