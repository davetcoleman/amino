/* -*- mode: C; c-basic-offset: 4 -*- */
/* ex: set shiftwidth=4 tabstop=4 expandtab: */
/*
 * Copyright (c) 2011, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Neil T. Dantam <ntd@gatech.edu>
 * Georgia Tech Humanoid Robotics Lab
 * Under Direction of Prof. Mike Stilman <mstilman@cc.gatech.edu>
 *
 *
 * This file is provided under the following "BSD-style" License:
 *
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
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
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 */

AA_API int AA_CLAPACK_NAME(getrf)
( int m, int n, AA_LA_TYPE *A, int lda, int *ipiv );

AA_API int AA_CLAPACK_NAME(getri)
( int n, AA_LA_TYPE *A, int lda, int *ipiv, AA_LA_TYPE *work, int lwork );

AA_API int AA_CLAPACK_NAME(gelsd_smlsiz)
();

AA_API int AA_CLAPACK_NAME(gelsd_nlvl)
( int m, int n );

AA_API int AA_CLAPACK_NAME(gelsd_miniwork)
( int m, int n );

AA_API int AA_CLAPACK_NAME(gelsd)
( int m, int n, int nrhs,
  AA_LA_TYPE *A, int lda,
  AA_LA_TYPE *B, int ldb,
  AA_LA_TYPE *S, AA_LA_TYPE *rcond, int *rank,
  AA_LA_TYPE *work, int lwork, int *iwork ) ;

static inline void AA_CLAPACK_NAME(lacpy)
( char uplo, int m, int n,
  const AA_LA_TYPE *A, int lda,
  AA_LA_TYPE *B, int ldb ) {
    AA_LAPACK_NAME(lacpy) (&uplo, &m, &n,
                           A, &lda, B, &ldb );

}

static inline AA_LA_TYPE AA_CLAPACK_NAME(lapy2)
( AA_LA_TYPE x, AA_LA_TYPE y )
{
    return AA_LAPACK_NAME(lapy2)(&x, &y);
}

static inline AA_LA_TYPE AA_CLAPACK_NAME(lapy3)
( AA_LA_TYPE x, AA_LA_TYPE y, AA_LA_TYPE z )
{
    return AA_LAPACK_NAME(lapy3)(&x, &y, &z);
}

static inline void AA_CLAPACK_NAME(laruv)
( int iseed[4], int n, AA_LA_TYPE *X )
{
    AA_LAPACK_NAME(laruv) (iseed, &n, X);
}

static inline void AA_CLAPACK_NAME(larnv)
( int idist, int iseed[4], int n, AA_LA_TYPE *X )
{
    AA_LAPACK_NAME(larnv) (&idist, iseed, &n, X);
}

static inline int AA_CLAPACK_NAME(lascl)
( char TYPE, int KL, int KU,
  AA_LA_TYPE CFROM, AA_LA_TYPE CTO,
  int M, int N, AA_LA_TYPE *A, int LDA ) {
    int info;
    AA_LAPACK_NAME( lascl )
        ( &TYPE, &KL, &KU, &CFROM, &CTO,
          &M, &N, A, &LDA, &info );
    return info;
}

#if AA_LA_TYPE == double
static inline int AA_CLAPACK_NAME(lag2s)
( int M, int N,
  double *A, int LDA,
  float *SA, int LDSA ) {
    int info;
    dlag2s_( &M, &N, A, &LDA, SA, &LDSA, &info);
    return info;
}

#endif // AA_LA_TYPE == double

#if AA_LA_TYPE == float
static inline int AA_CLAPACK_NAME(lag2d)
( int M, int N,
  float * SA, int LDSA,
  double *A, int LDA ) {
    int info;
    slag2d_( &M, &N, SA, &LDSA, A, &LDA, &info );
    return info;
}

#endif // AA_LA_TYPE == float


#undef AA_LA_TYPE
#undef AA_CLAPACK_NAME
#undef AA_LAPACK_NAME
#undef AA_CBLAS_NAME
#undef AA_CLAPACK_NAME