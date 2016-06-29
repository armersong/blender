/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) Blender Foundation
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): Lukas Toenne
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file DNA_strand_types.h
 *  \ingroup DNA
 */

#ifndef __DNA_STRAND_TYPES_H__
#define __DNA_STRAND_TYPES_H__

#include "DNA_defs.h"
#include "DNA_ID.h"
#include "DNA_meshdata_types.h"

typedef struct StrandVertex {
	/* Position */
	float co[3];
	int pad;
} StrandVertex;

typedef struct StrandCurve {
	/* Point on the scalp mesh for the root vertex */
	MeshSample root;
	/* Start of vertex list */
	unsigned int verts_begin;
	/* Number of vertices in the curve */
	unsigned int num_verts;
} StrandCurve;

#if 0
typedef struct StrandData {
	/* Array of vertices */
	StrandVertex *verts;
	/* Array of curves */
	StrandCurve *curves;
	
	/* Total number of vertices */
	int totverts;
	/* Total number of curves */
	int totcurves;
} StrandData;
#endif

typedef struct StrandInfo {
	/* Sample on the scalp mesh for the root vertex */
	MeshSample root;
	/* Indices of control strands for interpolation */
	unsigned int control_index[4];
	/* Weights of control strands for interpolation */
	float control_weights[4];
} StrandInfo;

typedef struct Strands {
	/* Array of vertices */
	StrandVertex *verts;
	/* Array of curves */
	StrandCurve *curves;
	
	/* Total number of vertices */
	int totverts;
	/* Total number of curves */
	int totcurves;
	
	struct GPUStrands *gpu_strands;
} Strands;

#endif
