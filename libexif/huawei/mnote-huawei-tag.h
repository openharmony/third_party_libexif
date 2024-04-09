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

#ifndef LIBEXIF_MNOTE_HUAWEI_TAG_H
#define LIBEXIF_MNOTE_HUAWEI_TAG_H

#include <libexif/exif-data.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum _MnoteHuaweiTag {
	MNOTE_HUAWEI_INFO				= 0xFFFF,
	MNOTE_HUAWEI_CAPTURE_MODE		= 0x0200,
	MNOTE_HUAWEI_BURST_NUMBER		= 0x0201,
	MNOTE_HUAWEI_FRONT_CAMERA		= 0x0202,
	MNOTE_HUAWEI_ROLL_ANGLE			= 0x0203,
	MNOTE_HUAWEI_PITCH_ANGLE		= 0x0204,
	MNOTE_HUAWEI_PHYSICAL_APERTURE	= 0x0205,
	MNOTE_HUAWEI_FOCUS_MODE			= 0x020d,

	MNOTE_HUAWEI_SCENE_INFO			= 0x0000, /* subtree */
	MNOTE_HUAWEI_SCENE_VERSION		= 0x0001, 
	MNOTE_HUAWEI_SCENE_FOOD_CONF	= 0x0002, 
	MNOTE_HUAWEI_SCENE_STAGE_CONF	= 0x0003, 
	MNOTE_HUAWEI_SCENE_BLUESKY_CONF	= 0x0004, 
	MNOTE_HUAWEI_SCENE_GREENPLANT_CONF	= 0x0005, 
	MNOTE_HUAWEI_SCENE_BEACH_CONF	= 0x0006, 
	MNOTE_HUAWEI_SCENE_SNOW_CONF	= 0x0007, 
	MNOTE_HUAWEI_SCENE_SUNSET_CONF	= 0x0008, 
	MNOTE_HUAWEI_SCENE_FLOWERS_CONF	= 0x0009, 
	MNOTE_HUAWEI_SCENE_NIGHT_CONF	= 0x000a, 
	MNOTE_HUAWEI_SCENE_TEXT_CONF	= 0x000b, 

	MNOTE_HUAWEI_FACE_INFO			= 0x0100, /* subtree */
	MNOTE_HUAWEI_FACE_VERSION 		= 0x0101,
	MNOTE_HUAWEI_FACE_COUNT 		= 0x0102,
	MNOTE_HUAWEI_FACE_CONF 			= 0x0103,
	MNOTE_HUAWEI_FACE_SMILE_SCORE 	= 0x0104,
	MNOTE_HUAWEI_FACE_RECT		 	= 0x0105,
	MNOTE_HUAWEI_FACE_LEYE_CENTER 	= 0x0106,
	MNOTE_HUAWEI_FACE_REYE_CENTER 	= 0x0107,
	MNOTE_HUAWEI_FACE_MOUTH_CENTER 	= 0x0108,
};
typedef enum _MnoteHuaweiTag MnoteHuaweiTag;

enum _MnoteHuaweiTagType {
	MNOTE_HUAWEI_TAG_TYPE_UNKONW,
	MNOTE_HUAWEI_TAG_TYPE_TAG,
	MNOTE_HUAWEI_TAG_TYPE_IFD,
	MNOTE_HUAWEI_TAG_TYPE_STRUCT,
};
typedef enum _MnoteHuaweiTagType MnoteHuaweiTagType;

const char *mnote_huawei_tag_get_name        (MnoteHuaweiTag);
const char *mnote_huawei_tag_get_title       (MnoteHuaweiTag);
const char *mnote_huawei_tag_get_description (MnoteHuaweiTag);
MnoteHuaweiTagType mnote_huawei_tag_type     (MnoteHuaweiTag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !defined(LIBEXIF_MNOTE_HUAWEI_TAG_H) */
