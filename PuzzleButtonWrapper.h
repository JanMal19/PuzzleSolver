#pragma once

#include "pch.h"
#include "PuzzleButton.h"

/// <summary>
/// Klasa która pozwala na wykorzystywanie klas zwyk³ych w ref klasach
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