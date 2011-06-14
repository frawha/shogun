/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Heiko Strathmann
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#ifndef __SUBSET_H_
#define __SUBSET_H_

#include "lib/DataType.h"
#include <string.h>

namespace shogun
{

/** @brief class for adding subset support to a class. Provides an interface for
 * getting/setting subset_matrices and index conversion.
 *
 * Note that this class does not inherit from CSGObject.
 */
class Subset
{
public:
	Subset();
	virtual ~Subset();

	/** removes (and deletes) the current subset indices matrix */
	virtual void remove_subset();

	/** getter for the subset indices
	 *
	 * @param m_subset_idx (copy of) subset indices matrix (returned)
	 * @param m_subset_len (copy of) number ofsubset indices (returned)
	 */
	void get_subset(index_t** subset_idx, index_t* subset_len);

	/** getter for the subset indices
	 *
	 * @param m_subset_len reference to number of subset indices (returned)
	 * @return subset indices array
	 */
	virtual index_t* get_subset(index_t& subset_len)
	{
		subset_len=m_subset_len;
		return m_subset_idx;
	}

	/** sets the subset indices matrix which is afterwards used for feature access
	 * (no copy, matrix is used directly)
	 *
	 * @param m_subset_idx index matrix
	 * @param m_subset_len number of subset indices
	 */
	virtual void set_subset(index_t subset_len, index_t* subset_idx);

	/** sets the subset indices matrix which is afterwards used for feature access
	 * (a copy of the matrix is stored)
	 *
	 * @param m_subset_idx index matrix
	 * @param m_subset_len number of subset indices
	 */
	virtual void set_subset(index_t* subset_idx, index_t subset_len);

protected:
	/** returns the corresponding real index (in array) of a subset index
	 * (if there is a subset)
	 *
	 * @ return array index of the provided subset index
	 */
	inline index_t subset_idx_conversion(index_t idx)
	{
		return m_subset_idx ? m_subset_idx[idx] : idx;
	}

protected:
	/* subset indices */
	index_t* m_subset_idx;

	/* length of subset */
	index_t m_subset_len;
};

}
#endif /* __SUBSET_H_ */
