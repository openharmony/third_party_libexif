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
#include "mnote-huawei-entry.h"

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