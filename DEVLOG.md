# **Dev Log**

> ## 2017-9-7
> ### Progress:
> - update to English Version
> - a few modifications on README.MD

> ## 2017-9-8
> ### Progress:
> - add function: create new image
>  1. add dialog "new image"
>  2. correlate dialog with button *ID_FILE_NEW*
>  3. [attain mainframe size][1]  ![][2]

> ## 2017-9-9
> ### Progress:
> - reset to delete dialog form of 'create new image'
> - delete original toolbar
> - create new image-edit tools
>    1. ~~[use ondraw function to create static shapes][3]~~
>    2. create pencil function (currently malfunctioning, actually presenting fold-lines rather than following mouse movement)

> ## 2017-9-11
> ### Progress:
> - Reset to empty single document
> - Fulfil "Pencil" function
> - Fulfil "Select color" function(user-defined);
> - Create dialog attached to ID_FILE_NEW: "NEW IMAGE" 
> - Fulfil "Settings" toolbar, including line width, line style and color selection
> - Fulfil "Line Function" (lacking double-buffer, a bit weird at the moment)   ![][4]
> - Fulfil "Rectangle Function" ~~(lacking double-buffer, a bit weird at the moment)~~

> ## 2017-9-12
> ### Progress:
> - Fulfil "Filled rectangle" function
> - Fulfil "Outlined rectangle" function
> - ~~**"Rectangle"s do not require double-bufferings!**~~

> ## 2017-9-13
> ### Progress:
> - Fulfil "round rectangle" function series
> - **NOTE: IMPLEMENT DOUBLE-BUFFER FOR ALL BASIC PAINTING FUNCTIONS**
> - Fulfil "Ellipse" function series
> - Fulfil "open file" function with openCV

> ## 2017-9-18
> ### Progress:
> - switch type CImage to type IplImage
> - override function OnSave() for saving various img types
> - initialize default-sized image upon opening the program(500*500)
> - restore order for OnSave
> - separate function **Save** from **Save As**
> ### Existing Bugs:
> - ~~deranged signal order for 'OnSave()'~~ ![][9]
> - ~~unable to set default-sized new image upon opening~~ ![][9]
> - lacking user-defined color panel(palette)
> - need extra caution on destroying iplimage and cimage
> ### Related Topics
> - [MFC document serialization][5]
> - [convertion between CImage and IplImage][6]
> - [BUG EXTERMINATION: 'MessageBoxA' : function does not take 1 parameters][7]
> - [switch from CBitmap to IplImage][8]

> ## 2017-9-19
> ### Progress:
> - evaded image-flip when saving pictures
> - solve 'user breakpoint at....' by rearranging reference to opencv1.o(see reference in READEME.MD)




  [1]: http://jingyan.baidu.com/album/3ea51489c0b2d852e61bbac0.html
  [2]: https://img.shields.io/badge/completion-10%25-red.svg
  [3]: http://www.cnblogs.com/shenxiaolin/p/5295995.html  
  [4]: https://img.shields.io/badge/progress-30%-blue.svg
  [5]: http://www.cnblogs.com/superanyi/archive/2011/01/06/1929182.html
  [6]: http://blog.sina.com.cn/s/blog_6f4991630100n20k.html
  [7]: http://blog.csdn.net/yitaohust/article/details/3051931
  [8]: http://3y.uu456.com/bp_9qzpt1ix4e2p7v440mh4_1.html
  [9]: https://img.shields.io/badge/state-exterminated-brightgreen.svg
  
  
  
  
