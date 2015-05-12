;;;; -*- Lisp -*-
;;;;
;;;; Copyright (c) 2015, Rice University
;;;; All rights reserved.
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

;; (cl:eval-when (:load-toplevel :execute)
;;     (asdf:operate 'asdf:load-op 'cffi-grovel))

(asdf:defsystem robray
  :depends-on ("amino" "sycamore" "cl-ppcre" "cxml")
  :components ((:file "robray-package")
               (:file "util" :depends-on ("robray-package"))
               (:file "parameters" :depends-on ("robray-package"))
               (:file "povray" :depends-on ("util" "parameters" "robray-package"))
               (:file "collada" :depends-on ("util" "povray"))
               (:file "scenegraph" :depends-on ("util" "povray" "collada"))
               (:file "scenefile/urdf" :depends-on ("util" "povray" "collada" "scenegraph"))
               (:file "scenefile/curly" :depends-on ("scenegraph"))
               (:file "scenefile/moveit" :depends-on ("scenegraph"))
               (:file "animate" :depends-on ("scenegraph" "povray"))
               (:file "draw" :depends-on ("scenegraph"))
               ))
