/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "grpc/_adapter/_c/types.h"

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <grpc/grpc.h>

int pygrpc_module_add_types(PyObject *module) {
  int i;
  PyTypeObject *types[] = {
      &pygrpc_ClientCredentials_type,
      &pygrpc_ServerCredentials_type,
      &pygrpc_CompletionQueue_type,
      &pygrpc_Call_type,
      &pygrpc_Channel_type,
      &pygrpc_Server_type
  };
  for (i = 0; i < sizeof(types)/sizeof(PyTypeObject *); ++i) {
    if (PyType_Ready(types[i]) < 0) {
      return -1;
    }
  }
  for (i = 0; i < sizeof(types)/sizeof(PyTypeObject *); ++i) {
    Py_INCREF(types[i]);
    PyModule_AddObject(module, types[i]->tp_name, (PyObject *)types[i]);
  }
  return 0;
}
