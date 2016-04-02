
#ifndef _COMMON_H_
#define _COMMON_H_

#pragma comment(lib, "dxguid.lib") // "dxguid.lib" �� "ddraw.lib"��
#pragma comment(lib, "ddraw.lib")  // ������Ʈ�� ��������� ���Խ�Ų��.

//////////////
// ��� ���� //
//////////////
#define ERR                     -1   // ���� ó���� �ڵ� -1.

#define SCREEN_BPP       16   // Bits per pixel.
#define SCREEN_WIDTH    800 // ȭ���� ���� ũ��.
#define SCREEN_HEIGHT  600 // ȭ���� ���� ũ��.
#define CLASS_NAME       "Display Mode Setting Example"

////////////////
// ��ũ�� �Լ� //
////////////////
#define KEYUP(KeyCode)      ((GetAsyncKeyState(KeyCode))? 0 : 1)
#define KEYDOWN(KeyCode)    ((GetAsyncKeyState(KeyCode))? 1 : 0)

#define SAFERELEASE(Object) if(Object) { Object->Release(); Object = NULL; }

#endif // end of ifndef _COMMON_H_. 
