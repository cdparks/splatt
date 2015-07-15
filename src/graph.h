#ifndef SPLATT_GRAPH_H
#define SPLATT_GRAPH_H

/******************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "base.h"
#include "ftensor.h"


/******************************************************************************
 * STRUCTURES
 *****************************************************************************/


/**
* @brief Different routines for determining vertex weights.
*/
typedef enum
{
  VTX_WT_NONE,      /** Unweighted vertices. */
  VTX_WT_FIB_NNZ    /** Weighted based on nnz in the fiber */
} hgraph_vwt_type;


/**
* @brief A structure representing a hypergraph.
*/
typedef struct
{
  idx_t nvtxs;    /** Number of vertices in the hypergraph. */
  idx_t nhedges;  /** Number of hyperedges in the hypergraph. */
  idx_t * vwts;   /** Array of vertex weights. NULL if unweighted. */
  idx_t * hewts;  /** Array of hyperedge weights. NULL if unweighted. */
  idx_t * eptr;   /** Array of length (nhedges+1) and marks start of hedges.
                      Indexes into 'eind'. */
  idx_t * eind;   /** Array containing all vertices that appear in hedges. */
} hgraph_t;


/******************************************************************************
 * PUBLIC FUNCTIONS
 *****************************************************************************/
hgraph_t * hgraph_fib_alloc(
  ftensor_t const * const ft,
  idx_t const mode);

void hgraph_free(
  hgraph_t * hg);

idx_t * hgraph_uncut(
  hgraph_t const * const hg,
  idx_t const * const parts,
  idx_t * const ncut);

#endif
