/* -*- mode: C; c-basic-offset: 4; -*- */
/* ex: set shiftwidth=4 tabstop=4 expandtab: */
/*
 * Copyright (c) 2015, Rice University
 * All rights reserved.
 *
 * Author(s): Neil T. Dantam <ntd@rice.edu>
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of copyright holder the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY HEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef AMINO_SCENEGRAPH_H
#define AMINO_SCENEGRAPH_H

/**
 *  Opaque type for a scene_graph
 */
struct aa_rx_sg;


/**
 *  Opaque type for a scene_graph frame
 */
struct aa_rx_sg_frame;

/**
 *  Construct a new scene graph
 */
struct aa_rx_sg *aa_rx_sg_create();

/**
 *  Destroy a scene graph
 */
AA_API void aa_rx_sg_destroy(struct aa_rx_sg *scene_graph);

/**
 *  Return the index of a frame in the scene graph
 */
AA_API size_t aa_rx_sg_index_frame(
    struct aa_rx_sg *scene_graph, const char *frame_name);

/**
 *  Return the index of a configuration variable in the scne graph
 */
AA_API size_t aa_rx_sg_config_index(
    struct aa_rx_sg *scene_graph, const char *config_name);

/**
 *  Add a fixed-transform frame to the scene graph
 */
AA_API void aa_rx_sg_add_frame_fixed
( struct aa_rx_sg *scene_graph,
  const char *parent, const char *name,
  const double q[4], const double v[3] );

/**
 *  Add a prismatic-joint frame to the scene graph
 */
AA_API void aa_rx_sg_add_frame_prismatic
( struct aa_rx_sg *scene_graph,
  const char *parent, const char *name,
  const double q[4], const double v[3],
  const char *config_name,
  const double axis[3], double offset );

/**
 *  Add a revolute-joint frame to the scene graph
 */
AA_API void aa_rx_sg_add_frame_revolute
( struct aa_rx_sg *scene_graph,
  const char *parent, const char *name,
  const double q[4], const double v[3],
  const char *config_name,
  const double axis[3], double offset );

/**
 *  Remove a frame
 */
AA_API void aa_rx_sg_rm_frame
( struct aa_rx_sg *scene_graph,
  const char *name );

/**
 *  Compute transforms for the scene graph
 */
AA_API void aa_rx_sg_tf
( struct aa_rx_sg *scene_graph,
  size_t n_q, double *q,
  size_t n_tf,
  double *TF_rel, size_t ld_rel,
  double *TF_abs, size_t ld_abs );

#endif /*AMINO_SCENEGRAPH_H*/
