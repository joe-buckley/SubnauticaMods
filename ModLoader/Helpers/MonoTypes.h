#pragma once
#include "..\stdafx.h"

namespace MonoTypes {
   typedef MonoClass*(__cdecl* mono_class_from_name_t)(MonoImage* pMonoImage, const char* _namespace, const char* name);
   typedef MonoMethod*(__cdecl* mono_class_get_method_from_name_t)(MonoClass* pMonoClass, const char* name, int param_count);
   typedef MonoClassField*(__cdecl* mono_class_get_field_from_name_t)(MonoClass* pMonoClass, const char* name);
   typedef void(__cdecl* mono_field_get_value_t)(MonoObject* pMonoObject, MonoClassField* pMonoClassField, LPVOID out_pValue);
   typedef MonoObject*(__cdecl* mono_runtime_invoke_t)(MonoMethod* pMonoMethod, LPVOID pInstancePointer, void** params, MonoObject** exc);
   typedef MonoAssembly*(__cdecl* mono_domain_assembly_open_t)(MonoDomain* pMonoDomain, const char* pathFile);
   typedef MonoImage*(__cdecl* mono_assembly_get_image_t)(MonoAssembly* pMonoAssembly);
   typedef MonoDomain*(__cdecl* mono_domain_get_t)();
   typedef void(__cdecl* GFunc_t)(LPVOID data, LPVOID user_data);
   typedef void(__cdecl* mono_assembly_foreach_t)(GFunc_t func, LPVOID user_data);

   template <typename T>
   T GetMonoFunction(HMODULE hMono, const char* fnName) {
      return reinterpret_cast<T>(GetProcAddress(hMono, fnName));
   }
}