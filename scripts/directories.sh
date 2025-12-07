#!/bin/sh
#
# -------------------------------------------------------------------------
#                                 AlthenosOS
#  (c) 2025-2026 littlefly365
#  This project is under the GPL v3 license.
#  You should receive the license with the source code. If not - check:
#  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
# -------------------------------------------------------------------------
#
BUILD_DIR=build
export BUILD_DIR

mkdir -p $BUILD_DIR/kernel
mkdir -p $BUILD_DIR/boot
mkdir -p $BUILD_DIR/bin
mkdir -p $BUILD_DIR/ksh
mkdir -p $BUILD_DIR/drivers
