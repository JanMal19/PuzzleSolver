#pragma once

/// <summary>
/// Pomys� aby w klasie GameForm zamiast u�ywa� PuzzleButtonWrappera to mo�emy mie� szablon bazowy
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