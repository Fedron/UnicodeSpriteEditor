#include <iostream>
#include "SpriteEditor.h"

int main()
{
    ce::Console::Create(L"Unicode Sprite Editor", 120, 30);
    SpriteEditor* se = new SpriteEditor();

    se->Run();
}
