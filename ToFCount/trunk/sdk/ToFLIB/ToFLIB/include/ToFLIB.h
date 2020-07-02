#pragma once

#ifndef ToFLIB_EXPORTS
#define ToFLIB_API __declspec(dllexport)
#else
#define ToFLIB_API __declspec(dllimport)
#endif

#define NEARMODE	1
#define FARMODE		2

#define IRVIEW		1
#define DEPTHVIEW	2
#define BOTHVIEW	3

#define STOP		0

ToFLIB_API unsigned char* uGetBuffer(int iMode, int iView);
/*
 *************************************************************************
 *
 * @brief: Capturing Camera Buffers;
 *
 * @param[in]		(iMode)		NEARMODE FARMODE or STOP;
 * @param[in]		(iView)		IRVIEW DEPTHVIEW BOTHVIEW or STOP;
 * @param[out]		(p)			if any param is STOP or NOT the following parameter, return NULL; else return the camera buffers.
 *
 *************************************************************************
 */