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

#include "config.h"
#include "exif-mnote-data-huawei.h"
#include "mnote-huawei-entry.h"
#include "mnote-huawei-tag.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <libexif/exif-format.h>
#include <libexif/exif-utils.h>
#include <libexif/i18n.h>

char *
mnote_huawei_entry_get_value(MnoteHuaweiEntry *entry, char *v, unsigned int maxlen) 
{
    
    memset(v, 0, maxlen);
    int write_pos = 0;
    ExifLong data = 0;

    for(int i=0; i < entry->components && write_pos < maxlen; i++) {
      if (entry->format == EXIF_FORMAT_UNDEFINED) {
        data = (entry->data + i)[0];
      } else if (entry->format == EXIF_FORMAT_SLONG) {
        data = exif_get_slong(entry->data + i*4, entry->order);
      } else if (entry->format == EXIF_FORMAT_LONG) {
        data = exif_get_long(entry->data + i*4, entry->order);
      } else {
        snprintf(v, maxlen, _("unsupported data types: %d"), entry->format);
        return NULL;
      }

      write_pos += snprintf(v+write_pos, maxlen-write_pos, _("%d "), data);
    }
    
    *(v+write_pos-1) = 0;
    return v;
}

int
mnote_huawei_entry_set_value(MnoteHuaweiEntry *entry, const char *v, int strlen)
{
    unsigned char data[1024] = {0};
    int increment = 0, components = 0, components_size = 0, ret = 0;
    char *token = NULL, *pv = NULL;

    if (!entry || !v || entry->md) {
      ret = -1;
      goto FINISH;
    }
    ExifMnoteData* parent_md = (ExifMnoteData*)entry->parent_md;
    if (!parent_md) {
      ret = -1;
      goto FINISH;
    }

    if (entry->format == EXIF_FORMAT_UNDEFINED) {
      increment = 1;
    } else if (entry->format == EXIF_FORMAT_SLONG || EXIF_FORMAT_LONG) {
      increment = 4;
    } else {
      ret = -1;
      goto FINISH;
    }

    pv = exif_mem_alloc(parent_md->mem, strlen + 1);
    if (!pv) {
      ret = -1;
      goto FINISH;
    }
    *(pv+strlen) = 0;
    memcpy(pv, v, strlen);

    token = strtok(pv, " ");
    for (;token && components_size < sizeof(data);) {
      int value = atoi(token);
      int offset = increment * components;
      if (increment == 1) {
        if (value > 0xff || value < 0) {
          ret = -1;
          goto FINISH;
        }       
        *(data+offset) = value;
      } else {
         exif_set_slong((data+offset), entry->order, value);
      }
      components++;
      components_size = components * increment;
      token = strtok(NULL, " ");
    }

    if (!components || (entry->format != EXIF_FORMAT_UNDEFINED && components > 1)) {
      ret = -1;
      goto FINISH;
    }

    if (entry->size < components_size) {
      unsigned char* realloc = NULL;
      realloc = exif_mem_realloc(parent_md->mem, entry->data, components_size);
      if (!realloc) {
        ret = -1;
        goto FINISH;
      }
      entry->data = realloc;
      entry->size = components_size;
    }

    entry->components = components;
    memcpy(entry->data, data, components_size);

FINISH:
    if (pv) exif_mem_free(parent_md->mem, pv);
    return ret;
}