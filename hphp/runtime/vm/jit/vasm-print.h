/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_JIT_VASM_PRINT_H_
#define incl_HPHP_JIT_VASM_PRINT_H_

#include "hphp/runtime/vm/jit/vasm-x64.h"

#include <vector>
#include <iostream>
#include <string>

namespace HPHP { namespace jit {

std::string show(x64::Vreg r);
std::string show(x64::Vptr p);
std::string show(const x64::Vunit& unit, const x64::Vinstr& inst);

// print a dot-compatible digraph of the blocks (without contents)
void printCfg(const x64::Vunit& unit, const jit::vector<Vlabel>& blocks);
void printCfg(std::ostream& out, const x64::Vunit& unit,
              const jit::vector<Vlabel>& blocks);

std::string show(const x64::Vunit& unit);

// Tracing level constants.
constexpr int kInitialVasmLevel = 1;
constexpr int kVasmImmsLevel = 2;
constexpr int kVasmRegAllocLevel = 3;
constexpr int kVasmJumpsLevel = 4;
constexpr int kVasmDCELevel = 4;

// Print the cfg digraph followed by a vasm code listing, if the trace level is
// above `level'.
void printUnit(int level,
               const std::string& caption,
               const x64::Vunit& unit);

// main, cold, frozen
extern const char* area_names[];

} }

#endif
