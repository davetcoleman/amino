;;;; -*- Lisp -*-
;;;;
;;;; Copyright (c) 2009-2011, Georgia Tech Research Corporation
;;;; All rights reserved.
;;;;
;;;; Author(s): Neil T. Dantam <ntd@gatech.edu>
;;;; Georgia Tech Humanoid Robotics Lab
;;;; Under Direction of Prof. Mike Stilman
;;;;
;;;;
;;;; This file is provided under the following "BSD-style" License:
;;;;
;;;;
;;;;   Redistribution and use in source and binary forms, with or
;;;;   without modification, are permitted provided that the following
;;;;   conditions are met:
;;;;
;;;;   * Redistributions of source code must retain the above copyright
;;;;     notice, this list of conditions and the following disclaimer.
;;;;
;;;;   * Redistributions in binary form must reproduce the above
;;;;     copyright notice, this list of conditions and the following
;;;;     disclaimer in the documentation and/or other materials provided
;;;;     with the distribution.
;;;;
;;;;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
;;;;   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
;;;;   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
;;;;   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;;;;   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
;;;;   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;;;;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;;;;   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
;;;;   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
;;;;   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
;;;;   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
;;;;   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;;;;   POSSIBILITY OF SUCH DAMAGE.

(cl:eval-when (:load-toplevel :execute)
    (asdf:operate 'asdf:load-op 'cffi-grovel))

(asdf:defsystem amino
  :description "Basic utilities / numerics"
  :depends-on ("cffi")
  :components ((:file "package")
               ;; FFI
               (cffi-grovel:grovel-file "grovel" :depends-on ("package"))
               (:file "ffi" :depends-on ("grovel"))
               ;; LA
               (:file "type" :depends-on ("package"))
               (:file "foreign" :depends-on ("type" "ffi"))
               (:file "blas" :depends-on ("foreign"))
               (:file "libc" :depends-on ("foreign"))
               (:file "amino-la" :depends-on ("foreign"))
               (:file "op" :depends-on ("package"))
               (:file "generic" :depends-on ("op" "tf-type"))
               (:file "blas-generic" :depends-on ("generic" "blas"))
               (:file "mem" :depends-on ("foreign"))
               (:file "io" :depends-on ("mem"))
               ;; TF
               (:file "tf-type" :depends-on ("foreign"))
               (:file "tf" :depends-on ("tf-type"))
               (:file "tf-op" :depends-on ("tf" "generic"))
               ))
