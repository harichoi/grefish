
#ifndef _COMMON_H_
#define _COMMON_H_

#pragma comment(lib, "dxguid.lib") // "dxguid.lib" 와 "ddraw.lib"를
#pragma comment(lib, "ddraw.lib")  // 프로젝트에 명시적으로 포함시킨다.

//////////////
// 상수 정의 //
//////////////
#define ERR                     -1   // 에러 처리용 코드 -1.

#define SCREEN_BPP       16   // Bits per pixel.
#define SCREEN_WIDTH    800 // 화면의 가로 크기.
#define SCREEN_HEIGHT  600 // 화면의 세로 크기.
#define CLASS_NAME       "Display Mode Setting Example"

////////////////
// 매크로 함수 //
////////////////
#define KEYUP(KeyCode)      ((GetAsyncKeyState(KeyCode))? 0 : 1)
#define KEYDOWN(KeyCode)    ((GetAsyncKeyState(KeyCode))? 1 : 0)

#define SAFERELEASE(Object) if(Object) { Object->Release(); Object = NULL; }

#endif // end of ifndef _COMMON_H_. 
