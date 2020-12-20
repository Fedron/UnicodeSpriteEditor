#include <iostream>
#include "Console.h"

int main()
{
    ce::Console::Create(L"Unicode Sprite Editor", 120, 30);
    ce::Console& console = ce::Console::rGetInstance();

    // Game loop
    while (true) {
        console.Draw(5, 10, L'#');
        console.Render();
    }
}
