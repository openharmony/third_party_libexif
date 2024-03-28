/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBEXIF_MNOTE_HUAWEI_ENTRY_H
#define LIBEXIF_MNOTE_HUAWEI_ENTRY_H

#include <libexif/exif-format.h>
#include <libexif/exif-byte-order.h>
#include <libexif/huawei/mnote-huawei-tag.h>

typedef struct _MnoteHuaweiEntry        MnoteHuaweiEntry;

struct _MnoteHuaweiEntry {
	MnoteHuaweiTag tag;
	ExifFormat format;
	unsigned long components;

	unsigned char *data;
	unsigned int size;
	ExifByteOrder order;

	void *md;
	void *parent_md;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

char *mnote_huawei_entry_get_value (MnoteHuaweiEntry *entry, char *v, unsigned int maxlen);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !defined(LIBEXIF_MNOTE_HUAWEI_ENTRY_H) */
