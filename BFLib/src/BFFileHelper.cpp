//---------------------------------------------------------------------------
// File:
//      BFFileHelper.cpp BFFileHelper.hpp
//
// Module:
//      CBFFileHelper
//
// History:
//		May. 7, 2002		Created by Benjamin Fung
//---------------------------------------------------------------------------

#include "BFPch.h"

#if !defined(BFFILEHELPER_H)
	#include "BFFileHelper.h"
#endif

//--------------------------------------------------------------------
//--------------------------------------------------------------------
CBFFileHelper::CBFFileHelper()
{
}

CBFFileHelper::~CBFFileHelper()
{
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
bool CBFFileHelper::removeFile(LPCTSTR filename)
{
    return _tremove(filename) == 0;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
void CBFFileHelper::splitPath(LPCTSTR fullPath, CString& drive, CString& dir, CString& fname, CString& ext)
{
    TCHAR tDrive[_MAX_DRIVE];
    TCHAR tDir[_MAX_DIR];
    TCHAR tFname[_MAX_FNAME];
    TCHAR tExt[_MAX_EXT];
    _tsplitpath_s(fullPath, tDrive, tDir, tFname, tExt);

    drive = tDrive;
    dir = tDir;
    fname = tFname;
    ext = tExt;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
bool CBFFileHelper::replaceExtension(LPCTSTR fname, LPCTSTR ext, CString& res)
{
    res = fname;
    int dotPos = res.ReverseFind(TCHAR('.'));
    if (dotPos == -1) {
        res.Empty();
        return false;
    }
    res = res.Left(dotPos + 1);
    res += ext;
    return true;
}