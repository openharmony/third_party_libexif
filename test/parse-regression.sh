#!/bin/sh
# Parses test EXIF files and compares the results to that expected
#
# Copyright (C) 2018-2021 Dan Fandrich <dan@coneharvesters.com>, et. al.
# SPDX-License-Identifier: LGPL-2.0-or-later

srcdir="${srcdir:-.}"
TMPLOG="$(mktemp)"
trap 'rm -f "${TMPLOG}"' 0
# Ensure that names are untranslated
LANG=
LANGUAGE=
LC_ALL=C
export LANG LANGUAGE LC_ALL
for fn in "${srcdir}"/testdata/*.jpg ; do
    ./test-parse "${fn}" > "${TMPLOG}"
    if ! diff "${fn}".parsed "${TMPLOG}"; then
        echo Error parsing "$fn"
        exit 1
    fi
done
