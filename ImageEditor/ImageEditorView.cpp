// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"
#include "ImageEditorView.h"
#include "ImageEditorColorPanel.h"
#include "ImageEditorLineWidth.h"
#include "cv.h"
#include "highgui.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView

IMPLEMENT_DYNCREATE(CImageEditorView, CView)

BEGIN_MESSAGE_MAP(CImageEditorView, CView)
//{{AFX_MSG_MAP(CImageEditorView)
ON_COMMAND(ID_Pencil, OnPencil)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_COMMAND(ID_Select_Color, OnSelectColor)
ON_COMMAND(ID_FILE_NEW, OnCreateNewFile)
ON_COMMAND(LINE_STYLE_SOLID, OnStyleSolid)
ON_COMMAND(LINE_STYLE_DASH, OnStyleDash)
ON_COMMAND(LINE_STYLE_DOT, OnStyleDot)
ON_COMMAND(LINE_STYLE_DASHDOT, OnStyleDashdot)
ON_COMMAND(LINE_STYLE_DASHDOTDOT, OnStyleDashdotdot)
ON_COMMAND(ID_MENUITEM32820, OnGetLineWidth)
ON_COMMAND(ID_Curve, OnCurve)
ON_COMMAND(ID_Text, OnText)
ON_COMMAND(ID_Line, OnLine)
ON_COMMAND(ID_Rectangle, OnRectangle)
ON_COMMAND(ID_Outlined_Rectangle, OnOutlinedRectangle)
ON_COMMAND(ID_Filled_Rectangle, OnFilledRectangle)
ON_COMMAND(ID_Round_Rectangle, OnRoundRectangle)
ON_COMMAND(ID_Outlined_Round_Rectangle, OnOutlinedRoundRectangle)
ON_COMMAND(ID_Filled_Round_Rectangle, OnFilledRoundRectangle)
ON_COMMAND(ID_Ellipse, OnEllipse)
ON_COMMAND(ID_Outlined_Ellipse, OnOutlinedEllipse)
ON_COMMAND(ID_Filled_Ellipse, OnFilledEllipse)
ON_COMMAND(ID_Gaussian_Filter, OnGaussianFilter)
ON_COMMAND(ID_IMG_ROTATE, OnImgFlipRotate)
ON_COMMAND(ID_IMG_INVERSE, OnInvertColor)
	ON_COMMAND(ID_IMG_Grey, OnIMGColororGrey)
	ON_COMMAND(ID_IMG_CLEAR, OnClear)
	ON_COMMAND(ID_IMG_STRETCH, OnImgZoom)
	ON_COMMAND(ID_MENUITEM32828, OnMoveImage)
	//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView construction/destruction

CImageEditorView::CImageEditorView()
{
	m_type = 1;
	LBtnDn = false;
	ImgHeight = 500;
	ImgWidth = 500;
	LineStyle = 0;
	GaussianFilter = false;
	invertColor = false;
	doFlipRotate = false;
	doGrey = false;
	createNewFile.ResetMap = true;
	clearImg = false;
	doZoom = false;
	moveImg = false;
	// TODO: add construction code here
}

CImageEditorView::~CImageEditorView()
{
}

