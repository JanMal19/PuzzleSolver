#pragma once

#include "pch.h"
#include "PuzzleButton.h"

/// <summary>
/// Klasa kt�ra pozwala na wykorzystywanie klas zwyk�ych w ref klasach
/// </summary>
public ref class PuzzleButtonWrapper
{
private:
    PuzzleButton* native;

public:
    PuzzleButtonWrapper(PuzzleButton* pb) : native(pb) {}

    property System::Windows::Forms::Button^ ButtonControl {
        System::Windows::Forms::Button^ get() { return native->getButton(); }
    }

    PuzzleButton* GetNative() { return native; }

};