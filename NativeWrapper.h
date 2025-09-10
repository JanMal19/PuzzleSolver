#pragma once

/// <summary>
/// Pomys³ aby w klasie GameForm zamiast u¿ywaæ PuzzleButtonWrappera to mo¿emy mieæ szablon bazowy
/// </summary>
/// <typeparam name="T"></typeparam>

template<typename T>
public ref class NativeWrapper
{
private:
    T* native;

public:
    NativeWrapper(T* obj) : native(obj) {}

    T* GetNative() { return native; }
};