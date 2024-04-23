/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <executorch/runtime/core/evalue.h>
#include <executorch/runtime/core/exec_aten/exec_aten.h>
#include <executorch/runtime/kernel/operator_registry.h>
#include <executorch/runtime/platform/profiler.h>
#include "${fn_header}" // Generated Function import headers
// ${generated_comment}

// NOTE [Sharded File]: This file is generated in a sharded fashion to speed up
// incremental rebuilds. See the comment at the top of
// templates/VariableType.cpp for an analogous, in-depth discussion.
//
// Generated by tools/jit/gen_unboxing.py. This file registers all ATen ops into
// JIT op registry instead of c10 dispatcher. JIT op registry only takes boxed
// kernels, so we are calling unboxing functions in UnboxingFunctions.h to cast
// arguments into C++ types (instead of IValue) and delegate to unboxed kernels.
using KernelArrayRef = ::torch::executor::ArrayRef<::torch::executor::Kernel>;
namespace torch {
namespace executor {
namespace function {
namespace {

static Kernel kernels_to_register[] = {
    ${unboxed_kernels} // Generated kernels
};

// Explicitly convert to ArrayRef, so that the API can take an empty C array of
// Kernels.
static KernelArrayRef kernel_array_ref(
    kernels_to_register,
    kernels_to_register + sizeof(kernels_to_register) / sizeof(Kernel));

// Return value not used. Keep the static variable assignment to register
// kernels in static initialization time.
static auto success_with_kernel_reg = register_kernels(kernel_array_ref);
} // namespace
} // namespace function
} // namespace executor
} // namespace torch