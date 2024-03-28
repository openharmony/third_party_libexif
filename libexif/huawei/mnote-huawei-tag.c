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

#include <config.h>
#include "mnote-huawei-tag.h"

#include <stdlib.h>

#include <libexif/i18n.h>


static const struct {
	MnoteHuaweiTag tag;
	const char *name;
	const char *title;
	const char *description;
	MnoteHuaweiTagType TagType;
} table[] = {
	{MNOTE_HUAWEI_SCENE_INFO, "HwMnoteScenePointer", N_("Scene Info"), "SceneInfo", MNOTE_HUAWEI_TAG_TYPE_IFD},
	{MNOTE_HUAWEI_SCENE_VERSION, "HwMnoteSceneVersion", N_("Scene Version"), "SceneVersion"},
	{MNOTE_HUAWEI_SCENE_FOOD_CONF, "HwMnoteSceneFoodConf", N_("Food Conf"), "FoodConf"},
	{MNOTE_HUAWEI_SCENE_STAGE_CONF, "HwMnoteSceneStageConf", N_("Stage Conf"), "StageConf"},
	{MNOTE_HUAWEI_SCENE_BLUESKY_CONF, "HwMnoteSceneBlueSkyConf", N_("Blue Sky Conf"), "BlueSkyConf"},
	{MNOTE_HUAWEI_SCENE_GREENPLANT_CONF, "HwMnoteSceneGreenPlantConf", N_("GreenPlant Conf"), "GreenPlantConf"},
	{MNOTE_HUAWEI_SCENE_BEACH_CONF, "HwMnoteSceneBeachConf", N_("Beach Conf"), "BeachConf"},
	{MNOTE_HUAWEI_SCENE_SNOW_CONF, "HwMnoteSceneSnowConf", N_("Snow Conf"), "SnowConf"},
	{MNOTE_HUAWEI_SCENE_SUNSET_CONF, "HwMnoteSceneSunsetConf", N_("Sunset Conf"), "SunsetConf"},
	{MNOTE_HUAWEI_SCENE_FLOWERS_CONF, "HwMnoteSceneFlowersConf", N_("Flowers Conf"), "FlowersConf"},
	{MNOTE_HUAWEI_SCENE_NIGHT_CONF, "HwMnoteSceneNightConf", N_("Night Conf"), "NightConf"},
	{MNOTE_HUAWEI_SCENE_TEXT_CONF, "HwMnoteSceneTextConf", N_("Text Conf"), "TextConf"},

	{MNOTE_HUAWEI_FACE_INFO, "HwMnoteFacePointer", N_("Face Info"), "FaceInfo", MNOTE_HUAWEI_TAG_TYPE_IFD},
	{MNOTE_HUAWEI_FACE_VERSION, "HwMnoteFaceVersion", N_("Face Version"), "FaceVersion"},
	{MNOTE_HUAWEI_FACE_COUNT, "HwMnoteFaceCount", N_("Count"), "Count"},
	{MNOTE_HUAWEI_FACE_CONF, "HwMnoteFaceConf", N_("Conf"), "Conf"},
	{MNOTE_HUAWEI_FACE_SMILE_SCORE, "HwMnoteFaceSmileScore", N_("Smile Score"), "SmileScore"},
	{MNOTE_HUAWEI_FACE_RECT, "HwMnoteFaceRect", N_("Rect"), "Rect"},
	{MNOTE_HUAWEI_FACE_LEYE_CENTER, "HwMnoteFaceLeyeCenter", N_("LeyeCenter"), "LeyeCenter"},
	{MNOTE_HUAWEI_FACE_REYE_CENTER, "HwMnoteFaceReyeCenter", N_("Reye Center"), "ReyeCenter"},
	{MNOTE_HUAWEI_FACE_MOUTH_CENTER, "HwMnoteFaceMouthCenter", N_("Mouth Center"), "MouthCenter"},

	{MNOTE_HUAWEI_CAPTURE_MODE, "HwMnoteCaptureMode", N_("Capture Mode"), "CaptureMode"},
	{MNOTE_HUAWEI_BURST_NUMBER, "HwMnoteBurstNumber", N_("Burst Number"), "BurstNumber"},
	{MNOTE_HUAWEI_FRONT_CAMERA, "HwMnoteFrontCamera", N_("Front Camera"), "FrontCamera"},
	{MNOTE_HUAWEI_ROLL_ANGLE, "HwMnoteRollAngle", N_("Roll Angle"), "RollAngle"},
	{MNOTE_HUAWEI_PITCH_ANGLE, "HwMnotePitchAngle", N_("Pitch Angle"), "PitchAngle"},
	{MNOTE_HUAWEI_PHYSICAL_APERTURE, "HwMnotePhysicalAperture", N_("Physical Aperture"), "PhysicalAperture"},
	{MNOTE_HUAWEI_FOCUS_MODE, "HwMnoteFocusMode", N_("Focus Mode"), "FocusMode"},

	{0, "HwUnknow", N_("Unknow Tag"), "UnknowTag"},
};

#define GET_TAG_INFO(t, idx, ret) do {	\
									for (int i = 0; i < sizeof (table) / sizeof (table[0]); i++) { \
									    ret = table[i].idx;										 \
										if (table[i].tag == t) break;	 	 					 \
									} \
							   } while (0)													 
							   

const char *
mnote_huawei_tag_get_name (MnoteHuaweiTag t) 
{
	const char* p = NULL;
	GET_TAG_INFO(t, name, p);
	return p;
}

const char *
mnote_huawei_tag_get_title (MnoteHuaweiTag t) 
{
	const char* p = NULL;
	GET_TAG_INFO(t, title, p);
	return p;
}

const char *
mnote_huawei_tag_get_description (MnoteHuaweiTag t) 
{
	const char* p = NULL;
	GET_TAG_INFO(t, description, p);
	return p;
}

MnoteHuaweiTagType
mnote_huawei_tag_type (MnoteHuaweiTag t) 
{
	MnoteHuaweiTagType p = 0;
	GET_TAG_INFO(t, TagType, p);
	return p;
}