BOOL CImageEditorView::PreCreateWindow(CREATESTRUCT &cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView drawing

void CImageEditorView::OnDraw(CDC *pDC)
{

	CImageEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect rc_size;
	GetClientRect(&rc_size);
	/////////doZoom//////////////////////////////
	if(moveImg == true)
	{
		moveImg = false;
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		int x_dist = tgtPoint.x - point.x;
		int y_dist = tgtPoint.y - point.y;
		//MessageBox("grey1!");
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		//MessageBox("grey2!");

		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数

		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			// nChannels = 1;//bmp.bmBitsPixel / 8;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels);   //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					   //创建缓冲区

		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				   //将位图信息复制到缓冲区

		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			   //将缓冲区信息复制给IplImage
		IplImage *dstImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, 1); //创建图像
		if (pImg != NULL)
		{
			cvSaveImage("tmp.bmp", pImg);
			IplImage *tImg = cvLoadImage("tmp.bmp",1);// CV_LOAD_IMAGE_GRAYSCALE);
			CImage tmpImg;
			// tmpImg.Create(ImgWidth, ImgHeight, 24);
			tmpImg.CopyOf(tImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			if(x_dist>0 && y_dist>0)
				pDC->FillSolidRect(0, 0,ImgWidth+x_dist,  ImgHeight+y_dist, RGB(255, 255, 255));
			CRect rect(x_dist, y_dist, ImgWidth+x_dist, ImgHeight+y_dist);
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
			//MessageBox("successful!");

			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}


		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}
	if(doZoom == true)
	{
		doZoom = false;
		//MessageBox("grey1!");
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		//MessageBox("grey2!");

		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数

		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			// nChannels = 1;//bmp.bmBitsPixel / 8;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels);   //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					   //创建缓冲区

		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				   //将位图信息复制到缓冲区

		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			   //将缓冲区信息复制给IplImage
		if (pImg != NULL)
		{	// cvCvtColor(pImg,dstImg,CV_BGR2GRAY);
			// MessageBox("grey!");

			//MessageBox(zoom.m_Zoom_Horizontal+" " + zoom.m_Zoom_Vertical);
			CvSize sz;
			double scaleX = 0.01*static_cast<double>(atoi(zoom.m_Zoom_Horizontal));
			double scaleY = 0.01*static_cast<double>(atoi(zoom.m_Zoom_Vertical));
			sz.width = ImgWidth * scaleX;
			sz.height = ImgHeight * scaleY;

			IplImage *dstImg = cvCreateImage(sz, depth, nChannels); //创建图像
			//int a = bmp.bmWidth*atoi(zoom.m_Zoom_Horizontal)*0.01;
			//int b = bmp.bmWidth;
			//CString ms;
			//ms.Format("%d",b);
			//MessageBox(ms);

			cvResize(pImg,dstImg,CV_INTER_AREA);
			cvSaveImage("tmp.bmp", dstImg);
			//MessageBox("saved");
			dstImg = cvLoadImage("tmp.bmp",1);// CV_LOAD_IMAGE_GRAYSCALE);
			CImage tmpImg;
			// tmpImg.Create(ImgWidth, ImgHeight, 24);
			tmpImg.CopyOf(dstImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			ImgHeight = tmpImg.Height();
			ImgWidth = tmpImg.Width();
			CRect rect(0, 0, tmpImg.Width(), tmpImg.Height());
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
			//MessageBox("successful!");

			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}


		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}

	/////////doGrey//////////////////////////////
	if(doGrey == true)
	{
		doGrey = false;
		//MessageBox("grey1!");
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		//MessageBox("grey2!");

		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数

		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			// nChannels = 1;//bmp.bmBitsPixel / 8;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels);   //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					   //创建缓冲区

		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				   //将位图信息复制到缓冲区

		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			   //将缓冲区信息复制给IplImage
		IplImage *dstImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, 1); //创建图像
		if (pImg != NULL)
		{
			cvCvtColor(pImg,dstImg,CV_BGR2GRAY);
			//MessageBox("grey!");
			//cvNot(pImg, dstImg);
			// vSmooth(pImg, dstImg, CV_GAUSSIAN, 3, 3, 0, 0);
			cvSaveImage("tmp.bmp", dstImg);

			IplImage *tImg = cvLoadImage("tmp.bmp",1);// CV_LOAD_IMAGE_GRAYSCALE);
			CImage tmpImg;
			// tmpImg.Create(ImgWidth, ImgHeight, 24);
			tmpImg.CopyOf(tImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			CRect rect(0, 0, ImgWidth, ImgHeight);
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
			//MessageBox("successful!");

			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}


		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}
	//////////invert color///////////////////////
	if (invertColor == true)
	{
		// CImage tmpImg;
		// tmpImg.Create(ImgWidth, ImgHeight, 24);
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数
		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels);   //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					   //创建缓冲区
		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				   //将位图信息复制到缓冲区
		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			   //将缓冲区信息复制给IplImage
		IplImage *dstImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels); //创建图像
		if (pImg != NULL)
		{
			cvNot(pImg, dstImg);
			// cvSmooth(pImg, dstImg, CV_GAUSSIAN, 3, 3, 0, 0);
			cvSaveImage("tmp.bmp", dstImg);
			dstImg = cvLoadImage("tmp.bmp", 1);
			CImage tmpImg;
			// tmpImg.Create(ImgWidth, ImgHeight, 24);
			tmpImg.CopyOf(dstImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			CRect rect(0, 0, ImgWidth, ImgHeight);
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
			//MessageBox("successful!");

			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}
		invertColor = false;

		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}
	//////////Flip and Rotate////////////////////
	if (doFlipRotate == true)
	{
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数
		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels);   //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					   //创建缓冲区
		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				   //将位图信息复制到缓冲区
		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			   //将缓冲区信息复制给IplImage
		IplImage *dstImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels); //创建图像
		if (pImg != NULL)
		{
			if (flipRotate.m_Flip_Type == 0)
			{
				cvFlip(pImg, NULL, 1);
			}
			else if (flipRotate.m_Flip_Type == 1)
			{
				cvFlip(pImg, NULL, 0);
			}
			else
			{
				if (flipRotate.m_Rotate_Type == 0)
				{
					cvTranspose(pImg, dstImg);
					pImg = dstImg;
					cvFlip(pImg, NULL, 1);
				}
				else if (flipRotate.m_Rotate_Type == 1)
				{
					cvFlip(pImg, NULL, 1);
					cvFlip(pImg, NULL, 0);
				}
				else if (flipRotate.m_Rotate_Type == 2)
				{
					cvTranspose(pImg, dstImg);
					pImg = dstImg;
					cvFlip(pImg, NULL, 0);
				}
			}
			cvSaveImage("tmp.bmp", pImg);
			dstImg = cvLoadImage("tmp.bmp", 1);
			CImage tmpImg;
			tmpImg.CopyOf(dstImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			CRect rect(0, 0, ImgWidth, ImgHeight);
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
		}
		else
		{
			MessageBox("alert!");
		}
		doFlipRotate = false;
	}
	/////////Gaussian Smooth/////////////////////
	if (GaussianFilter == true)
	{
		// CImage tmpImg;
		// tmpImg.Create(ImgWidth, ImgHeight, 24);
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数
		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels); //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					 //创建缓冲区
		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				 //将位图信息复制到缓冲区
		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			 //将缓冲区信息复制给IplImage
		//convert bitmap to cimage
		// HBITMAP hbmp = (HBITMAP)bm.GetSafeHandle();
		// if (!tmpImg.IsNull()) //make sure tmpImg is null
		// 	tmpImg.Destroy();
		// tmpImg.Attach(hbmp);
		// pDoc->pImg = tmpImg.GetImage();

		// DIBSECTION ds;
		// bm.GetObject(hbmp, sizeof(CBitmap), &bm);
		// IplImage *pImage = cvCreateImage(cvSize(bm.bmWidth, bm.bmHeight), 8, bm.biBitCount / 8);
		// memcpy(pImage->imageData, ds.dsBm.bmBits, pImage->imageSize);
		IplImage *dstImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels); //创建图像
		if (pImg != NULL)
		{
			//			cvSaveImage("1.bmp", pImg);
			//cvFlip(pImg);
			cvSmooth(pImg, dstImg, CV_GAUSSIAN, 3, 3, 0, 0);
			cvSaveImage("tmp.bmp", dstImg);
			dstImg = cvLoadImage("tmp.bmp", 1);
			CImage tmpImg;
			// tmpImg.Create(ImgWidth, ImgHeight, 24);
			tmpImg.CopyOf(dstImg);
			pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
			CRect rect(0, 0, ImgWidth, ImgHeight);
			tmpImg.DrawToHDC(pDC->GetSafeHdc(), &rect);
			//MessageBox("successful!");

			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}
		GaussianFilter = false;

		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}
	//////////////new image/////////////////////

	//////////////open image from...////////////
	if (pDoc->openImg == true)
	{
		CImage &img = pDoc->m_img;
		HDC hDC = pDC->GetSafeHdc();
		pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
		CRect rect(0, 0, img.Width(), img.Height());
		img.DrawToHDC(hDC, &rect);
		ImgHeight = (img.Height() < rc_size.right) ? img.Height() : rc_size.right;
		ImgWidth = (img.Width() < rc_size.right) ? img.Width() : rc_size.right;
		pDoc->openImg = false;
	}
	if (pDoc->saveImg == true)
	{
		// CImage tmpImg;
		// tmpImg.Create(ImgWidth, ImgHeight, 24);
		CDC tmpDC;
		tmpDC.CreateCompatibleDC(pDC);
		CBitmap Bm;
		Bm.CreateCompatibleBitmap(pDC, ImgWidth, ImgHeight);
		tmpDC.SelectObject(&Bm);
		tmpDC.StretchBlt(0, 0, ImgWidth, ImgHeight, pDC, 0, 0, ImgWidth, ImgHeight, SRCCOPY);
		HBITMAP hBmp = HBITMAP(Bm);
		BITMAP bmp;
		Bm.GetBitmap(&bmp); //获得位图信息
		int depth, nChannels;
		if (bmp.bmBitsPixel == 1) //得到图像深度和通道数
		{
			depth = IPL_DEPTH_1U;
			nChannels = 1;
		}
		else
		{
			depth = IPL_DEPTH_8U;
			nChannels = bmp.bmBitsPixel / 8;
		}
		IplImage *pImg = cvCreateImage(cvSize(bmp.bmWidth, bmp.bmHeight), depth, nChannels); //创建图像
		BYTE *pBuffer = new BYTE[bmp.bmHeight * bmp.bmWidth * nChannels];					 //创建缓冲区
		GetBitmapBits(hBmp, bmp.bmHeight * bmp.bmWidth * nChannels, pBuffer);				 //将位图信息复制到缓冲区
		memcpy(pImg->imageData, pBuffer, bmp.bmHeight * bmp.bmWidth * nChannels);			 //将缓冲区信息复制给IplImage
		//convert bitmap to cimage
		// HBITMAP hbmp = (HBITMAP)bm.GetSafeHandle();
		// if (!tmpImg.IsNull()) //make sure tmpImg is null
		// 	tmpImg.Destroy();
		// tmpImg.Attach(hbmp);
		// pDoc->pImg = tmpImg.GetImage();

		// DIBSECTION ds;
		// bm.GetObject(hbmp, sizeof(CBitmap), &bm);
		// IplImage *pImage = cvCreateImage(cvSize(bm.bmWidth, bm.bmHeight), 8, bm.biBitCount / 8);
		// memcpy(pImage->imageData, ds.dsBm.bmBits, pImage->imageSize);
		if (pImg != NULL)
		{
			MessageBox("successful!");
			//cvFlip(pImg);
			cvSaveImage(pDoc->getPathName, pImg);
			//cvFlip(pImg);
			//	cvReleaseImageheader(&pImage);
		}
		else
		{
			MessageBox("alert!");
		}
		pDoc->saveImg = false;
		// pDoc->m_img.Destroy();
		// tmpImg.Destroy();
		// cvReleaseImage(&pDoc->pImg);
	}
	///////set color//////////
	int red = atoi(colorPanel.m_Color_Red);
	int green = atoi(colorPanel.m_Color_Green);
	int blue = atoi(colorPanel.m_Color_Blue);
	int bg_red = atoi(colorPanel.m_BG_Color_Red);
	int bg_green = atoi(colorPanel.m_BG_Color_Green);
	int bg_blue = atoi(colorPanel.m_BG_Color_Blue);

	int bgcolor = RGB(bg_red, bg_green, bg_blue);
	int color = RGB(red, green, blue);

	///////double buffer//////
	// CDC MemDC;
	// MemDC.CreateCompatibleDC(pDC);

	// CBitmap oldBitmap;
	// oldBitmap.CreateCompatibleBitmap(pDC,rc_size.Width(),rc_size.Height());

	// MemDC.SelectObject(&oldBitmap);
	// MemDC.FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
	// MemDC.FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));

	///create new bitmap//////
	// if (createNewFile.ResetMap == true){
	// 	ImgHeight = (atoi(createNewFile.m_New_Img_Horizontal) < rc_size.right)?atoi(createNewFile.m_New_Img_Horizontal) : rc_size.right;
	// 	ImgWidth = (atoi(createNewFile.m_New_Img_Vertical) < rc_size.bottom)?atoi(createNewFile.m_New_Img_Vertical) : rc_size.bottom;

	// 	MemDC.FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
	// 	MemDC.FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));
	// 	createNewFile.ResetMap = false;
	// 	}
	if (clearImg == true){
		pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
		pDC->FillSolidRect(0, 0, ImgWidth, ImgHeight, bgcolor);
		clearImg = false;
	}
	if (createNewFile.ResetMap == true)
	{
		if (pDoc->newImg == false)
		{
			ImgHeight = (atoi(createNewFile.m_New_Img_Horizontal) < rc_size.right) ? atoi(createNewFile.m_New_Img_Horizontal) : rc_size.right;
			ImgWidth = (atoi(createNewFile.m_New_Img_Vertical) < rc_size.bottom) ? atoi(createNewFile.m_New_Img_Vertical) : rc_size.bottom;
		}
		pDC->FillSolidRect(0, 0, rc_size.right, rc_size.bottom, RGB(128, 128, 128));
		pDC->FillSolidRect(0, 0, ImgWidth, ImgHeight, bgcolor);
		createNewFile.ResetMap = false;
		pDoc->newImg = false;
	}

	///////set width//////////
	int width = getLineWidth.m_Line_Width;
	///////create pen/////////
	// CPen newPen(LineStyle,width,color);
	//////////////////////////
	////////pencil////////////
	if (m_type == 1)
	{
		CPen newPen(LineStyle, width, color);
		CPoint point = pDoc->m_Last_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(&newPen);
		// MemDC.SelectObject(&newPen);
		if (point.x <= ImgWidth && point.y <= ImgHeight && tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight)
		{
			pDC->MoveTo(point);
			pDC->LineTo(tgtPoint);
		}
		pDoc->m_Last_Position = pDoc->m_Current_Position;
		newPen.DeleteObject();
	}
	////////line/////////////
	else if (m_type == 2)
	{
		CPen newPen(LineStyle, width, color);
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(&newPen);
		// MemDC.SelectObject(&newPen);
		if (point.x <= ImgWidth && point.y <= ImgHeight && tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight)
		{
			pDC->MoveTo(point);
			pDC->LineTo(tgtPoint);
			newPen.DeleteObject();
		}
		pDoc->m_Last_Position = pDoc->m_Current_Position;
	}
	////////rectangle////////
	else if (m_type == 5)
	{
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		CPoint LDn(point.x, tgtPoint.y);
		CPoint RUp(tgtPoint.x, point.y);
		CPen newPen(LineStyle, width, color);
		pDC->SelectObject(&newPen);
		if (point.x <= ImgWidth && point.y <= ImgHeight && tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight)
		{
			pDC->MoveTo(point);
			pDC->LineTo(LDn);
			pDC->MoveTo(LDn);
			pDC->LineTo(tgtPoint);
			pDC->MoveTo(tgtPoint);
			pDC->LineTo(RUp);
			pDC->MoveTo(RUp);
			pDC->LineTo(point);
		}
		newPen.DeleteObject();
	}
	////outlined rectangle///
	else if (m_type == 6)
	{
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		CPoint LDn(point.x, tgtPoint.y);
		CPoint RUp(tgtPoint.x, point.y);
		CBrush newBrush(bgcolor);
		//MessageBox(bgcolor);
		pDC->SelectObject(&newBrush);
		CRect drawrc(point.x, point.y, tgtPoint.x, tgtPoint.y);
		pDC->FillRect(&drawrc, &newBrush);
		// pDC->Rectangle(point.x,point.y,tgtPoint.x,tgtPoint.y);
		newBrush.DeleteObject();
		CPen newPen(LineStyle, width, color);
		pDC->SelectObject(&newPen);
		if (point.x <= ImgWidth && point.y <= ImgHeight && tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight)
		{
			pDC->MoveTo(point);
			pDC->LineTo(LDn);
			pDC->MoveTo(LDn);
			pDC->LineTo(tgtPoint);
			pDC->MoveTo(tgtPoint);
			pDC->LineTo(RUp);
			pDC->MoveTo(RUp);
			pDC->LineTo(point);
		}
		newPen.DeleteObject();

		// CBrush newBrush;
		// newBrush.CreateSolidBrush(bgcolor);
		// pDC->Rectangle(point.x, point.y, tgtPoint.x, tgtPoint.y);
		// newBrush.DeleteObject();
	}
	else if (m_type == 7)
	{
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		CPoint LDn(point.x, tgtPoint.y);
		CPoint RUp(tgtPoint.x, point.y);

		CBrush newBrush(bgcolor);
		//MessageBox(bgcolor);
		pDC->SelectObject(&newBrush);
		CRect drawrc(point.x, point.y, tgtPoint.x, tgtPoint.y);
		pDC->FillRect(&drawrc, &newBrush);
		// pDC->Rectangle(point.x,point.y,tgtPoint.x,tgtPoint.y);
		newBrush.DeleteObject();

		// CPen newPen(LineStyle,width,bgcolor);
		// pDC->SelectObject(&newPen);
		// if(point.x <= ImgWidth && point.y <= ImgHeight &&tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight ){
		// 		pDC->MoveTo(point);
		// 		pDC->LineTo(LDn);
		// 		pDC->MoveTo(LDn);
		// 		pDC->LineTo(tgtPoint);
		// 		pDC->MoveTo(tgtPoint);
		// 		pDC->LineTo(RUp);
		// 		pDC->MoveTo(RUp);
		// 		pDC->LineTo(point);
		// }
		// newPen.DeleteObject();
	}
	else if (m_type == 8)
	{
		// CPen newPen(LineStyle, width, color);
		// CBrush rrcBrush(bgcolor);
		CBrush *rrcBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		// pDC->SelectObject(&newPen);
		pDC->SelectObject(rrcBrush);
		pDC->RoundRect(point.x, point.y, tgtPoint.x, tgtPoint.y, (tgtPoint.x - point.x) / 7, (tgtPoint.y - point.y) / 7);
		rrcBrush->DeleteObject();
	}
	else if (m_type == 9 || m_type == 10)
	{
		CBrush rrcBrush;
		rrcBrush.CreateSolidBrush(bgcolor);
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(rrcBrush);
		pDC->RoundRect(point.x, point.y, tgtPoint.x, tgtPoint.y, (tgtPoint.x - point.x) / 7, (tgtPoint.y - point.y) / 7);
		rrcBrush.DeleteObject();
		if (m_type == 10)
		{
			CPen rrcBrush2(PS_SOLID, 1, bgcolor);
			pDC->SelectObject(rrcBrush2);
			pDC->RoundRect(point.x, point.y, tgtPoint.x, tgtPoint.y, (tgtPoint.x - point.x) / 7, (tgtPoint.y - point.y) / 7);
			rrcBrush2.DeleteObject();
		}
	}
	else if (m_type == 11)
	{
		CBrush *rrcBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		// pDC->SelectObject(&newPen);
		pDC->SelectObject(rrcBrush);
		pDC->Ellipse(point.x, point.y, tgtPoint.x, tgtPoint.y);
		rrcBrush->DeleteObject();
	}
	else if (m_type == 12 || m_type == 13)
	{
		CBrush rrcBrush;
		rrcBrush.CreateSolidBrush(bgcolor);
		CPoint point = pDoc->m_Last_LBtnDn_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(rrcBrush);
		pDC->Ellipse(point.x, point.y, tgtPoint.x, tgtPoint.y);
		rrcBrush.DeleteObject();
		if (m_type == 13)
		{
			CPen rrcBrush2(PS_SOLID, 1, bgcolor);
			pDC->SelectObject(rrcBrush2);
			pDC->Ellipse(point.x, point.y, tgtPoint.x, tgtPoint.y);
			rrcBrush2.DeleteObject();
		}
	}

	// pDC->BitBlt(rc_size.left,rc_size.top,rc_size.Width(),rc_size.Height(),&MemDC,0,0,SRCCOPY);
	// oldBitmap.DeleteObject();
	// MemDC.DeleteDC();
	pDoc->m_Last_Position = pDoc->m_Current_Position;

	return;
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView printing

