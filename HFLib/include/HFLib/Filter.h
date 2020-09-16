#pragma once

#include <vector>

namespace HFLib
{

/**
 *	A Filter is a function from N into N, equipped with a "modulus", and a "period".
 *	 Given a modulus m, a period p and letting f be the map, f must obey f(n+p) = f(n) + m.
 */

class Filter
	{
	public:
		Filter( std::vector<size_t> v );

		/** Evaluate the filter as a function */
		size_t operator()( size_t i ) const;

		/** Function composition */
		Filter operator()( const Filter & ) const;

		/** The modulus of the function  */
		size_t modulus() const { return _modulus; }

		/** The period of the function */
		size_t period() const { return map.size(); }

	private:
		const size_t _modulus;
		const std::vector<size_t> map;
	};

};