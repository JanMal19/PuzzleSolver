#pragma once

/// <summary>
/// Pomys³ aby usprawniæ przekazywanie i u¿ycie ToIntPtr
/// </summary>
/// <typeparam name="T"></typeparam>

template<typename T>
ref class PointerConverter
{
public:
    static System::IntPtr ToIntPtr(T* ptr) {
        return System::IntPtr(ptr);
    }

    static T* FromIntPtr(System::IntPtr ip) {
        return static_cast<T*>(ip.ToPointer());
    }
};