BOOL CImageEditorView::OnPreparePrinting(CPrintInfo *pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageEditorView::OnBeginPrinting(CDC * /*pDC*/, CPrintInfo * /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageEditorView::OnEndPrinting(CDC * /*pDC*/, CPrintInfo * /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView diagnostics

#ifdef _DEBUG
void CImageEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CImageEditorView::Dump(CDumpContext &dc) const
{
	CView::Dump(dc);
}

CImageEditorDoc *CImageEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageEditorDoc)));
	return (CImageEditorDoc *)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView message handlers

void CImageEditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	LBtnDn = true;
	CImageEditorDoc *pDoc = GetDocument();

	pDoc->m_Last_LBtnDn_Position = point;
	pDoc->m_Last_Position = point;
	// InvalidateRect(NULL,FALSE);

	CView::OnLButtonDown(nFlags, point);
}

void CImageEditorView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	LBtnDn = false;

	if (m_type == 2 || m_type >= 5 || moveImg)
	{
		CImageEditorDoc *pDoc = GetDocument();
		pDoc->m_Current_Position = point;
		InvalidateRect(NULL, FALSE);
	}
	CView::OnLButtonUp(nFlags, point);
}

void CImageEditorView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(doFlipRotate || invertColor ||GaussianFilter||doGrey || clearImg || doZoom)
		InvalidateRect(NULL, FALSE);
	if (m_type == 1 && !moveImg)
	{
		if (LBtnDn == true)
		{
			CImageEditorDoc *pDoc = GetDocument();
			pDoc->m_Current_Position = point;
			InvalidateRect(NULL, FALSE);
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CImageEditorView::OnSelectColor()
{
	// TODO: Add your command handler code here
	colorPanel.DoModal();
	//	CView::OnMouseMove(nFlags, point);
}

void CImageEditorView::OnCreateNewFile()
{
	// TODO: Add your command handler code here
	createNewFile.DoModal();
	if (createNewFile.ResetMap == true)
		InvalidateRect(NULL, FALSE);
}

void CImageEditorView::OnStyleSolid()
{
	// TODO: Add your command handler code here
	LineStyle = 0;
}

void CImageEditorView::OnStyleDash()
{
	// TODO: Add your command handler code here
	LineStyle = 1;
}

void CImageEditorView::OnStyleDot()
{
	// TODO: Add your command handler code here
	LineStyle = 2;
}

void CImageEditorView::OnStyleDashdot()
{
	// TODO: Add your command handler code here
	LineStyle = 3;
}

void CImageEditorView::OnStyleDashdotdot()
{
	// TODO: Add your command handler code here
	LineStyle = 4;
}

void CImageEditorView::OnGetLineWidth()
{
	// TODO: Add your command handler code here
	getLineWidth.DoModal();
}

void CImageEditorView::OnPencil()
{
	m_type = 1;
}

void CImageEditorView::OnLine()
{
	// TODO: Add your command handler code here
	m_type = 2;
}
void CImageEditorView::OnCurve()
{
	// TODO: Add your command handler code here
	m_type = 3;
}

void CImageEditorView::OnText()
{
	// TODO: Add your command handler code here
	m_type = 4;
}

void CImageEditorView::OnRectangle()
{
	// TODO: Add your command handler code here
	m_type = 5;
}

void CImageEditorView::OnOutlinedRectangle()
{
	// TODO: Add your command handler code here
	m_type = 6;
}

void CImageEditorView::OnFilledRectangle()
{
	// TODO: Add your command handler code here
	m_type = 7;
}

void CImageEditorView::OnRoundRectangle()
{
	// TDO: Add your command handler code here
	m_type = 8;
}

void CImageEditorView::OnOutlinedRoundRectangle()
{
	// TODO: Add your command handler code here
	m_type = 9;
}

void CImageEditorView::OnFilledRoundRectangle()
{
	// TODO: Add your command handler code here
	m_type = 10;
}

void CImageEditorView::OnEllipse()
{
	// TODO: Add your command handler code here
	m_type = 11;
}

void CImageEditorView::OnOutlinedEllipse()
{
	// TODO: Add your command handler code here
	m_type = 12;
}

void CImageEditorView::OnFilledEllipse()
{
	// TODO: Add your command handler code here
	m_type = 13;
}

void CImageEditorView::OnGaussianFilter()
{
	GaussianFilter = true;
}

void CImageEditorView::OnImgFlipRotate()
{
	// TODO: Add your command handler code here
	flipRotate.DoModal();
	doFlipRotate = true;
}

void CImageEditorView::OnInvertColor()
{
	// TODO: Add your command handler code here
	invertColor = true;
}

void CImageEditorView::OnIMGColororGrey() 
{
	doGrey = !doGrey;
	// TODO: Add your command handler code here
	
}

void CImageEditorView::OnClear() 
{
	clearImg = true;
	// TODO: Add your command handler code here
	
}

void CImageEditorView::OnImgZoom() 
{
	// TODO: Add your command handler code here
	zoom.DoModal();
	doZoom = true;
}

void CImageEditorView::OnMoveImage() 
{
	moveImg = true;	
}
